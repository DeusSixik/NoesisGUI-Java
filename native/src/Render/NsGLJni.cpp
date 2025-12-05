//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "Render/GLRenderDevice/Include/NsRender/GLFactory.h"

extern "C" {

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_1render_gl_NSOpenGl_nativeCreateDevice(JNIEnv *env, jclass, jboolean sRGB) {
        auto ptr = NoesisApp::GLFactory::CreateDevice(sRGB);
        if (!ptr) return 0;
        auto p = ptr.GiveOwnership();
        if (!p) return 0;
        return reinterpret_cast<jlong>(p);
    }

    // JNIEXPORT jlong JNICALL
    // Java_dev_sixik_noesisgui_render_gl_NSOpenGl_nativeWrapTexture(JNIEnv *env, jclass,
    //     jint object, jlong w, jlong h, jlong levels, jboolean isInverted, jboolean hasAlpha) {
    //     auto a = NoesisApp::GLFactory::WrapTexture(object, w, h, levels, isInverted, hasAlpha);
    // }
}
