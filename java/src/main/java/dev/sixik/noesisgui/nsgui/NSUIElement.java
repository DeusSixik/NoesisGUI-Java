package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSDependencyObject;
import dev.sixik.noesisgui.nsdrawing.NSPoint;
import dev.sixik.noesisgui.nsdrawing.NSRect;
import dev.sixik.noesisgui.nsdrawing.NSSize;

public class NSUIElement extends NSVisual {

    public NSUIElement(long ptr) {
        super(ptr);
    }

    /**
     * Gets or sets a value indicating whether this element can be used as the target of a
     * drag-and-drop operation
     */
    public final boolean getAllowDrop() {
        return nativeGetAllowDrop(getPtr());
    }

    /**
     * Gets or sets a value indicating whether this element can be used as the target of a
     * drag-and-drop operation
     */
    public final void setAllowDrop(final boolean value) {
        nativeSetAllowDrop(getPtr(), value);
    }

    /**
     * Gets or sets the geometry used to define the outline of the contents of an element
     */
    public final NSGeometry getClip() {
        return new NSGeometry(nativeGetClip(getPtr()));
    }

    /**
     * Gets or sets the geometry used to define the outline of the contents of an element
     */
    public final void setClip(final NSGeometry geometry) {
        nativeSetClip(getPtr(), geometry.getPtr());
    }

    /**
     * Gets or sets a value indicating whether to clip the content of this element (or content
     * coming from the child elements of this element) to fit into the size of the containing
     * element
     */
    public final boolean getClipToBounds() {
        return nativeGetClipToBounds(getPtr());
    }

    /**
     * Gets or sets a value indicating whether to clip the content of this element (or content
     * coming from the child elements of this element) to fit into the size of the containing
     * element
     */
    public final void setClipToBounds(final boolean clipToBounds) {
        nativeSetClipToBounds(getPtr(), clipToBounds);
    }

    /**
     * Gets or sets the bitmap effect to apply to the element
     */
    public final NSEffect getEffect() {
        return new NSEffect(nativeGetEffect(getPtr()));
    }

    /**
     * Gets or sets the bitmap effect to apply to the element
     */
    public final void setEffect(final NSEffect effect) {
        nativeSetEffect(getPtr(), effect.getPtr());
    }

