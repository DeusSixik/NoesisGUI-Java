package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nshandlers.NSRoutedPropertyChangedEventHandler;

/**
 * Represents an element that has a value within a specific range.
 *
 * @see <a href="http://msdn.microsoft.com/en-us/library/system.windows.controls.primitives.rangebase.aspx">
 * Microsoft Documentation: RangeBase Class</a>
 * @since 1.0
 */
public class NSRangeBase extends NSControl {

    public NSRangeBase(long ptr) {
        super(ptr);
    }

    /**
     * Gets or sets a value to be added to or subtracted from the Value of a RangeBase control
     */
    public final float getLargeChange() {
        return nGetLargeChange(getPtr());
    }

    /**
     * Gets or sets a value to be added to or subtracted from the Value of a RangeBase control
     */
    public final void setLargeChange(final float value) {
        nSetLargeChange(getPtr(), value);
    }

    /**
     * Gets or sets the highest possible Value of the range element
     */
    public final float getMaximum() {
        return nGetMaximum(getPtr());
    }

    /**
     * Gets or sets the highest possible Value of the range element
     */
    public final void setMaximum(final float value) {
        nSetMaximum(getPtr(), value);
    }

    /**
     * Geets or sets the Minimum possible Value of the range lement
     */
    public final float getMinimum() {
        return nGetMinimum(getPtr());
    }

    /**
     * Geets or sets the Minimum possible Value of the range lement
     */
    public final void setMinimum(final float value) {
        nSetMinimum(getPtr(), value);
    }

    /**
     * Gets or sets a value to be added to or subtracted from the Value of a RangeBase control
     */
    public final float getSmallChange() {
        return nGetSmallChange(getPtr());
    }

    /**
     * Gets or sets a value to be added to or subtracted from the Value of a RangeBase control
     */
    public final void setSmallChange(final float value) {
        nSetSmallChange(getPtr(), value);
    }

    /**
     * Gets or sets the current magnitude of the range control
     */
    public final float getValue() {
        return nGetValue(getPtr());
    }

    /**
     * Gets or sets the current magnitude of the range control
     */
    public final void setValue(final float value) {
        nSetValue(getPtr(), value);
    }

    /**
     * Occurs when the range value changes
     */
    public final void valueChangedEvent(final NSRoutedPropertyChangedEventHandler<Float> eventHandler) {
        nValueChanged(getPtr(), eventHandler);
    }

    private static native float nGetLargeChange(long ptr);

    private static native void nSetLargeChange(long ptr, float value);

    private static native float nGetMaximum(long ptr);

    private static native void nSetMaximum(long ptr, float value);

    private static native float nGetMinimum(long ptr);

    private static native void nSetMinimum(long ptr, float value);

    private static native float nGetSmallChange(long ptr);

    private static native void nSetSmallChange(long ptr, float value);

    private static native float nGetValue(long ptr);

    private static native void nSetValue(long ptr, float value);

    private static native void nValueChanged(long ptr, NSRoutedPropertyChangedEventHandler<Float> event);
}
