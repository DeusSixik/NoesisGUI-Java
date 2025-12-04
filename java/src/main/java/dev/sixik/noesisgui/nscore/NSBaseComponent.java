package dev.sixik.noesisgui.nscore;

public class NSBaseComponent extends NSBaseRefCounted {

    public NSBaseComponent(long ptr) {
        super(ptr);
    }

    /**
     * Deletes an object from memory. Call it only if you have created this object and NoesisGui
     * does not have the ability to manage the object.
     */
    public final void destroy() {
        nativeDestroy();
    }

    private native void nativeDestroy();
}
