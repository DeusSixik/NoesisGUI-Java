package dev.sixik.noesisgui.nsdrawing;

import dev.sixik.noesisgui.nsmath.NSVector2;

public final class NSPoint extends NSVector2 {

    public NSPoint() {
        this(0);
    }

    public NSPoint(float values) {
        super(values);
    }

    public NSPoint(NSVector2 vector2) {
        super(vector2);
    }

    public NSPoint(NSPoint point) {
        super(point.x, point.y);
    }

    public NSPoint(float xx, float yy) {
        super(xx, yy);
    }

    @Override
    public String toString() {
        return "NSPoint{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}
