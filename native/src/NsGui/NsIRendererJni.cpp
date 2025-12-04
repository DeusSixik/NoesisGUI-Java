//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>

#include "../utils/NSJniUtils.h"
#include "NsGui/IRenderer.h"
#include "NsMath/Matrix.h"
#include "NsRender/RenderDevice.h"

namespace Noesis {
    class Visual;
}

extern "C" {

    static Noesis::IRenderer *getComponent(JNIEnv *env, const jlong handle) {
        if (handle == 0) {
            jclass excCls = env->FindClass("java/lang/IllegalStateException");
            if (excCls != nullptr) {
                env->ThrowNew(excCls, "Noesis.IRenderer ptr is null");
            }
            return nullptr;
        }
        return reinterpret_cast<Noesis::IRenderer *>(handle);
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsgui_NSIRenderer_nativeInit(JNIEnv *env, jclass, jlong ptr, jlong renderDevice_ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return;
        obj->Init(reinterpret_cast<Noesis::RenderDevice*>(renderDevice_ptr));
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsgui_NSIRenderer_nativeShutdown(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return;
        obj->Shutdown();
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsgui_NSIRenderer_nativeSetRenderRegion(JNIEnv *env, jclass, jlong ptr,
        jfloat x, jfloat y, jfloat w, jfloat h) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return;
        obj->SetRenderRegion(x, y, w, h);
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsgui_NSIRenderer_nativeUpdateRenderTree(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return;
        obj->UpdateRenderTree();
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsgui_NSIRenderer_nativeRenderOffscreen(JNIEnv *env, jclass, jlong ptr) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return;
        obj->RenderOffscreen();
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsgui_NSIRenderer_nativeRender(JNIEnv *env, jclass, jlong ptr, jboolean flipY, jboolean clear) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return;
        obj->Render(flipY, clear);
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsgui_NSIRenderer_nativeRenderStereoSingle(JNIEnv *env, jclass, jlong ptr,
        jobject eyeMtx, jboolean flipY, jboolean clear) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return;
        Noesis::Matrix4 mat = Noesis::Matrix4();
        NSJniUtils::Matrix4ToCopy(env, mat, eyeMtx);
        obj->RenderStereo(mat, flipY, clear);
    }

    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsgui_NSIRenderer_nativeRenderStereo(JNIEnv *env, jclass, jlong ptr,
        jobject leftEyeMtx, jobject rightEyeMtx, jboolean flipY, jboolean clear) {
        const auto obj = getComponent(env, ptr);
        if (!obj) return;
        Noesis::Matrix4 lmat = Noesis::Matrix4();
        NSJniUtils::Matrix4ToCopy(env, lmat, leftEyeMtx);

        Noesis::Matrix4 rmat = Noesis::Matrix4();
        NSJniUtils::Matrix4ToCopy(env, rmat, rightEyeMtx);
        obj->RenderStereo(lmat, rmat, flipY, clear);
    }



}
