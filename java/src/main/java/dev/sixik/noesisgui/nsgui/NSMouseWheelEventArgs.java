package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nsdrawing.NSPoint;

public class NSMouseWheelEventArgs extends NSMouseEventArgs {

    public int wheelRotation;
    public NSGui_Orientation orientation;

    public NSMouseWheelEventArgs(long source_ptr, long routedEvent_ptr, boolean handled, NSPoint position,
                                 int leftButton, int middleButton, int rightButton, int xButton1Button,
                                 int xButton2Button, int wheelRotation, int orientation) {
        super(source_ptr, routedEvent_ptr, handled, position, leftButton, middleButton, rightButton, xButton1Button, xButton2Button);
        this.wheelRotation = wheelRotation;
        this.orientation = NSGui_Orientation.values()[orientation];
    }
}
