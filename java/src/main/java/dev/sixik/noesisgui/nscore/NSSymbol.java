package dev.sixik.noesisgui.nscore;

import dev.sixik.noesisgui.utils.PtrObject;

public class NSSymbol extends PtrObject implements AutoCloseable {

    public NSSymbol() {
        this(nativeCreate());
    }

    public NSSymbol(int index) {
        this(nativeCreateByIndex(index));
    }

    public NSSymbol(String name) {
        this(nativeCreateByName(name));
    }

    public NSSymbol(long ptr) {
        super(ptr);
    }

    public final boolean isNull() {
        return nativeIsNull(getPtr());
    }

    @Override
    public void close() {
        final long ptr = getPtr();
        if(ptr != 0) {
            nativeFree(ptr);
            ptrClear();
        }
    }

    private static native long nativeCreate();

    private static native long nativeCreateByIndex(int index);

    private static native long nativeCreateByName(String str);

    private static native void nativeFree(long ptr);

    private static native boolean nativeIsNull(long ptr);
}
