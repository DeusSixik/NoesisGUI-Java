//
// Created by Sixik on 08.12.2025.
//

#include <jni.h>

#include "NsWidgetEvents.h"
#include "../jni.h"
#include "../utils/NSJniUtils.h"
#include "NsGui/FrameworkElement.h"
#include "NsGui/RoutedEvent.h"


struct JniEnvScope {
    JNIEnv* env = nullptr;
    bool attached = false;

    JniEnvScope(JavaVM* vm) {
        jint res = vm->GetEnv((void**)&env, JNI_VERSION_1_8);
        if (res == JNI_EDETACHED) {
            if (vm->AttachCurrentThread((void**)&env, nullptr) == 0) {
                attached = true;
            }
        }
    }

    ~JniEnvScope() {
        if (attached) NoesisJava::g_vm->DetachCurrentThread();
    }

    operator JNIEnv*() const { return env; }
};

extern "C" {
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nContextMenuClosing(JNIEnv *env, jclass,
                                                                      jlong elementPtr, jobject jListener) {
    if (elementPtr == 0 || jListener == nullptr) {
        return;
    }

    const auto element = reinterpret_cast<Noesis::FrameworkElement* >(elementPtr);
    if (element == nullptr)
        return;

    auto *data = new NoesisJava::NSFramework_ContextMenuEventHandlerData();
    data->handlerGlobal = env->NewGlobalRef(jListener);

    data->handlerMethod = NSJavaUtils::methodFromHandler(env,
        jListener,
        "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSContextMenuEventArgs;)V"
        );

    if (data->handlerMethod == nullptr) {

        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }

    element->ContextMenuClosing() += [data](Noesis::BaseComponent* sender, const Noesis::ContextMenuEventArgs& args) {
        if (NoesisJava::g_vm == nullptr || data == nullptr)
            return;

        const JniEnvScope envScope(NoesisJava::g_vm);
        JNIEnv* env = envScope;
        if (!env) return;

        auto& rg = data->args;
        rg.source_ptr        = reinterpret_cast<jlong>(args.source);
        rg.routedEvent_ptr   = reinterpret_cast<jlong>(args.routedEvent);
        rg.handled           = args.handled;
        rg.targetElement_ptr = reinterpret_cast<jlong>(args.targetElement);
        rg.cursorLeft        = args.cursorLeft;
        rg.cursorTop         = args.cursorTop;

        jobject javaComponent = NSJavaUtils::createBaseObject(env, sender);
        jobject javaArgs      = rg.Create(env);

        env->CallVoidMethod(
            data->handlerGlobal,
            data->handlerMethod,
            javaComponent,
            javaArgs
        );

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        env->DeleteLocalRef(javaComponent);
        env->DeleteLocalRef(javaArgs);
    };
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nContextMenuOpening(JNIEnv *env, jclass,
                                                                      jlong elementPtr, jobject jListener) {
    if (elementPtr == 0 || jListener == nullptr) {
        return;
    }

    const auto element = reinterpret_cast<Noesis::FrameworkElement* >(elementPtr);
    if (element == nullptr)
        return;

    auto *data = new NoesisJava::NSFramework_ContextMenuEventHandlerData();
    data->handlerGlobal = env->NewGlobalRef(jListener);

    data->handlerMethod = NSJavaUtils::methodFromHandler(env,
        jListener,
        "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSContextMenuEventArgs;)V"
        );

    if (data->handlerMethod == nullptr) {

        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }

    element->ContextMenuOpening() += [data](Noesis::BaseComponent* sender,
                                        const Noesis::ContextMenuEventArgs& args) {
        if (NoesisJava::g_vm == nullptr || data == nullptr)
            return;

        const JniEnvScope envScope(NoesisJava::g_vm);
        JNIEnv* env = envScope;
        if (!env) return;

        auto& rg = data->args;
        rg.source_ptr        = reinterpret_cast<jlong>(args.source);
        rg.routedEvent_ptr   = reinterpret_cast<jlong>(args.routedEvent);
        rg.handled           = args.handled;
        rg.targetElement_ptr = reinterpret_cast<jlong>(args.targetElement);
        rg.cursorLeft        = args.cursorLeft;
        rg.cursorTop         = args.cursorTop;

        jobject javaComponent = NSJavaUtils::createBaseObject(env, sender);
        jobject javaArgs      = rg.Create(env);

        env->CallVoidMethod(
            data->handlerGlobal,
            data->handlerMethod,
            javaComponent,
            javaArgs
        );

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        env->DeleteLocalRef(javaComponent);
        env->DeleteLocalRef(javaArgs);

    };
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nLoaded(JNIEnv *env, jclass,
                                                        jlong elementPtr, jobject jListener) {
    if (elementPtr == 0 || jListener == nullptr) {
        return;
    }

    const auto element = reinterpret_cast<Noesis::FrameworkElement* >(elementPtr);
    if (element == nullptr)
        return;

    auto *data = new NoesisJava::JavaRoutedEventHandler();
    data->handlerGlobal = env->NewGlobalRef(jListener);

    data->handlerMethod = NSJavaUtils::methodFromHandler(env,
        jListener,
        "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSRoutedEventArgs;)V"
        );

    if (data->handlerMethod == nullptr) {

        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }

    element->Loaded() += [data](Noesis::BaseComponent* sender,
                                        const Noesis::RoutedEventArgs& args) {
        if (NoesisJava::g_vm == nullptr || data == nullptr)
            return;

        const JniEnvScope envScope(NoesisJava::g_vm);
        JNIEnv* env = envScope;
        if (!env) return;

        auto& rg = data->args;
        rg.source_ptr        = reinterpret_cast<jlong>(args.source);
        rg.routedEvent_ptr   = reinterpret_cast<jlong>(args.routedEvent);
        rg.handled           = args.handled;

        jobject javaComponent = NSJavaUtils::createBaseObject(env, sender);
        jobject javaArgs      = rg.Create(env);

        env->CallVoidMethod(
            data->handlerGlobal,
            data->handlerMethod,
            javaComponent,
            javaArgs
        );

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        env->DeleteLocalRef(javaComponent);
        env->DeleteLocalRef(javaArgs);

    };
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nUnloaded(JNIEnv *env, jclass,
                                                        jlong elementPtr, jobject jListener) {
    if (elementPtr == 0 || jListener == nullptr) {
        return;
    }

    const auto element = reinterpret_cast<Noesis::FrameworkElement* >(elementPtr);
    if (element == nullptr)
        return;

    auto *data = new NoesisJava::JavaRoutedEventHandler();
    data->handlerGlobal = env->NewGlobalRef(jListener);

    data->handlerMethod = NSJavaUtils::methodFromHandler(env,
        jListener,
        "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSRoutedEventArgs;)V"
        );

    if (data->handlerMethod == nullptr) {

        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }

    element->Unloaded() += [data](Noesis::BaseComponent* sender,
                                        const Noesis::RoutedEventArgs& args) {
        if (NoesisJava::g_vm == nullptr || data == nullptr)
            return;

        const JniEnvScope envScope(NoesisJava::g_vm);
        JNIEnv* env = envScope;
        if (!env) return;

        auto& rg = data->args;
        rg.source_ptr        = reinterpret_cast<jlong>(args.source);
        rg.routedEvent_ptr   = reinterpret_cast<jlong>(args.routedEvent);
        rg.handled           = args.handled;

        jobject javaComponent = NSJavaUtils::createBaseObject(env, sender);
        jobject javaArgs      = rg.Create(env);

        env->CallVoidMethod(
            data->handlerGlobal,
            data->handlerMethod,
            javaComponent,
            javaArgs
        );

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        env->DeleteLocalRef(javaComponent);
        env->DeleteLocalRef(javaArgs);

    };
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nReloaded(JNIEnv *env, jclass,
                                                        jlong elementPtr, jobject jListener) {
    if (elementPtr == 0 || jListener == nullptr) {
        return;
    }

    const auto element = reinterpret_cast<Noesis::FrameworkElement* >(elementPtr);
    if (element == nullptr)
        return;

    auto *data = new NoesisJava::JavaRoutedEventHandler();
    data->handlerGlobal = env->NewGlobalRef(jListener);

    data->handlerMethod = NSJavaUtils::methodFromHandler(env,
        jListener,
        "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSRoutedEventArgs;)V"
        );

    if (data->handlerMethod == nullptr) {

        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }

    element->Reloaded() += [data](Noesis::BaseComponent* sender,
                                        const Noesis::RoutedEventArgs& args) {
        if (NoesisJava::g_vm == nullptr || data == nullptr)
            return;

        const JniEnvScope envScope(NoesisJava::g_vm);
        JNIEnv* env = envScope;
        if (!env) return;

        auto& rg = data->args;
        rg.source_ptr        = reinterpret_cast<jlong>(args.source);
        rg.routedEvent_ptr   = reinterpret_cast<jlong>(args.routedEvent);
        rg.handled           = args.handled;

        jobject javaComponent = NSJavaUtils::createBaseObject(env, sender);
        jobject javaArgs      = rg.Create(env);

        env->CallVoidMethod(
            data->handlerGlobal,
            data->handlerMethod,
            javaComponent,
            javaArgs
        );

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        env->DeleteLocalRef(javaComponent);
        env->DeleteLocalRef(javaArgs);

    };
}


JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nRequestBringIntoView(JNIEnv *env, jclass,
                                                        jlong elementPtr, jobject jListener) {
    if (elementPtr == 0 || jListener == nullptr) {
        return;
    }

    const auto element = reinterpret_cast<Noesis::FrameworkElement* >(elementPtr);
    if (element == nullptr)
        return;

    auto *data = new NoesisJava::JavaNSRequestBringIntoViewEventHandler();
    data->handlerGlobal = env->NewGlobalRef(jListener);

    data->handlerMethod = NSJavaUtils::methodFromHandler(env,
        jListener,
        "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSRequestBringIntoViewEventArgs;)V"
        );

    if (data->handlerMethod == nullptr) {
        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }

    element->RequestBringIntoView() += [data](Noesis::BaseComponent* sender,
                                        const Noesis::RequestBringIntoViewEventArgs& args) {
        if (NoesisJava::g_vm == nullptr || data == nullptr)
            return;

        const JniEnvScope envScope(NoesisJava::g_vm);
        JNIEnv* env = envScope;
        if (!env) return;

        auto& rg = data->args;
        rg.source_ptr        = reinterpret_cast<jlong>(args.source);
        rg.routedEvent_ptr   = reinterpret_cast<jlong>(args.routedEvent);
        rg.handled           = args.handled;
        rg.targetObject_ptr  = reinterpret_cast<jlong>(args.targetObject);
        rg.targetRect        = args.targetRect;

        jobject javaComponent = NSJavaUtils::createBaseObject(env, sender);
        jobject javaArgs      = rg.Create(env);

        env->CallVoidMethod(
            data->handlerGlobal,
            data->handlerMethod,
            javaComponent,
            javaArgs
        );

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        env->DeleteLocalRef(javaComponent);
        env->DeleteLocalRef(javaArgs);

    };
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nSizeChanged(JNIEnv *env, jclass,
                                                        jlong elementPtr, jobject jListener) {
    if (elementPtr == 0 || jListener == nullptr) {
        return;
    }

    const auto element = reinterpret_cast<Noesis::FrameworkElement* >(elementPtr);
    if (element == nullptr)
        return;

    auto *data = new NoesisJava::JavaNSSizeChangedEventHandler();
    data->handlerGlobal = env->NewGlobalRef(jListener);

    data->handlerMethod = NSJavaUtils::methodFromHandler(env,
        jListener,
        "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSSizeChangedEventArgs;)V"
        );

    if (data->handlerMethod == nullptr) {
        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }

    element->SizeChanged() += [data](Noesis::BaseComponent* sender,
                                        const Noesis::SizeChangedEventArgs& args) {
        if (NoesisJava::g_vm == nullptr || data == nullptr)
            return;

        const JniEnvScope envScope(NoesisJava::g_vm);
        JNIEnv* env = envScope;
        if (!env) return;

        auto& rg = data->args;
        rg.source_ptr        = reinterpret_cast<jlong>(args.source);
        rg.routedEvent_ptr   = reinterpret_cast<jlong>(args.routedEvent);
        rg.handled           = args.handled;
        rg.newSize           = args.newSize;
        rg.previousSize      = args.previousSize;
        rg.widthChanged      = args.widthChanged;
        rg.heightChanged     = args.heightChanged;

        jobject javaComponent = NSJavaUtils::createBaseObject(env, sender);
        jobject javaArgs      = rg.Create(env);

        env->CallVoidMethod(
            data->handlerGlobal,
            data->handlerMethod,
            javaComponent,
            javaArgs
        );

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        env->DeleteLocalRef(javaComponent);
        env->DeleteLocalRef(javaArgs);

    };
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nToolTipClosing(JNIEnv *env, jclass,
                                                        jlong elementPtr, jobject jListener) {
    if (elementPtr == 0 || jListener == nullptr) {
        return;
    }

    const auto element = reinterpret_cast<Noesis::FrameworkElement* >(elementPtr);
    if (element == nullptr)
        return;

    auto *data = new NoesisJava::JavaNSToolTipEventHandler();
    data->handlerGlobal = env->NewGlobalRef(jListener);

    data->handlerMethod = NSJavaUtils::methodFromHandler(env,
        jListener,
        "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSToolTipEventArgs;)V"
        );

    if (data->handlerMethod == nullptr) {
        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }

    element->ToolTipClosing() += [data](Noesis::BaseComponent* sender,
                                        const Noesis::ToolTipEventArgs& args) {
        if (NoesisJava::g_vm == nullptr || data == nullptr)
            return;

        const JniEnvScope envScope(NoesisJava::g_vm);
        JNIEnv* env = envScope;
        if (!env) return;

        auto& rg = data->args;
        rg.source_ptr        = reinterpret_cast<jlong>(args.source);
        rg.routedEvent_ptr   = reinterpret_cast<jlong>(args.routedEvent);
        rg.handled           = args.handled;

        jobject javaComponent = NSJavaUtils::createBaseObject(env, sender);
        jobject javaArgs      = rg.Create(env);

        env->CallVoidMethod(
            data->handlerGlobal,
            data->handlerMethod,
            javaComponent,
            javaArgs
        );

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        env->DeleteLocalRef(javaComponent);
        env->DeleteLocalRef(javaArgs);

    };
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nToolTipOpening(JNIEnv *env, jclass,
                                                        jlong elementPtr, jobject jListener) {
    if (elementPtr == 0 || jListener == nullptr) {
        return;
    }

    const auto element = reinterpret_cast<Noesis::FrameworkElement* >(elementPtr);
    if (element == nullptr)
        return;

    auto *data = new NoesisJava::JavaNSToolTipEventHandler();
    data->handlerGlobal = env->NewGlobalRef(jListener);

    data->handlerMethod = NSJavaUtils::methodFromHandler(env,
        jListener,
        "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSToolTipEventArgs;)V"
        );

    if (data->handlerMethod == nullptr) {
        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }

    element->ToolTipOpening() += [data](Noesis::BaseComponent* sender,
                                        const Noesis::ToolTipEventArgs& args) {
        if (NoesisJava::g_vm == nullptr || data == nullptr)
            return;

        const JniEnvScope envScope(NoesisJava::g_vm);
        JNIEnv* env = envScope;
        if (!env) return;

        auto& rg = data->args;
        rg.source_ptr        = reinterpret_cast<jlong>(args.source);
        rg.routedEvent_ptr   = reinterpret_cast<jlong>(args.routedEvent);
        rg.handled           = args.handled;

        jobject javaComponent = NSJavaUtils::createBaseObject(env, sender);
        jobject javaArgs      = rg.Create(env);

        env->CallVoidMethod(
            data->handlerGlobal,
            data->handlerMethod,
            javaComponent,
            javaArgs
        );

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        env->DeleteLocalRef(javaComponent);
        env->DeleteLocalRef(javaArgs);

    };
}

        JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nDataContextChanged(JNIEnv *env, jclass,
                                                        jlong elementPtr, jobject jListener) {
    if (elementPtr == 0 || jListener == nullptr) {
        return;
    }

    const auto element = reinterpret_cast<Noesis::FrameworkElement* >(elementPtr);
    if (element == nullptr)
        return;

    auto *data = new NoesisJava::JavaNSDependencyPropertyChangedEventHandler();
    data->handlerGlobal = env->NewGlobalRef(jListener);

    data->handlerMethod = NSJavaUtils::methodFromHandler(env,
        jListener,
        "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSDependencyPropertyChangedEventArgs;)V"
        );

    if (data->handlerMethod == nullptr) {
        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }

    element->DataContextChanged() += [data](Noesis::BaseComponent* sender,
                                        const Noesis::DependencyPropertyChangedEventArgs& args) {
        if (NoesisJava::g_vm == nullptr || data == nullptr)
            return;

        const JniEnvScope envScope(NoesisJava::g_vm);
        JNIEnv* env = envScope;
        if (!env) return;

        auto& rg = data->args;
        rg.prop_ptr       = reinterpret_cast<jlong>(args.prop);
        rg.oldValue_ptr   = reinterpret_cast<jlong>(args.oldValue);
        rg.newValue_ptr   = reinterpret_cast<jlong>(args.newValue);

        jobject javaComponent = NSJavaUtils::createBaseObject(env, sender);
        jobject javaArgs      = rg.Create(env);

        env->CallVoidMethod(
            data->handlerGlobal,
            data->handlerMethod,
            javaComponent,
            javaArgs
        );

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        env->DeleteLocalRef(javaComponent);
        env->DeleteLocalRef(javaArgs);

    };
}

        JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nInitialized(JNIEnv *env, jclass,
                                                        jlong elementPtr, jobject jListener) {
    if (elementPtr == 0 || jListener == nullptr) {
        return;
    }

    const auto element = reinterpret_cast<Noesis::FrameworkElement* >(elementPtr);
    if (element == nullptr)
        return;

    auto *data = new NoesisJava::JavaNSEventHandler();
    data->handlerGlobal = env->NewGlobalRef(jListener);

    data->handlerMethod = NSJavaUtils::methodFromHandler(env,
        jListener,
        "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;)V"
        );

    if (data->handlerMethod == nullptr) {
        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }

    element->Initialized() += [data](Noesis::BaseComponent* sender,
                                        const Noesis::EventArgs& args) {
        if (NoesisJava::g_vm == nullptr || data == nullptr)
            return;

        const JniEnvScope envScope(NoesisJava::g_vm);
        JNIEnv* env = envScope;
        if (!env) return;

        jobject javaComponent = NSJavaUtils::createBaseObject(env, sender);
        env->CallVoidMethod(
            data->handlerGlobal,
            data->handlerMethod,
            javaComponent
        );

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        env->DeleteLocalRef(javaComponent);

    };
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSFrameworkElement_nAncestorChanged(JNIEnv *env, jclass,
                                                        jlong elementPtr, jobject jListener) {
    if (elementPtr == 0 || jListener == nullptr) {
        return;
    }

    const auto element = reinterpret_cast<Noesis::FrameworkElement* >(elementPtr);
    if (element == nullptr)
        return;

    auto *data = new NoesisJava::JavaNSEventHandler();
    data->handlerGlobal = env->NewGlobalRef(jListener);

    data->handlerMethod = NSJavaUtils::methodFromHandler(env,
        jListener,
        "(Ldev/sixik/noesisgui/nsgui/NSFrameworkElement;)V"
        );

    if (data->handlerMethod == nullptr) {
        env->DeleteGlobalRef(data->handlerGlobal);
        delete data;
        return;
    }

    element->AncestorChanged() += [data](Noesis::FrameworkElement* sender) {
        if (NoesisJava::g_vm == nullptr || data == nullptr)
            return;

        const JniEnvScope envScope(NoesisJava::g_vm);
        JNIEnv* env = envScope;
        if (!env) return;

        jobject javaComponent = NSJavaUtils::createBaseObject(env, sender);
        env->CallVoidMethod(
            data->handlerGlobal,
            data->handlerMethod,
            javaComponent
        );

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
        }

        env->DeleteLocalRef(javaComponent);

    };
}
}
