//
// Created by Sixik on 05.12.2025.
//

#include <jni.h>

#include "NsGui/RoutedEvent.h"

namespace Noesis {
    struct Interface;
}

extern "C" {

    static Noesis::RoutedEvent *getComponent(JNIEnv *env, const jlong handle) {
        if (handle == 0) {
            jclass excCls = env->FindClass("java/lang/IllegalStateException");
            if (excCls != nullptr) {
                env->ThrowNew(excCls, "Noesis.RoutedEvent ptr is null");
            }
            return nullptr;
        }
        return reinterpret_cast<Noesis::RoutedEvent *>(handle);
    }

    JNIEXPORT jstring JNICALL
    Java_dev_sixik_noesisgui_nscore_NSRoutedEvent_nGetName(JNIEnv *env, jclass,  jlong ptr) {
        const auto data = getComponent(env, ptr);
        if (data == nullptr) return nullptr;
        return env->NewStringUTF(data->GetName().Str());
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSRoutedEvent_nGetOwnerType(JNIEnv *env, jclass, jlong ptr) {
        const auto data = getComponent(env, ptr);
        if (data == nullptr) return 0;
        return reinterpret_cast<jlong>(data->GetOwnerType());
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nscore_NSRoutedEvent_nSetOwnerType(JNIEnv *env, jclass, jlong ptr, jlong  ptr2) {
        const auto data = getComponent(env, ptr);
        if (data == nullptr) return;
        data->SetOwnerType(reinterpret_cast<Noesis::TypeClass *>(data));
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nscore_NSRoutedEvent_nSetRoutingStrategy(JNIEnv *env, jclass, jlong ptr, jint  value) {
        const auto data = getComponent(env, ptr);
        if (data == nullptr) return;
        data->SetRoutingStrategy(static_cast<Noesis::RoutingStrategy>(value));
    }

    JNIEXPORT jint JNICALL
    Java_dev_sixik_noesisgui_nscore_NSRoutedEvent_nGetRoutingStrategy(JNIEnv *env, jclass, jlong ptr) {
        const auto data = getComponent(env, ptr);
        if (data == nullptr) return -1;
        return data->GetRoutingStrategy();
    }

}
