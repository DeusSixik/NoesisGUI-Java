package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSBaseComponent;

public class NSCursor extends NSBaseComponent {
    public NSCursor(long ptr) {
        super(ptr);
    }

    /**
     * Returns the cursor type
     */
    public final NSGui_CursorType type() {
        return NSGui_CursorType.values()[nType(getPtr())];
    }

    private static native int nType(long ptr);
}
