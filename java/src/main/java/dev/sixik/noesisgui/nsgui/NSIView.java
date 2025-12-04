package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.NoesisGui;
import dev.sixik.noesisgui.nsmath.NSMatrix4;

public class NSIView {

    private final long ptr;

    public NSIView(long ptr) {
        this.ptr = ptr;
    }

    public long getPtr() {
        return ptr;
    }

    /**
     * Returns the renderer associated to this view
     */
    public final NSIRenderer getRenderer() {
        return new NSIRenderer(nativeGetRenderer(ptr));
    }

    /**
     * Returns the root element
     */
    public final NSFrameworkElement getContent() {
        return new NSFrameworkElement(nativeGetContent(getPtr()));
    }

    /**
     * Sets DPI scale value. Default is 1.0 which corresponds to 96 pixels per inch.
     */
    public final void setScale(final float scale) {
        nativeSetScale(getPtr(), scale);
    }

    /**
     * Sets the size of the surface where UI elements will layout and render
     */
    public final void setSize(final long width, final long height) {
        nativeSetSize(getPtr(), width, height);
    }

    /**
     * Sets the tessellation curve tolerance in screen space. MediumQuality is the default value
     */
    public final void setTessellationMaxPixelError(final NSTessellationMaxPixelError maxPixelError) {
        nativeSetTessellationMaxPixelError(getPtr(), maxPixelError);
    }

    /**
     * Gets current tessellation curve tolerance
     */
    public final NSTessellationMaxPixelError getTessellationMaxPixelError() {
        final NSTessellationMaxPixelError error = NSTessellationMaxPixelError.LowQuality();
        getTessellationMaxPixelError(error);
        return error;
    }

    /**
     * Gets current tessellation curve tolerance
     */
    public final void getTessellationMaxPixelError(final NSTessellationMaxPixelError out) {
        nativeGetTessellationMaxPixelError(getPtr(), out);
    }

    /**
     * Sets render flags
     */
    public final void setFlags(final int flags) {
        nativeSetFlags(getPtr(), flags);
    }

    /**
     * Sets render flags
     */
    public final void setFlags(final NSGui_RenderFlags flag) {
        setFlags(flag.value);
    }

    /**
     * Sets render flags
     */
    public final void setFlags(final NSGui_RenderFlags[] flags) {
        int flag = 0;
        for (NSGui_RenderFlags nsGuiRenderFlags : flags) {
            flag |= nsGuiRenderFlags.value;
        }
        setFlags(flag);
    }

    /**
     * Gets current render flags
     */
    public final int getFlags() {
        return NoesisGui.toSignedInt(nativeGetFlags(getPtr()));
    }

    /**
     * As Tapped and Holding events are mutually exclusive, this threshold indicates when an
     * interaction should start a Holding event. By default it is 500 milliseconds
     */
    public final void setHoldingTimeThreshold(final long milliseconds) {
        nativeSetHoldingTimeThreshold(getPtr(), milliseconds);
    }

    /**
     * Minimum distance, in pixels, between first interaction and last interaction to consider
     * valid Tapped or Holding events. By default it is 10 pixels
     */
    public final void setHoldingDistanceThreshold(final long pixels) {
        nativeSetHoldingDistanceThreshold(getPtr(), pixels);
    }

    /**
     * Minimun distance since first contact, in pixels, to start a manipulation. Once this
     * threshold is reached, the event ManipulationStarted is sent. By default it is 10 pixels
     */
    public final void setManipulationDistanceThreshold(final long pixels) {
        nativeSetManipulationDistanceThreshold(getPtr(), pixels);
    }

    /**
     * The maximum delay required for two consecutives Tapped events to be interpreted as
     * a DoubleTapped event. By default it is 500 milliseconds
     */
    public final void setDoubleTapTimeThreshold(final long milliseconds) {
        nativeSetDoubleTapTimeThreshold(getPtr(), milliseconds);
    }

    /**
     * Minimum distance, in pixels, between first interaction and last interaction to consider
     * a DoubleTapped event. By default it is 10 pixels
     */
    public final void setDoubleTapDistanceThreshold(final long pixels) {
        nativeSetDoubleTapDistanceThreshold(getPtr(), pixels);
    }

