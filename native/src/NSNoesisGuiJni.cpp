//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "NsGui/IntegrationAPI.h"
#include "NsGui/IView.h"
#include "NsMath/AABBox.h"
#include <NsGui/ResourceDictionary.h>

#include "App/Theme/Include/NsApp/ThemeProviders.h"
#include "Render/GLRenderDevice/Include/NsRender/GLFactory.h"

extern "C" {



    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_NoesisGui_nativeSetThemeProviders(JNIEnv* env, jclass) {
        NoesisApp::SetThemeProviders();
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_NoesisGui_nativeLoadApplicationResources(JNIEnv* env, jclass, jlong ptr) {
        Noesis::GUI::LoadApplicationResources(*reinterpret_cast<Noesis::Uri *>(ptr));
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_NoesisGui_nativeInit(JNIEnv* env, jclass) {
        Noesis::GUI::Init();
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_NoesisGui_nativeShutdown(JNIEnv* env, jclass) {
        Noesis::GUI::Shutdown();
    }

    JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_NoesisGui_nativeCreateView(JNIEnv* env, jclass, jlong elementPtr) {
        if (!elementPtr) return 0;
        return reinterpret_cast<jlong>(Noesis::GUI::CreateView(reinterpret_cast<Noesis::FrameworkElement *>(elementPtr)).GiveOwnership());
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_NoesisGui_nativeParseXamlTheme(JNIEnv* env, jclass, jstring xamlCode) {
        if (xamlCode == nullptr) return 0;

        const char* nativeCode = env->GetStringUTFChars(xamlCode, nullptr);
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
    Java_dev_sixik_noesisgui_NoesisGui_nativeParseXaml(JNIEnv* env, jclass, jstring xamlCode) {
        if (xamlCode == nullptr) return 0;

        const char* nativeCode = env->GetStringUTFChars(xamlCode, nullptr);
        if (!nativeCode) return 0;

        Noesis::Ptr<Noesis::BaseComponent> root;
        try {
            root = Noesis::GUI::ParseXaml(nativeCode);
        } catch (...) {
            env->ReleaseStringUTFChars(xamlCode, nativeCode);
            return 0;
        }

        env->ReleaseStringUTFChars(xamlCode, nativeCode);

        Noesis::BaseComponent* ptr = root.GetPtr();
        if (ptr != nullptr) {
            // Увеличиваем refcount, чтобы объект жил после уничтожения Ptr
            ptr->AddReference();
        }


        // root выходит из области видимости -> Release() -> refcount--,
        // но мы только что сделали AddReference(), так что объект остаётся жив.
        return reinterpret_cast<jlong>(ptr);
    }
}
