package dev.sixik.noesisgui.utils;

public class PtrObject {

    private long ptr;

    public PtrObject(long ptr) {
        this.ptr = ptr;
    }

    public long getPtr() {
        return ptr;
    }

    protected void ptrClear() {
        ptr = 0;
    }

    /**
     * Check is nullptr
     */
    public final boolean isNullPtr()  {
        return ptr == 0;
    }
}
