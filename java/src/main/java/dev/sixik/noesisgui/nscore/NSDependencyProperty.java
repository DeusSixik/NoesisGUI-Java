package dev.sixik.noesisgui.nscore;

public class NSDependencyProperty extends NSBaseComponent{

    public NSDependencyProperty(long ptr) {
        super(ptr);
    }

    public static NSBaseComponent getUnsetValue() {
        return new NSBaseComponent(nativeGetUnsetValue());
    }

    public final String getName() {
        return nativeGetName(getPtr());
    }

    public final NSType getType() {
        return new NSType(nativeGetType(getPtr()));
    }

    public final NSTypeClass getOwnerType() {
        return new NSTypeClass(nativeGetOwnerType(getPtr()));
    }

    public final long getDefaultValue(final NSTypeClass typeClass) {
        return nativeGetDefaultValue(getPtr(), typeClass.getPtr());
    }

    public final boolean isReadOnly() {
        return nativeIsReadOnly(getPtr());
    }

    public final long getSize() {
        return nativeGetSize(getPtr());
    }

    private static native long nativeGetUnsetValue();

    private static native String nativeGetName(long ptr);

    private static native long nativeGetType(long ptr);

    private static native long nativeGetOwnerType(long ptr);

    private static native long nativeGetDefaultValue(long ptr, long typeClassPtr);

    private static native boolean nativeIsReadOnly(long ptr);

    private static native long nativeGetSize(long ptr);

    //TODO: Add other methods (Noesis::DependencyProperty)
}
