//
// Created by Sixik on 12.12.2025.
//

#include <jni.h>

#include "JavaNotifyPropertyChangedBase.h"
#include "../events/NsWidgetEvents.h"

#include "../jni.h"
#include "App/ApplicationLauncher/Include/NsApp/NotifyPropertyChangedBase.h"

namespace NoesisApp {
    class NotifyPropertyChangedBase;
}

namespace Noesis {
    struct PropertyChangedEventArgs;
}

namespace NoesisJava {
    class JavaNotifyPropertyChangedBase;

    template<typename EventType, typename JavaArgsType, typename EventAdderType, typename ArgsFillerType>
    void RegisterEventHandler(JNIEnv *env, jlong elementPtr, jobject jListener,
                              const char *methodSig,
                              EventAdderType &&eventAdder,
                              ArgsFillerType &&argsFiller) {
        if (elementPtr == 0 || jListener == nullptr) return;

        auto *element = reinterpret_cast<JavaNotifyPropertyChangedBase *>(elementPtr);
        if (element == nullptr) return;

        auto *data = new GenericEventHandler<JavaArgsType>();
        data->handlerGlobal = env->NewGlobalRef(jListener);
        data->handlerMethod = NSJavaUtils::methodFromHandler(env, jListener, methodSig);

        if (data->handlerMethod == nullptr) {
            env->DeleteGlobalRef(data->handlerGlobal);
            delete data;
            return;
        }

        eventAdder(element, [data, argsFiller](Noesis::BaseComponent *sender, const EventType &noesisArgs) {
            if (g_vm == nullptr || data == nullptr) return;

            JniEnvScope envScope(g_vm);
            JNIEnv *jniEnv = envScope;
            if (!jniEnv) return;

            argsFiller(data->args, noesisArgs);
            jobject javaSender = NSJavaUtils::createBaseObject(jniEnv, reinterpret_cast<jlong>(sender));
            jobject javaArgs = data->args.Create(jniEnv);

            jniEnv->CallVoidMethod(data->handlerGlobal, data->handlerMethod, javaSender, javaArgs);

            if (jniEnv->ExceptionCheck()) {
                jniEnv->ExceptionDescribe();
                jniEnv->ExceptionClear();
            }

            jniEnv->DeleteLocalRef(javaSender);
            jniEnv->DeleteLocalRef(javaArgs);
        });
    }
}

extern "C" {
static NoesisJava::JavaNotifyPropertyChangedBase *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.NotifyPropertyChangedBase ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<NoesisJava::JavaNotifyPropertyChangedBase *>(handle);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsapp_NsNotifyPropertyChangedBase_nCreate(JNIEnv *env, jclass clazz) {
    auto *obj = new NoesisJava::JavaNotifyPropertyChangedBase();
    obj->AddReference();
    return reinterpret_cast<jlong>(obj);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsapp_NsNotifyPropertyChangedBase_nPropertyChanged(
    JNIEnv *env, jclass clazz, jlong ptr, jobject event) {
    using EventType = Noesis::PropertyChangedEventArgs;
    using JavaArgsType = NoesisJava::JavaNSPropertyChangedEventHandler::JavaNSPropertyChangedEventArgs;
    constexpr auto sig = "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSPropertyChangedEventArgs;)V";

    auto eventAdder = [](NoesisJava::JavaNotifyPropertyChangedBase *el, auto &&lambda) { el->PropertyChanged() += lambda; };
    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {

    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(env, ptr, event, sig, eventAdder, argsFiller);

}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsapp_NsNotifyPropertyChangedBase_nRaisePropertyChanged(
    JNIEnv *env, jclass clazz, jlong ptr, jstring jName) {
    if (!ptr || !jName) return;

    auto* obj = reinterpret_cast<NoesisJava::JavaNotifyPropertyChangedBase*>(ptr);

    const char* name = env->GetStringUTFChars(jName, nullptr);
    obj->JavaOnPropertyChanged(name);
    env->ReleaseStringUTFChars(jName, name);
}
}
