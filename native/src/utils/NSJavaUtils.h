//
// Created by Sixik on 08.12.2025.
//

#ifndef NOESIS_JNI_NSJAVAUTILS_H
#define NOESIS_JNI_NSJAVAUTILS_H
#include <jni.h>

#include "NsCore/BaseComponent.h"
#include "NsGui/FrameworkElement.h"

#endif //NOESIS_JNI_NSJAVAUTILS_H

namespace Noesis {

}

class NSJavaUtils {

public:

    static jmethodID methodFromHandler(JNIEnv* env, jobject thiz, const char* signature) {
        const auto clazz = env->GetObjectClass(thiz);
        const auto id = env->GetMethodID(clazz, "handler", signature);
        env->DeleteLocalRef(clazz);
        return id;
    }

    static jobject createBaseObject(JNIEnv* env, Noesis::BaseComponent* component) {
        return createBaseObject(env, reinterpret_cast<jlong>(component));
    }

    static jobject createBaseObject(JNIEnv* env, Noesis::FrameworkElement* component) {
        return createObject(env, "dev/sixik/noesisgui/nsgui/NSFrameworkElement", "(J)V", reinterpret_cast<jlong>(component));
    }

    static jobject createBaseObject(JNIEnv* env, jlong ptr) {
        return createObject(env, "dev/sixik/noesisgui/nscore/NSBaseComponent", "(J)V", ptr);
    }

    static jobject createObject(JNIEnv* env,
                            const char* className,
                            const char* ctorSig,
                            ...) {
        return createObject(env, className, "<init>", ctorSig);
    }

    static jobject createObject(JNIEnv* env,
                            const char* className,
                            const char* methodName,
                            const char* ctorSig,
                            ...) {
        const auto clz = env->FindClass(className);
        if (clz == nullptr) {
            return nullptr;
        }

        const auto ctor = env->GetMethodID(clz, methodName, ctorSig);
        if (ctor == nullptr) {
            env->DeleteLocalRef(clz);
            return nullptr;
        }

        va_list args;
        va_start(args, ctorSig);
        const auto obj = env->NewObjectV(clz, ctor, args);
        va_end(args);

        env->DeleteLocalRef(clz);

        return obj;
    }

};