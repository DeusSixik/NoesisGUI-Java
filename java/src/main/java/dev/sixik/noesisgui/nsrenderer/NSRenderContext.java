package dev.sixik.noesisgui.nsrenderer;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui_render.gl.NSGLRenderContext;

public class NSRenderContext extends NSBaseComponent {

    /**
     * Gets the current render context
     */
    public static NSRenderContext current() {
        long p = nCurrent();
        return p != 0L ? new NSRenderContext(p) : null;
    }

    public static NSRenderContext create() {
        return new NSGLRenderContext(nCreate());
    }

    public static NSRenderContext create(final String name) {
        return new NSGLRenderContext(nCreateByName(name));
    }

    public NSRenderContext(long ptr) {
        super(ptr);
    }

    /**
     * Brief description provided by the implementation
     */
    public String getDescription() {
        return nGetDescription(getPtr());
    }

    /**
     * Returns the shader language used by this implementation
     */
    public String getShaderLang() {
        return nGetShaderLang(getPtr());
    }

    /**
     * When looking for the best render context, those with higher score are tried first
     */
    public int getScore() {
        return nGetScore(getPtr());
    }

    /**
     * Returns whether the implementation is valid
     */
    public boolean validate() {
        return nValidate(getPtr());
    }

    /**
     * Initializes the rendering context with the given window and multisampling samples
     * @param windowPtr pointer to HWND\NSView*\GLFWwindow*
     * @param samples in/out
     */
    public void init(long windowPtr, int[] samples, boolean vsync, boolean sRGB) {
        if (samples == null || samples.length == 0) {
            throw new IllegalArgumentException("samples must be int[1] or bigger");
        }
        nInit(getPtr(), windowPtr, samples, vsync, sRGB);
    }

    public void shutdown() {
        nShutdown(getPtr());
    }

    public void setWindow(long windowPtr) {
        nSetWindow(getPtr(), windowPtr);
    }

    public void saveState() {
        nSaveState(getPtr());
    }

    public void beginRender() {
        nBeginRender(getPtr());
    }

    public void endRender() {
        nEndRender(getPtr());
    }

    public void resize() {
        nResize(getPtr());
    }

    public float getGpuTimeMs() {
        return nGetGpuTimeMs(getPtr());
    }

    public void setClearColor(float r, float g, float b, float a) {
        nSetClearColor(getPtr(), r, g, b, a);
    }

    public void setDefaultRenderTarget(int width, int height, boolean doClearColor) {
        nSetDefaultRenderTarget(getPtr(), width, height, doClearColor);
    }

    public void swap() {
        nSwap(getPtr());
    }

    @Override
    public void destroy() {
        nDestroy(getPtr());
    }

//    public NSImage captureRenderTarget(NSRenderTarget surface) {
//        long surfPtr = surface != null ? surface.getPtr() : 0L;
//        long imgPtr = nCaptureRenderTarget(getPtr(), surfPtr);
//        return new NSImage(imgPtr);
//    }

    public long createPixelShader(String label, byte shader, byte[] code) {
        return nCreatePixelShader(getPtr(), label, shader, code);
    }

    private static native long nCreate();

    private static native long nCreateByName(String name);

    private static native long nCurrent();

    private static native void nDestroy(long ptr);

    private static native String nGetDescription(long ptr);

    private static native String nGetShaderLang(long ptr);

    private static native int nGetScore(long ptr);

    private static native boolean nValidate(long ptr);

    private static native void nInit(long ptr, long windowPtr,
                                     int[] samplesInOut,
                                     boolean vsync,
                                     boolean sRGB);

    private static native void nShutdown(long ptr);

    private static native void nSetWindow(long ptr, long windowPtr);

    private static native void nSaveState(long ptr);

    private static native void nBeginRender(long ptr);

    private static native void nEndRender(long ptr);

    private static native void nResize(long ptr);

    private static native float nGetGpuTimeMs(long ptr);

    private static native void nSetClearColor(long ptr,
                                              float r, float g, float b, float a);

    private static native void nSetDefaultRenderTarget(long ptr,
                                                       int width, int height,
                                                       boolean doClearColor);

    private static native void nSwap(long ptr);

//    private static native long nCaptureRenderTarget(long ctxPtr, long surfacePtr);

    private static native long nCreatePixelShader(long ctxPtr,
                                                  String label,
                                                  byte shader,
                                                  byte[] code);

//    private static native void nEnsureBrushShaders(long shadersPtr,
//                                                   String label,
//                                                   byte[] blob);
//
//    private static native void nEnsureEffectShaders(long shadersPtr,
//                                                    String label,
//                                                    byte[] blob);
}
