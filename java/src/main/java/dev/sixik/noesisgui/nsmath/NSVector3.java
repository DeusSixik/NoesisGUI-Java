package dev.sixik.noesisgui.nsmath;

import java.util.Objects;

public final class NSVector3 {
    public float x;
    public float y;
    public float z;

    public NSVector3() {
        this(0);
    }

    public NSVector3(final float value) {
        this(value, value, value);
    }

    public NSVector3(final NSVector2 vector) {
        this(vector.x, vector.y, 0);
    }

    public NSVector3(final NSVector2 vector, final float z) {
        this(vector.x, vector.y, z);
    }

    public NSVector3(final NSVector3 vector) {
        this(vector.x, vector.y, vector.z);
    }

    public NSVector3(final float x, final float y, final float z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public float[] toArray() {
        return new float[] {x, y, z};
    }

    public NSVector3 plus(final float value) {
        this.x += value;
        this.y += value;
        this.z += value;
        return this;
    }

    public NSVector3 plus(final NSVector3 vector) {
        this.x += vector.x;
        this.y += vector.y;
        this.z += vector.z;
        return this;
    }

    public NSVector3 minus(final float value) {
        this.x -= value;
        this.y -= value;
        this.z -= value;
        return this;
    }

    public NSVector3 minus(final NSVector3 vector) {
        this.x -= vector.x;
        this.y -= vector.y;
        this.z -= vector.z;
        return this;
    }

    public NSVector3 mul(final float value) {
        this.x *= value;
        this.y *= value;
        this.z *= value;
        return this;
    }

    public NSVector3 mul(final NSVector3 vector) {
        this.x *= vector.x;
        this.y *= vector.y;
        this.z *= vector.z;
        return this;
    }

    public NSVector3 div(final float value) {
        this.x /= value;
        this.y /= value;
        this.z /= value;
        return this;
    }

    public NSVector3 div(final NSVector3 vector) {
        this.x /= vector.x;
        this.y /= vector.y;
        this.z /= vector.z;
        return this;
    }

    public NSVector2 xy() {
        return new NSVector2(x, y);
    }

    public NSVector2 xz() {
        return new NSVector2(x, z);
    }

    public NSVector2 yz() {
        return new NSVector2(y, z);
    }

    public float length() {
        return (float) Math.sqrt(x * x + y * y + z * z);
    }

    public float lengthSquared() {
        return x * x + y * y + z * z;
    }

    public NSVector3 normalize() {
        final float lenght = length();
        return new NSVector3(x / lenght, y / lenght, z / lenght);
    }

    public NSVector2 project() {
        return new NSVector2(x / z, y / z);
    }

    public float dot(final NSVector3 v1) {
        return x * v1.x + y * v1.y + z * v1.z;
    }

    public NSVector3 cross(final NSVector3 v1) {
        return new NSVector3(y * v1.z - z * v1.y, z * v1.x - x * v1.z, x * v1.y - y * v1.x);
    }

    @Override
    public String toString() {
        return "NSVector3{" +
                "x=" + x +
                ", y=" + y +
                ", z=" + z +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        NSVector3 nsVector3 = (NSVector3) o;
        return Float.compare(x, nsVector3.x) == 0 && Float.compare(y, nsVector3.y) == 0 && Float.compare(z, nsVector3.z) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y, z);
    }

    public static NSVector3 zero() {
        return new NSVector3();
    }

    public static NSVector3 xAxis() {
        return new NSVector3(1, 0, 0);
    }

    public static NSVector3 yAxis() {
        return new NSVector3(0, 1, 0);
    }

    public static NSVector3 zAxis() {
        return new NSVector3(0, 0, 1);
    }

}
