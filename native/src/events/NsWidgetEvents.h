//
// Created by Sixik on 05.12.2025.
//

#include <iostream>
#include <jni.h>

#include "../utils/NSJavaUtils.h"
#include "../utils/NSJniUtils.h"
#include "NsDrawing/Rect.h"
#include "NsGui/Hyperlink.h"
#include "NsGui/INotifyCollectionChanged.h"
#include "NsGui/ItemContainerGenerator.h"
#include "NsGui/ScrollBar.h"

namespace NoesisJava {
    struct JavaDefault {
    protected:
        ~JavaDefault() = default;

    public:
        virtual jobject Create(JNIEnv *env) = 0;
    };
}

namespace NoesisJava {
    struct JavaMethodHandler {
        jobject handlerGlobal = nullptr;
        jmethodID handlerMethod = nullptr;
    };

    struct JavaRoutedEventHandler {
        struct JavaNSRoutedEventArgs : JavaDefault {
            virtual ~JavaNSRoutedEventArgs() = default;

        public:
            jlong source_ptr = 0;
            jlong routedEvent_ptr = 0;
            jboolean handled = false;

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
                 "dev/sixik/noesisgui/nsgui/NSRoutedEventArgs",
                 "(JJZ)V", source_ptr, routedEvent_ptr, handled);
            }
        };

        jobject handlerGlobal = nullptr;
        jmethodID handlerMethod = nullptr;
        JavaNSRoutedEventArgs args = {};
    };

    struct NSFramework_ContextMenuEventHandlerData {
        struct JavaNSContextMenuEventArgs : JavaRoutedEventHandler::JavaNSRoutedEventArgs {
            jlong targetElement_ptr = 0;
            jfloat cursorLeft{};
            jfloat cursorTop{};

        public:
            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
                                                 "dev/sixik/noesisgui/nsgui/NSContextMenuEventArgs",
                                                 "(JJZJFF)V",
                                                 source_ptr,
                                                 routedEvent_ptr,
                                                 handled,
                                                 targetElement_ptr,
                                                 cursorLeft,
                                                 cursorTop
                );
            }
        };

        jobject handlerGlobal = nullptr;
        jmethodID handlerMethod = nullptr;
        JavaNSContextMenuEventArgs args = {};
    };

    struct JavaNSRequestBringIntoViewEventHandler : JavaMethodHandler {
        struct JavaNSRequestBringIntoViewEventArgs : JavaRoutedEventHandler::JavaNSRoutedEventArgs {
            jlong targetObject_ptr;
            Noesis::Rect targetRect = Noesis::Rect();

            jobject Create(JNIEnv *env) override {
                const auto obj = NSJavaUtils::createObject(env, "dev/sixik/noesisgui/nsdrawing/NSRect", "()V");
                NSJniUtils::RectFromCopy(env, targetRect, obj);
                return NSJavaUtils::createObject(env,
                                                 "dev/sixik/noesisgui/nsgui/NSRequestBringIntoViewEventArgs",
                                                 "(JJZJLdev/sixik/noesisgui/nsdrawing/NSRect;)V",
                                                 source_ptr,
                                                 routedEvent_ptr,
                                                 handled,
                                                 targetObject_ptr,
                                                 obj);
            }
        };

        JavaNSRequestBringIntoViewEventArgs args = {};
    };

    struct JavaNSSizeChangedEventHandler : JavaMethodHandler {
        struct JavaNSSizeChangedEventArgs : JavaRoutedEventHandler::JavaNSRoutedEventArgs {
            Noesis::Size newSize = Noesis::Size();
            Noesis::Size previousSize = Noesis::Size();
            bool widthChanged;
            bool heightChanged;

            jobject Create(JNIEnv *env) override {
                const auto obj1 = NSJavaUtils::createObject(env, "dev/sixik/noesisgui/nsdrawing/NSSize", "()V");
                const auto obj2 = NSJavaUtils::createObject(env, "dev/sixik/noesisgui/nsdrawing/NSSize", "()V");
                NSJniUtils::SizeFromCopy(env, newSize, obj1);
                NSJniUtils::SizeFromCopy(env, previousSize, obj2);
                return NSJavaUtils::createObject(env,
                                                 "dev/sixik/noesisgui/nsgui/NSSizeChangedEventArgs",
                                                 "(JJZLdev/sixik/noesisgui/nsdrawing/NSSize;Ldev/sixik/noesisgui/nsdrawing/NSSize;ZZ)V",
                                                 source_ptr,
                                                 routedEvent_ptr,
                                                 handled,
                                                 obj1,
                                                 obj2, widthChanged, heightChanged);
            }
        };

        JavaNSSizeChangedEventArgs args = {};
    };

    struct JavaNSToolTipEventHandler : JavaMethodHandler {
        struct JavaNSToolTipEventArgs : JavaRoutedEventHandler::JavaNSRoutedEventArgs {
            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
                                                 "dev/sixik/noesisgui/nsgui/NSToolTipEventArgs",
                                                 "(JJZ)V", source_ptr, routedEvent_ptr, handled);
            }
        };

        JavaNSToolTipEventArgs args = {};
    };

    struct JavaNSDependencyPropertyChangedEventHandler : JavaMethodHandler {
        struct JavaNSDependencyPropertyChangedEventArgs : JavaDefault {
            virtual ~JavaNSDependencyPropertyChangedEventArgs() = default;

            jlong prop_ptr;
            jlong oldValue_ptr;
            jlong newValue_ptr;

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
                                                 "dev/sixik/noesisgui/nsgui/NSDependencyPropertyChangedEventArgs",
                                                 "(JJJ)V",
                                                 prop_ptr,
                                                 oldValue_ptr,
                                                 newValue_ptr
                );
            }
        };

        JavaNSDependencyPropertyChangedEventArgs args = {};
    };

    struct JavaNSEventHandler : JavaMethodHandler {
        struct JavaNSEventHandlerArgs : JavaDefault {
            virtual ~JavaNSEventHandlerArgs() = default;

            jobject Create(JNIEnv *env) override {
                return nullptr;
            };
        };

        JavaNSEventHandlerArgs args = {};
    };

    struct JavaNSInputEventArgs : JavaRoutedEventHandler::JavaNSRoutedEventArgs {
        jobject Create(JNIEnv *env) override {
            return NSJavaUtils::createObject(env,
                 "dev/sixik/noesisgui/nsgui/NSInputEventArgs",
                 "(JJZ)V", source_ptr, routedEvent_ptr, handled);
        }
    };

    struct JavaNSKeyboardEventArgs : JavaNSInputEventArgs {
        jobject Create(JNIEnv *env) override {
            return NSJavaUtils::createObject(env,
                 "dev/sixik/noesisgui/nsgui/NSKeyboardEventArgs",
                 "(JJZ)V", source_ptr, routedEvent_ptr, handled);
        }
    };

    struct JavaNSKeyboardFocusChangedEventHandler : JavaMethodHandler {
        struct JavaNSKeyboardFocusChangedEventArgs : JavaNSKeyboardEventArgs {

            jlong oldFocus{};
            jlong newFocus{};

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
                   "dev/sixik/noesisgui/nsgui/NSKeyboardFocusChangedEventArgs",
                   "(JJZJJ)V", source_ptr, routedEvent_ptr, handled, oldFocus, newFocus);
            }
        };

        JavaNSKeyboardFocusChangedEventArgs args = {};
    };

    struct JavaNSMouseEventHandler : JavaMethodHandler {
        struct JavaNSMouseEventArgs : JavaNSInputEventArgs {
            Noesis::MouseEventArgs args = Noesis::MouseEventArgs(nullptr, nullptr);

            jobject Create(JNIEnv *env) override {
                const auto jPoint = NSJavaUtils::createObject(
                    env,
                    "dev/sixik/noesisgui/nsdrawing/NSPoint",
                    "()V"
                );
                NSJniUtils::PointFromCopy(env, args.position, jPoint);
                return NSJavaUtils::createObject(
                    env,
                    "dev/sixik/noesisgui/nsgui/NSMouseEventArgs",
                    "(JJZLdev/sixik/noesisgui/nsdrawing/NSPoint;IIIII)V",
                    source_ptr,
                    routedEvent_ptr,
                    handled,
                    jPoint,
                    args.leftButton,
                    args.middleButton,
                    args.rightButton,
                    args.xButton1Button,
                    args.xButton2Button
                );
            }
        };

        JavaNSMouseEventArgs args;
    };

    struct JavaNSNSKeyEventHandler : JavaMethodHandler {
        struct JavaNSKeyEventArgs : JavaNSKeyboardEventArgs {
            Noesis::KeyEventArgs args = Noesis::KeyEventArgs(nullptr, nullptr, Noesis::Key_A, Noesis::KeyStates_Down);

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
               "dev/sixik/noesisgui/nsgui/NSKeyEventArgs",
               "(JJZJIII)V", source_ptr, routedEvent_ptr, handled, &args,
                args.key, args.originalKey, args.keyStates);
                }
            };
        JavaNSKeyEventArgs args = {};
    };

    struct JavaNSMouseButtonEventHandler : JavaMethodHandler {
        struct JavaNSMouseButtonEventArgs : JavaNSMouseEventHandler::JavaNSMouseEventArgs {
            Noesis::MouseButtonEventArgs _args = Noesis::MouseButtonEventArgs(nullptr, nullptr, Noesis::MouseButton_Count, Noesis::MouseButtonState_Pressed, 0);

            jobject Create(JNIEnv *env) override {

                const auto jPoint = NSJavaUtils::createObject(env, "dev/sixik/noesisgui/nsdrawing/NSPoint", "()V");
                NSJniUtils::PointFromCopy(env, _args.position, jPoint);

                return NSJavaUtils::createObject(env,
                   "dev/sixik/noesisgui/nsgui/NSMouseButtonEventArgs",
                   "(JJZLdev/sixik/noesisgui/nsdrawing/NSPoint;IIIIIIIJ)V",
                   source_ptr, routedEvent_ptr, handled, jPoint,
                    _args.leftButton, _args.middleButton,
                    _args.rightButton, _args.xButton1Button,
                    _args.xButton2Button,
                    _args.changedButton,
                    _args.buttonState,
                    _args.clickCount
                    );
            }
        };

        JavaNSMouseButtonEventArgs args = {};
    };

    struct JavaNSMouseWheelEventHandler : JavaMethodHandler {
        struct JavaNSMouseEventArgs : JavaNSMouseEventHandler::JavaNSMouseEventArgs {
            Noesis::MouseWheelEventArgs _args = Noesis::MouseWheelEventArgs(nullptr, nullptr, 0, Noesis::Orientation_Horizontal);

            jobject Create(JNIEnv *env) override {

                const auto jPoint = NSJavaUtils::createObject(
                    env,
                    "dev/sixik/noesisgui/nsdrawing/NSPoint",
                    "()V"
                );
                NSJniUtils::PointFromCopy(env, args.position, jPoint);
                return NSJavaUtils::createObject(
                    env,
                    "dev/sixik/noesisgui/nsgui/NSMouseWheelEventArgs",
                    "(JJZLdev/sixik/noesisgui/nsdrawing/NSPoint;IIIIIII)V",
                    source_ptr,
                    routedEvent_ptr,
                    handled,
                    jPoint,
                    args.leftButton,
                    args.middleButton,
                    args.rightButton,
                    args.xButton1Button,
                    args.xButton2Button,
                    _args.wheelRotation,
                    _args.orientation
                );
            }
        };

        JavaNSMouseEventArgs args = {};
    };

    struct JavaNSTouchEventHandler : JavaMethodHandler {
        struct JavaNSTouchEventArgs : JavaNSInputEventArgs {
            Noesis::TouchEventArgs args = Noesis::TouchEventArgs(nullptr, nullptr, Noesis::Point(), 0);

            jobject Create(JNIEnv *env) override {

                const auto jPoint = NSJavaUtils::createObject(
                    env,
                    "dev/sixik/noesisgui/nsdrawing/NSPoint",
                    "()V"
                );
                NSJniUtils::PointFromCopy(env, args.touchPoint, jPoint);

                return NSJavaUtils::createObject(env,
                     "dev/sixik/noesisgui/nsgui/NSTouchEventArgs",
                     "(JJZLdev/sixik/noesisgui/nsdrawing/NSPoint;J)V",
                     source_ptr,
                     routedEvent_ptr,
                     handled,
                     jPoint,
                     args.touchDevice
                );
            }
        };

        JavaNSTouchEventArgs args = {};
    };

    struct JavaNSTextCompositionEventHandler : JavaMethodHandler {
        struct JavaNSTextCompositionEventArgs : JavaNSInputEventArgs {
            Noesis::TextCompositionEventArgs args = Noesis::TextCompositionEventArgs(nullptr, nullptr, 0);

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
                 "dev/sixik/noesisgui/nsgui/NSTextCompositionEventArgs",
                 "(JJZI)V", source_ptr, routedEvent_ptr, handled, static_cast<jint>(args.ch));
            }
        };

        JavaNSTextCompositionEventArgs args = {};
    };

    struct JavaNSQueryCursorEventHandler : JavaMethodHandler {
        struct JavaNSQueryCursorEventArgs : JavaNSMouseEventHandler::JavaNSMouseEventArgs {
            Noesis::QueryCursorEventArgs _args = Noesis::QueryCursorEventArgs(nullptr, nullptr);

            jobject Create(JNIEnv *env) override {
                const auto jPoint = NSJavaUtils::createObject(
                                    env,
                                    "dev/sixik/noesisgui/nsdrawing/NSPoint",
                                    "()V"
                                );
                NSJniUtils::PointFromCopy(env, _args.position, jPoint);
                return NSJavaUtils::createObject(
                    env,
                    "dev/sixik/noesisgui/nsgui/NSQueryCursorEventArgs",
                    "(JJZLdev/sixik/noesisgui/nsdrawing/NSPoint;IIIIIJ)V",
                    source_ptr,
                    routedEvent_ptr,
                    handled,
                    jPoint,
                    _args.leftButton,
                    _args.middleButton,
                    _args.rightButton,
                    _args.xButton1Button,
                    _args.xButton2Button,
                    reinterpret_cast<jlong>(_args.cursor)
                );
            }
        };

        JavaNSQueryCursorEventArgs args = {};
    };

    struct JavaNSQueryContinueDragEventHandler : JavaMethodHandler {
        struct JavaNSQueryContinueDragEventArgs : JavaRoutedEventHandler::JavaNSRoutedEventArgs {
            Noesis::QueryContinueDragEventArgs args = Noesis::QueryContinueDragEventArgs(nullptr, nullptr, false, 0);

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
                 "dev/sixik/noesisgui/nsgui/NSQueryContinueDragEventArgs",
                 "(JJZZII)V", source_ptr, routedEvent_ptr, handled, args.escapePressed, args.keyStates, args.action);
            }
        };

        JavaNSQueryContinueDragEventArgs args = {};
    };

    struct JavaNSGiveFeedbackEventHandler : JavaMethodHandler {
        struct JavaNSGiveFeedbackEventArgs : JavaRoutedEventHandler::JavaNSRoutedEventArgs {
            Noesis::GiveFeedbackEventArgs args = Noesis::GiveFeedbackEventArgs(nullptr, nullptr, 0, false);

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
             "dev/sixik/noesisgui/nsgui/NSGiveFeedbackEventArgs",
             "(JJZIZ)V", source_ptr, routedEvent_ptr, handled, args.effects, args.useDefaultCursors);
            }
        };

        JavaNSGiveFeedbackEventArgs args = {};
    };

    struct JavaNSDragEventHandler : JavaMethodHandler {
        struct JavaNSDragEventArgs : JavaRoutedEventHandler::JavaNSRoutedEventArgs {
            Noesis::DragEventArgs args = Noesis::DragEventArgs(nullptr, nullptr, nullptr, 0, 0, nullptr, Noesis::Point());

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
             "dev/sixik/noesisgui/nsgui/NSDragEventArgs",
             "(JJZJIII)V", source_ptr, routedEvent_ptr, handled, reinterpret_cast<jlong>(args.data), args.keyStates, args.allowedEffects, args.effects);
            }
        };

        JavaNSDragEventArgs args = {};
    };

    struct JavaNSItemsChangedEventHandler :  JavaMethodHandler {
        struct JavaNSItemsChangedEventArgs : JavaDefault {
            virtual ~JavaNSItemsChangedEventArgs() = default;

            Noesis::ItemsChangedEventArgs args = Noesis::ItemsChangedEventArgs(
                Noesis::NotifyCollectionChangedAction::NotifyCollectionChangedAction_Add,
                Noesis::GeneratorPosition(), Noesis::GeneratorPosition(), 0, 0
                );

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
             "dev/sixik/noesisgui/nsgui/NSItemsChangedEventArgs",
             "(IIIIIII)V",
             args.action,
             args.position.index,
             args.position.offset,
             args.oldPosition.index,
             args.oldPosition.offset,
             args.itemCount,
             args.itemUICount);
            }
        };

        JavaNSItemsChangedEventArgs args = {};
    };

    struct JavaNSRoutedPropertyChangedEventHandler : JavaMethodHandler {

        struct JavaNSRoutedPropertyChangedEventArgs : JavaRoutedEventHandler::JavaNSRoutedEventArgs {

        };

        struct JavaNSRoutedPropertyChangedEventArgsLong : JavaNSRoutedPropertyChangedEventArgs {

            long oldValue = 0;
            long newValue = 0;

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
                 "dev/sixik/noesisgui/nsgui/NSRoutedPropertyChangedEventArgsLong",
                 "(JJZJJ)V", source_ptr, routedEvent_ptr, handled, oldValue, newValue);
            }
        };

        struct JavaNSRoutedPropertyChangedEventArgsBaseComponent : JavaNSRoutedPropertyChangedEventArgsLong {
            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
                 "dev/sixik/noesisgui/nsgui/NSRoutedPropertyChangedEventArgsBaseComponent",
                 "(JJZJJ)V", source_ptr, routedEvent_ptr, handled, oldValue, newValue);
            }
        };

        struct JavaNSRoutedPropertyChangedEventArgsFloat : JavaNSRoutedPropertyChangedEventArgs {

            float oldValue = 0;
            float newValue = 0;

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
                 "dev/sixik/noesisgui/nsgui/NSRoutedPropertyChangedEventArgsFloat",
                 "(JJZFF)V", source_ptr, routedEvent_ptr, handled, oldValue, newValue);
            }
        };

        JavaNSRoutedPropertyChangedEventArgs args = {};
    };

    struct JavaNSScrollEventHandler : JavaMethodHandler {
        struct JavaNSScrollEventArgs : JavaRoutedEventHandler::JavaNSRoutedEventArgs {

            float newValue;
            Noesis::ScrollEventType scrollType;

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
                 "dev/sixik/noesisgui/nsgui/NSScrollEventArgs",
                 "(JJZFI)V", source_ptr, routedEvent_ptr, handled, newValue, scrollType);
            }

        };

        JavaNSScrollEventArgs args = {};
    };

    struct JavaNSRequestNavigateEventHandler : JavaMethodHandler {
        struct JavaNSRequestNavigateEventArgs : JavaRoutedEventHandler::JavaNSRoutedEventArgs {
            const char *uri;
            const char* target;

            jobject Create(JNIEnv *env) override {
                return NSJavaUtils::createObject(env,
                 "dev/sixik/noesisgui/nsgui/NSRequestNavigateEventArgs",
                 "(JJZLjava/lang/String;Ljava/lang/String;)V",
                 source_ptr, routedEvent_ptr, handled, env->NewStringUTF(uri), env->NewStringUTF(target));
            }
        };

        JavaNSRequestNavigateEventArgs args = {};
    };

    template <typename JavaArgsType>
    struct GenericEventHandler {
        jobject handlerGlobal = nullptr;
        jmethodID handlerMethod = nullptr;
        JavaArgsType args{};  // Stack-аллокация для оптимизации
    };

}