    /**
     * Sets the projection matrix that transforms the coordinates of each primitive to a
     * non-normalized homogeneous space where (0, 0) is at the lower-left corner and
     * (width, height) is at the upper-right corner after projection.
     * The following table compares the clip space used by OpenGL and D3D in comparison. <br>
     * ========= =========== ============ ========= <br>
     * System    X Range     Y Range      Z Range <br>
     * ========= =========== ============ ========= <br>
     * OpenGL    [-1...+1]   [-1...+1]    [-1...+1] <br>
     * Direct3D  [-1...+1]   [-1...+1]    [0...1] <br>
     * NoesisGUI [0...width] [0...height] [0...1] <br>
     * ========= =========== ============ ========= <br>
     */
    public final void setProjectionMatrix(final NSMatrix4 projection) {
        nativeSetProjectionMatrix(getPtr(), projection);
    }

    /**
     * The projection matrix set to the view is used for determining the visual impact of nodes
     * in the offscreen phase. The stereo matrices used for rendering in VR are slightly different.
     * To account for this difference, it is recommended to apply a scale using this function.
     * For non-VR this must be always 1. For VR, we recommend a value between 2 and 3.
     */
    public final void setStereoOffscreenScaleFactor(final float factor) {
        nativeSetStereoOffscreenScaleFactor(getPtr(), factor);
    }

    /**
     * Activates the view and recovers keyboard focus
     */
    public final void activate() {
        nativeActivate(getPtr());
    }

    /**
     * Deactivates the view and removes keyboard focus
     */
    public final void deactivate() {
        nativeDeactivate(getPtr());
    }

    /**
     * Indicates if touch input events are emulated by the mouse
     */
    public final void setEmulateTouch(boolean emulate) {
        nativeSetEmulateTouch(getPtr(), emulate);
    }

    /**
     * Notifies that a mouse button was pressed. Origin is in the upper-left corner.
     * @return Returns true if event was handled
     */
    public final boolean mouseButtonDown(final int x, final int y, final NSGui_MouseButton button) {
        return nativeMouseButtonDown(getPtr(), x, y, button.ordinal());
    }

    /**
     * Notifies that a mouse button was released. Origin is in the upper-left corner.
     * @return Returns true if event was handled
     */
    public final boolean mouseButtonUp(final int x, final int y, final NSGui_MouseButton button) {
        return nativeMouseButtonUp(getPtr(), x ,y, button.ordinal());
    }

    /**
     * Notifies that a mouse button was double clicked. Origin is in the upper-left corner. <br>
     * When a double click happens the following sequence of events are expected: <br>
     *  - MouseButtonDown (first click) <br>
     *  - MouseButtonUp <br>
     *  - MouseDoubleClick (second click) <br>
     *  - MouseButtonUp <br>
     * {@link <a href="https://docs.microsoft.com/en-us/windows/win32/learnwin32/mouse-clicks#double-clicks">See</a>}
     * @return Returns true if event was handled
     */
    public final boolean mouseDoubleClick(final int x, final int y, final NSGui_MouseButton button) {
        return nativeMouseDoubleClick(getPtr(), x, y, button.ordinal());
    }

    /**
     * Notifies that mouse was moved. Origin is in the upper-left corner.
     * @return Returns true if event was handled
     */
    public final boolean mouseMove(final int x, final int y) {
        return nativeMouseMove(getPtr(), x, y);
    }

    /**
     * Notifies that mouse vertical wheel was rotated. Origin is in the upper-left corner
     * The parameter wheelRotation indicates the distance the wheel is rotated, expressed in
     * multiples or divisions of 120 (is the default value for 3 lines of scrolling). A positive
     * value indicates that the wheel was rotated forward, away from the user; a negative value
     * indicates that the wheel was rotated backward, toward the user.
     * @return Returns true if event was handled
     */
    public final boolean mouseWheel(final int x, final int y, final int wheelRotation) {
        return nativeMouseWheel(getPtr(), x, y, wheelRotation);
    }

    /**
     * Notifies that mouse horizontal wheel was rotated. Origin is in the upper-left corner
     * The parameter wheelRotation indicates the distance the wheel is rotated, expressed in
     * multiples or divisions of 120 (is the default value for 3 lines of scrolling). A positive
     * value indicates that the wheel was rotated to the right; a negative value indicates that
     * the wheel was rotated to the left.
     * @return Returns true if event was handled
     */
    public final boolean mouseHWheel(final int x, final int y, final int wheelRotation) {
        return nativeMouseHWheel(getPtr(), x, y, wheelRotation);
    }

