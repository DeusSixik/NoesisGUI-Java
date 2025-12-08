//
// Created by Sixik on 05.12.2025.
//

#include <jni.h>

#include "../jni.h"
#include "../events/NsWidgetEvents.h"
#include "../utils/NSJniUtils.h"
#include "NsGui/FrameworkElement.h"

namespace Noesis {
    struct IRenderer;
}

extern "C" {
static Noesis::FrameworkElement *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.FrameworkElement ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::FrameworkElement *>(handle);
}


// int nGetFlowDirectionStatic(long objPtr);
JNIEXPORT jint JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetFlowDirectionStatic(
    JNIEnv *env, jclass, jlong objPtr) {
    return Noesis::FrameworkElement::GetFlowDirection(reinterpret_cast<Noesis::DependencyObject *>(objPtr));
}

// void nSetFlowDirectionStatic(long objPtr, int flowDirection);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetFlowDirectionStatic(
    JNIEnv *env, jclass, jlong objPtr, jint flowDirection) {
    Noesis::FrameworkElement::SetFlowDirection(reinterpret_cast<Noesis::DependencyObject *>(objPtr),
                                               static_cast<Noesis::FlowDirection>(flowDirection));
}

// float nGetActualHeight(long ptr);
JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetActualHeight(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetActualHeight();
}

// float nGetActualWidth(long ptr);
JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetActualWidth(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetActualWidth();
}

// int nGetBlendingMode(long ptr);
JNIEXPORT jint JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetBlendingMode(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetBlendingMode();
}

// void nSetBlendingMode(long ptr, int value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetBlendingMode(
    JNIEnv *env, jclass, jlong ptr, jint value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetBlendingMode(static_cast<Noesis::BlendingMode>(value));
}

// long nGetContextMenu(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetContextMenu(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetContextMenu());
}

// void nSetContextMenu(long ptr, long contextPtr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetContextMenu(
    JNIEnv *env, jclass, jlong ptr, jlong contextPtr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetContextMenu(reinterpret_cast<Noesis::ContextMenu *>(contextPtr));
}

// long nGetCursor(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetCursor(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetCursor());
}

// void nSetCursor(long ptr, long cursorPtr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetCursor(
    JNIEnv *env, jclass, jlong ptr, jlong cursorPtr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetCursor(reinterpret_cast<Noesis::Cursor *>(cursorPtr));
}

// long nGetDataContext(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetDataContext(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetDataContext());
}

// void nSetDataContext(long ptr, long cursorPtr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetDataContext(
    JNIEnv *env, jclass, jlong ptr, jlong cursorPtr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetDataContext(reinterpret_cast<Noesis::BaseComponent *>(cursorPtr));
}

// long nGetDefaultStyleKey(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetDefaultStyleKey(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetDefaultStyleKey());
}

// void nSetDefaultStyleKey(long ptr, long type_ptr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetDefaultStyleKey(
    JNIEnv *env, jclass, jlong ptr, jlong type_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetDefaultStyleKey(reinterpret_cast<Noesis::Type *>(type_ptr));
}

// int nGetFlowDirection(long ptr);
JNIEXPORT jint JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetFlowDirection(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetFlowDirection();
}

// void nSetFlowDirection(long ptr, int value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetFlowDirection(
    JNIEnv *env, jclass, jlong ptr, jint value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetFlowDirection(static_cast<Noesis::FlowDirection>(value));
}

// long nGetFocusVisualStyle(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetFocusVisualStyle(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetFocusVisualStyle());
}

// void nSetFocusVisualStyle(long ptr, long style_ptr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetFocusVisualStyle(
    JNIEnv *env, jclass, jlong ptr, jlong style_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetFocusVisualStyle(reinterpret_cast<Noesis::Style *>(style_ptr));
}

// boolean nGetForceCursor(long ptr);
JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetForceCursor(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return JNI_FALSE;
    return obj->GetForceCursor();
}

// void nSetForceCursor(long ptr, boolean value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetForceCursor(
    JNIEnv *env, jclass, jlong ptr, jboolean value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetForceCursor(value);
}

