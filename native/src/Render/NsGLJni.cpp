#include <jni.h>
#include <jni_md.h>

#include "NSGLRenderUtil.h"
#include "NsGui/ImageBrush.h"
#include "NsGui/TextureSource.h"
#include "Render/GLRenderDevice/Include/NsRender/GLFactory.h"
#include "Render/GLRenderDevice/Src/GLRenderDevice.h"
#include "NsRender/Texture.h"

using namespace Noesis;
using namespace NoesisApp;

extern "C" {

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_1render_gl_NSOpenGl_nativeCreateDevice(
            JNIEnv *env, jclass, jboolean sRGB) {

        auto ptr = GLFactory::CreateDevice(sRGB);
        if (!ptr) return 0;

        auto p = ptr.GiveOwnership();
        if (!p) return 0;

        return reinterpret_cast<jlong>(p);
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_1render_gl_NSOpenGl_nCreateImageBrushFromGLTexture(
            JNIEnv* env, jclass,
            jint textureId,
            jint width,
            jint height,
            jboolean hasAlpha,
            jboolean inverted) {

        const GLuint tex = static_cast<GLuint>(textureId);
        if (tex == 0 || width <= 0 || height <= 0)
            return 0;

        Ptr<Texture> texture = GLRenderDevice::WrapTexture(
            tex,
            static_cast<uint32_t>(width),
            static_cast<uint32_t>(height),
            1,
            inverted == JNI_TRUE,
            hasAlpha == JNI_TRUE
        );

        if (!texture)
            return 0;

        Ptr<TextureSource> source = *new TextureSource(texture);
        Ptr<ImageBrush> brush = *new ImageBrush();
        brush->SetImageSource(source);

        brush->AddReference();
        return reinterpret_cast<jlong>(brush.GetPtr());
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_1render_gl_NSOpenGl_nCreateImageFromGLTexture(
            JNIEnv* env, jclass,
            jint textureId,
            jint width,
            jint height,
            jboolean hasAlpha,
            jboolean inverted) {

        const GLuint tex = static_cast<GLuint>(textureId);
        if (tex == 0 || width <= 0 || height <= 0)
            return 0;

        const auto image = NSGLRenderUtil::CreateImageFromGLTexture(
            tex, width, height, hasAlpha, inverted);

        if (image == nullptr) return 0;
        image->AddReference();
        return reinterpret_cast<jlong>(image.GetPtr());
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_1render_gl_NSOpenGl_nCreateTextureSourceFromGLTexture(
            JNIEnv* env, jclass,
            jint textureId,
            jint width,
            jint height,
            jboolean hasAlpha,
            jboolean inverted) {

        const GLuint tex = static_cast<GLuint>(textureId);
        if (tex == 0 || width <= 0 || height <= 0)
            return 0;

        const auto ts = NSGLRenderUtil::CreateTextureSourceFromGLTexture(
            tex, width, height, hasAlpha, inverted);

        if (ts == nullptr) return 0;
        ts->AddReference();
        return reinterpret_cast<jlong>(ts.GetPtr());
    }
}
