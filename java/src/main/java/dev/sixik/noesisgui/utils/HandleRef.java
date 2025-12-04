package dev.sixik.noesisgui.utils;

import java.util.Objects;

public final class HandleRef<T> {
    private final T wrapper;
    private final long ptr;

    public HandleRef(T wrapper, long ptr) {
        this.wrapper = wrapper;
        this.ptr = ptr;
    }

    public T wrapper() {
        return wrapper;
    }

    public long ptr() {
        return ptr;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj == null || obj.getClass() != this.getClass()) return false;
        var that = (HandleRef) obj;
        return Objects.equals(this.wrapper, that.wrapper) &&
                this.ptr == that.ptr;
    }

    @Override
    public int hashCode() {
        return Objects.hash(wrapper, ptr);
    }

    @Override
    public String toString() {
        return "HandleRef[" +
                "wrapper=" + wrapper + ", " +
                "ptr=" + ptr + ']';
    }
}
