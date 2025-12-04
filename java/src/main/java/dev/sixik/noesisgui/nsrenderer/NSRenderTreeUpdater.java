package dev.sixik.noesisgui.nsrenderer;

public class NSRenderTreeUpdater {

    private final long ptr;

    public NSRenderTreeUpdater(long ptr) {
        this.ptr = ptr;
    }

    public long getPtr() {
        return ptr;
    }
}
