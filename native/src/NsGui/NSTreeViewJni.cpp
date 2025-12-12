//
// Created by Sixik on 12.12.2025.
//

#include <jni.h>

#include "../jni.h"
#include "../events/NsWidgetEvents.h"
#include "NsGui/TreeView.h"

namespace NoesisJava {
    template<typename EventType, typename JavaArgsType, typename EventAdderType, typename ArgsFillerType>
    void RegisterEventHandler(JNIEnv *env, jlong elementPtr, jobject jListener,
                              const char *methodSig,
                              EventAdderType &&eventAdder,
                              ArgsFillerType &&argsFiller) {
        if (elementPtr == 0 || jListener == nullptr) return;

        auto *element = reinterpret_cast<Noesis::TreeView *>(elementPtr);
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
static Noesis::TreeView *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.TreeView ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::TreeView *>(handle);
}

JNIEXPORT jlong JNICALL Java_dev_sixik_noesisgui_nsgui_NSTreeView_nCreate(JNIEnv *env, jclass clazz) {
    return reinterpret_cast<jlong>(new Noesis::TreeView());
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nsgui_NSTreeView_nGetSelectedItem(JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return 0;
    return reinterpret_cast<jlong>(component->GetSelectedItem());
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTreeView_nItemClicked(
    JNIEnv *env, jclass clazz, jlong ptr, jlong element_ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->ItemClicked(reinterpret_cast<Noesis::TreeViewItem *>(element_ptr));
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTreeView_nResetSelectedItem(
    JNIEnv *env, jclass clazz, jlong ptr) {
    const auto component = getComponent(env, ptr);
    if (component == nullptr) return;
    component->ResetSelectedItem();
}

JNIEXPORT void JNICALL Java_dev_sixik_noesisgui_nsgui_NSTreeView_nSelectedItemChanged(
    JNIEnv *env, jclass clazz, jlong ptr, jobject event) {
    using EventType = Noesis::RoutedPropertyChangedEventArgs<Noesis::Ptr<Noesis::BaseComponent>>;
    using JavaArgsType = NoesisJava::JavaNSRoutedPropertyChangedEventHandler::JavaNSRoutedPropertyChangedEventArgsBaseComponent;
    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSRoutedPropertyChangedEventArgs;)V";

    auto eventAdder = [](Noesis::TreeView *el, auto &&lambda) { el->SelectedItemChanged() += lambda; };
    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.oldValue = reinterpret_cast<long>(nArgs.oldValue.GetPtr());
        jArgs.newValue = reinterpret_cast<long>(nArgs.newValue.GetPtr());
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(env, ptr, event, sig, eventAdder, argsFiller);
}
}
