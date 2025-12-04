package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSInterface;
import dev.sixik.noesisgui.nsmath.NSMatrix4;
import dev.sixik.noesisgui.nsrenderer.NSRenderDevice;

public class NSIRenderer extends NSInterface {

    public NSIRenderer(long ptr) {
        super(ptr);
    }

    /**
     * Initializes the renderer with the given render device abstraction
     */
    public final void init(final NSRenderDevice renderDevice) {
        nativeInit(getPtr(), renderDevice.getPtr());
    }

    /**
     * Free allocated render resources and render tree
     */
    public final void shutdown() {
        nativeShutdown(getPtr());
    }

    /**
     * Determines the visible region. By default it is set to cover the view dimensions
     */
    public final void setRenderRegion(final float x, final float y, final float width, final float height) {
        nativeSetRenderRegion(getPtr(), x, y, width, height);
    }

    /**
     * Grabs the most recent snapshot captured by IView::Update()
     * Returns false if no new snapshots were found
     */
    public final void updateRenderTree() {
        nativeUpdateRenderTree(getPtr());
    }

    /**
     * Updates internal offscreen textures needed by global opacity and shader effects. It is
     * recommended, specially on tiled architectures, to invoke this function before binding the
     * main render target to avoid unnecessary render target changes that may affect performance.
     * Returns 'false' when no textures are updates and restoring the device state is not necessary
     */
    public final boolean renderOffscreen() {
        return nativeRenderOffscreen(getPtr());
    }

    /**
     * Renders UI into the current render target with the active viewport and scissor rects
     */
    public final void render() {
        render(false);
    }

    /**
     * Renders UI into the current render target with the active viewport and scissor rects
     */
    public final void render(boolean flipY) {
        render(flipY, false);
    }

    /**
     * Renders UI into the current render target with the active viewport and scissor rects
     */
    public final void render(boolean flipY, boolean clear) {
        nativeRender(getPtr(), flipY, clear);
    }

    public final void renderStereo(NSMatrix4 eyeMtx) {
        renderStereo(eyeMtx, false, false);
    }

    /**
     * Multi-pass stereo version of Render(). Since culling always uses the projection set via
     * IView::SetProjectionMatrix, the provided 'eyeMtx' must be fully enclosed by that matrix
     */
    public final void renderStereo(NSMatrix4 eyeMtx, boolean flipY, boolean clear) {
        nativeRenderStereoSingle(getPtr(), eyeMtx, flipY, clear);
    }

    public final void renderStereo(NSMatrix4 leftEyeMtx, NSMatrix4 rightEyeMtx) {
        renderStereo(leftEyeMtx, rightEyeMtx, false, false);
    }

    /**
     * Single-pass stereo version of Render(). Since culling always uses the projection set via
     * IView::SetProjectionMatrix, both 'leftEyeMtx' and 'rightEyeMtx' must be fully enclosed by
     * that matrix
     */
    public final void renderStereo(NSMatrix4 leftEyeMtx, NSMatrix4 rightEyeMtx, boolean flipY, boolean clear) {
        nativeRenderStereo(getPtr(), leftEyeMtx, rightEyeMtx, flipY, clear);
    }

    private static native void nativeInit(long ptr, long renderDevice_ptr);

    private static native void nativeShutdown(long ptr);

    private static native void nativeSetRenderRegion(long ptr, float x, float y, float w, float h);

    private static native void nativeUpdateRenderTree(long ptr);

    private static native boolean nativeRenderOffscreen(long ptr);

    private static native void nativeRender(long ptr, boolean flipY, boolean clear);

    private static native void nativeRenderStereoSingle(long ptr, NSMatrix4 eyeMtx, boolean flipY, boolean clear);

    private static native void nativeRenderStereo(long ptr, NSMatrix4 leftEyeMtx, NSMatrix4 rightEyeMtx, boolean flipY, boolean clear);
}
