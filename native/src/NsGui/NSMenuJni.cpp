//
// Created by Sixik on 12.12.2025.
//

#include <jni.h>

#include "NsGui/Menu.h"

extern "C" {
static Noesis::Menu *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.Menu ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::Menu *>(handle);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSMenu_nCreate(JNIEnv *env, jclass clazz) {
    return reinterpret_cast<jlong>(new Noesis::Menu());
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSMenu_nGetIsMainMenu(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetIsMainMenu();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSMenu_nSetIsMainMenu(
    JNIEnv *env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetIsMainMenu(value);
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSMenu_nGetActivated(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetActivated();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSMenu_nSetActivated(
    JNIEnv *env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetActivated(value);
}
}
