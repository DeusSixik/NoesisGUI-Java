package dev.sixik.noesisgui.nsmath;

import java.util.Objects;

public final class NSTransform2 {

    public float m00;
    public float m01;
    public float m10;
    public float m11;
    public float m20;
    public float m21;

    public NSTransform2(final float value) {
        this(value, value, value, value, value, value);
    }

    public NSTransform2(final NSVector2 vec1, final NSVector2 vec2, final NSVector2 vec3) {
        this(vec1.x, vec1.y, vec2.x, vec2.y, vec3.x, vec3.y);
    }

    public NSTransform2(final NSVector3 vec1, final NSVector3 vec2) {
        this(vec1.x, vec1.y, vec1.z, vec2.x, vec2.y, vec2.z);
    }

    public NSTransform2(final NSTransform2 transform) {
        this(transform.m00, transform.m01, transform.m10, transform.m11, transform.m20, transform.m21);
    }

    public NSTransform2(final float m00, final float m01, final float m10, final float m11, final float m20, final float m21) {
        this.m00 = m00;
        this.m01 = m01;
        this.m10 = m10;
        this.m11 = m11;
        this.m20 = m20;
        this.m21 = m21;
    }

    public float[] toArray() {
        return new float[] {m00, m01, m10, m11, m20, m21};
    }

    public NSVector2[] toVecArray() {
        return new NSVector2[] {new NSVector2(m00, m01), new NSVector2(m10, m11), new NSVector2(m20, m21)};
    }

    public NSMatrix2 rotation() {
        return new NSMatrix2(m00);
    }

    public NSVector2 translation() {
        return new NSVector2(m10);
    }

    public NSMatrix3 toMatrix3() {
        return new NSMatrix3(new NSVector3(m00, m01, 0), new NSVector3(m10, m11, 0), new NSVector3(m20, m21, 0));
    }

    public NSTransform2 mul(final float value) {
        m00 *= value;
        m01 *= value;
        m10 *= value;
        m11 *= value;
        m20 *= value;
        m21 *= value;
        return this;
    }

    public NSTransform2 mul(final NSTransform2 m) {
        m00 = m00 * m.m00 + m01 * m.m10;
        m01 = m00 * m.m01 + m01 * m.m11;
        m10 = m10 * m.m00 + m11 * m.m10;
        m11 = m10 * m.m01 + m11 * m.m11;
        m20 = m20 * m.m00 + m21 * m.m10 + m.m20;
        m21 = m20 * m.m01 + m21 * m.m11 + m.m21;
        return this;
    }

    public NSTransform2 div(final float value) {
        m00 /= value;
        m01 /= value;
        m10 /= value;
        m11 /= value;
        m20 /= value;
        m21 /= value;
        return this;
    }

    public NSTransform2 rotateAt(final float radians, final float centerX, final float centerY) {
        return postTrans(-centerX, -centerY).postRot(radians).postTrans(centerX, centerY);
    }

    public NSTransform2 scaleAt(final float scaleX, final float scaleY, final float centerX, final float centerY) {
        return postTrans(-centerX, -centerY).postScale(scaleX, scaleY).postTrans(centerX, centerY);
    }

    public NSTransform2 translate(final float dx, final float dy) {
        return postTrans(dx, dy);
    }

    public NSTransform2 postScale(final float scaleX, final float scaleY) {
        return new NSTransform2(
                m00 * scaleX, m01 * scaleY,
                m10 * scaleX, m11 * scaleY,
                m20 * scaleX, m21 * scaleY
        );
    }

    public NSTransform2 postTrans(final float transX, final float transY) {
        return new NSTransform2(
                m00, m01,
                m10, m11,
                m20 + transX, m21 + transY
        );
    }

    public NSTransform2 postRot(final float radians) {
        final float cs = (float) Math.cos(radians);
        final float sn = (float) Math.sin(radians);

        return new NSTransform2(
                m00 * cs - m01 * sn, m01 * cs + m00 * sn,
                m10 * cs - m11 * sn, m11 * cs + m10 * sn,
                m20 * cs - m21 * sn, m21 * cs + m20 * sn
        );
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        NSTransform2 that = (NSTransform2) o;
        return Float.compare(m00, that.m00) == 0 && Float.compare(m01, that.m01) == 0 && Float.compare(m10, that.m10) == 0 && Float.compare(m11, that.m11) == 0 && Float.compare(m20, that.m20) == 0 && Float.compare(m21, that.m21) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(m00, m01, m10, m11, m20, m21);
    }

    @Override
    public String toString() {
        return "NSTransform2{" +
                "m00=" + m00 +
                ", m01=" + m01 +
                ", m10=" + m10 +
                ", m11=" + m11 +
                ", m20=" + m20 +
                ", m21=" + m21 +
                '}';
    }

    public static NSTransform2 identity() {
        return new NSTransform2(1f, 0f, 0f, 1f, 0f, 0f);
    }

    public static NSTransform2 scale(final float scaleX, final float scaleY) {
        return new NSTransform2(scaleX, 0, 0, scaleY, 0, 0);
    }

    public static NSTransform2 trans(final float transX, final float transY) {
        return new NSTransform2(1f, 0f, 0f, 1f, transX, transY);
    }

    public static NSTransform2 rot(final float radians) {
        final float cs = (float) Math.cos(radians);
        final float sn = (float) Math.sin(radians);
        return new NSTransform2(cs, sn, -sn, cs, 0, 0);
    }

    public static NSTransform2 shearXY(final float shear) {
        return new NSTransform2(1f, 0f, shear, 0f, 0f, 0f);
    }

    public static NSTransform2 shearYX(final float shear) {
        return new NSTransform2(1f, shear, 0f, 1f, 0f, 0f);
    }
}


