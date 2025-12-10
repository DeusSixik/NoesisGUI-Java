//
// Created by Sixik on 10.12.2025.
//

#include <jni.h>

#include "NsGui/Panel.h"

extern "C" {

    static Noesis::Panel *getComponent(JNIEnv *env, const jlong handle) {
        if (handle == 0) {
            jclass excCls = env->FindClass("java/lang/IllegalStateException");
            if (excCls != nullptr) {
                env->ThrowNew(excCls, "Noesis.Panel ptr is null");
            }
            return nullptr;
        }
        return reinterpret_cast<Noesis::Panel *>(handle);
    }


    JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSPanel_nGetBackground(JNIEnv* env, jclass clazz, jlong ptr) {
        const auto component = getComponent(env, ptr);
        if (component == nullptr) return 0;
        return reinterpret_cast<jlong>(component->GetBackground());
    }

    JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSPanel_nSetBackground(JNIEnv* env, jclass clazz, jlong ptr, jlong brush_ptr) {
        const auto component = getComponent(env, ptr);
        if (component == nullptr) return;
        component->SetBackground(reinterpret_cast<Noesis::Brush *>(brush_ptr));
    }

    JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSPanel_nGetIsItemsHost(JNIEnv* env, jclass clazz, jlong ptr) {
        const auto component = getComponent(env, ptr);
        if (component == nullptr) return false;
        return component->GetIsItemsHost();
    }

    JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSPanel_nSetIsItemsHost(JNIEnv* env, jclass clazz, jlong ptr, jboolean value) {
        const auto component = getComponent(env, ptr);
        if (component == nullptr) return;
        component->SetIsItemsHost(value);
    }

    JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSPanel_nGetZIndex(JNIEnv* env, jclass clazz, jlong element_ptr) {
        return Noesis::Panel::GetZIndex(reinterpret_cast<Noesis::DependencyObject *>(element_ptr));
    }

    JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSPanel_nSetZIndex(JNIEnv* env, jclass clazz, jlong element_ptr, jint value) {
        Noesis::Panel::SetZIndex(reinterpret_cast<Noesis::DependencyObject *>(element_ptr), value);
    }

    JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSPanel_nGetChildren(JNIEnv* env, jclass clazz, jlong ptr) {
        const auto component = getComponent(env, ptr);
        if (component == nullptr) return 0;
        return reinterpret_cast<jlong>(component->GetChildren());
    }
}
