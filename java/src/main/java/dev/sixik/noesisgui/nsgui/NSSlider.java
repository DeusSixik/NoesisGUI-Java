package dev.sixik.noesisgui.nsgui;

/**
 * Represents a control that lets the user select from a range of values by moving a Thumb
 * control along a Track.
 *
 * @see <a href="http://msdn.microsoft.com/en-us/library/system.windows.controls.slider.aspx">
 * Microsoft Documentation: Slider Class</a>
 */
public class NSSlider extends NSRangeBase {

    public NSSlider() {
        this(nCreate());
    }

    public NSSlider(long ptr) {
        super(ptr);
    }

    /**
     * Gets or sets the amount of time in milliseconds that a RepeatButton waits, while it is
     * pressed, before a command to move the Thumb executes, such as a *DecreaseLarge* command
     */
    public final int getDelay() {
        return nGetDelay(getPtr());
    }

    /**
     * Gets or sets the amount of time in milliseconds that a RepeatButton waits, while it is
     * pressed, before a command to move the Thumb executes, such as a *DecreaseLarge* command
     */
    public final void setDelay(final int delay) {
        nSetDelay(getPtr(), delay);
    }

    /**
     * Gets or sets the amount of time in milliseconds between increase or decrease commands when
     * a user clicks the RepeatButton of a Slider
     */
    public final int getInterval() {
        return nGetInterval(getPtr());
    }

    /**
     * Gets or sets the amount of time in milliseconds between increase or decrease commands when
     * a user clicks the RepeatButton of a Slider
     */
    public final void setInterval(final int value) {
        nSetInterval(getPtr(), value);
    }

    /**
     * Gets or sets the direction of increasing value
     */
    public final boolean getIsDirectionReversed() {
        return nGetIsDirectionReversed(getPtr());
    }

    /**
     * Gets or sets the direction of increasing value
     */
    public final void setIsDirectionReversed(final boolean value) {
        nSetIsDirectionReversed(getPtr(), value);
    }

    /**
     * Gets or sets a value that indicates whether the Thumb of a Slider moves immediately to the
     * location of the mouse click that occurs while the mouse pointer pauses on the Slider track
     */
    public final boolean getIsMoveToPointEnabled() {
        return nGetIsMoveToPointEnabled(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether the Thumb of a Slider moves immediately to the
     * location of the mouse click that occurs while the mouse pointer pauses on the Slider track
     */
    public final void setIsMoveToPointEnabled(final boolean value) {
        nSetIsMoveToPointEnabled(getPtr(), value);
    }

    /**
     * Gets or sets a value that indicates whether the Slider displays a selection range along the
     * Slider
     */
    public final boolean getIsSelectionRangeEnabled() {
        return nGetIsSelectionRangeEnabled(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether the Slider displays a selection range along the
     * Slider
     */
    public final void setIsSelectionRangeEnabled(final boolean value) {
        nSetIsSelectionRangeEnabled(getPtr(), value);
    }

    /**
     * Gets or sets a value that indicates whether the Slider automatically moves the Thumb to the
     * closest tick mark
     */
    public final boolean getIsSnapToTickEnabled() {
        return nGetIsSnapToTickEnabled(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether the Slider automatically moves the Thumb to the
     * closest tick mark
     */
    public final void setIsSnapToTickEnabled(final boolean value) {
        nSetIsSnapToTickEnabled(getPtr(), value);
    }

    /**
     * Gets or sets the orientation of a Slider
     */
    public final NSGui_Orientation getOrientation() {
        return NSGui_Orientation.values()[nGetOrientation(getPtr())];
    }

    /**
     * Gets or sets the orientation of a Slider
     */
    public final void setOrientation(final NSGui_Orientation orientation) {
        nSetOrientation(getPtr(), orientation.ordinal());
    }

    /**
     * Gets or sets the largest value of a specified selection for a Slider
     */
    public final float getSelectionEnd() {
        return nGetSelectionEnd(getPtr());
    }

    /**
     * Gets or sets the largest value of a specified selection for a Slider
     */
    public final void setSelectionEnd(final float value) {
        nSetSelectionEnd(getPtr(), value);
    }

    /**
     * Gets or sets the smallest value of a specified selection for a Slider
     */
    public final float getSelectionStart() {
        return nGetSelectionStart(getPtr());
    }

    /**
     * Gets or sets the smallest value of a specified selection for a Slider
     */
    public final void setSelectionStart(final float value) {
        nSetSelectionStart(getPtr(), value);
    }

    /**
     * Gets or sets the interval between tick marks
     */
    public final float getTickFrequency() {
        return nGetTickFrequency(getPtr());
    }

    /**
     * Gets or sets the interval between tick marks
     */
    public final void setTickFrequency(final float value) {
        nSetTickFrequency(getPtr(), value);
    }

    /**
     * Gets or sets the position of tick marks with respect to the Track of the Slider
     */
    public final NSGui_TickPlacement getTickPlacement() {
        return NSGui_TickPlacement.values()[nGetTickPlacement(getPtr())];
    }

    /**
     * Gets or sets the position of tick marks with respect to the Track of the Slider
     */
    public final void setTickPlacement(final NSGui_TickPlacement placement) {
        nSetTickPlacement(getPtr(), placement.ordinal());
    }

    /**
     * Gets or sets the positions of the tick marks to display for a Slider
     */
    public final String getTicks() {
        return nGetTicks(getPtr());
    }

    /**
     * Gets or sets the positions of the tick marks to display for a Slider
     */
    public final void setTicks(final String value) {
        nSetTicks(getPtr(), value);
    }

    /**
     * Gets the Track for a Slider control
     */
    public final NSTrack getTrack() {
        return new NSTrack(nGetTrack(getPtr()));
    }

    private static native long nCreate();

    private static native int nGetDelay(long ptr);

    private static native void nSetDelay(long ptr, int value);

    private static native int nGetInterval(long ptr);

    private static native void nSetInterval(long ptr, int value);

    private static native boolean nGetIsDirectionReversed(long ptr);

    private static native void nSetIsDirectionReversed(long ptr, boolean value);

    private static native boolean nGetIsMoveToPointEnabled(long ptr);

    private static native void nSetIsMoveToPointEnabled(long ptr, boolean value);

    private static native boolean nGetIsSelectionRangeEnabled(long ptr);

    private static native void nSetIsSelectionRangeEnabled(long ptr, boolean value);

    private static native boolean nGetIsSnapToTickEnabled(long ptr);

    private static native void nSetIsSnapToTickEnabled(long ptr, boolean value);

    private static native int nGetOrientation(long ptr);

    private static native void nSetOrientation(long ptr, int value);

    private static native float nGetSelectionEnd(long ptr);

    private static native void nSetSelectionEnd(long ptr, float value);

    private static native float nGetSelectionStart(long ptr);

    private static native void nSetSelectionStart(long ptr, float value);

    private static native float nGetTickFrequency(long ptr);

    private static native void nSetTickFrequency(long ptr, float value);

    private static native int nGetTickPlacement(long ptr);

    private static native void nSetTickPlacement(long ptr, int value);

    private static native String nGetTicks(long ptr);

    private static native void nSetTicks(long ptr, String value);

    private static native long nGetTrack(long ptr);
}
