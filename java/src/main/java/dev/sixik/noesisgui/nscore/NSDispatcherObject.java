package dev.sixik.noesisgui.nscore;

public class NSDispatcherObject extends NSBaseComponent{

    public NSDispatcherObject(long ptr) {
        super(ptr);
    }

    /**
     * Gets the thread this DispatcherObject is associated with.
     * Returns NoThreadId when this object is not attached to any thread.
     */
    public final long getThreadId() {
        return nativeGetThreadId(getPtr());
    }

    /**
     * Determines whether the calling thread has access to this DispatcherObject
     */
    public final boolean checkAccess() {
        return nativeCheckAccess(getPtr());
    }

    /**
     * Enforces that the calling thread has access to this DispatcherObject
     */
    public final void verifyAccess() {
        nativeVerifyAccess(getPtr());
    }

    private static native boolean nativeCheckAccess(long ptr);

    private static native long nativeGetThreadId(long ptr);

    private static native void nativeVerifyAccess(long ptr);
}
