//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "NSGLRenderUtil.h"
#include "NsGui/ImageBrush.h"
#include "NsGui/TextureSource.h"
#include "Render/GLRenderDevice/Include/NsRender/GLFactory.h"
#include "Render/GLRenderDevice/Src/GLRenderDevice.h"
#include "NsRender/Texture.h"

namespace Noesis {
    class ImageBrush;
    class TextureSource;
}

namespace NoesisApp {
    class GLRenderDevice;
}

extern "C" {

    static  RenderDevice* gRenderDevice = nullptr;

    static GLRenderDevice* GetGLRenderDevice()
    {
        return dynamic_cast<GLRenderDevice*>(gRenderDevice);
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_1render_gl_NSOpenGl_nativeCreateDevice(JNIEnv *env, jclass, jboolean sRGB) {
        auto ptr = GLFactory::CreateDevice(sRGB);
        gRenderDevice = ptr;
        if (!ptr) return 0;
        auto p = ptr.GiveOwnership();
        if (!p) return 0;
        return reinterpret_cast<jlong>(p);
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_1render_gl_NSOpenGl_nCreateImageBrushFromGLTexture( JNIEnv* env, jclass,
        jint textureId,
        jint width,
        jint height,
        jboolean hasAlpha,
        jboolean inverted) {
        auto* device = GetGLRenderDevice();
        if (device == nullptr) {
            jclass excCls = env->FindClass("java/lang/IllegalStateException");
            if (excCls != nullptr) {
                env->ThrowNew(excCls, "GLRenderDevice NULL!");
            }
            return 0;
        }

        const GLuint tex = static_cast<GLuint>(textureId);
        if (tex == 0 || width <= 0 || height <= 0)
            return 0;

        const Ptr<Texture> texture = GLRenderDevice::WrapTexture(
            tex,
            (uint32_t)width,
            (uint32_t)height,
            1,
            inverted == JNI_TRUE,
            hasAlpha == JNI_TRUE
        );

        if (!texture)
            return 0;

        const Ptr<TextureSource> source = *new TextureSource(texture);
        const Ptr<ImageBrush> brush = *new ImageBrush();
        brush->SetImageSource(source);

        brush->AddReference();
        return reinterpret_cast<jlong>(brush.GetPtr());
    }

    JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1render_gl_NSOpenGl_nCreateImageFromGLTexture( JNIEnv* env, jclass,
    jint textureId,
    jint width,
    jint height,
    jboolean hasAlpha,
    jboolean inverted) {

        const GLuint tex = static_cast<GLuint>(textureId);
        if (tex == 0 || width <= 0 || height <= 0)
            return 0;

        const auto texture = NSGLRenderUtil::CreateImageFromGLTexture(tex, width, height, hasAlpha, inverted);
        if (texture == nullptr) return 0;
        texture->AddReference();
        return reinterpret_cast<jlong>(texture.GetPtr());
    }

    JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1render_gl_NSOpenGl_nCreateTextureSourceFromGLTexture( JNIEnv* env, jclass,
    jint textureId,
    jint width,
    jint height,
    jboolean hasAlpha,
    jboolean inverted) {

        const GLuint tex = static_cast<GLuint>(textureId);
        if (tex == 0 || width <= 0 || height <= 0)
            return 0;

        const auto texture = NSGLRenderUtil::CreateTextureSourceFromGLTexture(tex, width, height, hasAlpha, inverted);
        if (texture == nullptr) return 0;
        texture->AddReference();
        return reinterpret_cast<jlong>(texture.GetPtr());
    }
}