    /**
     * Gets or sets a value that indicates whether the element can receive focus
     */
    public final boolean getFocusable() {
        return nativeGetFocusable(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether the element can receive focus
     */
    public final void setFocusable(final boolean value) {
        nativeSetFocusable(getPtr(), value);
    }

    /**
     * Gets or sets a value indicating whether this element is enabled in the user interface
     */
    public final boolean getIsEnabled() {
        return nativeGetIsEnabled(getPtr());
    }

    /**
     * Gets or sets a value indicating whether this element is enabled in the user interface
     */
    public final void setIsEnabled(final boolean value) {
        nativeSetIsEnabled(getPtr(), value);
    }

    /**
     * Indicates whether this element has the focus
     */
    public final boolean getIsFocused() {
        return nativeGetIsFocused(getPtr());
    }

    /**
     * Gets or sets a value that declares whether this element can possibly be returned as a hit
     * test result from some portion of its rendered content
     */
    public final void setIsHitTestVisible(final boolean value) {
        nativeSetIsHitTestVisible(getPtr(), value);
    }

    /**
     * Gets or sets a value that declares whether this element can possibly be returned as a hit
     * test result from some portion of its rendered content
     */
    public final boolean getIsHitTestVisible() {
        return nativeGetIsHitTestVisible(getPtr());
    }

    /**
     * Gets a value indicating whether this element has keyboard focus
     */
    public final boolean getIsKeyboardFocused() {
        return nativeGetIsKeyboardFocused(getPtr());
    }

    /**
     * Gets a value indicating whether keyboard focus is anywhere within the element or its visual
     * tree child elements
     */
    public final boolean getIsKeyboardFocusWithin() {
        return nativeGetIsKeyboardFocusWithin(getPtr());
    }

    /**
     * Gets a value indicating whether the mouse is captured to this element
     */
    public final boolean getIsMouseCaptured() {
        return nativeGetIsMouseCaptured(getPtr());
    }

    /**
     * Gets a value that determines whether mouse capture is held by this element or by child
     * elements in its visual tree
     */
    public final boolean getIsMouseCaptureWithin() {
        return nativeGetIsMouseCaptureWithin(getPtr());
    }

    /**
     * Gets a value that indicates whether the position of the mouse pointer corresponds to hit
     * test results, which take element compositing into account.
     */
    public final boolean getIsMouseDirectlyOver() {
        return nativeGetIsMouseDirectlyOver(getPtr());
    }

    /**
     * Gets a value indicating whether the mouse pointer is located over this element (including
     * child elements in the visual tree)
     */
    public final boolean getIsMouseOver() {
        return nativeGetIsMouseOver(getPtr());
    }

    /**
     * Indicates whether this element is visible in the user interface
     */
    public final boolean getIsVisible() {
        return nativeGetIsVisible(getPtr());
    }

    /**
     * Gets or sets an opacity mask, as a Brush implementation that is applied to any
     * alpha-channel masking for the rendered content of this element
     */
    public final NSBrush getOpacityMask() {
        return new NSBrush(nativeGetOpacityMask(getPtr()));
    }

    /**
     * Gets or sets an opacity mask, as a Brush implementation that is applied to any
     * alpha-channel masking for the rendered content of this element
     */
    public final void setOpacityMask(final NSBrush brush) {
        nativeSetOpacityMask(getPtr(), brush.getPtr());
    }

    /**
     * Gets or sets the opacity factor applied to the entire element when it is rendered
     */
    public final float getOpacity() {
        return nativeGetOpacity(getPtr());
    }

    /**
     * Gets or sets the opacity factor applied to the entire element when it is rendered
     */
    public final void setOpacity(final float value) {
        nativeSetOpacity(getPtr(), value);
    }

    /**
     * Gets or sets the center point of any possible render transform declared by
     * *RenderTransform*, relative to the bounds of the element
     */
    public final NSPoint getRenderTransformOrigin() {
        final NSPoint point = new NSPoint();
        getRenderTransformOrigin(point);
        return point;
    }

    /**
     * Gets or sets the center point of any possible render transform declared by
     * *RenderTransform*, relative to the bounds of the element
     */
    public final void getRenderTransformOrigin(final NSPoint point) {
        nativeGetRenderTransformOrigin(getPtr(), point);
    }

    /**
     * Gets or sets the center point of any possible render transform declared by
     * *RenderTransform*, relative to the bounds of the element
     */
    public final void setRenderTransformOrigin(final NSPoint point) {
        nativeSetRenderTransformOrigin(getPtr(), point);
    }

    /**
     * Gets or sets transform information that affects the rendering position of this element
     */
    public final NSTransform getRenderTransform() {
        return new NSTransform(nativeGetRenderTransform(getPtr()));
    }

    /**
     * Gets or sets transform information that affects the rendering position of this element
     */
    public final void setRenderTransform(final NSTransform transform) {
        nativeSetRenderTransform(getPtr(), transform.getPtr());
    }

    /**
     * Gets or sets the 3D effect to apply when rendering this element
     */
    public final NSTransform3D getTransform3D() {
        return new NSTransform3D(nativeGetTransform3D(getPtr()));
    }

    /**
     * Gets or sets the 3D effect to apply when rendering this element
     */
    public final void setTransform3D(final NSTransform3D transform) {
        nativeSetTransform3D(getPtr(), transform.getPtr());
    }

    /**
     * Gets or sets the user interface visibility of this element
     */
    public final NSGui_Visibility getVisibility() {
        return NSGui_Visibility.values()[nativeGetVisibility(getPtr())];
    }

    /**
     * Gets or sets the user interface visibility of this element
     */
    public final void setVisibility(final NSGui_Visibility visibility) {
        nativeSetVisibility(getPtr(), visibility.ordinal());
    }

    /**
     * Finds the View where this element is connected to traversing visual or logical ancestors
     */
    public final NSIView getUIView() {
        return new NSIView(nativeGetUIView(getPtr()));
    }

    /**
     * Gets the logical or visual parent for this element
     */
    public final NSUIElement getUIParent() {
        return new NSUIElement(nativeGetUIParent(getPtr()));
    }

    /**
     * Gets a collection of CommandBinding objects associated with this element
     */
    public final NSCommandBindingCollection getCommandBindings() {
        return new NSCommandBindingCollection(nativeGetCommandBindings(getPtr()));
    }

    /**
     * Gets a collection of InputBinding objects associated with this element
     */
    public final NSInputBindingCollection getInputBindings() {
        return new NSInputBindingCollection(nativeGetInputBindings(getPtr()));
    }

    /**
     * Gets mouse input manager
     */
    public final NSMouse getMouse() {
        return new NSMouse(nativeGetMouse(getPtr()));
    }

    /**
     * Attempts to force capture of the mouse to this element
     */
    public final boolean captureMouse() {
        return nativeCaptureMouse(getPtr());
    }

    /**
     * Releases the mouse capture, if this element held the capture
     */
    public final void releaseMouseCapture() {
        nativeReleaseMouseCapture(getPtr());
    }

    /**
     * Translates a point relative to this element to coordinates of the specified element
     */
    public final NSPoint translatePoint(final NSPoint point, final NSUIElement element) {
        final NSPoint out = new NSPoint();
        translatePoint(point, out, element);
        return out;
    }

    /**
     * Translates a point relative to this element to coordinates of the specified element
     */
    public final void translatePoint(final NSPoint input, final NSPoint out, final NSUIElement element) {
        nativeTranslatePoint(getPtr(), input, out, element);
    }

    /**
     * Gets or sets a value that determines whether this element can originate *Tapped* events
     */
    public final boolean getIsTapEnabled() {
        return nativeGetIsTapEnabled(getPtr());
    }

    /**
     * Gets or sets a value that determines whether this element can originate *Tapped* events
     */
    public final void setIsTapEnabled(final boolean value) {
        nativeSetIsTapEnabled(getPtr(), value);
    }

    /**
     * Gets or sets a value that indicates whether manipulation events are enabled on this element
     */
    public final boolean getIsManipulationEnabled() {
        return nativeGetIsManipulationEnabled(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether manipulation events are enabled on this element
     */
    public final void setIsManipulationEnabled(final boolean value) {
        nativeSetIsManipulationEnabled(getPtr(), value);
    }

    /**
     * Gets or sets a value that determines whether this element can originate *DoubleTapped* events
     */
    public final boolean getIsDoubleTapEnabled() {
        return nativeGetIsDoubleTapEnabled(getPtr());
    }

    /**
     * Gets or sets a value that determines whether this element can originate *DoubleTapped* events
     */
    public final void setIsDoubleTapEnabled(final boolean enabled) {
        nativeSetIsDoubleTapEnabled(getPtr(), enabled);
    }

    /**
     * Gets or sets a value that determines whether this element can originate *Holding* events
     */
    public final boolean getIsHoldingEnabled() {
        return nativeGetIsHoldingEnabled(getPtr());
    }

    /**
     * Gets or sets a value that determines whether this element can originate *Holding* events
     */
    public final void setIsHoldingEnabled(final boolean enabled) {
        nativeSetIsHoldingEnabled(getPtr(), enabled);
    }

    /**
     * Gets or sets a value that determines whether this element can originate *RightTapped* events
     */
    public final boolean getIsRightTapEnabled() {
        return nativeGetIsRightTapEnabled(getPtr());
    }

    /**
     * Gets or sets a value that determines whether this element can originate *RightTapped* events
     */
    public final void setIsRightTapEnabled(final boolean value) {
        nativeSetIsRightTapEnabled(getPtr(), value);
    }

    /**
     * Attempts to force capture of a touch to this element
     */
    public final boolean captureTouch(final long touchDevice) {
        return nativeCaptureTouch(getPtr(), touchDevice);
    }

    /**
     * Attempts to release the specified touch device from this element
     */
    public final boolean releaseTouchCapture(final long touchDevice) {
        return nativeReleaseTouchCapture(getPtr(), touchDevice);
    }

    /**
     * Releases all captured touch devices from this element
     */
    public final void releaseAllTouchCaptures() {
        nativeReleaseAllTouchCaptures(getPtr());
    }

    /**
     * Gets element captured by the specified touch device
     */
    public final NSUIElement getTouchCaptured(final long touchDevice) {
        return new NSUIElement(nativeGetTouchCaptured(getPtr(), touchDevice));
    }

    /**
     * Gets keyboard input manager
     */
    public final NSKeyboard getKeyboard() {
        return new NSKeyboard(nativeGetKeyboard(getPtr()));
    }

    /**
     * Attempts to set focus to this element
     */
    public final boolean focus() {
        return nativeFocus(getPtr());
    }

    /**
     * Attempts to set focus to this element indicating if control should be engaged or not
     */
    public final boolean focus(boolean engage) {
        return nativeFocusEnguage(getPtr(), engage);
    }

    /**
     * Gets control's desired size (calculated after *Measure* process)
     */
    public final NSSize getDesiredSize() {
        final NSSize size = new NSSize(0, 0);
        getDesiredSize(size);
        return size;
    }

    /**
     * Gets control's desired size (calculated after *Measure* process)
     */
    public final void getDesiredSize(final NSSize out) {
        nativeGetDesiredSize(getPtr(), out);
    }

    /**
     * Gets calculated (during *Arrange*) render size
     */
    public final NSSize getRenderSize() {
        final NSSize size = new NSSize(0, 0);
        getRenderSize(size);
        return size;
    }

    /**
     * Gets calculated (during *Arrange*) render size
     */
    public final void getRenderSize(final NSSize out) {
        nativeGetRenderSize(getPtr(), out);
    }

    /**
     * Invalidates the measurement state (layout) for the element
     */
    public final void invalidateMeasure() {
        nativeInvalidateMeasure(getPtr());
    }

    /**
     * Indicates if measured size is valid
     */
    public final boolean isMeasureValid() {
        return nativeIsMeasureValid(getPtr());
    }

    /**
     * Updates the *DesiredSize* of a UIElement. Parent elements call this method from their own
     * *MeasureCore* implementations to form a recursive layout update. Calling this method
     * constitutes the first pass of a layout update in the layout system
     */
    public final void measure(NSSize size) {
        nativeMeasure(getPtr(), size);
    }

    /**
     * Invalidates the arrange state (layout) for the element. After the invalidation,
     * the element will have its layout updated, which will occur asynchronously
     * unless subsequently forced by *UpdateLayout*
     */
    public final void invalidateArrange() {
        nativeInvalidateArrange(getPtr());
    }

    /**
     * Indicates if arrange is valid
     */
    public final boolean isArrangeValid() {
        return nativeIsArrangeValid(getPtr());
    }

    /**
     * Positions child elements and determines a size for a UIElement. Parent elements call this
     * method from their *ArrangeCore* implementation to form a recursive layout update. This
     * method constitutes the second pass of a layout update
     */
    public final void arrange(NSRect rect) {
        nativeArrange(getPtr(), rect);
    }

    /**
     * Invalidates the rendering of the element, and forces a complete new layout pass. *OnRender*
     * is called after the layout cycle is completed
     */
    public final void invalidateVisual() {
        nativeInvalidateVisual(getPtr());
    }

    /**
     * Ensures that all visual child elements of this element are properly updated for layout
     */
    public final void updateLayout() {
        nativeUpdateLayout(getPtr());
    }

    /**
     * Request to move the focus from this element to another element. Returns true if focus is
     * moved successfully, returns false if there is no next element
     */
    public final boolean moveFocus(final NSTraversalRequest request) {
        return nativeMoveFocus(getPtr(), request);
    }

    /**
     * When overridden in a derived class, returns the element that would receive focus for a
     * specified focus traversal direction, without actually moving focus to that element
     */
    public final NSDependencyObject predictFocus(final NSGui_FocusNavigationDirection direction) {
        return new NSDependencyObject(nativePredictFocus(getPtr(), direction.ordinal()));
    }

    /**
     * Gets previous measure constraint (internally used by Layout manager)
     */
    public final NSSize getMeasureConstraint() {
        final NSSize size = new NSSize(0, 0);
        getMeasureConstraint(size);
        return size;
    }

    /**
     * Gets previous measure constraint (internally used by Layout manager)
     */
    public final void getMeasureConstraint(final NSSize out) {
        nativeGetMeasureConstraint(getPtr(), out);
    }

    /**
     * Gets previous arrange constraint (internally used by Layout manager)
     */
    public final NSRect getArrangeConstraint() {
        final NSRect rect = new NSRect();
        getArrangeConstraint(rect);
        return rect;
    }

    /**
     * Gets previous arrange constraint (internally used by Layout manager)
     */
    public final void getArrangeConstraint(final NSRect out) {
        nativeGetArrangeConstraint(getPtr(), out);
    }

    private static native boolean nativeGetAllowDrop(long ptr);

    private static native void nativeSetAllowDrop(long ptr, boolean value);

    private static native long nativeGetClip(long ptr);

    private static native void nativeSetClip(long ptr, long geometryPtr);

    private static native boolean nativeGetClipToBounds(long ptr);

    private static native void nativeSetClipToBounds(long ptr, boolean value);

    private static native long nativeGetEffect(long ptr);

    private static native void nativeSetEffect(long ptr, long effectPtr);

    private static native boolean nativeGetFocusable(long ptr);

    private static native void nativeSetFocusable(long ptr, boolean value);

    private static native boolean nativeGetIsEnabled(long ptr);

    private static native void nativeSetIsEnabled(long ptr, boolean value);

    private static native boolean nativeGetIsFocused(long ptr);

    private static native boolean nativeGetIsHitTestVisible(long ptr);

    private static native void nativeSetIsHitTestVisible(long ptr, boolean value);

    private static native boolean nativeGetIsKeyboardFocused(long ptr);

    private static native boolean nativeGetIsKeyboardFocusWithin(long ptr);

    private static native boolean nativeGetIsMouseCaptured(long ptr);

    private static native boolean nativeGetIsMouseCaptureWithin(long ptr);

    private static native boolean nativeGetIsMouseDirectlyOver(long ptr);

    private static native boolean nativeGetIsMouseOver(long ptr);

    private static native boolean nativeGetIsVisible(long ptr);

    private static native long nativeGetOpacityMask(long ptr);

    private static native void nativeSetOpacityMask(long ptr, long brushPtr);

    private static native float nativeGetOpacity(long ptr);

    private static native void nativeSetOpacity(long ptr, float value);

    private static native void nativeGetRenderTransformOrigin(long ptr, NSPoint point);

    private static native void nativeSetRenderTransformOrigin(long ptr, NSPoint point);

    private static native long nativeGetRenderTransform(long ptr);

    private static native void nativeSetRenderTransform(long ptr, long transformPtr);

    private static native long nativeGetTransform3D(long ptr);

    private static native void nativeSetTransform3D(long ptr, long transformPtr);

    private static native int nativeGetVisibility(long ptr);

    private static native void nativeSetVisibility(long ptr, int value);

    private static native long nativeGetUIView(long ptr);

    private static native long nativeGetUIParent(long ptr);

    private static native long nativeGetCommandBindings(long ptr);

    private static native long nativeGetInputBindings(long ptr);

    private static native long nativeGetMouse(long ptr);

    private static native boolean nativeCaptureMouse(long ptr);

    private static native void nativeReleaseMouseCapture(long ptr);

    private static native void nativeTranslatePoint(long ptr, NSPoint input, NSPoint out, NSUIElement element);

    private static native boolean nativeGetIsTapEnabled(long ptr);

    private static native void nativeSetIsTapEnabled(long ptr, boolean value);

    private static native boolean nativeGetIsManipulationEnabled(long ptr);

    private static native void nativeSetIsManipulationEnabled(long ptr, boolean value);

    private static native boolean nativeGetIsDoubleTapEnabled(long ptr);

    private static native void nativeSetIsDoubleTapEnabled(long ptr, boolean value);

    private static native boolean nativeGetIsHoldingEnabled(long ptr);

    private static native void nativeSetIsHoldingEnabled(long ptr, boolean value);

    private static native boolean nativeGetIsRightTapEnabled(long ptr);

    private static native void nativeSetIsRightTapEnabled(long ptr, boolean value);

    private static native boolean nativeCaptureTouch(long ptr, long touchDevice);

    private static native boolean nativeReleaseTouchCapture(long ptr, long touchDevice);

    private static native void nativeReleaseAllTouchCaptures(long ptr);

    private static native long nativeGetTouchCaptured(long ptr, long touchDevice);

    private static native long nativeGetKeyboard(long ptr);

    private static native boolean nativeFocus(long ptr);

    private static native boolean nativeFocusEnguage(long ptr, boolean engage);

    private static native void nativeGetDesiredSize(long ptr, NSSize size);

    private static native void nativeGetRenderSize(long ptr, NSSize size);

    private static native void nativeInvalidateMeasure(long ptr);

    private static native boolean nativeIsMeasureValid(long ptr);

    private static native void nativeMeasure(long ptr, NSSize availableSize);

    private static native void nativeInvalidateArrange(long ptr);

    private static native boolean nativeIsArrangeValid(long ptr);

    private static native void nativeArrange(long ptr, NSRect rect);

    private static native void nativeInvalidateVisual(long ptr);

    private static native void nativeUpdateLayout(long ptr);

    private static native boolean nativeMoveFocus(long ptr, NSTraversalRequest request);

    private static native long nativePredictFocus(long ptr, int direction);

    private static native void nativeGetMeasureConstraint(long ptr, NSSize size);

    private static native void nativeGetArrangeConstraint(long ptr, NSRect rect);
}

