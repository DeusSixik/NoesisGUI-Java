package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSDependencyProperty;
import dev.sixik.noesisgui.nsdrawing.NSColor;

/**
 * Describes the location and color of a transition point in a gradient.
 *
 * @see <a href="http://msdn.microsoft.com/en-us/library/system.windows.media.gradientstop.aspx">
 *      Microsoft Documentation: GradientStop Class</a>
 */
public class NSGradientStop extends NSAnimatable {

    public static final NSDependencyProperty ColorProperty = new NSDependencyProperty(nColorProperty());
    public static final NSDependencyProperty OffsetProperty = new NSDependencyProperty(nOffsetProperty());

    public NSGradientStop() {
        this(nCreate());
    }

    public NSGradientStop(final NSColor color) {
        this(nCreate());
        setColor(color);
    }

    public NSGradientStop(final NSColor color, final float offset) {
        this(nCreate());
        setColor(color);
        setOffset(offset);
    }

    public NSGradientStop(long ptr) {
        super(ptr);
    }

    /**
     * Gets or sets the color of the gradient stop
     */
    public final NSColor getColor() {
        final NSColor color = new NSColor();
        getColor(color);
        return color;
    }

    /**
     * Gets or sets the color of the gradient stop
     */
    public final void getColor(final NSColor color) {
        nGetColor(getPtr(), color);
    }

    /**
     * Gets or sets the color of the gradient stop
     */
    public final void setColor(final NSColor color) {
        nSetColor(getPtr(), color);
    }

    /**
     * Gets or sets the location of the gradient stop within the gradient vector
     */
    public final float getOffset() {
        return nGetOffset(getPtr());
    }

    /**
     * Gets or sets the location of the gradient stop within the gradient vector
     */
    public final void setOffset(final float value) {
        nSetOffset(getPtr(), value);
    }

    private static native long nCreate();

    private static native void nGetColor(long ptr, NSColor color);

    private static native void nSetColor(long ptr, NSColor color);

    private static native float nGetOffset(long ptr);

    private static native void nSetOffset(long ptr, float value);

    private static native long nColorProperty();

    private static native long nOffsetProperty();
}
