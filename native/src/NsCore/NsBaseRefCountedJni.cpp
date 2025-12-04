//
// Created by Sixik on 04.12.2025.
//


#include <jni.h>

#include "NsCore/BaseRefCounted.h"

namespace Noesis {
    class BaseObject;
}

extern "C" {
    static Noesis::BaseRefCounted *getComponent(JNIEnv *env, const jlong handle) {
        if (handle == 0) {
            jclass excCls = env->FindClass("java/lang/IllegalStateException");
            if (excCls != nullptr) {
                env->ThrowNew(excCls, "Noesis.BaseRefCounted ptr is null");
            }
            return nullptr;
        }
        return reinterpret_cast<Noesis::BaseRefCounted *>(handle);
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSBaseRefCounted_nativeAddReference(JNIEnv *env, jclass, const jlong ptr) {
        const auto ref = getComponent(env, ptr);
        if (!ref) return -1;
        return ref->AddReference();
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSBaseRefCounted_nativeRelease(JNIEnv *env, jclass, const jlong ptr) {
        const auto ref = getComponent(env, ptr);
        if (!ref) return -1;
        return ref->Release();
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSBaseRefCounted_nativeGetNumReferences(JNIEnv *env, jclass, const jlong ptr) {
        const auto ref = getComponent(env, ptr);
        if (!ref) return -1;
        return ref->GetNumReferences();
    }
}
