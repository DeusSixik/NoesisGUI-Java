package dev.sixik.noesisgui_render.gl;

import dev.sixik.noesisgui.nsrenderer.NSRenderDevice;

public class NSOpenGl {

    public static NSRenderDevice createDevice(boolean sRGB) {
        return new NSRenderDevice(nativeCreateDevice(sRGB));
    }

//    public static NSTexture wrapTexture(@NativeType("GLint") int object, long width, long height, long levels, boolean isInverted, boolean hasAlpha) {
//        return new NSTexture(nativeWrapTexture(object, width, height, levels, isInverted, hasAlpha));
//    }
//
//    public static long createPixelShader(final NSRenderDevice renderDevice, String label, short shader, String glsl) {
//        return nativeCreatePixelShader(renderDevice.getPtr(), label, shader, glsl);
//    }
//
//    public static void clearPixelShaders(final NSRenderDevice renderDevice) {
//        nativeClearPixelShaders(renderDevice.getPtr());
//    }

    private static native long nativeCreateDevice(boolean sRGB);

//    private static native long nativeWrapTexture(@NativeType("GLint") int object, long width, long height, long levels, boolean isInverted, boolean hasAlpha);
//
//    private static native long nativeCreatePixelShader(long renderDevicePtr, String label, short shader, String glsl);
//
//    private static native void nativeClearPixelShaders(long renderDevicePtr);
}
