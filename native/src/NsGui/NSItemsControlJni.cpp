//
// Created by Sixik on 12.12.2025.
//

#include <jni.h>

#include "NsGui/ItemsControl.h"
#include "NsGui/Panel.h"

extern "C" {
static Noesis::ItemsControl *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.ItemsControl ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::ItemsControl *>(handle);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nCreate(JNIEnv *env, jclass clazz) {
    return reinterpret_cast<jlong>(new Noesis::ItemsControl());
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetAlternationCount(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetAlternationCount();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nSetAlternationCount(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetAlternationCount(value);
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetAlternationIndexStatic(
    JNIEnv *env, jclass clazz, jlong element_ptr) {
    return Noesis::ItemsControl::GetAlternationIndex(reinterpret_cast<Noesis::DependencyObject *>(element_ptr));
}

JNIEXPORT jstring JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetDisplayMemberPath(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return env->NewStringUTF("");
    return env->NewStringUTF(component->GetDisplayMemberPath());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nSetDisplayMemberPath(
    JNIEnv *env, jclass clazz, jlong ptr, jstring value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    const char *cstr = env->GetStringUTFChars(value, nullptr);
    if (cstr == nullptr) {
        return;
    }

    component->SetDisplayMemberPath(cstr);
    env->ReleaseStringUTFChars(value, cstr);
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetHasItems(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetHasItems();
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetItemContainerGenerator(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetItemContainerGenerator());
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetItemContainerStyle(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetItemContainerStyle());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nSetItemContainerStyle(
    JNIEnv *env, jclass clazz, jlong ptr, jlong style_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetItemContainerStyle(reinterpret_cast<Noesis::Style *>(style_ptr));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetItemsPanel(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetItemsPanel());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nItemsPanelTemplate(
    JNIEnv *env, jclass clazz, jlong ptr, jlong template_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetItemsPanel(reinterpret_cast<Noesis::ItemsPanelTemplate *>(template_ptr));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetDefaultItemsPanel(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    const auto t = component->GetDefaultItemsPanel();
    t->AddReference();
    return reinterpret_cast<jlong>(t.GetPtr());
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetItemsSource(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetItemsSource());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nSetItemsSource(
    JNIEnv *env, jclass clazz, jlong ptr, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetItemsSource(reinterpret_cast<Noesis::BaseComponent *>(element_ptr));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetItemTemplate(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetItemTemplate());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nSetItemTemplate(
    JNIEnv *env, jclass clazz, jlong ptr, jlong template_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetItemTemplate(reinterpret_cast<Noesis::DataTemplate *>(template_ptr));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetItemTemplateSelector(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetItemTemplateSelector());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nSetItemTemplateSelector(
    JNIEnv *env, jclass clazz, jlong ptr, jlong selector_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetItemTemplateSelector(reinterpret_cast<Noesis::DataTemplateSelector *>(selector_ptr));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetItems(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetItems());
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nItemsControlFromItemContainerStatic(
    JNIEnv *env, jclass clazz, jlong element_ptr) {
    return reinterpret_cast<jlong>(Noesis::ItemsControl::ItemsControlFromItemContainer(reinterpret_cast<Noesis::DependencyObject *>(element_ptr)));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nContainerFromElementStatic(
    JNIEnv *env, jclass clazz, jlong container_ptr, jlong element_ptr) {
    return reinterpret_cast<jlong>(Noesis::ItemsControl::ContainerFromElement(reinterpret_cast<Noesis::ItemsControl *>(container_ptr), reinterpret_cast<Noesis::DependencyObject *>(element_ptr)));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nContainerFromElement(
    JNIEnv *env, jclass clazz, jlong ptr, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->ContainerFromElement(reinterpret_cast<Noesis::DependencyObject *>(element_ptr)));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nGetItemsOwnerStatic(
    JNIEnv *env, jclass clazz, jlong element_ptr) {
    return reinterpret_cast<jlong>(Noesis::ItemsControl::GetItemsOwner(reinterpret_cast<Noesis::DependencyObject *>(element_ptr)));
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSItemsControl_nIsItemItsOwnContainer(
    JNIEnv *env, jclass clazz, jlong ptr, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->IsItemItsOwnContainer(reinterpret_cast<Noesis::BaseComponent *>(element_ptr));
}
}
