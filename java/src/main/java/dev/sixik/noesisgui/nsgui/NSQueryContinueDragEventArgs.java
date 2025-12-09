package dev.sixik.noesisgui.nsgui;

public class NSQueryContinueDragEventArgs extends NSRoutedEventArgs {

    public final boolean escapePressed;
    public final int keyStates;
    public final NSGui_DragAction action;

    public NSQueryContinueDragEventArgs(long source_ptr, long routedEvent_ptr, boolean handled, boolean escapePressed,
                                        int keyStates, int action) {
        super(source_ptr, routedEvent_ptr, handled);
        this.escapePressed = escapePressed;
        this.keyStates = keyStates;
        this.action = NSGui_DragAction.values()[action];
    }
}
