//
// Created by Sixik on 05.12.2025.
//

#include "jni.h"

#include <jni.h>

extern "C"

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM* vm, void* /*reserved*/) {
    NoesisJava::g_vm = vm;
    return JNI_VERSION_1_8;
}

