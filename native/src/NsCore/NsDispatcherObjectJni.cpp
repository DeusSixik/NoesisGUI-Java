//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "NsGui/DispatcherObject.h"

extern "C" {

    static Noesis::DispatcherObject *getComponent(JNIEnv *env, const jlong handle) {
        if (handle == 0) {
            jclass excCls = env->FindClass("java/lang/IllegalStateException");
            if (excCls != nullptr) {
                env->ThrowNew(excCls, "Noesis.DispatcherObject ptr is null");
            }
            return nullptr;
        }
        return reinterpret_cast<Noesis::DispatcherObject *>(handle);
    }

    JNIEXPORT jboolean JNICALL
    Java_dev_sixik_noesisgui_nscore_NSDispatcherObject_nativeCheckAccess(JNIEnv *env, jclass, const jlong ptr) {
        const auto handle = getComponent(env, ptr);
        if (handle == nullptr) return false;
        return handle->CheckAccess();
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSDispatcherObject_nativeGetThreadId(JNIEnv *env, jclass, const jlong ptr) {
        const auto handle = getComponent(env, ptr);
        if (handle == nullptr) return -1;
        return handle->GetThreadId();
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nscore_NSDispatcherObject_nativeVerifyAccess(JNIEnv *env, jclass, const jlong ptr) {
        const auto handle = getComponent(env, ptr);
        if (handle == nullptr) return;
        handle->VerifyAccess();
    }
}
