package dev.sixik.noesisgui.nsdrawing;

public final class NSSize {

    public float width;
    public float height;

    public NSSize() {
        this(0);
    }

    public NSSize(final float v) {
        this(v, v);
    }

    public NSSize(final float width, final float height) {
        this.width = width;
        this.height = height;
    }
}