    /**
     * Notifies that a vertical scroll is being actioned. This is normally mapped to a gamepad
     * stick. Value ranges from -1.0 (fully pushed down) to +1.0 (fully pushed up). The value
     * is internally adjusted to be frame-rate independent. No dead zone filtering is applied.
     * Raises the event on the focused element.
     * @return Returns true if event was handled
     */
    public final boolean scroll(final float value) {
        return nativeScroll(getPtr(), value);
    }

    /**
     * Notifies that a vertical scroll is being actioned. This is normally mapped to a gamepad
     * stick. Value ranges from -1.0 (fully pushed down) to +1.0 (fully pushed up). The value
     * is internally adjusted to be frame-rate independent. No dead zone filtering is applied.
     * Raises the event on the element under the specified x,y.
     * @return Returns true if event was handled
     */
    public final boolean scroll(final int x, final int y, final float value) {
        return nativeScrollPos(getPtr(), x ,y, value);
    }

    /**
     * Notifies that a horizontal scroll is being actioned. This is normally mapped to a gamepad
     * stick. Value ranges from -1.0 (fully pushed left) to +1.0 (fully pushed right). The value
     * is internally adjusted to be frame-rate independent. No dead zone filtering is applied.
     * Raises the event on the focused element.
     * @return Returns true if event was handled
     */
    public final boolean HScroll(final float value) {
        return nativeHScroll(getPtr(), value);
    }

    /**
     * Notifies that a horizontal scroll is being actioned. This is normally mapped to a gamepad
     * stick. Value ranges from -1.0 (fully pushed left) to +1.0 (fully pushed right). The value
     * is internally adjusted to be frame-rate independent. No dead zone filtering is applied.
     * Raises the event on the element under the specified x,y.
     * @return Returns true if event was handled
     */
    public final boolean HScroll(final int x, final int y, final float value) {
        return nativeHScrollPos(getPtr(), x, y, value);
    }

    /**
     * Notifies that a finger touched the screen. Origin is in the upper-left corner.
     * @return Returns true if event was handled
     */
    public final boolean touchDown(final int x, final int y, long id) {
        return nativeTouchDown(getPtr(), x, y, id);
    }

    /**
     * Notifies that a finger moved on the screen. Origin is in the upper-left corner.
     * @return Returns true if event was handled
     */
    public final boolean touchMove(final int x, final int y, long id) {
        return nativeTouchMove(getPtr(), x, y, id);
    }

    /**
     * Notifies that a finger raised off of the screen. Origin is in the upper-left corner.
     * @return Returns true if event was handled
     */
    public final boolean touchUp(final int x, final int y, long id) {
        return nativeTouchUp(getPtr(), x, y, id);
    }

    /**
     * Notifies that a key was initially pressed or repeatedly pressed
     * @return Returns true if event was handled
     */
    public final boolean keyDown(final NSGui_Key key) {
        return keyDown(key.value);
    }

    /**
     * Notifies that a key was initially pressed or repeatedly pressed
     * @return Returns true if event was handled
     */
    public final boolean keyDown(final int key_code) {
        return nativeKeyDown(getPtr(), key_code);
    }

    /**
     * Notifies that a key was released.
     * @return Returns true if event was handled
     */
    public final boolean keyUp(final NSGui_Key key) {
        return keyUp(key.value);
    }

    /**
     * Notifies that a key was released.
     * @return Returns true if event was handled
     */
    public final boolean keyUp(final int key_code) {
        return nativeKeyUp(getPtr(), key_code);
    }

    /**
     * Notifies that a key was translated to the corresponding unicode character. <br>
     * If a key is repeatedly pressed, its corresponding 'Char' event is sent again. <br>
     * 'Char' messages are expected to be sent between the corresponding 'Down' and 'Up' events: <br>
     *  - KeyDown <br>
     *  - Char <br>
     *  - KeyUp <br>
     * @return Returns true if event was handled
     */
    public final boolean charEvent(final long ch) {
        return nativeChar(getPtr(), ch);
    }

