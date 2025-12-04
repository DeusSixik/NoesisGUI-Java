//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>

#include "NsCore/Interface.h"

namespace Noesis {
    class Stream;
}

extern "C" {

    static Noesis::Interface *getComponent(JNIEnv *env, const jlong handle) {
        if (handle == 0) {
            jclass excCls = env->FindClass("java/lang/IllegalStateException");
            if (excCls != nullptr) {
                env->ThrowNew(excCls, "Noesis.Interface ptr is null");
            }
            return nullptr;
        }
        return reinterpret_cast<Noesis::Interface *>(handle);
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSInterface_nativeGetClassType(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return 0;
        return reinterpret_cast<jlong>(obj->GetClassType());
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSInterface_nativeGetBaseObject(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return 0;
        return reinterpret_cast<jlong>(obj->GetBaseObject());
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSInterface_nativeAddReference(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return 0;
        return obj->AddReference();
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSInterface_nativeRelease(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return 0;
        return obj->Release();
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSInterface_nativeGetNumReferences(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return 0;
        return obj->GetNumReferences();
    }

}
