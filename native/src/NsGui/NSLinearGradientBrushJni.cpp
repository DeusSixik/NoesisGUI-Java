//
// Created by Sixik on 11.12.2025.
//

#include <jni.h>

#include "../utils/NSJniUtils.h"
#include "NsGui/LinearGradientBrush.h"

extern "C" {
static Noesis::LinearGradientBrush *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.LinearGradientBrush ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::LinearGradientBrush *>(handle);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSLinearGradientBrush_nCreate(JNIEnv* env, jclass) {
    return reinterpret_cast<jlong>(new Noesis::LinearGradientBrush());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSLinearGradientBrush_nGetStartPoint(
    JNIEnv *env, jclass clazz, jlong ptr, jobject point) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    NSJniUtils::PointFromCopy(env, component->GetStartPoint(), point);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSLinearGradientBrush_nSetStartPoint(
    JNIEnv *env, jclass clazz, jlong ptr, jobject point) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    Noesis::Point p = Noesis::Point();
    NSJniUtils::PointToCopy(env, p, point);
    component->SetStartPoint(p);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSLinearGradientBrush_nGetEndPoint(
    JNIEnv *env, jclass clazz, jlong ptr, jobject point) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    NSJniUtils::PointFromCopy(env, component->GetEndPoint(), point);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSLinearGradientBrush_nSetEndPoint(
    JNIEnv *env, jclass clazz, jlong ptr, jobject point) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    Noesis::Point p = Noesis::Point();
    NSJniUtils::PointToCopy(env, p, point);
    component->SetEndPoint(p);
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSLinearGradientBrush_nEndPointProperty(JNIEnv *env, jclass clazz) {
    return reinterpret_cast<jlong>(Noesis::LinearGradientBrush::EndPointProperty);
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSLinearGradientBrush_nStartPointProperty(
    JNIEnv *env, jclass clazz) {
    return reinterpret_cast<jlong>(Noesis::LinearGradientBrush::StartPointProperty);
}
}
