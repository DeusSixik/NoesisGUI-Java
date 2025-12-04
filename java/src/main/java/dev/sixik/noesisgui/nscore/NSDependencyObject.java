package dev.sixik.noesisgui.nscore;

public class NSDependencyObject extends NSDispatcherObject {

    public NSDependencyObject(long ptr) {
        super(ptr);
    }


    @Deprecated
    private static native long nativeCreate();

    @Deprecated
    private static native long nativeGetValueObject(long ptr, long dependencyPropertyPtr);

    @Deprecated
    private static native long nativeGetLocalValue(long ptr, long dependencyPropertyPtr);
}
