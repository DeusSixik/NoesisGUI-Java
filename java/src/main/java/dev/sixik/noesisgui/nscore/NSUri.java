package dev.sixik.noesisgui.nscore;

public class NSUri {

    private final long ptr;

    public NSUri(long ptr) {
        this.ptr = ptr;
    }

    public long getPtr() {
        return ptr;
    }

    private static native boolean nativeIsValid(long ptr);

    private static native boolean nativeIsAbsolute(long ptr);

    private static native String nativeFullPath(long ptr);
}