// float nGetHeight(long ptr);
JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetHeight(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetHeight();
}

// void nSetHeight(long ptr, float value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetHeight(
    JNIEnv *env, jclass, jlong ptr, jfloat value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetHeight(value);
}

// int nGetHorizontalAlignment(long ptr);
JNIEXPORT jint JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetHorizontalAlignment(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetHorizontalAlignment();
}

// void nSetHorizontalAlignment(long ptr, int value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetHorizontalAlignment(
    JNIEnv *env, jclass, jlong ptr, jint value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetHorizontalAlignment(static_cast<Noesis::HorizontalAlignment>(value));
}

// int nGetInputScope(long ptr);
JNIEXPORT jint JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetInputScope(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetInputScope();
}

// void nSetInputScope(long ptr, int value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetInputScope(
    JNIEnv *env, jclass, jlong ptr, jint value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetInputScope(static_cast<Noesis::InputScope>(value));
}

// long nGetLayoutTransform(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetLayoutTransform(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetLayoutTransform());
}

// void nSetLayoutTransform(long ptr, long transform_ptr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetLayoutTransform(
    JNIEnv *env, jclass, jlong ptr, jlong transform_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetLayoutTransform(reinterpret_cast<Noesis::Transform *>(transform_ptr));
}

// void nGetMargin(long ptr, NSThickness out);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetMargin(
    JNIEnv *env, jclass, jlong ptr, jobject outThickness) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    NSJniUtils::ThicknessFromCopy(env, obj->GetMargin(), outThickness);
}

// void nSetMargin(long ptr, NSThickness in);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetMargin(
    JNIEnv *env, jclass, jlong ptr, jobject inThickness) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;

    Noesis::Thickness thickness = Noesis::Thickness();
    NSJniUtils::ThicknessToCopy(env, thickness, inThickness);
    obj->SetMargin(thickness);
}

// float nGetMaxHeight(long ptr);
JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetMaxHeight(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetMaxHeight();
}

// void nSetMaxHeight(long ptr, float value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetMaxHeight(
    JNIEnv *env, jclass, jlong ptr, jfloat value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetMaxHeight(value);
}

// float nGetMaxWidth(long ptr);
JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetMaxWidth(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetMaxWidth();
}

// void nSetMaxWidth(long ptr, float value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetMaxWidth(
    JNIEnv *env, jclass, jlong ptr, jfloat value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetMaxWidth(value);
}

// float nGetMinHeight(long ptr);
JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetMinHeight(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetMinHeight();
}

// void nSetMinHeight(long ptr, float value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetMinHeight(
    JNIEnv *env, jclass, jlong ptr, jfloat value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetMinHeight(value);
}

// float nGetMinWidth(long ptr);
JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetMinWidth(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetMinWidth();
}

// void nSetMinWidth(long ptr, float value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetMinWidth(
    JNIEnv *env, jclass, jlong ptr, jfloat value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetMinWidth(value);
}

// String nGetName(long ptr);
JNIEXPORT jstring JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetName(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return nullptr;
    return env->NewStringUTF(obj->GetName());
}

// void nSetName(long ptr, String str);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetName(
    JNIEnv *env, jclass, jlong ptr, jstring str) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr || str == nullptr) return;

    const char *cstr = env->GetStringUTFChars(str, nullptr);
    if (cstr == nullptr) {
        return;
    }


    obj->SetName(cstr);
    env->ReleaseStringUTFChars(str, cstr);
}

// boolean nGetOverridesDefaultStyle(long ptr);
JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetOverridesDefaultStyle(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return JNI_FALSE;
    return obj->GetOverridesDefaultStyle();
}

// void nSetOverridesDefaultStyle(long ptr, boolean value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetOverridesDefaultStyle(
    JNIEnv *env, jclass, jlong ptr, jboolean value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetOverridesDefaultStyle(value);
}

// int nGetPPAAMode(long ptr);
JNIEXPORT jint JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetPPAAMode(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetPPAAMode();
}

