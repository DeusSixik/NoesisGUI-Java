package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nsdrawing.NSPoint;

public class NSQueryCursorEventArgs extends NSMouseEventArgs{

    public long cursor_ptr;

    public NSQueryCursorEventArgs(long source_ptr, long routedEvent_ptr, boolean handled, NSPoint position, int leftButton, int middleButton, int rightButton, int xButton1Button, int xButton2Button,
                                  long cursor_ptr) {
        super(source_ptr, routedEvent_ptr, handled, position, leftButton, middleButton, rightButton, xButton1Button, xButton2Button);
        this.cursor_ptr = cursor_ptr;
    }
}
