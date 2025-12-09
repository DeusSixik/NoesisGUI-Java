//
// Created by Sixik on 09.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "NsWidgetEvents.h"
#include "../jni.h"
#include <functional>
#include <utility>

namespace Noesis {
    class FrameworkElement;
}

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

        auto *element = reinterpret_cast<Noesis::UIElement *>(elementPtr);
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
JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nGotFocus(JNIEnv *env, jclass,
                                                     jlong elementPtr, jobject jListener) {
    using EventType = Noesis::RoutedEventArgs;
    using JavaArgsType = NoesisJava::JavaRoutedEventHandler::JavaNSRoutedEventArgs;
    constexpr auto sig = "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSRoutedEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) { el->GotFocus() += lambda; };
    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(env, elementPtr, jListener, sig, eventAdder, argsFiller);
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nGotKeyboardFocus(JNIEnv *env, jclass,
                                                             jlong elementPtr, jobject jListener) {
    using EventType = Noesis::KeyboardFocusChangedEventArgs;
    using JavaArgsType = NoesisJava::JavaNSKeyboardFocusChangedEventHandler::JavaNSKeyboardFocusChangedEventArgs;
    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSKeyboardFocusChangedEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) { el->GotKeyboardFocus() += lambda; };
    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.oldFocus = reinterpret_cast<jlong>(nArgs.oldFocus);
        jArgs.newFocus = reinterpret_cast<jlong>(nArgs.newFocus);
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(env, elementPtr, jListener, sig, eventAdder, argsFiller);
}


JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nGotMouseCapture(JNIEnv *env, jclass,
                                                            jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseEventHandler::JavaNSMouseEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;"
            "Ldev/sixik/noesisgui/nsgui/NSMouseEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->GotMouseCapture() += lambda;
    };

    auto argsFiller = [](JavaArgsType &dst, const EventType &src) {
        dst.source_ptr = reinterpret_cast<jlong>(src.source);
        dst.routedEvent_ptr = reinterpret_cast<jlong>(src.routedEvent);
        dst.handled = src.handled;
        dst.args = src;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}


JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nKeyDown(JNIEnv *env, jclass,
                                                    jlong elementPtr, jobject jListener) {
    using EventType = Noesis::KeyEventArgs;
    using JavaArgsType = NoesisJava::JavaNSNSKeyEventHandler::JavaNSKeyEventArgs;

    constexpr auto sig = "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSKeyEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->KeyDown() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nKeyUp(JNIEnv *env, jclass,
                                                  jlong elementPtr, jobject jListener) {
    using EventType = Noesis::KeyEventArgs;
    using JavaArgsType = NoesisJava::JavaNSNSKeyEventHandler::JavaNSKeyEventArgs;

    constexpr auto sig = "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSKeyEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->KeyUp() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}


JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nLostKeyboardFocus(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::KeyboardFocusChangedEventArgs;
    using JavaArgsType = NoesisJava::JavaNSKeyboardFocusChangedEventHandler::JavaNSKeyboardFocusChangedEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSKeyboardFocusChangedEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->LostKeyboardFocus() += lambda;
    };

    auto argsFiller = [](JavaArgsType &dst, const EventType &src) {
        dst.source_ptr = reinterpret_cast<jlong>(src.source);
        dst.routedEvent_ptr = reinterpret_cast<jlong>(src.routedEvent);
        dst.handled = src.handled;
        dst.oldFocus = reinterpret_cast<jlong>(src.oldFocus);
        dst.newFocus = reinterpret_cast<jlong>(src.newFocus);
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nLostMouseCapture(JNIEnv *env, jclass,
                                                             jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseEventHandler::JavaNSMouseEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->LostMouseCapture() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nMouseDown(JNIEnv *env, jclass,
                                                      jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->MouseDown() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nMouseLeave(JNIEnv *env, jclass,
                                                       jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseEventHandler::JavaNSMouseEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->MouseLeave() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nMouseEnter(JNIEnv *env, jclass,
                                                       jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseEventHandler::JavaNSMouseEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->MouseEnter() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}


JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nMouseLeftButtonDown(JNIEnv *env, jclass,
                                                                jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->MouseLeftButtonDown() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nMouseLeftButtonUp(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->MouseLeftButtonUp() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nMouseMove(JNIEnv *env, jclass,
                                                      jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseEventHandler::JavaNSMouseEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->MouseMove() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}


JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nMouseRightButtonDown(JNIEnv *env, jclass,
                                                                 jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->MouseRightButtonDown() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nMouseRightButtonUp(JNIEnv *env, jclass,
                                                               jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->MouseRightButtonUp() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nMouseUp(JNIEnv *env, jclass,
                                                    jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->MouseUp() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nMouseWheel(JNIEnv *env, jclass,
                                                       jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseWheelEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseWheelEventHandler::JavaNSMouseEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseWheelEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->MouseWheel() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nTouchDown(JNIEnv *env, jclass,
                                                      jlong elementPtr, jobject jListener) {
    using EventType = Noesis::TouchEventArgs;
    using JavaArgsType = NoesisJava::JavaNSTouchEventHandler::JavaNSTouchEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSTouchEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->TouchDown() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nTouchMove(JNIEnv *env, jclass,
                                                      jlong elementPtr, jobject jListener) {
    using EventType = Noesis::TouchEventArgs;
    using JavaArgsType = NoesisJava::JavaNSTouchEventHandler::JavaNSTouchEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSTouchEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->TouchMove() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nTouchUp(JNIEnv *env, jclass,
                                                    jlong elementPtr, jobject jListener) {
    using EventType = Noesis::TouchEventArgs;
    using JavaArgsType = NoesisJava::JavaNSTouchEventHandler::JavaNSTouchEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSTouchEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->TouchUp() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nTouchEnter(JNIEnv *env, jclass,
                                                       jlong elementPtr, jobject jListener) {
    using EventType = Noesis::TouchEventArgs;
    using JavaArgsType = NoesisJava::JavaNSTouchEventHandler::JavaNSTouchEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSTouchEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->TouchEnter() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nTouchLeave(JNIEnv *env, jclass,
                                                       jlong elementPtr, jobject jListener) {
    using EventType = Noesis::TouchEventArgs;
    using JavaArgsType = NoesisJava::JavaNSTouchEventHandler::JavaNSTouchEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSTouchEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->TouchLeave() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nGotTouchCapture(JNIEnv *env, jclass,
                                                            jlong elementPtr, jobject jListener) {
    using EventType = Noesis::TouchEventArgs;
    using JavaArgsType = NoesisJava::JavaNSTouchEventHandler::JavaNSTouchEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSTouchEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->GotTouchCapture() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nLostTouchCapture(JNIEnv *env, jclass,
                                                             jlong elementPtr, jobject jListener) {
    using EventType = Noesis::TouchEventArgs;
    using JavaArgsType = NoesisJava::JavaNSTouchEventHandler::JavaNSTouchEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSTouchEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->LostTouchCapture() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewTouchDown(JNIEnv *env, jclass,
                                                             jlong elementPtr, jobject jListener) {
    using EventType = Noesis::TouchEventArgs;
    using JavaArgsType = NoesisJava::JavaNSTouchEventHandler::JavaNSTouchEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSTouchEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewTouchDown() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewTouchMove(JNIEnv *env, jclass,
                                                             jlong elementPtr, jobject jListener) {
    using EventType = Noesis::TouchEventArgs;
    using JavaArgsType = NoesisJava::JavaNSTouchEventHandler::JavaNSTouchEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSTouchEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewTouchMove() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewTouchUp(JNIEnv *env, jclass,
                                                           jlong elementPtr, jobject jListener) {
    using EventType = Noesis::TouchEventArgs;
    using JavaArgsType = NoesisJava::JavaNSTouchEventHandler::JavaNSTouchEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSTouchEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewTouchUp() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewGotKeyboardFocus(JNIEnv *env, jclass,
                                                                    jlong elementPtr, jobject jListener) {
    using EventType = Noesis::KeyboardFocusChangedEventArgs;
    using JavaArgsType = NoesisJava::JavaNSKeyboardFocusChangedEventHandler::JavaNSKeyboardFocusChangedEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSKeyboardFocusChangedEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewGotKeyboardFocus() += lambda;
    };

    auto argsFiller = [](JavaArgsType &dst, const EventType &src) {
        dst.source_ptr = reinterpret_cast<jlong>(src.source);
        dst.routedEvent_ptr = reinterpret_cast<jlong>(src.routedEvent);
        dst.handled = src.handled;
        dst.oldFocus = reinterpret_cast<jlong>(src.oldFocus);
        dst.newFocus = reinterpret_cast<jlong>(src.newFocus);
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewKeyDown(JNIEnv *env, jclass,
                                                           jlong elementPtr, jobject jListener) {
    using EventType = Noesis::KeyEventArgs;
    using JavaArgsType = NoesisJava::JavaNSNSKeyEventHandler::JavaNSKeyEventArgs;

    constexpr auto sig = "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSKeyEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewKeyDown() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewKeyUp(JNIEnv *env, jclass,
                                                         jlong elementPtr, jobject jListener) {
    using EventType = Noesis::KeyEventArgs;
    using JavaArgsType = NoesisJava::JavaNSNSKeyEventHandler::JavaNSKeyEventArgs;

    constexpr auto sig = "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSKeyEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewKeyUp() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewLostKeyboardFocus(JNIEnv *env, jclass,
                                                                     jlong elementPtr, jobject jListener) {
    using EventType = Noesis::KeyboardFocusChangedEventArgs;
    using JavaArgsType = NoesisJava::JavaNSKeyboardFocusChangedEventHandler::JavaNSKeyboardFocusChangedEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSKeyboardFocusChangedEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewLostKeyboardFocus() += lambda;
    };

    auto argsFiller = [](JavaArgsType &dst, const EventType &src) {
        dst.source_ptr = reinterpret_cast<jlong>(src.source);
        dst.routedEvent_ptr = reinterpret_cast<jlong>(src.routedEvent);
        dst.handled = src.handled;
        dst.oldFocus = reinterpret_cast<jlong>(src.oldFocus);
        dst.newFocus = reinterpret_cast<jlong>(src.newFocus);
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewMouseDown(JNIEnv *env, jclass,
                                                             jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewMouseDown() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewMouseLeftButtonDown(JNIEnv *env, jclass,
                                                                       jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewMouseLeftButtonDown() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewMouseLeftButtonUp(JNIEnv *env, jclass,
                                                                     jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewMouseLeftButtonUp() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewMouseMove(JNIEnv *env, jclass,
                                                             jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseEventHandler::JavaNSMouseEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewMouseMove() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewMouseRightButtonDown(JNIEnv *env, jclass,
                                                                        jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewMouseRightButtonDown() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewMouseRightButtonUp(JNIEnv *env, jclass,
                                                                      jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewMouseRightButtonUp() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewMouseUp(JNIEnv *env, jclass,
                                                           jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseButtonEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseButtonEventHandler::JavaNSMouseButtonEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewMouseUp() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewMouseWheel(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::MouseWheelEventArgs;
    using JavaArgsType = NoesisJava::JavaNSMouseWheelEventHandler::JavaNSMouseEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSMouseWheelEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewMouseWheel() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewTextInput(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::TextCompositionEventArgs;
    using JavaArgsType = NoesisJava::JavaNSTextCompositionEventHandler::JavaNSTextCompositionEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSTextCompositionEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewTextInput() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nQueryCursor(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::QueryCursorEventArgs;
    using JavaArgsType = NoesisJava::JavaNSQueryCursorEventHandler::JavaNSQueryCursorEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSQueryCursorEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->QueryCursor() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs._args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nTextInputEvent(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::TextCompositionEventArgs;
    using JavaArgsType = NoesisJava::JavaNSTextCompositionEventHandler::JavaNSTextCompositionEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSTextCompositionEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->TextInput() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewQueryContinueDrag(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::QueryContinueDragEventArgs;
    using JavaArgsType = NoesisJava::JavaNSQueryContinueDragEventHandler::JavaNSQueryContinueDragEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSQueryContinueDragEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewQueryContinueDrag() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nQueryContinueDrag(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::QueryContinueDragEventArgs;
    using JavaArgsType = NoesisJava::JavaNSQueryContinueDragEventHandler::JavaNSQueryContinueDragEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSQueryContinueDragEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->QueryContinueDrag() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewGiveFeedback(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::GiveFeedbackEventArgs;
    using JavaArgsType = NoesisJava::JavaNSGiveFeedbackEventHandler::JavaNSGiveFeedbackEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSGiveFeedbackEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewGiveFeedback() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nGiveFeedback(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::GiveFeedbackEventArgs;
    using JavaArgsType = NoesisJava::JavaNSGiveFeedbackEventHandler::JavaNSGiveFeedbackEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSGiveFeedbackEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->GiveFeedback() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewDragEnter(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::DragEventArgs;
    using JavaArgsType = NoesisJava::JavaNSDragEventHandler::JavaNSDragEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSDragEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewDragEnter() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nDragEnter(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::DragEventArgs;
    using JavaArgsType = NoesisJava::JavaNSDragEventHandler::JavaNSDragEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSDragEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->DragEnter() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewDragOver(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::DragEventArgs;
    using JavaArgsType = NoesisJava::JavaNSDragEventHandler::JavaNSDragEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSDragEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewDragOver() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nDragOver(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::DragEventArgs;
    using JavaArgsType = NoesisJava::JavaNSDragEventHandler::JavaNSDragEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSDragEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->DragOver() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewDragLeave(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::DragEventArgs;
    using JavaArgsType = NoesisJava::JavaNSDragEventHandler::JavaNSDragEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSDragEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewDragLeave() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nDragLeave(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::DragEventArgs;
    using JavaArgsType = NoesisJava::JavaNSDragEventHandler::JavaNSDragEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSDragEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->DragLeave() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nPreviewDrop(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::DragEventArgs;
    using JavaArgsType = NoesisJava::JavaNSDragEventHandler::JavaNSDragEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSDragEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->PreviewDrop() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

    JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nsgui_NSUIElement_nDrop(JNIEnv *env, jclass,
                                                              jlong elementPtr, jobject jListener) {
    using EventType = Noesis::DragEventArgs;
    using JavaArgsType = NoesisJava::JavaNSDragEventHandler::JavaNSDragEventArgs;

    constexpr auto sig =
            "(Ldev/sixik/noesisgui/nscore/NSBaseComponent;Ldev/sixik/noesisgui/nsgui/NSDragEventArgs;)V";

    auto eventAdder = [](Noesis::UIElement *el, auto &&lambda) {
        el->Drop() += lambda;
    };

    auto argsFiller = [](JavaArgsType &jArgs, const EventType &nArgs) {
        jArgs.source_ptr = reinterpret_cast<jlong>(nArgs.source);
        jArgs.routedEvent_ptr = reinterpret_cast<jlong>(nArgs.routedEvent);
        jArgs.handled = nArgs.handled;
        jArgs.args = nArgs;
    };

    NoesisJava::RegisterEventHandler<EventType, JavaArgsType>(
        env, elementPtr, jListener, sig, eventAdder, argsFiller
    );
}

}