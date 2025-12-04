package dev.sixik.noesisgui.nscore;

public class NSBaseRefCounted extends NSBaseObject {

    public NSBaseRefCounted(long ptr) {
        super(ptr);
    }

    /**
     * Increments reference count and returns the new value
     */
    public final void addReference() {
        nativeAddReference(getPtr());
    }

    /**
     * Decrements reference count and returns the new value
     * When the reference count on an object reaches zero, it is deleted
     */
    public final void release() {
        nativeRelease(getPtr());
    }

    /**
     * Gets current reference count for the object
     */
    public final long getNumReferences() {
        return nativeGetNumReferences(getPtr());
    }

    private static native long nativeAddReference(long ptr);

    private static native long nativeRelease(long ptr);

    private static native long nativeGetNumReferences(long ptr);
}
