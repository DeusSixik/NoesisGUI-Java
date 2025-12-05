package dev.sixik.noesisgui.nsgui;

import java.util.Objects;

public class NSThickness {

    public float left;
    public float top;
    public float right;
    public float bottom;

    public NSThickness() {
        this(0);
    }

    public NSThickness(float thickness) {
        this(thickness, thickness);
    }

    public NSThickness(float lr, float tb) {
        this(lr, tb, lr, tb);
    }

    public NSThickness(float l, float t, float r, float b) {
        this.left = l;
        this.top = t;
        this.right = r;
        this.bottom = b;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        NSThickness that = (NSThickness) o;
        return Float.compare(left, that.left) == 0 && Float.compare(top, that.top) == 0 && Float.compare(right, that.right) == 0 && Float.compare(bottom, that.bottom) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(left, top, right, bottom);
    }

    @Override
    public String toString() {
        return "NSThickness{" +
                "left=" + left +
                ", top=" + top +
                ", right=" + right +
                ", bottom=" + bottom +
                '}';
    }
}
