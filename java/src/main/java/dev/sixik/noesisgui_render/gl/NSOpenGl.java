package dev.sixik.noesisgui_render.gl;

import dev.sixik.noesisgui.nsgui.NSImageBrush;
import dev.sixik.noesisgui.nsgui.NSImageSource;
import dev.sixik.noesisgui.nsrenderer.NSRenderDevice;
import dev.sixik.noesisgui.nsrenderer.NSTexture;

public class NSOpenGl {

    public static NSRenderDevice createDevice(boolean sRGB) {
        return new NSRenderDevice(nativeCreateDevice(sRGB));
    }

    public static NSImageBrush createImageBrushFromGLTexture(
            int textureId, int width, int height, boolean hasAlpha, boolean inverted
    ) {
        long ptr = nCreateImageBrushFromGLTexture(textureId, width, height, hasAlpha, inverted);
        if (ptr == 0L) return null;
        return new NSImageBrush(ptr);
    }

    public static NSTexture createImageFromGLTexture(
            int textureId, int width, int height, boolean hasAlpha, boolean inverted
    ) {
        long ptr = nCreateImageFromGLTexture(textureId, width, height, hasAlpha, inverted);
        if (ptr == 0L) return null;
        return new NSTexture(ptr);
    }

    public static NSImageSource createTextureSourceFromGLTexture(
            int textureId, int width, int height, boolean hasAlpha, boolean inverted
    ) {
        long ptr = nCreateTextureSourceFromGLTexture(textureId, width, height, hasAlpha, inverted);
        if (ptr == 0L) return null;
        return new NSImageSource(ptr);
    }

    private static native long nativeCreateDevice(boolean sRGB);

    private static native long nCreateImageBrushFromGLTexture(int textureId, int width, int height, boolean hasAlpha, boolean inverted);

    private static native long nCreateImageFromGLTexture(int textureId, int width, int height, boolean hasAlpha, boolean inverted);

    private static native long nCreateTextureSourceFromGLTexture(int textureId, int width, int height, boolean hasAlpha, boolean inverted);

}
