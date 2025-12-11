//
// Created by Sixik on 12.12.2025.
//

#include <jni.h>

#include "../utils/NSJniUtils.h"
#include "NsGui/TextBlock.h"

extern "C" {
static Noesis::TextBlock *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.TextBlock ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::TextBlock *>(handle);
}


JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nCreate(JNIEnv *env, jclass clazz) {
    return reinterpret_cast<jlong>(new Noesis::TextBlock());
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetBackground(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetBackground());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetBackground(
    JNIEnv *env, jclass clazz, jlong ptr, jlong brush_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetBackground(reinterpret_cast<Noesis::Brush *>(brush_ptr));
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetCharacterSpacing(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetCharacterSpacing();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetCharacterSpacing(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetCharacterSpacing(value);
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetFontFamily(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetFontFamily());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetFontFamily(
    JNIEnv *env, jclass clazz, jlong ptr, jlong fontFamily_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetFontFamily(reinterpret_cast<Noesis::FontFamily *>(fontFamily_ptr));
}

JNIEXPORT jfloat JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetFontSize(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetFontSize();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetFontSize(
    JNIEnv *env, jclass clazz, jlong ptr, jfloat value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetFontSize(value);
}

JNIEXPORT jint JNICALL
Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetFontStretch(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetFontStretch();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetFontStretch(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetFontStretch(static_cast<Noesis::FontStretch>(value));
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetFontStyle(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetFontStyle();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetFontStyle(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetFontStyle(static_cast<Noesis::FontStyle>(value));
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetFontWeight(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetFontWeight();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetFontWeight(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetFontWeight(static_cast<Noesis::FontWeight>(value));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetForeground(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetForeground());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetForeground(
    JNIEnv *env, jclass clazz, jlong ptr, jlong brush_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetForeground(reinterpret_cast<Noesis::Brush *>(brush_ptr));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetInlines(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetInlines());
}

JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nHasInlines(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->HasInlines();
}

JNIEXPORT jfloat JNICALL
Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetLineHeight(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetLineHeight();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetLineHeight(
    JNIEnv *env, jclass clazz, jlong ptr, jfloat value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetLineHeight(value);
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetLineStackingStrategy(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetLineStackingStrategy();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetLineStackingStrategy(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetLineStackingStrategy(static_cast<Noesis::LineStackingStrategy>(value));
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetPadding(
    JNIEnv *env, jclass clazz, jlong ptr, jobject thickness) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    NSJniUtils::ThicknessFromCopy(env, component->GetPadding(), thickness);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetPadding(
    JNIEnv *env, jclass clazz, jlong ptr, jobject thickness) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    Noesis::Thickness _t = Noesis::Thickness();
    NSJniUtils::ThicknessToCopy(env, _t, thickness);
    component->SetPadding(_t);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetStroke(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetStroke());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetStroke(
    JNIEnv *env, jclass clazz, jlong ptr, jlong brush_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetStroke(reinterpret_cast<Noesis::Brush *>(brush_ptr));
}

JNIEXPORT jfloat JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetStrokeThickness(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetStrokeThickness();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetStrokeThickness(
    JNIEnv *env, jclass clazz, jlong ptr, jfloat value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetStrokeThickness(value);
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetTextAlignment(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetTextAlignment();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetTextAlignment(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetTextAlignment(static_cast<Noesis::TextAlignment>(value));
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetTextDecorations(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetTextDecorations();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetTextDecorations(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetTextDecorations(static_cast<Noesis::TextDecorations>(value));
}

JNIEXPORT jstring JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetText(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return env->NewStringUTF("");
    return env->NewStringUTF(component->GetText());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetText(
    JNIEnv *env, jclass clazz, jlong ptr, jstring value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    const char *cstr = env->GetStringUTFChars(value, nullptr);
    if (cstr == nullptr) {
        return;
    }

    component->SetText(cstr);
    env->ReleaseStringUTFChars(value, cstr);
}

JNIEXPORT jint JNICALL
Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetTextTrimming(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetTextTrimming();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetTextTrimming(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetTextTrimming(static_cast<Noesis::TextTrimming>(value));
}

JNIEXPORT jint JNICALL
Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetTextWrapping(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetTextWrapping();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetTextWrapping(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetTextWrapping(static_cast<Noesis::TextWrapping>(value));
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nFirstInlineIsFromText(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->FirstInlineIsFromText();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetTypography(
    JNIEnv *env, jclass clazz, jlong ptr, jobject typography) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    NSJniUtils::TypographyFromCopy(env, component->GetTypography(), typography);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nSetTypography(
    JNIEnv *env, jclass clazz, jlong ptr, jobject typography) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    NSJniUtils::TypographyToCopy(env, component->GetTypography(), typography);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTextBlock_nGetFormattedText(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetFormattedText());
}
}
