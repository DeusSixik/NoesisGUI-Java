package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nsdrawing.NSRect;
import dev.sixik.noesisgui.nshandlers.NSRoutedEventHandler;

/**
 * Represents a pop-up menu that enables a control to expose functionality that is specific to
 * the context of the control.
 *
 * @see <a href="http://msdn.microsoft.com/en-us/library/system.windows.controls.contextmenu.aspx">
 * Microsoft Documentation: ContextMenu Class</a>
 */
public class NSContextMenu extends NSBaseMenu {

    public NSContextMenu() {
        this(nCreate());
    }

    public NSContextMenu(long ptr) {
        super(ptr);
    }

    /**
     * Gets or sets a value that indicates whether the context menu appears with a dropped shadow
     */
    public final boolean getHasDropShadow() {
        return nGetHasDropShadow(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether the context menu appears with a dropped shadow
     */
    public final void setHasDropShadow(final boolean value) {
        nSetHasDropShadow(getPtr(), value);
    }

    /**
     * Get or sets the horizontal distance between the target origin and the popup alignment point
     */
    public final float getHorizontalOffset() {
        return nGetHorizontalOffset(getPtr());
    }

    /**
     * Get or sets the horizontal distance between the target origin and the popup alignment point
     */
    public final void setHorizontalOffset(final float value) {
        nSetHorizontalOffset(getPtr(), value);
    }

    /**
     * Gets or sets a value that indicates whether the ContextMenu is visible
     */
    public final boolean getIsOpen() {
        return nGetIsOpen(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether the ContextMenu is visible
     */
    public final void setIsOpen(final boolean value) {
        nSetIsOpen(getPtr(), value);
    }

    /**
     * Gets or sets the Placement property of a ContextMenu
     */
    public final NSGui_PlacementMode getPlacement() {
        return NSGui_PlacementMode.values()[nGetPlacement(getPtr())];
    }

    /**
     * Gets or sets the Placement property of a ContextMenu
     */
    public final void setPlacement(final NSGui_PlacementMode mode) {
        nSetPlacement(getPtr(), mode.ordinal());
    }

    /**
     * Gets or sets the area relative to which the context menu is positioned when it opens
     */
    public final NSRect getPlacementRectangle() {
        final NSRect rect = new NSRect();
        getPlacementRectangle(rect);
        return rect;
    }

    /**
     * Gets or sets the area relative to which the context menu is positioned when it opens
     */
    public final void getPlacementRectangle(final NSRect rect) {
        nGetPlacementRectangle(getPtr(), rect);
    }

    /**
     * Gets or sets the area relative to which the context menu is positioned when it opens
     */
    public final void setPlacementRectangle(final NSRect rect) {
        nSetPlacementRectangle(getPtr(), rect);
    }

    /**
     * Gets or sets the UIElement relative to which the ContextMenu is positioned when it opens
     */
    public final NSUIElement getPlacementTarget() {
        return new NSUIElement(nGetPlacementTarget(getPtr()));
    }

    /**
     * Gets or sets the UIElement relative to which the ContextMenu is positioned when it opens
     */
    public final void setPlacementTarget(final NSUIElement target) {
        nSetPlacementTarget(getPtr(), target.getPtr());
    }

    /**
     * Gets or sets a value that indicates whether the ContextMenu should close automatically
     */
    public final boolean getStaysOpen() {
        return nGetStaysOpen(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether the ContextMenu should close automatically
     */
    public final void setStaysOpen(final boolean value) {
        nSetStaysOpen(getPtr(), value);
    }

    /**
     * Get or sets the vertical distance between the target origin and the popup alignment point
     */
    public final float getVerticalOffset() {
        return nGetVerticalOffset(getPtr());
    }

    /**
     * Get or sets the vertical distance between the target origin and the popup alignment point
     */
    public final void setVerticalOffset(final float value) {
        nSetVerticalOffset(getPtr(), value);
    }

    /**
     * Gets Popup where ContextMenu is shown
     */
    public final NSPopup getPopup() {
        return new NSPopup(nGetPopup(getPtr()));
    }

    /**
     * Occurs when a particular instance of a ContextMenu closes
     */
    public final void closedEvent(final NSRoutedEventHandler event) {
        nClosed(getPtr(), event);
    }

    /**
     * Occurs when a particular instance of a context menu opens
     */
    public final void openedEvent(final NSRoutedEventHandler event) {
        nOpened(getPtr(), event);
    }

    private static native long nCreate();

    private static native boolean nGetHasDropShadow(long ptr);

    private static native void nSetHasDropShadow(long ptr, boolean value);

    private static native float nGetHorizontalOffset(long ptr);

    private static native void nSetHorizontalOffset(long ptr, float value);

    private static native boolean nGetIsOpen(long ptr);

    private static native void nSetIsOpen(long ptr, boolean value);

    private static native int nGetPlacement(long ptr);

    private static native void nSetPlacement(long ptr, int value);

    private static native void nGetPlacementRectangle(long ptr, NSRect rect);

    private static native void nSetPlacementRectangle(long ptr, NSRect rect);

    private static native long nGetPlacementTarget(long ptr);

    private static native void nSetPlacementTarget(long ptr, long target_ptr);

    private static native boolean nGetStaysOpen(long ptr);

    private static native void nSetStaysOpen(long ptr, boolean value);

    private static native float nGetVerticalOffset(long ptr);

    private static native void nSetVerticalOffset(long ptr, float value);

    private static native long nGetPopup(long ptr);

    private static native void nClosed(long ptr, NSRoutedEventHandler event);

    private static native void nOpened(long ptr, NSRoutedEventHandler event);
}
