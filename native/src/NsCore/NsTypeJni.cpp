//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "NsCore/Type.h"
#include "NsCore/TypeClass.h"

extern "C" {
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nscore_NSType_nativeCreate(JNIEnv *env, jclass, jobject symbolObj) {
    const jclass symbolCls = env->GetObjectClass(symbolObj);
    const jfieldID ptrField = env->GetFieldID(symbolCls, "ptr", "J");

    if (ptrField == nullptr) {
        return 0;
    }

    const jlong ptrValue = env->GetLongField(symbolObj, ptrField);
    const auto *symbol = reinterpret_cast<Noesis::Symbol *>(ptrValue);

    if (symbol == nullptr) {
        return 0;
    }

    const auto *type = new Noesis::Type(*symbol);
    return reinterpret_cast<jlong>(type);
}

JNIEXPORT jstring JNICALL
Java_dev_sixik_noesisgui_nscore_NSType_nativeGetTypeId(JNIEnv *env, jclass, jlong ptr) {
    const Noesis::Type *type = reinterpret_cast<Noesis::Type *>(ptr);
    if (!type) return nullptr;
    return env->NewStringUTF(type->GetName());
}

JNIEXPORT jstring JNICALL
Java_dev_sixik_noesisgui_nscore_NSType_nativeGetClassTypeName(JNIEnv *env, jclass, jlong ptr) {
    const Noesis::Type *type = reinterpret_cast<Noesis::Type *>(ptr);
    if (!type) return nullptr;
    return env->NewStringUTF(type->GetClassType()->GetName());
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nscore_NSType_nativeFree(JNIEnv *env, jclass, jlong ptr) {
    delete reinterpret_cast<Noesis::Type *>(ptr);
}
}
