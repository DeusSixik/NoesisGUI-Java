//
// Created by Sixik on 05.12.2025.
//

#include <jni.h>

#include "../utils/NSJavaUtils.h"
#include "../utils/NSJniUtils.h"
#include "NsDrawing/Rect.h"

namespace NoesisJava {
    struct JavaDefault {
    protected:
        ~JavaDefault() = default;

    public:
        virtual jobject Create(JNIEnv* env) = 0;
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
            jobject Create(JNIEnv* env) override {
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

    struct JavaNSEventHandler : JavaMethodHandler { };

}
