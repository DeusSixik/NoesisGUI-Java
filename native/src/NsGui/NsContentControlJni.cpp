//
// Created by Sixik on 10.12.2025.
//

#include <jni.h>

#include "NsGui/ContentControl.h"

extern "C" {

static Noesis::ContentControl *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.ContentControl ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::ContentControl *>(handle);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSContentControl_nGetContent(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetContent());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContentControl_nSetContent(JNIEnv* env, jclass clazz, jlong ptr, jlong component_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetContent(reinterpret_cast<Noesis::BaseComponent *>(component_ptr));
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContentControl_nSetContentString(JNIEnv* env, jclass clazz, jlong ptr, jstring content) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;

    const char *cstr = env->GetStringUTFChars(content, nullptr);
    if (cstr == nullptr) {
        return;
    }


    component->SetContent(cstr);
    env->ReleaseStringUTFChars(content, cstr);
}

JNIEXPORT jstring JNICALL Java_dev_sixik_noesisgui_nsgui_NSContentControl_nGetContentStringFormat(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return nullptr;
    return env->NewStringUTF(component->GetContentStringFormat());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContentControl_nSetContentStringFormat(JNIEnv* env, jclass clazz, jlong ptr, jstring value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    const char *cstr = env->GetStringUTFChars(value, nullptr);
    if (cstr == nullptr) {
        return;
    }
    component->SetContentStringFormat(cstr);
    env->ReleaseStringUTFChars(value, cstr);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSContentControl_nGetContentTemplate(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetContentTemplate());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContentControl_nSetContentTemplate(JNIEnv* env, jclass clazz, jlong ptr, jlong data_template_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetContentTemplate(reinterpret_cast<Noesis::DataTemplate *>(data_template_ptr));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSContentControl_nGetContentTemplateSelector(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetContentTemplateSelector());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContentControl_nSetContentTemplateSelector(JNIEnv* env, jclass clazz, jlong ptr, jlong selector_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetContentTemplateSelector(reinterpret_cast<Noesis::DataTemplateSelector *>(selector_ptr));
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSContentControl_nGetHasContent(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return false;
    return component->GetHasContent();
}

}
