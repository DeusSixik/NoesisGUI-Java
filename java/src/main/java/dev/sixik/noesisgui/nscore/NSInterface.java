package dev.sixik.noesisgui.nscore;

public class NSInterface {

    private final long ptr;

    public NSInterface(long ptr) {
        this.ptr = ptr;
    }

    public long getPtr() {
        return ptr;
    }

    /**
     * Gets the class type information
     */
    public final NSTypeClass getClassType() {
        return new NSTypeClass(nativeGetClassType(ptr));
    }

    /**
     * Returns a pointer to the BaseObject implementing this interface
     */
    public final NSBaseObject getBaseObject() {
        return new NSBaseObject(nativeGetBaseObject(ptr));
    }

    /**
     * Increments reference count and returns the new value
     */
    public final int addReference() {
        return nativeAddReference(ptr);
    }

    /**
     * Decrements reference count and returns the new value
     */
    public final int release() {
        return nativeRelease(ptr);
    }

    /**
     * Gets current reference count for the object
     */
    public final int getNumReferences() {
        return nativeGetNumReferences(ptr);
    }

    private static native long nativeGetClassType(long ptr);

    private static native long nativeGetBaseObject(long ptr);

    private static native int nativeAddReference(long ptr);

    private static native int nativeRelease(long ptr);

    private static native int nativeGetNumReferences(long ptr);
}
