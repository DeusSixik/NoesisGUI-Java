//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "NsCore/BaseComponent.h"

extern "C" {

    static Noesis::BaseComponent *getComponent(JNIEnv *env, const jlong handle) {
        if (handle == 0) {
            jclass excCls = env->FindClass("java/lang/IllegalStateException");
            if (excCls != nullptr) {
                env->ThrowNew(excCls, "Noesis.BaseComponent ptr is null");
            }
            return nullptr;
        }
        return reinterpret_cast<Noesis::BaseComponent *>(handle);
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nscore_NSBaseComponent_nativeFree(JNIEnv *env, jclass, jlong ptr) {
        delete getComponent(env, ptr);
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nscore_NSBaseComponent_nativeDestroy(JNIEnv* env, jobject thiz) {
        jclass cls = env->GetObjectClass(thiz);
        jfieldID ptrField = env->GetFieldID(cls, "ptr", "J");

        jlong ptrVal = env->GetLongField(thiz, ptrField);
        auto* comp = reinterpret_cast<Noesis::BaseComponent*>(ptrVal);

        if (comp != nullptr) {
            comp->Release();
            env->SetLongField(thiz, ptrField, 0);
        }

        env->DeleteLocalRef(cls);
    }
}
