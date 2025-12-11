//
// Created by Sixik on 12.12.2025.
//

#include <jni.h>

#include "NsGui/Slider.h"

extern "C" {
static Noesis::Slider *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.Slider ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::Slider *>(handle);
}


JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nCreate(JNIEnv *env, jclass clazz) {
    return reinterpret_cast<jlong>(new Noesis::Slider());
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetDelay(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetDelay();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nSetDelay(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetDelay(value);
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetInterval(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetInterval();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nSetInterval(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetInterval(value);
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetIsDirectionReversed(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetIsDirectionReversed();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nSetIsDirectionReversed(
    JNIEnv *env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetIsDirectionReversed(value);
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetIsMoveToPointEnabled(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetIsMoveToPointEnabled();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nSetIsMoveToPointEnabled(
    JNIEnv *env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetIsMoveToPointEnabled(value);
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetIsSelectionRangeEnabled(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetIsSelectionRangeEnabled();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nSetIsSelectionRangeEnabled(
    JNIEnv *env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetIsSelectionRangeEnabled(value);
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetIsSnapToTickEnabled(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetIsSnapToTickEnabled();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nSetIsSnapToTickEnabled(
    JNIEnv *env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetIsSnapToTickEnabled(value);
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetOrientation(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetOrientation();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nSetOrientation(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetOrientation(static_cast<Noesis::Orientation>(value));
}

JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetSelectionEnd(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetSelectionEnd();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nSetSelectionEnd(
    JNIEnv *env, jclass clazz, jlong ptr, jfloat value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetSelectionEnd(value);
}

JNIEXPORT jfloat JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetSelectionStart(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetSelectionStart();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nSetSelectionStart(
    JNIEnv *env, jclass clazz, jlong ptr, jfloat value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetSelectionStart(value);
}

JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetTickFrequency(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetTickFrequency();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nSetTickFrequency(
    JNIEnv *env, jclass clazz, jlong ptr, jfloat value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetTickFrequency(value);
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetTickPlacement(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetTickPlacement();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nSetTickPlacement(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetTickPlacement(static_cast<Noesis::TickPlacement>(value));
}

JNIEXPORT jstring JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetTicks(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return env->NewStringUTF("");
    return env->NewStringUTF(component->GetTicks());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nSetTicks(
    JNIEnv *env, jclass clazz, jlong ptr, jstring value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;

    const char *cstr = env->GetStringUTFChars(value, nullptr);
    if (cstr == nullptr)return;

    component->SetTicks(cstr);
    env->ReleaseStringUTFChars(value, cstr);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSSlider_nGetTrack(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetTrack());
}
}
