package dev.sixik.noesisgui.nsrenderer;

public class NSImage {

    private final long ptr;

    public NSImage(long ptr) {
        this.ptr = ptr;
    }

    public long getPtr() {
        return ptr;
    }
}
