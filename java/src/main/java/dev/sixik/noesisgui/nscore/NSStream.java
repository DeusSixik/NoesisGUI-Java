package dev.sixik.noesisgui.nscore;

public class NSStream extends NSBaseComponent{

    public NSStream(long ptr) {
        super(ptr);
    }

    /**
     * Set the current position within the stream
     */
    public final void setPosition(int pos) {
        nativeSetPosition(getPtr(), pos);
    }

    /**
     * Returns the current position within the stream
     */
    public final long getPosition() {
        return nativeGetPosition(getPtr());
    }

    /**
     * Returns the length of the stream in bytes
     */
    public final long getLength() {
        return nativeGetLength(getPtr());
    }

    /**
     * Reads data at the current position and advances it by the number of bytes read
     * Returns the total number of bytes read. This can be less than the number of bytes requested
     */
    public final long read(long buffer_ptr, int size) {
        return nativeRead(getPtr(), buffer_ptr, size);
    }

    /**
     * Returns the starting address for the whole data or null if not supported
     * It is recommended, especially when reading fonts, to return a non-null value
     */
    public final long getMemoryBase() {
        return nativeGetMemoryBase(getPtr());
    }

    /**
     * Closes the current stream and releases any resources associated with the current stream
     */
    public final void close() {
        nativeClose(getPtr());
    }

    private static native void nativeSetPosition(long ptr, int pos);

    private static native long nativeGetPosition(long ptr);

    private static native long nativeGetLength(long ptr);

    private static native long nativeRead(long ptr, long buffer_ptr, int size);

    private static native long nativeGetMemoryBase(long ptr);

    private static native void nativeClose(long ptr);
}
