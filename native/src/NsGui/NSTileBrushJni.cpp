//
// Created by Sixik on 11.12.2025.
//

#include <jni.h>

#include "../utils/NSJniUtils.h"
#include "NsGui/TileBrush.h"

extern "C" {

static Noesis::TileBrush *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.TileBrush ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::TileBrush *>(handle);
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nGetAlignmentX(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetAlignmentX();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nSetAlignmentX(JNIEnv* env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetAlignmentX(static_cast<Noesis::AlignmentX>(value));
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nGetAlignmentY(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetAlignmentY();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nSetAlignmentY(JNIEnv* env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetAlignmentY(static_cast<Noesis::AlignmentY>(value));
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nGetStretch(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetStretch();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nSetStretch(JNIEnv* env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetStretch(static_cast<Noesis::Stretch>(value));
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nGetTileMode(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetTileMode();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nSetTileMode(JNIEnv* env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetTileMode(static_cast<Noesis::TileMode>(value));
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nGetViewbox(JNIEnv* env, jclass clazz, jlong ptr, jobject rect) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    NSJniUtils::RectFromCopy(env, component->GetViewbox(), rect);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nSetViewbox(JNIEnv* env, jclass clazz, jlong ptr, jobject rect) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    Noesis::Rect r = Noesis::Rect();
    NSJniUtils::RectToCopy(env, r, rect);
    component->SetViewbox(r);
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nGetViewboxUnits(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetViewboxUnits();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nSetViewboxUnits(JNIEnv* env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetViewboxUnits(static_cast<Noesis::BrushMappingMode>(value));
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nGetViewport(JNIEnv* env, jclass clazz, jlong ptr, jobject rect) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    NSJniUtils::RectFromCopy(env, component->GetViewport(), rect);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nSetViewport(JNIEnv* env, jclass clazz, jlong ptr, jobject rect) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    Noesis::Rect r = Noesis::Rect();
    NSJniUtils::RectToCopy(env, r, rect);
    component->SetViewport(r);
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nGetViewportUnits(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetViewportUnits();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nSetViewportUnits(JNIEnv* env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetViewportUnits(static_cast<Noesis::BrushMappingMode>(value));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nAlignmentXProperty(JNIEnv* env, jclass clazz) {
    return reinterpret_cast<jlong>(Noesis::TileBrush::AlignmentXProperty);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nAlignmentYProperty(JNIEnv* env, jclass clazz) {
    return reinterpret_cast<jlong>(Noesis::TileBrush::AlignmentYProperty);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nStretchProperty(JNIEnv* env, jclass clazz) {
    return reinterpret_cast<jlong>(Noesis::TileBrush::StretchProperty);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nTileModeProperty(JNIEnv* env, jclass clazz) {
    return reinterpret_cast<jlong>(Noesis::TileBrush::TileModeProperty);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nViewboxProperty(JNIEnv* env, jclass clazz) {
    return reinterpret_cast<jlong>(Noesis::TileBrush::ViewboxProperty);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nViewboxUnitsProperty(JNIEnv* env, jclass clazz) {
    return reinterpret_cast<jlong>(Noesis::TileBrush::ViewboxUnitsProperty);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nViewportProperty(JNIEnv* env, jclass clazz) {
    return reinterpret_cast<jlong>(Noesis::TileBrush::ViewportProperty);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTileBrush_nViewportUnitsProperty(JNIEnv* env, jclass clazz) {
    return reinterpret_cast<jlong>(Noesis::TileBrush::ViewportUnitsProperty);
}

}