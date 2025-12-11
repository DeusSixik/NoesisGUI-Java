package dev.sixik.noesisgui.nsgui;

public class NSTrack extends NSFrameworkElement{
    public NSTrack(long ptr) {
        super(ptr);
    }

    /**
     * Gets the RepeatButton that decreases the *Value* property of the Track
     */
    public final NSRepeatButton getDecreaseRepeatButton() {
        return new NSRepeatButton(nGetDecreaseRepeatButton(getPtr()));
    }

    /**
     * Gets the RepeatButton that decreases the *Value* property of the Track
     */
    public final void setDecreaseRepeatButton(final NSRepeatButton button) {
        nSetDecreaseRepeatButton(getPtr(), button.getPtr());
    }

    /**
     * Gets the RepeatButton that increases the *Value* property of the Track class
     */
    public final NSRepeatButton getIncreaseRepeatButton() {
        return new NSRepeatButton(nGetIncreaseRepeatButton(getPtr()));
    }

    /**
     * Gets the RepeatButton that increases the *Value* property of the Track class
     */
    public final void setIncreaseRepeatButton(final NSRepeatButton button) {
        nSetIncreaseRepeatButton(getPtr(), button.getPtr());
    }

    /**
     * Gets or sets if the direction of increasing *Value* is reversed from the default direction
     */
    public final boolean getIsDirectionReversed() {
        return nGetIsDirectionReversed(getPtr());
    }

    /**
     * Gets or sets if the direction of increasing *Value* is reversed from the default direction
     */
    public final void setIsDirectionReversed(final boolean value) {
        nSetIsDirectionReversed(getPtr(), value);
    }

    public final float getMaximum() {
        return nGetMaximum(getPtr());
    }

    public final void setMaximum(final float value) {
        nSetMaximum(getPtr(), value);
    }

    private static native long nCreate();

    private static native long nGetDecreaseRepeatButton(long ptr);

    private static native void nSetDecreaseRepeatButton(long ptr, long button_ptr);

    private static native long nGetIncreaseRepeatButton(long ptr);

    private static native void nSetIncreaseRepeatButton(long ptr, long button_ptr);

    private static native boolean nGetIsDirectionReversed(long ptr);

    private static native void nSetIsDirectionReversed(long ptr, boolean value);

    private static native float nGetMaximum(long ptr);

    private static native void nSetMaximum(long ptr, float value);
}
