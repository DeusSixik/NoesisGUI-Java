//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "NsCore/BaseObject.h"
#include "NsCore/String.h"

namespace Noesis {
    class DispatcherObject;
}

extern "C" {
static Noesis::BaseObject *getComponent(JNIEnv *env, const jlong handle) {
    if (handle == 0) {
        jclass excCls = env->FindClass("java/lang/IllegalStateException");
        if (excCls != nullptr) {
            env->ThrowNew(excCls, "Noesis.BaseObject ptr is null");
        }
        return nullptr;
    }
    return reinterpret_cast<Noesis::BaseObject *>(handle);
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_nscore_NSBaseObject_nativeTrackCollectTypenames(JNIEnv *enc, jclass) {
    Noesis::BaseObject::TrackCollectTypenames();
}

JNIEXPORT jboolean JNICALL
Java_dev_sixik_noesisgui_nscore_NSBaseObject_nativeTrackDumpObjects(JNIEnv *enc, jclass, const jboolean finalizing) {
    return Noesis::BaseObject::TrackDumpObjects(finalizing);
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_nscore_NSBaseObject_nativeGetClassType(JNIEnv *enc, jclass, const jlong ptr) {
    const auto obj = getComponent(enc, ptr);
    if (!obj) return -1;
    return reinterpret_cast<jlong>(obj->GetClassType());
}

JNIEXPORT jstring JNICALL
Java_dev_sixik_noesisgui_nscore_NSBaseObject_nativeToString(JNIEnv *env, jclass, const jlong handle) {
    const auto c = getComponent(env, handle);
    if (!c) return nullptr;

    const auto s = c->ToString();
    return env->NewStringUTF(s.Str());
}
}
