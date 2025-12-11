package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nshandlers.NSScrollEventHandler;

public class NSScrollBar extends NSRangeBase {

    public NSScrollBar() {
        this(nCreate());
    }

    public NSScrollBar(long ptr) {
        super(ptr);
    }

    /**
     * Gets or sets whether the ScrollBar is displayed horizontally or vertically
     */
    public final NSGui_Orientation getOrientation() {
        return NSGui_Orientation.values()[nGetOrientation(getPtr())];
    }

    /**
     * Gets or sets whether the ScrollBar is displayed horizontally or vertically
     */
    public final void setOrientation(final NSGui_Orientation orientation) {
        nSetOrientation(getPtr(), orientation.ordinal());
    }

    /**
     * Gets or sets the amount of the scrollable content that is currently visible
     */
    public final float getViewportSize() {
        return nGetViewportSize(getPtr());
    }

    /**
     * Gets or sets the amount of the scrollable content that is currently visible
     */
    public final void setViewportSize(final float value) {
        nSetViewportSize(getPtr(), value);
    }

    /**
     * Gets the Track for a ScrollBar control
     */
    public final NSTrack getTrack() {
        return new NSTrack(nGetTrack(getPtr()));
    }

    /**
     * Occurs one or more times as content scrolls in a ScrollBar when the user moves the Thumb by
     * using the mouse
     */
    public final void scrollEvent(final NSScrollEventHandler event) {
        nScroll(getPtr(), event);
    }

    private static native long nCreate();

    private static native int nGetOrientation(long ptr);

    private static native void nSetOrientation(long ptr, int value);

    private static native float nGetViewportSize(long ptr);

    private static native void nSetViewportSize(long ptr, float value);

    private static native long nGetTrack(long ptr);

    private static native void nScroll(long ptr, NSScrollEventHandler event);
}
