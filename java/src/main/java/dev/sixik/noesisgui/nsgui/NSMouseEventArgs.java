package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nsdrawing.NSPoint;

public class NSMouseEventArgs extends NSInputEventArgs{

    public NSPoint position;
    public NSGui_MouseButtonState leftButton;
    public NSGui_MouseButtonState middleButton;
    public NSGui_MouseButtonState rightButton;
    public NSGui_MouseButtonState xButton1Button;
    public NSGui_MouseButtonState xButton2Button;



    public NSMouseEventArgs(long source_ptr, long routedEvent_ptr, boolean handled,
                            NSPoint position,
                            int leftButton,
                            int middleButton,
                            int rightButton,
                            int xButton1Button,
                            int xButton2Button) {
        super(source_ptr, routedEvent_ptr, handled);
        this.position = position;
        this.leftButton = NSGui_MouseButtonState.values()[leftButton];
        this.middleButton = NSGui_MouseButtonState.values()[middleButton];
        this.rightButton = NSGui_MouseButtonState.values()[rightButton];
        this.xButton1Button = NSGui_MouseButtonState.values()[xButton1Button];
        this.xButton2Button = NSGui_MouseButtonState.values()[xButton2Button];
    }
}
