//
// Created by Sixik on 10.12.2025.
//

#include <jni.h>

#include "../jni.h"
#include "../events/NsWidgetEvents.h"
#include "../utils/NSJniUtils.h"
#include "NsGui/Control.h"

struct JniEnvScope {
    JNIEnv *env = nullptr;
    bool attached = false;

    JniEnvScope(JavaVM *vm) {
        const jint res = vm->GetEnv((void **) &env, JNI_VERSION_1_8);
        if (res == JNI_EDETACHED) {
            if (vm->AttachCurrentThread((void **) &env, nullptr) == 0) {
                attached = true;
            }
        }
    }

    ~JniEnvScope() {
        if (attached) NoesisJava::g_vm->DetachCurrentThread();
    }

    operator JNIEnv *() const { return env; }
};

namespace NoesisJava {
    template<typename EventType, typename JavaArgsType, typename EventAdderType, typename ArgsFillerType>
    void RegisterEventHandler(JNIEnv *env, jlong elementPtr, jobject jListener,
                              const char *methodSig,
                              EventAdderType &&eventAdder,
                              ArgsFillerType &&argsFiller) {
        if (elementPtr == 0 || jListener == nullptr) return;

        auto *element = reinterpret_cast<Noesis::Control *>(elementPtr);
        if (element == nullptr) return;

        auto *data = new GenericEventHandler<JavaArgsType>();
        data->handlerGlobal = env->NewGlobalRef(jListener);
        data->handlerMethod = NSJavaUtils::methodFromHandler(env, jListener, methodSig);

        if (data->handlerMethod == nullptr) {
            env->DeleteGlobalRef(data->handlerGlobal);
            delete data;
            return;
        }

        eventAdder(element, [data, argsFiller](Noesis::BaseComponent *sender, const EventType &noesisArgs) {
            if (g_vm == nullptr || data == nullptr) return;

            JniEnvScope envScope(g_vm);
            JNIEnv *jniEnv = envScope;
            if (!jniEnv) return;

            argsFiller(data->args, noesisArgs);

            jobject javaSender = NSJavaUtils::createBaseObject(jniEnv, sender);
            jobject javaArgs = data->args.Create(jniEnv);

            jniEnv->CallVoidMethod(data->handlerGlobal, data->handlerMethod, javaSender, javaArgs);

            if (jniEnv->ExceptionCheck()) {
                jniEnv->ExceptionDescribe();
                jniEnv->ExceptionClear();
            }

            jniEnv->DeleteLocalRef(javaSender);
            jniEnv->DeleteLocalRef(javaArgs);
        });
    }
}

extern "C" {

static Noesis::Control *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.Control ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::Control *>(handle);
}


JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetBackground(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetBackground());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetBackground(JNIEnv* env, jclass clazz, jlong ptr, jlong brush_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetBackground(reinterpret_cast<Noesis::Brush *>(brush_ptr));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetBorderBrush(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetBorderBrush());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetBorderBrush(JNIEnv* env, jclass clazz, jlong ptr, jlong brush_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetBorderBrush(reinterpret_cast<Noesis::Brush *>(brush_ptr));
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetBorderThickness(JNIEnv* env, jclass clazz, jlong ptr, jobject thickness) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    NSJniUtils::ThicknessFromCopy(env, component->GetBorderThickness(), thickness);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetBorderThickness(JNIEnv* env, jclass clazz, jlong ptr, jobject thickness) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    auto t = Noesis::Thickness();
    NSJniUtils::ThicknessToCopy(env, t, thickness);
    component->SetBorderThickness(t);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetFontFamily(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetFontFamily());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetFontFamily(JNIEnv* env, jclass clazz, jlong ptr, jlong family_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetFontFamily(reinterpret_cast<Noesis::FontFamily *>(family_ptr));
}

JNIEXPORT jfloat JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetFontSize(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetFontSize();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetFontSize(JNIEnv* env, jclass clazz, jlong ptr, jfloat size) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetFontSize(size);
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetFontStretch(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return static_cast<jint>(component->GetFontStretch());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetFontStretch(JNIEnv* env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetFontStretch(static_cast<Noesis::FontStretch>(value));
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetFontStyle(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetFontStyle();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetFontStyle(JNIEnv* env, jclass clazz, jlong ptr, jint ordinal) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetFontStyle(static_cast<Noesis::FontStyle>(ordinal));
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetFontWeight(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetFontWeight();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetFontWeight(JNIEnv* env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetFontWeight(static_cast<Noesis::FontWeight>(value));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetForeground(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetForeground());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetForeground(JNIEnv* env, jclass clazz, jlong ptr, jlong brush_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetForeground(reinterpret_cast<Noesis::Brush *>(brush_ptr));
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetHorizontalContentAlignment(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetHorizontalContentAlignment();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetHorizontalContentAlignment(JNIEnv* env, jclass clazz, jlong ptr, jint ordinal) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetHorizontalContentAlignment(static_cast<Noesis::HorizontalAlignment>(ordinal));
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetIsTabStop(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return false;
    return component->GetIsTabStop();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetIsTabStop(JNIEnv* env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetIsTabStop(value);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetPadding(JNIEnv* env, jclass clazz, jlong ptr, jobject thickness) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    NSJniUtils::ThicknessFromCopy(env, component->GetPadding(), thickness);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetPadding(JNIEnv* env, jclass clazz, jlong ptr, jobject thickness) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    auto t = Noesis::Thickness();
    NSJniUtils::ThicknessToCopy(env, t, thickness);
    component->SetPadding(t);
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetTabIndex(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetTabIndex();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetTabIndex(JNIEnv* env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetTabIndex(value);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetTemplate(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetTemplate());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetTemplate(JNIEnv* env, jclass clazz, jlong ptr, jlong controlTemplate_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetTemplate(reinterpret_cast<Noesis::ControlTemplate *>(controlTemplate_ptr));
}

JNIEXPORT jint JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetVerticalContentAlignment(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetVerticalContentAlignment();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetVerticalContentAlignment(JNIEnv* env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetVerticalContentAlignment(static_cast<Noesis::VerticalAlignment>(value));
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetIsFocusEngaged(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return false;
    return component->GetIsFocusEngaged();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetIsFocusEngaged(JNIEnv* env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetIsFocusEngaged(value);
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetIsFocusEngagementEnabled(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return false;
    return component->GetIsFocusEngagementEnabled();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetIsFocusEngagementEnabled(JNIEnv* env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetIsFocusEngagementEnabled(value);
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetUsingFocusEngagement(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return false;
    return component->GetUsingFocusEngagement();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetUsingFocusEngagement(JNIEnv* env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetUsingFocusEngagement(value);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetXYFocusLeft(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetXYFocusLeft());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetXYFocusLeft(JNIEnv* env, jclass clazz, jlong ptr, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetXYFocusLeft(reinterpret_cast<Noesis::UIElement *>(element_ptr));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetXYFocusRight(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetXYFocusRight());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetXYFocusRight(JNIEnv* env, jclass clazz, jlong ptr, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetXYFocusRight(reinterpret_cast<Noesis::UIElement *>(element_ptr));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetXYFocusUp(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetXYFocusUp());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetXYFocusUp(JNIEnv* env, jclass clazz, jlong ptr, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetXYFocusUp(reinterpret_cast<Noesis::UIElement *>(element_ptr));
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nGetXYFocusDown(JNIEnv* env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetXYFocusDown());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nSetXYFocusDown(JNIEnv* env, jclass clazz, jlong ptr, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetXYFocusDown(reinterpret_cast<Noesis::UIElement *>(element_ptr));
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nMouseDoubleClick(JNIEnv* env, jclass clazz, jlong ptr, jobject event) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;
    constexpr auto sig = "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::Control *el, auto &&lambda) { el->MouseDoubleClick() += lambda; };
    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(env, ptr, event, sig, eventAdder, argsFiller);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSControl_nPreviewMouseDoubleClick(JNIEnv* env, jclass clazz, jlong ptr, jobject event) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;
    constexpr auto sig = "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::Control *el, auto &&lambda) { el->PreviewMouseDoubleClick() += lambda; };
    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(env, ptr, event, sig, eventAdder, argsFiller);
}
}
