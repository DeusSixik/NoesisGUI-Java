//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "NsGui/IntegrationAPI.h"
#include "NsGui/IView.h"
#include "NsMath/AABBox.h"
#include <NsGui/ResourceDictionary.h>

#include "jni.h"
#include "App/Theme/Include/NsApp/ThemeProviders.h"
#include "Render/GLRenderDevice/Include/NsRender/GLFactory.h"


extern "C" {
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_NoesisGui_nSetLicense(JNIEnv *env, jclass, jstring name, jstring key) {
    const char *cstr = env->GetStringUTFChars(name, nullptr);
    if (cstr == nullptr) {
        return;
    }

    const char *cstr2 = env->GetStringUTFChars(key, nullptr);
    if (cstr2 == nullptr) {
        return;
    }

    Noesis::GUI::SetLicense(cstr, cstr2);
    env->ReleaseStringUTFChars(name, cstr);
    env->ReleaseStringUTFChars(key, cstr2);
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_NoesisGui_nativeSetThemeProviders(JNIEnv *env, jclass) {
    NoesisApp::SetThemeProviders();
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_NoesisGui_nativeLoadApplicationResources(JNIEnv *env, jclass, jlong ptr) {
    Noesis::GUI::LoadApplicationResources(*reinterpret_cast<Noesis::Uri *>(ptr));
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_NoesisGui_nativeInit(JNIEnv *env, jclass) {
    Noesis::GUI::Init();
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_NoesisGui_nativeShutdown(JNIEnv *env, jclass) {
    Noesis::GUI::Shutdown();
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_NoesisGui_nativeCreateView(JNIEnv *env, jclass, jlong elementPtr) {
    if (!elementPtr) return 0;
    return reinterpret_cast<jlong>(Noesis::GUI::CreateView(reinterpret_cast<Noesis::FrameworkElement *>(elementPtr)).
        GiveOwnership());
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_NoesisGui_nativeParseXamlTheme(JNIEnv *env, jclass, jstring xamlCode) {
    if (xamlCode == nullptr) return 0;

    const char *nativeCode = env->GetStringUTFChars(xamlCode, nullptr);
    if (!nativeCode) return 0;

    Noesis::Ptr<Noesis::ResourceDictionary> root;
    try {
        root = Noesis::GUI::ParseXaml<Noesis::ResourceDictionary>(nativeCode);
    } catch (...) {
        env->ReleaseStringUTFChars(xamlCode, nativeCode);
        return 0;
    }

    env->ReleaseStringUTFChars(xamlCode, nativeCode);

    Noesis::ResourceDictionary *ptr = root.GetPtr();
    if (ptr != nullptr) {
        ptr->AddReference();
    }

    return reinterpret_cast<jlong>(ptr);
}


JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_NoesisGui_nativeParseXaml(JNIEnv *env, jclass, jstring xamlCode) {
    if (xamlCode == nullptr) return 0;

    const char *nativeCode = env->GetStringUTFChars(xamlCode, nullptr);
    if (!nativeCode) return 0;

    Noesis::Ptr<Noesis::BaseComponent> root;
    try {
        root = Noesis::GUI::ParseXaml(nativeCode);
    } catch (...) {
        env->ReleaseStringUTFChars(xamlCode, nativeCode);
        return 0;
    }

    env->ReleaseStringUTFChars(xamlCode, nativeCode);

    Noesis::BaseComponent *ptr = root.GetPtr();
    if (ptr != nullptr) {
        // Увеличиваем refcount, чтобы объект жил после уничтожения Ptr
        ptr->AddReference();
    }


    // root выходит из области видимости -> Release() -> refcount--,
    // но мы только что сделали AddReference(), так что объект остаётся жив.
    return reinterpret_cast<jlong>(ptr);
}


struct NsLogHandler {
    jobject handlerGlobal = nullptr;
    jmethodID onLogMethod = nullptr;
};

static NsLogHandler g_logHandler;

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_NoesisGui_nSetLogHandler(
    JNIEnv *env, jclass,
    jobject jHandler) {
    // 1. Убиваем старый глобальный ref (если был)
    if (g_logHandler.handlerGlobal != nullptr) {
        env->DeleteGlobalRef(g_logHandler.handlerGlobal);
        g_logHandler.handlerGlobal = nullptr;
        g_logHandler.onLogMethod = nullptr;
    }

    // Если передали null – просто выключаем логгер (или ставим дефолтный)
    if (jHandler == nullptr) {
        Noesis::GUI::SetLogHandler(nullptr);
        return;
    }

    jclass handlerClass = env->GetObjectClass(jHandler);
    if (handlerClass == nullptr) {
        return; // что-то совсем странное
    }

    jmethodID onLogMethod = env->GetMethodID(
        handlerClass,
        "onLog",
        "(Ljava/lang/String;JJLjava/lang/String;Ljava/lang/String;)V"
    );
    env->DeleteLocalRef(handlerClass);

    if (onLogMethod == nullptr) {
        // нет такого метода — можно кинуть исключение в Java, но минимум просто выйти
        return;
    }

    g_logHandler.handlerGlobal = env->NewGlobalRef(jHandler);
    g_logHandler.onLogMethod = onLogMethod;

    // 2. Ставим log handler
    Noesis::GUI::SetLogHandler([](const char *file,
                                  uint32_t line,
                                  uint32_t level,
                                  const char *channel,
                                  const char *msg) {
        if (NoesisJava::g_vm == nullptr) return;

        JNIEnv *env = nullptr;
        bool attached = false;

        jint res = NoesisJava::g_vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_8);
        if (res == JNI_EDETACHED) {
            if (NoesisJava::g_vm->AttachCurrentThread(reinterpret_cast<void **>(&env), nullptr) != JNI_OK) {
                return;
            }
            attached = true;
        } else if (res != JNI_OK) {
            return;
        }

        // Если handler уже очищен — просто выходим
        if (g_logHandler.handlerGlobal == nullptr || g_logHandler.onLogMethod == nullptr) {
            if (attached) {
                NoesisJava::g_vm->DetachCurrentThread();
            }
            return;
        }

        jstring jFile = env->NewStringUTF(file ? file : "");
        jstring jChannel = env->NewStringUTF(channel ? channel : "");
        jstring jMsg = env->NewStringUTF(msg ? msg : "");

        env->CallVoidMethod(
            g_logHandler.handlerGlobal,
            g_logHandler.onLogMethod,
            jFile,
            static_cast<jlong>(line),
            static_cast<jlong>(level),
            jChannel,
            jMsg
        );

        // Чистим локальные ссылки
        env->DeleteLocalRef(jFile);
        env->DeleteLocalRef(jChannel);
        env->DeleteLocalRef(jMsg);

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        if (attached) {
            NoesisJava::g_vm->DetachCurrentThread();
        }
    });
}
}
