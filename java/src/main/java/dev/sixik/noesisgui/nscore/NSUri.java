package dev.sixik.noesisgui.nscore;

public class NSUri {

    private static native boolean nativeIsValid(long ptr);

    private static native boolean nativeIsAbsolute(long ptr);

    private static native String nativeFullPath(long ptr);
}
