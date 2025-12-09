package dev.sixik.noesisgui.nsgui;

public class NSKeyboardEventArgs extends NSInputEventArgs{

    public NSKeyboardEventArgs(long source_ptr, long routedEvent_ptr, boolean handled) {
        super(source_ptr, routedEvent_ptr, handled);
    }
}