// void nSetPPAAMode(long ptr, int index);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetPPAAMode(
    JNIEnv *env, jclass, jlong ptr, jint index) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetPPAAMode(static_cast<Noesis::PPAAMode>(index));
}

// float nGetPPAAIn(long ptr);
JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetPPAAIn(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetPPAAIn();
}

// void nSetPPAAIn(long ptr, float value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetPPAAIn(
    JNIEnv *env, jclass, jlong ptr, jfloat value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetPPAAIn(value);
}

// float nGetPPAAOut(long ptr);
JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetPPAAOut(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetPPAAOut();
}

// void nSetPPAAOut(long ptr, float value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetPPAAOut(
    JNIEnv *env, jclass, jlong ptr, jfloat value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetPPAAOut(value);
}

// void nSetStyle(long ptr, long style_ptr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetStyle(
    JNIEnv *env, jclass, jlong ptr, jlong style_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetStyle(reinterpret_cast<Noesis::Style *>(style_ptr));
}

// long nGetStyle(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetStyle(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetStyle());
}

// long nGetTag(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetTag(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetTag());
}

// void nSetTag(long ptr, long component_ptr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetTag(
    JNIEnv *env, jclass, jlong ptr, jlong component_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetTag(reinterpret_cast<Noesis::BaseComponent *>(component_ptr));
}

// void nSetTagString(long ptr, String value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetTagString(
    JNIEnv *env, jclass, jlong ptr, jstring value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;

    const char *cstr = env->GetStringUTFChars(value, nullptr);
    if (cstr == nullptr) {
        return;
    }

    obj->SetTag(cstr);
    env->ReleaseStringUTFChars(value, cstr);
}

// long nGetToolTip(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetToolTip(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetToolTip());
}

// void nSetToolTip(long ptr, long component_ptr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetToolTip(
    JNIEnv *env, jclass, jlong ptr, jlong component_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetToolTip(reinterpret_cast<Noesis::BaseComponent *>(component_ptr));
}

// void nSetToolTipString(long ptr, String tooltip);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetToolTipString(
    JNIEnv *env, jclass, jlong ptr, jstring tooltip) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;

    const char *cstr = env->GetStringUTFChars(tooltip, nullptr);
    if (cstr == nullptr) {
        return;
    }

    obj->SetToolTip(cstr);
    env->ReleaseStringUTFChars(tooltip, cstr);
}

// boolean nGetUseLayoutRounding(long ptr);
JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetUseLayoutRounding(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return JNI_FALSE;
    return obj->GetUseLayoutRounding();
}

// void nSetUseLayoutRounding(long ptr, boolean value);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetUseLayoutRounding(
    JNIEnv *env, jclass, jlong ptr, jboolean value) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetUseLayoutRounding(value);
}

// int nGetVerticalAlignment(long ptr);
JNIEXPORT jint JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetVerticalAlignment(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetVerticalAlignment();
}

// void nSetVerticalAlignment(long ptr, int alight);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetVerticalAlignment(
    JNIEnv *env, jclass, jlong ptr, jint alight) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetVerticalAlignment(static_cast<Noesis::VerticalAlignment>(alight));
}

// float nGetWidth(long ptr);
JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetWidth(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return obj->GetWidth();
}

// void nSetWidth(long ptr, float w);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetWidth(
    JNIEnv *env, jclass, jlong ptr, jfloat w) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetWidth(w);
}

// long nGetTriggers(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetTriggers(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetTriggers());
}

// long nGetBindingExpression(long ptr, long dp_ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetBindingExpression(
    JNIEnv *env, jclass, jlong ptr, jlong dp_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetBindingExpression(reinterpret_cast<Noesis::DependencyProperty *>(dp_ptr)));
}

// long nSetBinding(long ptr, long dp_ptr, long base_ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetBinding(
    JNIEnv *env, jclass, jlong ptr, jlong dp_ptr, jlong base_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->SetBinding(reinterpret_cast<Noesis::DependencyProperty*>(dp_ptr), reinterpret_cast<Noesis::BaseBinding *>(base_ptr)));
}

