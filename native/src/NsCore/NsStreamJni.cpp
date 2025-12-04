//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "NsGui/Stream.h"

namespace Noesis {
    class Symbol;
}

extern "C" {
static Noesis::Stream *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.Stream ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::Stream *>(handle);
}


JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nscore_NSStream_nativeSetPosition(JNIEnv *env, jclass, const jlong ptr, const jint pos) {
    const auto stream = getComponent(env, ptr);
    if (!stream) return;
    stream->SetPosition(pos);
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nscore_NSStream_nativeGetPosition(JNIEnv *env, jclass, const jlong ptr) {
    const auto stream = getComponent(env, ptr);
    if (!stream) return -1;
    return stream->GetPosition();
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nscore_NSStream_nativeGetLength(JNIEnv *env, jclass, const jlong ptr) {
    const auto stream = getComponent(env, ptr);
    if (!stream) return -1;
    return stream->GetLength();
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nscore_NSStream_nativeRead(JNIEnv *env, jclass, const jlong ptr, const jlong buffer_ptr,
                                                    jint size) {
    const auto stream = getComponent(env, ptr);
    if (!stream) return -1;
    return stream->Read(reinterpret_cast<void *>(buffer_ptr), size);
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nscore_NSStream_nativeGetMemoryBase(JNIEnv *env, jclass, const jlong ptr) {
    const auto stream = getComponent(env, ptr);
    if (!stream) return -1;
    return reinterpret_cast<jlong>(stream->GetMemoryBase());
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nscore_NSStream_nativeClose(JNIEnv *env, jclass, const jlong ptr) {
    const auto stream = getComponent(env, ptr);
    if (!stream) return;
    stream->Close();
}
}
