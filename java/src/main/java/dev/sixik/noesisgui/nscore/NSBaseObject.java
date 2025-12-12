package dev.sixik.noesisgui.nscore;

import dev.sixik.noesisgui_impl.PtrSupport;

import java.util.Objects;

/**
 * Base class for all Noesis polymorphic objects
 */
public class NSBaseObject implements PtrSupport {

    private long ptr;

    public NSBaseObject(long ptr) {
        this.ptr = ptr;
    }

    public final long getPtr() {
        return ptr;
    }

    public final void clearPtr() {
        ptr = 0;
    }

    /**
     * Check is nullptr
     */
    public final boolean isNullPtr()  {
        return ptr == 0;
    }

    /**
     * For tracking alive objects
     */
    public static void trackCollectTypenames() {
        nativeTrackCollectTypenames();
    }

    /**
     * For tracking alive objects
     */
    public static boolean trackDumpObjects(final boolean finalizing) {
        return nativeTrackDumpObjects(finalizing);
    }

    /**
     * Gets the class type information
     */
    public final NSTypeClass getClassType() {
        return new NSTypeClass(nativeGetClassType(getPtr()));
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        NSBaseObject that = (NSBaseObject) o;
        return ptr == that.ptr;
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(ptr);
    }

    @Override
    public String toString() {
        return nativeToString(getPtr());
    }

    private static native void nativeTrackCollectTypenames();

    private static native boolean nativeTrackDumpObjects(final boolean finalizing);

    private static native long nativeGetClassType(long ptr);

    private static native String nativeToString(long ptr);
}