// long nSetBindingString(long ptr, long dp_ptr, String path);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetBindingString(
    JNIEnv *env, jclass, jlong ptr, jlong dp_ptr, jstring path) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;

    const char *cstr = env->GetStringUTFChars(path, nullptr);
    if (cstr == nullptr) {
        return 0;
    }

    jlong p = reinterpret_cast<jlong>(obj->SetBinding(reinterpret_cast<Noesis::DependencyProperty*>(dp_ptr), cstr));
    env->ReleaseStringUTFChars(path, cstr);
    return p;
}

// void nSetResourceReference(long ptr, long dp_ptr, String name);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetResourceReference(
    JNIEnv *env, jclass, jlong ptr, jlong dp_ptr, jstring name) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;

    const char *cstr = env->GetStringUTFChars(name, nullptr);
    if (cstr == nullptr) {
        return;
    }

    obj->SetResourceReference(reinterpret_cast<Noesis::DependencyProperty*>(dp_ptr), cstr);
    env->ReleaseStringUTFChars(name, cstr);
}

// boolean nIsLoaded(long ptr);
JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nIsLoaded(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return JNI_FALSE;
    return obj->IsLoaded();
}

// void nBringIntoView(long ptr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nBringIntoView(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->BringIntoView();
}

// void nBringIntoViewRect(long ptr, NSRect rect);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nBringIntoViewRect(
    JNIEnv *env, jclass, jlong ptr, jobject rect) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    Noesis::Rect _rect = Noesis::Rect();
    NSJniUtils::RectToCopy(env, _rect, rect);
    obj->BringIntoView(_rect);
}

// long nGetTimeManager(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetTimeManager(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetTimeManager());
}

// long nGetParent(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetParent(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetParent());
}

// boolean nApplyTemplate(long ptr);
JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nApplyTemplate(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return JNI_FALSE;
    return obj->ApplyTemplate();
}

// long nGetParentOrTemplatedParent(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetParentOrTemplatedParent(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetParentOrTemplatedParent());
}

// long nGetTemplatedParent(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetTemplatedParent(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetTemplatedParent());
}

// void nSetTemplatedParent(long ptr, long templatedParent_ptr, long frameworkTemplate_ptr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetTemplatedParent(
    JNIEnv *env, jclass, jlong ptr, jlong templatedParent_ptr, jlong frameworkTemplate_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetTemplatedParent(reinterpret_cast<Noesis::FrameworkElement *>(templatedParent_ptr), reinterpret_cast<Noesis::FrameworkTemplate *>(frameworkTemplate_ptr));
}

// long nGetFrameworkTemplate(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetFrameworkTemplate(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetFrameworkTemplate());
}

// void nClearFrameworkTemplate(long ptr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nClearFrameworkTemplate(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->ClearFrameworkTemplate();
}

// long nClone(long ptr, long parent_ptr, long templatedParent_ptr, long template_ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nClone(
    JNIEnv *env, jclass, jlong ptr, jlong parent_ptr, jlong templatedParent_ptr, jlong template_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->Clone(
        reinterpret_cast<Noesis::FrameworkElement *>(parent_ptr),
        reinterpret_cast<Noesis::FrameworkElement *>(templatedParent_ptr),
        reinterpret_cast<Noesis::FrameworkTemplate *>(template_ptr)
    ).GiveOwnership());
}

// long nGetStateGroupsRoot(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetStateGroupsRoot(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetStateGroupsRoot());
}

// long nFindName(long ptr, String name);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nFindName(
    JNIEnv *env, jclass, jlong ptr, jstring name) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;

    const char *cstr = env->GetStringUTFChars(name, nullptr);
    if (cstr == nullptr) {
        return 0;
    }

    const auto p = reinterpret_cast<jlong>(obj->FindName(cstr));
    env->ReleaseStringUTFChars(name, cstr);
    return p;
}

