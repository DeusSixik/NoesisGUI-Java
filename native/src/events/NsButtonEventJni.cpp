//
// Created by Sixik on 05.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "NsWidgetEvents.h"
#include "NsGui/Button.h"
#include "NsGui/IView.h"
#include <cstdio>

#include "../jni.h"

using namespace NoesisJava;

extern "C" {


    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nshandlers_NSEventHandlerManager_nativeSubscribeButtonClickEvent(
    JNIEnv *env, jclass,
    jlong viewPtr,
    jstring jElementName,
    jobject jHandler) {

    if (viewPtr == 0 || jElementName == nullptr || jHandler == nullptr) {
        return;
    }

    const char *nativeElementName = env->GetStringUTFChars(jElementName, 0);

    auto *view = reinterpret_cast<Noesis::IView *>(viewPtr);
    auto *root = Noesis::DynamicCast<Noesis::FrameworkElement *>(view->GetContent());

    if (root == nullptr) {
        env->ReleaseStringUTFChars(jElementName, nativeElementName);
        return;
    }

    auto *button = root->FindName<Noesis::Button>(nativeElementName);
    env->ReleaseStringUTFChars(jElementName, nativeElementName);

    if (button == nullptr) {
        return;
    }

    auto *data = new ClickCallbackData();
    data->handlerGlobal = env->NewGlobalRef(jHandler);

    jclass handlerClass = env->GetObjectClass(jHandler);
    data->onClickMethod = env->GetMethodID(handlerClass, "onClick", "(Ldev/sixik/noesisgui/nsgui/NSRoutedEventArgs;)V");
    env->DeleteLocalRef(handlerClass);

    if (data->onClickMethod == nullptr) {

        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }


    button->Click() += [data](Noesis::BaseComponent *sender,
                          const Noesis::RoutedEventArgs &args) {

        if (g_vm == nullptr || data == nullptr)
            return;

        JNIEnv *env = nullptr;
        bool attached = false;

        jint res = g_vm->GetEnv((void**)&env, JNI_VERSION_1_8);
        if (res == JNI_EDETACHED) {
            if (g_vm->AttachCurrentThread((void**)&env, nullptr) != 0) {
                return;
            }
            attached = true;
        } else if (res != JNI_OK) {
            return;
        }

        auto& rg = data->args;
        rg.source_ptr = reinterpret_cast<jlong>(args.source);
        rg.routedEvent_ptr = reinterpret_cast<jlong>(args.routedEvent);
        rg.handled = args.handled;

        env->CallVoidMethod(data->handlerGlobal, data->onClickMethod, data->args.CreateJavaObject(env));

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        if (attached) g_vm->DetachCurrentThread();
    };
}
}