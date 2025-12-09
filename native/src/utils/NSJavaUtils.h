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
        va_list args;
        va_start(args, ctorSig);
        jobject obj = createObjectV(env, className, "<init>", ctorSig, args);
        va_end(args);
        return obj;
    }

    static jobject createObject(JNIEnv* env,
                                const char* className,
                                const char* methodName,
                                const char* sig,
                                ...) {
        va_list args;
        va_start(args, sig);
        jobject obj = createObjectV(env, className, methodName, sig, args);
        va_end(args);
        return obj;
    }

private:
    static jobject createObjectV(JNIEnv* env,
                                 const char* className,
                                 const char* methodName,
                                 const char* sig,
                                 va_list args) {
        jclass clz = env->FindClass(className);
        if (clz == nullptr) {
            if (env->ExceptionCheck()) {
                env->ExceptionDescribe();
                env->ExceptionClear();
            }
            return nullptr;
        }

        jmethodID ctor = env->GetMethodID(clz, methodName, sig);
        if (ctor == nullptr) {
            if (env->ExceptionCheck()) {
                env->ExceptionDescribe();
                env->ExceptionClear();
            }
            env->DeleteLocalRef(clz);
            return nullptr;
        }

        jobject obj = env->NewObjectV(clz, ctor, args);

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
            obj = nullptr;
        }

        env->DeleteLocalRef(clz);
        return obj;
    }
};