// void nFindNameAndScope(long ptr, String name, NSObjectWithNameScope scope);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nFindNameAndScope(
    JNIEnv *env, jclass, jlong ptr, jstring name, jobject scope) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;

    const char *cstr = env->GetStringUTFChars(name, nullptr);
    if (cstr == nullptr) {
        return;
    }

    auto _scope = obj->FindNameAndScope(cstr);
    env->ReleaseStringUTFChars(name, cstr);
    NSJniUtils::ObjectWithNameScopeFromCopy(env, _scope, scope);
}

// void nRegisterName(long ptr, String name, long component_ptr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nRegisterName(
    JNIEnv *env, jclass, jlong ptr, jstring name, jlong component_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;

    const char *cstr = env->GetStringUTFChars(name, nullptr);
    if (cstr == nullptr) {
        return;
    }

    obj->RegisterName(cstr, reinterpret_cast<Noesis::BaseComponent *>(component_ptr));
    env->ReleaseStringUTFChars(name, cstr);
}

// void nUnregisterName(long ptr, String name);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nUnregisterName(
    JNIEnv *env, jclass, jlong ptr, jstring name) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;

    const char *cstr = env->GetStringUTFChars(name, nullptr);
    if (cstr == nullptr) {
        return;
    }
    obj->UnregisterName(cstr);
    env->ReleaseStringUTFChars(name, cstr);
}

// void nUpdateName(long ptr, String name, long component_ptr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nUpdateName(
    JNIEnv *env, jclass, jlong ptr, jstring name, jlong component_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;

    const char *cstr = env->GetStringUTFChars(name, nullptr);
    if (cstr == nullptr) {
        return;
    }
    obj->UpdateName(cstr, reinterpret_cast<Noesis::BaseComponent *>(component_ptr));
    env->ReleaseStringUTFChars(name, cstr);
}

// long nFindResource(long ptr, String key);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nFindResource(
    JNIEnv *env, jclass, jlong ptr, jstring key) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;

    const char *cstr = env->GetStringUTFChars(key, nullptr);
    if (cstr == nullptr) {
        return 0;
    }

    jlong p = reinterpret_cast<jlong>(obj->FindResource(cstr));
    env->ReleaseStringUTFChars(key, cstr);
    return p;
}

// long nGetResources(long ptr);
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nGetResources(
    JNIEnv *env, jclass, jlong ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;
    return reinterpret_cast<jlong>(obj->GetResources());
}

// void nSetResources(long ptr, long resource_ptr);
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSetResources(
    JNIEnv *env, jclass, jlong ptr, jlong resource_ptr) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return;
    obj->SetResources(reinterpret_cast<Noesis::ResourceDictionary *>(resource_ptr));
}

// boolean nConnectField(long ptr, long object_ptr, String name);
JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nConnectField(
    JNIEnv *env, jclass, jlong ptr, jlong object_ptr, jstring name) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;

    const char *cstr = env->GetStringUTFChars(name, nullptr);
    if (cstr == nullptr) {
        return 0;
    }

    const auto p = obj->ConnectField(reinterpret_cast<Noesis::BaseComponent*>(object_ptr), cstr);
    env->ReleaseStringUTFChars(name, cstr);
    return p;
}

// boolean nConnectEvent(long ptr, long source_ptr, String event, String name);
JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nConnectEvent(
    JNIEnv *env, jclass, jlong ptr, jlong source_ptr, jstring event, jstring name) {
    const auto obj = getComponent(env, ptr);
    if (obj == nullptr) return 0;

    const char *cstr = env->GetStringUTFChars(name, nullptr);
    if (cstr == nullptr) {
        return 0;
    }

    const char *cstr2 = env->GetStringUTFChars(event, nullptr);
    if (cstr2 == nullptr) {
        return 0;
    }

    const auto p = obj->ConnectEvent(reinterpret_cast<Noesis::BaseComponent*>(source_ptr), cstr2, cstr);
    env->ReleaseStringUTFChars(name, cstr);
    env->ReleaseStringUTFChars(event, cstr2);
    return p;
}
}
