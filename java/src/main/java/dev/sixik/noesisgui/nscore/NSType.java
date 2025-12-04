package dev.sixik.noesisgui.nscore;

import dev.sixik.noesisgui.utils.PtrObject;

public class NSType extends PtrObject implements AutoCloseable {

    public NSType(int index) {
        this(new NSSymbol(index));
    }

    public NSType(String name) {
        this(new NSSymbol(name));
    }

    public NSType(NSSymbol symbol) {
        this(nativeCreate(symbol));
    }

    public NSType(long ptr) {
        super(ptr);
    }

    public final String getTypeId() {
        return nativeGetTypeId(getPtr());
    }

    @Override
    public void close() {
        final var ptr = getPtr();
        if(ptr != 0) {
            nativeFree(ptr);
            ptrClear();
        }
    }

    private static native long nativeCreate(NSSymbol symbol);

    private static native void nativeFree(long ptr);

    private static native String nativeGetTypeId(long ptr);
}
