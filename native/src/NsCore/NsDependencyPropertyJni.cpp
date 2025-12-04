//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>

#include "NsGui/DependencyProperty.h"

namespace Noesis {
    class BaseRefCounted;
}

extern "C" {

    static Noesis::DependencyProperty *getComponent(JNIEnv *env, const jlong handle) {
        if (handle == 0) {
            jclass excCls = env->FindClass("java/lang/IllegalStateException");
            if (excCls != nullptr) {
                env->ThrowNew(excCls, "Noesis.BaseRefCounted ptr is null");
            }
            return nullptr;
        }
        return reinterpret_cast<Noesis::DependencyProperty *>(handle);
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSDependencyProperty_nativeGetUnsetValue(JNIEnv *env, jclass) {
        return reinterpret_cast<jlong>(Noesis::DependencyProperty::GetUnsetValue());
    }

    JNIEXPORT jstring JNICALL
    Java_dev_sixik_noesisgui_nscore_NSDependencyProperty_nativeGetName(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return nullptr;
        return env->NewStringUTF(obj->GetName().Str());
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSDependencyProperty_nativeGetType(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return -1;
        return reinterpret_cast<jlong>(obj->GetType());
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSDependencyProperty_nativeGetOwnerType(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return -1;
        return reinterpret_cast<jlong>(obj->GetOwnerType());
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSDependencyProperty_nativeGetDefaultValue(JNIEnv *env, jclass, jlong ptr, jlong typeClassPtr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return -1;
        return reinterpret_cast<jlong>(obj->GetDefaultValue(reinterpret_cast<Noesis::TypeClass*>(typeClassPtr)));
    }

    JNIEXPORT jboolean JNICALL
    Java_dev_sixik_noesisgui_nscore_NSDependencyProperty_nativeIsReadOnly(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return -1;
        return obj->IsReadOnly();
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nscore_NSDependencyProperty_nativeGetSize(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return -1;
        return obj->GetSize();
    }
}