    /**
     * Performs a layout pass and records UI changes into a snapshot to be consumed by the renderer.
     * Successive UI state changes won't be visible by the renderer until a new snapshot is taken.
     * Returns false to indicate no state changes were detected and rendering is not necessary.
     * A balance must be kept between invocations of Update() returning true and UpdateRenderTree()
     * Note that the initial update to a view establishes its origin time, which serves as the
     * reference point for calculating delta times. If you wish to position a newly created view
     * at a specific time, two updates are necessary: the first with a timestamp of 0.0
     * (Update(0.0)), and the second with the desired seek time (Update(seekTime))
     */
    public final boolean update(final double timeInSeconds) {
        return nativeUpdate(getPtr(), timeInSeconds);
    }

//    TODO: Add events
//    /// Rendering event occurs after animation and layout have been applied to the composition
//    /// tree, just before objects in the composition tree are rendered
//    typedef Delegate<void (IView* view)> RenderingEventHandler;
//    virtual RenderingEventHandler& Rendering() = 0;
//
//    /// Creates a timer that will be fired at the given milliseconds interval. Returns an ID to
//    /// handle restarts and cancellations. The callback returns the next interval or just 0 to stop
//    typedef Delegate<uint32_t ()> TimerCallback;
//    virtual uint32_t CreateTimer(uint32_t interval, const TimerCallback& callback) = 0;

    /**
     * Restarts specified timer with a new interval in milliseconds
     */
    public final void restartTimer(final long timerId, final long interval) {
        nativeRestartTimer(getPtr(), timerId, interval);
    }

    /**
     * Cancels specified timer
     */
    public final void cancelTimer(final long timerId) {
        nativeCancelTimer(getPtr(), timerId);
    }

    /**
     * Gets performance counters for the last rendered frame
     */
    public final NSViewStats getStats() {
        final NSViewStats stats = new NSViewStats();
        getStats(stats);
        return stats;
    }

    /**
     * Gets performance counters for the last rendered frame
     */
    public final void getStats(final NSViewStats out) {
        nativeGetStats(getPtr(), out);
    }


    private static native long nativeGetRenderer(long ptr);
    private static native long nativeGetContent(long ptr);
    private static native void nativeSetScale(long ptr, float scale);
    private static native void nativeSetSize(long ptr, long w, long h);
    private static native void nativeSetTessellationMaxPixelError(long ptr, NSTessellationMaxPixelError error);
    private static native void nativeGetTessellationMaxPixelError(long ptr, NSTessellationMaxPixelError error);
    private static native void nativeSetFlags(long ptr, int flags);
    private static native long nativeGetFlags(long ptr);
    private static native void nativeSetHoldingTimeThreshold(long ptr, long milliseconds);
    private static native void nativeSetHoldingDistanceThreshold(long ptr, long pixels);
    private static native void nativeSetManipulationDistanceThreshold(long ptr, long pixels);
    private static native void nativeSetDoubleTapTimeThreshold(long ptr, long milliseconds);
    private static native void nativeSetDoubleTapDistanceThreshold(long ptr, long pixels);
    private static native void nativeSetProjectionMatrix(long ptr, NSMatrix4 mtx);
    private static native void nativeSetStereoOffscreenScaleFactor(long ptr, float factor);
    private static native void nativeActivate(long ptr);
    private static native void nativeDeactivate(long ptr);
    private static native void nativeSetEmulateTouch(long ptr, boolean emulate);
    private static native boolean nativeMouseButtonDown(long ptr, int x, int y, int button);
    private static native boolean nativeMouseButtonUp(long ptr, int x, int y, int button);
    private static native boolean nativeMouseDoubleClick(long ptr, int x, int y, int button);
    private static native boolean nativeMouseMove(long ptr, int x, int y);
    private static native boolean nativeMouseWheel(long ptr, int x, int y, int wheel);
    private static native boolean nativeMouseHWheel(long ptr, int x, int y, int wheel);
    private static native boolean nativeScroll(long ptr, float value);
    private static native boolean nativeScrollPos(long ptr, int x, int y, float value);
    private static native boolean nativeHScroll(long ptr, float value);
    private static native boolean nativeHScrollPos(long ptr, int x, int y, float value);
    private static native boolean nativeTouchDown(long ptr, int x, int y, long id);
    private static native boolean nativeTouchMove(long ptr, int x, int y, long id);
    private static native boolean nativeTouchUp(long ptr, int x, int y, long id);
    private static native boolean nativeKeyDown(long ptr, int key_code);
    private static native boolean nativeKeyUp(long ptr, int key_code);
    private static native boolean nativeChar(long ptr, long ch);
    private static native boolean nativeUpdate(long ptr, double value);
    private static native void nativeRestartTimer(long ptr, long id, long value);
    private static native void nativeCancelTimer(long ptr, long id);
    private static native void nativeGetStats(long ptr, NSViewStats stats);
}

