//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>

#include "../utils/NSJniUtils.h"
#include "NsGui/BaseGridViewRowPresenter.h"

namespace Noesis {
    class Stream;
}

extern "C" {
static Noesis::Visual *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.Visual ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::Visual *>(handle);
}

JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeIsAncestorOf(JNIEnv *env, jclass, const jlong ptr,
                                                            const jlong visualPtr) {
    const auto obj = getComponent(env, ptr);
    if (!obj) return false;
    const auto obj2 = getComponent(env, visualPtr);
    if (!obj2) return false;
    return obj->IsAncestorOf(obj2);
}

JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeIsDescendantOf(JNIEnv *env, jclass, const jlong ptr,
                                                              const jlong visualPtr) {
    const auto obj = getComponent(env, ptr);
    if (!obj) return false;
    const auto obj2 = getComponent(env, visualPtr);
    if (!obj2) return false;
    return obj->IsDescendantOf(obj2);
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeFindCommonVisualAncestor(JNIEnv *env, jclass, const jlong ptr,
                                                                        const jlong visualPtr) {
    const auto obj = getComponent(env, ptr);
    if (!obj) return false;
    const auto obj2 = getComponent(env, visualPtr);
    if (!obj2) return false;
    return reinterpret_cast<jlong>(obj->FindCommonVisualAncestor(obj2));
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativePointFromScreen(JNIEnv *env, jclass, const jlong ptr, const jobject in,
                                                               const jobject out) {
    const auto obj = getComponent(env, ptr);
    if (!obj || !in || !out) return;
    Noesis::Point point;
    NSJniUtils::PointToCopy(env, point, in);
    point = obj->PointFromScreen(point);
    NSJniUtils::PointFromCopy(env, point, out);
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativePointToScreen(JNIEnv *env, jclass, const jlong ptr, const jobject in,
                                                             const jobject out) {
    const auto obj = getComponent(env, ptr);
    if (!obj || !in || !out) return;
    Noesis::Point point;
    NSJniUtils::PointToCopy(env, point, in);
    point = obj->PointToScreen(point);
    NSJniUtils::PointFromCopy(env, point, out);
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeTransformToAncestor(JNIEnv *env, jclass, const jlong ptr,
                                                                   const long visualPtr, const jobject out) {
    const auto obj = getComponent(env, ptr);
    const auto obj2 = getComponent(env, visualPtr);
    if (!obj || !obj2 || !out) return;
    NSJniUtils::Matrix4FromCopy(env, obj->TransformToAncestor(obj2), out);
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeTransformToDescendant(JNIEnv *env, jclass, const jlong ptr,
                                                                     const long visualPtr, const jobject out) {
    const auto obj = getComponent(env, ptr);
    const auto obj2 = getComponent(env, visualPtr);
    if (!obj || !obj2 || !out) return;
    NSJniUtils::Matrix4FromCopy(env, obj->TransformToDescendant(obj2), out);
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeTransformToVisual(JNIEnv *env, jclass, const jlong ptr,
                                                                 const long visualPtr, const jobject out) {
    const auto obj = getComponent(env, ptr);
    const auto obj2 = getComponent(env, visualPtr);
    if (!obj || !obj2 || !out) return;
    NSJniUtils::Matrix4FromCopy(env, obj->TransformToVisual(obj2), out);
}

JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeIsInvalidated(JNIEnv *env, jclass, const jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (!obj) return false;
    return obj->IsInvalidated();
}

JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeIsConnectedToView(JNIEnv *env, jclass, const jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (!obj) return false;
    return obj->IsConnectedToView();
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeGetView(JNIEnv *env, jclass, const jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (!obj) return false;
    return reinterpret_cast<jlong>(obj->GetView());
}

JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeIsInRenderTree(JNIEnv *env, jclass, const jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (!obj) return false;
    return obj->IsInRenderTree();
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeGetRenderTreeId(JNIEnv *env, jclass, const jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (!obj) return false;
    return obj->GetRenderTreeId();
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeUpdateRender(JNIEnv *env, jclass, const jlong ptr, jlong updaterPtr) {
    const auto obj = getComponent(env, ptr);
    if (!obj) return;
    obj->UpdateRender(*reinterpret_cast<Noesis::RenderTreeUpdater *>(updaterPtr));
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSVisual_nativeEnsureRenderId(JNIEnv *env, jclass, const jlong ptr, jlong updaterPtr) {
    const auto obj = getComponent(env, ptr);
    if (!obj) return;
    obj->EnsureRenderId(*reinterpret_cast<Noesis::RenderTreeUpdater *>(updaterPtr));
}
}
