//
// Created by Sixik on 11.12.2025.
//

#include <jni.h>

#include "NsGui/GradientStopCollection.h"

extern "C" {

static Noesis::GradientStopCollection *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.GradientStopCollection ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::GradientStopCollection *>(handle);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStopCollection_nCreate(
     JNIEnv *env, jclass clazz) {
    return reinterpret_cast<jlong>(new Noesis::GradientStopCollection());
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStopCollection_nGet(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->Get(value));
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStopCollection_nSet(
    JNIEnv *env, jclass clazz, jlong ptr, jint value, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->Set(value, reinterpret_cast<Noesis::GradientStop *>(element_ptr));
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStopCollection_nAdd(
    JNIEnv *env, jclass clazz, jlong ptr, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->Add(reinterpret_cast<Noesis::GradientStop *>(element_ptr));
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStopCollection_nInsert(
    JNIEnv *env, jclass clazz, jlong ptr, jint index, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->Insert(index, reinterpret_cast<Noesis::GradientStop *>(element_ptr));
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStopCollection_nContains(
    JNIEnv *env, jclass clazz, jlong ptr, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return false;
    return component->Contains(reinterpret_cast<Noesis::GradientStop *>(element_ptr));
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStopCollection_nIndexOf(
    JNIEnv *env, jclass clazz, jlong ptr, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return -1;
    return component->IndexOf(reinterpret_cast<Noesis::GradientStop *>(element_ptr));
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStopCollection_nRemove(
    JNIEnv *env, jclass clazz, jlong ptr, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return false;
    return component->Remove(reinterpret_cast<Noesis::GradientStop *>(element_ptr));
}
}
