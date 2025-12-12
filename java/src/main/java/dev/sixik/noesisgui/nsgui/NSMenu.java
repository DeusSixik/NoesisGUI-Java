package dev.sixik.noesisgui.nsgui;

/**
 * Represents a Windows menu control that enables you to hierarchically organize elements
 * associated with commands and event handlers.
 *
 * @see <a href="http://msdn.microsoft.com/en-us/library/ms611602.aspx">
 * Microsoft Documentation: Menu Class</a>
 */
public class NSMenu extends NSBaseMenu {

    public NSMenu() {
        this(nCreate());
    }

    public NSMenu(long ptr) {
        super(ptr);
    }

    /**
     * Gets or sets a value that indicates whether this Menu receives a main menu activation
     * notification
     */
    public final boolean getIsMainMenu() {
        return nGetIsMainMenu(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether this Menu receives a main menu activation
     * notification
     */
    public final void setIsMainMenu(final boolean value) {
        nSetIsMainMenu(getPtr(), value);
    }

    /**
     * Gets or sets a value that indicates whether this Menu is activated and sub menu items
     * get opened when mouse moves over them
     */
    public final boolean getActivated() {
        return nGetActivated(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether this Menu is activated and sub menu items
     * get opened when mouse moves over them
     */
    public final void setActivated(final boolean value) {
        nSetActivated(getPtr(), value);
    }

    private static native long nCreate();

    private static native boolean nGetIsMainMenu(long ptr);

    private static native void nSetIsMainMenu(long ptr, boolean value);

    private static native boolean nGetActivated(long ptr);

    private static native void nSetActivated(long ptr, boolean value);
}
