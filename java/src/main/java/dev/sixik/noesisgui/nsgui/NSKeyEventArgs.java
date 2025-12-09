package dev.sixik.noesisgui.nsgui;

public class NSKeyEventArgs extends NSKeyboardEventArgs {

    private final long ptr;

    public NSGui_Key key;
    public NSGui_Key originalKey;
    public NSGui_KeyStates keyStates;

    public NSKeyEventArgs(long source_ptr, long routedEvent_ptr, boolean handled,
                          long ptr, int key, int originalkey, int state) {
        this(source_ptr, routedEvent_ptr, handled, ptr, NSGui_Key.values()[key], NSGui_Key.values()[originalkey], NSGui_KeyStates.values()[state]);
    }

    public NSKeyEventArgs(long source_ptr, long routedEvent_ptr, boolean handled,
                          long ptr, NSGui_Key key, NSGui_Key originalKey, NSGui_KeyStates keyStates) {
        super(source_ptr, routedEvent_ptr, handled);
        this.ptr = ptr;
        this.key = key;
        this.originalKey = originalKey;
        this.keyStates = keyStates;
    }

    public long getPtr() {
        return ptr;
    }

    private static native boolean nGetIsDown(long ptr);

    private static native boolean nGetIsRepeat(long ptr);

    private static native boolean nGetIsToggled(long ptr);

    private static native boolean nGetIsUp(long ptr);
}
