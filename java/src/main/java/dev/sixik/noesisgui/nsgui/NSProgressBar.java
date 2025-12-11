package dev.sixik.noesisgui.nsgui;

/**
 * Indicates the progress of an operation.
 *
 * @see <a href="http://msdn.microsoft.com/en-us/library/system.windows.controls.progressbar.aspx">
 * Microsoft Documentation: ProgressBar Class</a>
 */
public class NSProgressBar extends NSRangeBase {

    public NSProgressBar() {
        this(nCreate());
    }

    public NSProgressBar(long ptr) {
        super(ptr);
    }

    /**
     * Gets or sets whether the ProgressBar shows actual values or generic, continuous progress
     * feedback
     */
    public final boolean getIsIndeterminate() {
        return nGetIsIndeterminate(getPtr());
    }

    /**
     * Gets or sets whether the ProgressBar shows actual values or generic, continuous progress
     * feedback
     */
    public final void setIsIndeterminate(final boolean value) {
        nSetIsIndeterminate(getPtr(), value);
    }

    /**
     * Gets or sets the orientation of a ProgressBar: horizontal or vertical.
     */
    public final NSGui_Orientation getOrientation() {
        return NSGui_Orientation.values()[nGetOrientation(getPtr())];
    }

    /**
     * Gets or sets the orientation of a ProgressBar: horizontal or vertical.
     */
    public final void setOrientation(final NSGui_Orientation orientation) {
        nSetOrientation(getPtr(), orientation.ordinal());
    }


    private static native long nCreate();

    private static native boolean nGetIsIndeterminate(long ptr);

    private static native void nSetIsIndeterminate(long ptr, boolean value);

    private static native int nGetOrientation(long ptr);

    private static native void nSetOrientation(long ptr, int value);
}
