package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsdrawing.NSPointi;

public class NSMouse extends NSBaseComponent {

    private final NSPointi mousePos = new NSPointi(0);

    public NSMouse(long ptr) {
        super(ptr);
    }

    /**
     * Resets mouse state
     */
    public final void resetState() {
        nativeResetState(getPtr());
    }

    /**
     * Gets last mouse position
     */
    public final NSPointi getMousePos() {
        nativeGetPosition(getPtr(), mousePos);
        return mousePos;
    }

    /**
     * Gets the mouse position relative to the specified element
     */
    public static NSPointi getMousePos(final NSUIElement element) {
        final NSPointi pointi = new NSPointi(0);
        getMousePos(element, pointi);
        return pointi;
    }

    /**
     * Gets the mouse position relative to the specified element
     */
    public static void getMousePos(final NSUIElement element, final NSPointi point) {
        nativeGetPositionStatic(element.getPtr(), point);
    }

    /**
     * Gets the state of any mouse button
     */
    public final NSGui_MouseButtonState getButtonState(NSGui_MouseButton button) {
        return NSGui_MouseButtonState.values()[nativeGetButtonState(getPtr(), button.ordinal())];
    }

    /**
     * Tries to capture the mouse for the specified element
     */
    public final boolean capture(final NSUIElement element) {
        return capture(element, NSGui_CaptureMode.CaptureMode_Element);
    }

    /**
     * Tries to capture the mouse for the specified element
     */
    public final boolean capture(final NSUIElement element, final NSGui_CaptureMode mode) {
        return nativeCapture(getPtr(), element.getPtr(), mode.ordinal());
    }

    /**
     * Gets the captured mouse element
     */
    public final NSUIElement getCaptured() {
        return new NSUIElement(nativeGetCaptured(getPtr()));
    }

    private static native void nativeResetState(long ptr);

    private static native void nativeGetPosition(long ptr, NSPointi out);

    private static native void nativeGetPositionStatic(long ui_element_ptr, NSPointi out);

    private static native int nativeGetButtonState(long ptr, int button);

    private static native boolean nativeCapture(long ptr, long ui_element_ptr, int mode);

    private static native long nativeGetCaptured(long ptr);
}
