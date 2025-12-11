//
// Created by Sixik on 12.12.2025.
//

#include <jni.h>

#include "NsGui/ProgressBar.h"

extern "C" {
static Noesis::ProgressBar *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.ProgressBar ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::ProgressBar *>(handle);
}


JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSProgressBar_nCreate(JNIEnv *env, jclass clazz) {
    return reinterpret_cast<jlong>(new Noesis::ProgressBar());
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSProgressBar_nGetIsIndeterminate(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetIsIndeterminate();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSProgressBar_nSetIsIndeterminate(
    JNIEnv *env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetIsIndeterminate(value);
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSProgressBar_nGetOrientation(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetOrientation();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSProgressBar_nSetOrientation(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetOrientation(static_cast<Noesis::Orientation>(value));
}
}
