//
// Created by Sixik on 11.12.2025.
//

#ifndef NOESIS_JNI_NSGLRENDERUTIL_H
#define NOESIS_JNI_NSGLRENDERUTIL_H
#include "NsCore/Ptr.h"
#include "NsGui/Enums.h"
#include "NsGui/ImageBrush.h"
#include "NsGui/TextureSource.h"
#include "Render/GLRenderDevice/Include/NsRender/GLFactory.h"
#include "Render/GLRenderDevice/Src/GLRenderDevice.h"
#include "NsRender/Texture.h"

#endif //NOESIS_JNI_NSGLRENDERUTIL_H

namespace Noesis {
    class ImageBrush;
}

using namespace Noesis;
using namespace NoesisApp;

class NSGLRenderUtil {
public:
    static Ptr<Texture> CreateImageFromGLTexture(GLuint tex,
                                                 uint32_t width,
                                                 uint32_t height,
                                                 bool hasAlpha,
                                                 bool isInverted) {
        return GLRenderDevice::WrapTexture(tex, width, height, 1,
                                           isInverted, hasAlpha);
    }

    static Ptr<TextureSource> CreateTextureSourceFromGLTexture(GLuint tex,
                                                               uint32_t width,
                                                               uint32_t height,
                                                               bool hasAlpha,
                                                               bool isInverted) {
        return *new TextureSource(GLRenderDevice::WrapTexture(tex, width, height, 1,
                                                              isInverted, hasAlpha));
    }

    static Ptr<ImageBrush> CreateImageBrushFromGLTexture(GLuint tex,
                                                         uint32_t width,
                                                         uint32_t height,
                                                         bool hasAlpha,
                                                         bool isInverted) {
        const Ptr<Texture> texture = GLRenderDevice::WrapTexture(tex, width, height, 1,
                                                           isInverted, hasAlpha);

        if (!texture)
            return nullptr;

        const Ptr<TextureSource> source = *new TextureSource(texture);
        const Ptr<ImageBrush> brush = *new ImageBrush();
        brush->SetImageSource(source);
        brush->SetStretch(Stretch_UniformToFill);
        brush->SetAlignmentX(AlignmentX_Center);
        brush->SetAlignmentY(AlignmentY_Center);

        return brush;
    }
};
