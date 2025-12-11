//
// Created by Sixik on 11.12.2025.
//

#include <jni.h>

#include "../utils/NSJniUtils.h"
#include "NsGui/GradientStop.h"

extern "C" {

    static Noesis::GradientStop *getComponent(JNIEnv *env, const jlong handle) {
        if (handle == 0) {
            jclass excCls = env->FindClass("java/lang/IllegalStateException");
            if (excCls != nullptr) {
                env->ThrowNew(excCls, "Noesis.GradientStop ptr is null");
            }
            return nullptr;
        }
        return reinterpret_cast<Noesis::GradientStop *>(handle);
    }


    JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStop_nCreate(JNIEnv* env, jclass clazz) {
        return reinterpret_cast<jlong>(new Noesis::GradientStop());
    }

    JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStop_nGetColor(JNIEnv* env, jclass clazz, jlong ptr, jobject color) {
        const auto component = getComponent(env, ptr);
        if (component == nullptr) return;
        NSJniUtils::ColorFromCopy(env, component->GetColor(), color);
    }

    JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStop_nSetColor(JNIEnv* env, jclass clazz, jlong ptr, jobject color) {
        const auto component = getComponent(env, ptr);
        if (component == nullptr) return;
        Noesis::Color nColor = Noesis::Color();
        NSJniUtils::ColorToCopy(env, nColor, color);
        component->SetColor(nColor);
    }

    JNIEXPORT jfloat JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStop_nGetOffset(JNIEnv* env, jclass clazz, jlong ptr) {
        const auto component = getComponent(env, ptr);
        if (component == nullptr) return 0;
        return component->GetOffset();
    }

    JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStop_nSetOffset(JNIEnv* env, jclass clazz, jlong ptr, jfloat value) {
        const auto component = getComponent(env, ptr);
        if (component == nullptr) return;
        component->SetOffset(value);
    }

    JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStop_nColorProperty(JNIEnv* env, jclass clazz) {
        return reinterpret_cast<jlong>(Noesis::GradientStop::ColorProperty);
    }

    JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSGradientStop_nOffsetProperty(JNIEnv* env, jclass clazz) {
        return reinterpret_cast<jlong>(Noesis::GradientStop::OffsetProperty);
    }
}
