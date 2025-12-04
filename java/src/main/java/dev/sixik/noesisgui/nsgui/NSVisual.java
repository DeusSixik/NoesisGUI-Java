package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSDependencyObject;
import dev.sixik.noesisgui.nsdrawing.NSPoint;
import dev.sixik.noesisgui.nsmath.NSMatrix4;
import dev.sixik.noesisgui.nsrenderer.NSRenderTreeUpdater;

/**
 * Provides rendering support, which includes hit testing, coordinate transformation, and bounding
 * box calculations.
 * <p>
 * http://msdn.microsoft.com/en-us/library/system.windows.media.visual.aspx
 */
public class NSVisual extends NSDependencyObject {

    public NSVisual(long ptr) {
        super(ptr);
    }

    /**
     * Determines whether the visual object is an ancestor of the descendant visual object
     * This object is not considered to be an ancestor of *visual* if they are the same
     */
    public final boolean isAncestorOf(final NSVisual visual) {
        return nativeIsAncestorOf(getPtr(), visual.getPtr());
    }

    /**
     * Determines whether the visual object is a descendant of the ancestor visual object
     * This object is not considered to be a descendant of *visual* if they are the same
     */
    public final boolean isDescendantOf(final NSVisual visual) {
        return nativeIsDescendantOf(getPtr(), visual.getPtr());
    }

    /**
     * Finds the common ancestor of two visuals objects
     * If *visual* is the same object as this, the common ancestor will be the parent
     */
    public final NSVisual findCommonVisualAncestor(final NSVisual visual) {
        return new NSVisual(nativeFindCommonVisualAncestor(getPtr(), visual.getPtr()));
    }

    /**
     * Converts a Point in screen coordinates into a Point that represents the current coordinate
     * system of the Visual
     */
    public final void pointFromScreen(final NSPoint inPoint, final NSPoint outPoint) {
        nativePointFromScreen(getPtr(), inPoint, outPoint);
    }

    /**
     * Converts a Point that represents the current coordinate system of the Visual into a Point
     * in screen coordinates
     */
    public final void pointToScreen(final NSPoint inPoint, final NSPoint outPoint) {
        nativePointToScreen(getPtr(), inPoint, outPoint);
    }

    /**
     * Returns a transform that can be used to transform coordinates from the Visual to the
     * specified ancestor of the visual object
     */
    public final void transformToAncestor(final NSVisual visual, final NSMatrix4 outMatrix) {
        nativeTransformToAncestor(getPtr(), visual.getPtr(), outMatrix);
    }

    /**
     * Returns a transform that can be used to transform coordinates from the Visual to the
     * specified visual object descendant
     */
    public final void transformToDescendant(final NSVisual visual, final NSMatrix4 outMatrix) {
        nativeTransformToDescendant(getPtr(), visual.getPtr(), outMatrix);
    }

    /**
     * Returns a transform that can be used to transform coordinates from the Visual to the
     * specified visual object
     */
    public final void transformToVisual(final NSVisual visual, final NSMatrix4 outMatrix) {
        nativeTransformToVisual(getPtr(), visual.getPtr(), outMatrix);
    }

    /**
     * Indicates if this visual is invalidated and should send updates to the render tree
     */
    public final boolean isInvalidated() {
        return nativeIsInvalidated(getPtr());
    }

    /**
     * Indicates if this visual has been connected to a View
     */
    public final boolean isConnectedToView() {
        return nativeIsConnectedToView(getPtr());
    }

    /**
     * Gets the view where this visual is connected to
     */
    public final NSIView getView() {
        return new NSIView(nativeGetView(getPtr()));
    }

    /**
     * Indicates if a render node has been created in the RenderTree for this visual
     */
    public final boolean isInRenderTree() {
        return nativeIsInRenderTree(getPtr());
    }

    /**
     * Gets RenderTree's identifier
     */
    public final long getRenderTreeId() {
        return nativeGetRenderTreeId(getPtr());
    }

    /**
     * Pushes all the layout updates into the UI render thread queue to update render nodes
     */
    public final void updateRender(final NSRenderTreeUpdater updater) {
        nativeUpdateRender(getPtr(), updater.getPtr());
    }

    /**
     * Ensures that a render node exists for this visual
     */
    public final void ensureRenderId(final NSRenderTreeUpdater updater) {
        nativeEnsureRenderId(getPtr(), updater.getPtr());
    }

    private static native boolean nativeIsAncestorOf(long ptr, long visualPtr);

    private static native boolean nativeIsDescendantOf(long ptr, long visualPtr);

    private static native long nativeFindCommonVisualAncestor(long ptr, long visualPtr);

    private static native void nativePointFromScreen(long ptr, NSPoint inPoint, NSPoint outPoint);

    private static native void nativePointToScreen(long ptr, NSPoint inPoint, NSPoint outPoint);

    private static native void nativeTransformToAncestor(long ptr, long visualPtr, NSMatrix4 outMatrix);

    private static native void nativeTransformToDescendant(long ptr, long visualPtr, NSMatrix4 outMatrix);

    private static native void nativeTransformToVisual(long ptr, long visualPtr, NSMatrix4 outMatrix);

    private static native boolean nativeIsInvalidated(long ptr);

    private static native boolean nativeIsConnectedToView(long ptr);

    private static native long nativeGetView(long ptr);

    private static native boolean nativeIsInRenderTree(long ptr);

    private static native long nativeGetRenderTreeId(long ptr);

    private static native void nativeUpdateRender(long ptr, long updaterPtr);

    private static native void nativeEnsureRenderId(long ptr, long updaterPtr);

}
