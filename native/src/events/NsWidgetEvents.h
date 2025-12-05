//
// Created by Sixik on 05.12.2025.
//

#include <jni.h>

namespace NoesisJava {
    struct ClickCallbackData {
        struct JavaNSRoutedEventArgs {
            jlong source_ptr = 0;
            jlong routedEvent_ptr = 0;
            jboolean handled = false;


            jobject CreateJavaObject(JNIEnv *env) {
                const auto clz = env->FindClass("dev/sixik/noesisgui/nsgui/NSRoutedEventArgs");
                const auto init = env->GetMethodID(clz, "<init>", "(JJZ)V");
                return env->NewObject(clz, init, source_ptr, routedEvent_ptr, handled);
            }
        };

        jobject handlerGlobal = nullptr;
        jmethodID onClickMethod = nullptr;
        JavaNSRoutedEventArgs args = {};
    };

}
