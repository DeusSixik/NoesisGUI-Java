//
// Created by Sixik on 12.12.2025.
//

#include <jni.h>

#include "../jni.h"
#include "../events/NsWidgetEvents.h"
#include "NsGui/ContextMenu.h"

namespace NoesisJava {
    template<typename EventType, typename JavaArgsType, typename EventAdderType, typename ArgsFillerType>
    void RegisterEventHandler(JNIEnv *env, jlong elementPtr, jobject jListener,
                              const char *methodSig,
                              EventAdderType &&eventAdder,
                              ArgsFillerType &&argsFiller) {
        if (elementPtr == 0 || jListener == nullptr) return;

        auto *element = reinterpret_cast<Noesis::ContextMenu *>(elementPtr);
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
static Noesis::ContextMenu *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.ContextMenu ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::ContextMenu *>(handle);
}


JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nCreate(JNIEnv *env, jclass clazz) {
    return reinterpret_cast<jlong>(new Noesis::ContextMenu());
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nGetHasDropShadow(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetHasDropShadow();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nSetHasDropShadow(
    JNIEnv *env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetHasDropShadow(value);
}

JNIEXPORT jfloat JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nGetHorizontalOffset(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetHorizontalOffset();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nSetHorizontalOffset(
    JNIEnv *env, jclass clazz, jlong ptr, jfloat value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetHorizontalOffset(value);
}

JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nGetIsOpen(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetIsOpen();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nSetIsOpen(
    JNIEnv *env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetIsOpen(value);
}

JNIEXPORT jint JNICALL
Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nGetPlacement(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetPlacement();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nSetPlacement(
    JNIEnv *env, jclass clazz, jlong ptr, jint value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetPlacement(static_cast<Noesis::PlacementMode>(value));
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nGetPlacementRectangle(
    JNIEnv *env, jclass clazz, jlong ptr, jobject rect) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    NSJniUtils::RectFromCopy(env, component->GetPlacementRectangle(), rect);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nSetPlacementRectangle(
    JNIEnv *env, jclass clazz, jlong ptr, jobject rect) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    Noesis::Rect _rect = Noesis::Rect();
    NSJniUtils::RectToCopy(env, _rect, rect);
    component->SetPlacementRectangle(_rect);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nGetPlacementTarget(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetPlacementTarget());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nSetPlacementTarget(
    JNIEnv *env, jclass clazz, jlong ptr, jlong target_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetPlacementTarget(reinterpret_cast<Noesis::UIElement *>(target_ptr));
}

JNIEXPORT jboolean JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nGetStaysOpen(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetStaysOpen();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nSetStaysOpen(
    JNIEnv *env, jclass clazz, jlong ptr, jboolean value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetStaysOpen(value);
}

JNIEXPORT jfloat JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nGetVerticalOffset(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return component->GetVerticalOffset();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nSetVerticalOffset(
    JNIEnv *env, jclass clazz, jlong ptr, jfloat value) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->SetVerticalOffset(value);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nGetPopup(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetPopup());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nClosed(
    JNIEnv *env, jclass clazz, jlong ptr, jobject event) {
    using EventType = Noesis::RoutedEventArgs;
    using JavaArgsType = NoesisJava::JavaRoutedEventHandler::JavaNSRoutedEventArgs;
    constexpr auto sig = "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSRoutedEventArgs;)V";

    auto eventAdder = [](Noesis::ContextMenu *el, auto &&lambda) { el->Closed() += lambda; };
    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(env, ptr, event, sig, eventAdder, argsFiller);
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSContextMenu_nOpened(
    JNIEnv *env, jclass clazz, jlong ptr, jobject event) {
    using EventType = Noesis::RoutedEventArgs;
    using JavaArgsType = NoesisJava::JavaRoutedEventHandler::JavaNSRoutedEventArgs;
    constexpr auto sig = "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSRoutedEventArgs;)V";

    auto eventAdder = [](Noesis::ContextMenu *el, auto &&lambda) { el->Opened() += lambda; };
    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(env, ptr, event, sig, eventAdder, argsFiller);
}
}
