package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nsdrawing.NSPoint;

public class NSMouseButtonEventArgs extends NSMouseEventArgs{

    public NSGui_MouseButton changedButton;
    public NSGui_MouseButtonState buttonState;
    public long clickCount;

    public NSMouseButtonEventArgs(long source_ptr,
                                  long routedEvent_ptr,
                                  boolean handled,
                                  NSPoint position, int leftButton, int middleButton,
                                  int rightButton, int xButton1Button, int xButton2Button, int changedButton, int buttonState, long clickCount) {
        this(source_ptr, routedEvent_ptr, handled, position, leftButton, middleButton, rightButton, xButton1Button, xButton2Button,
                NSGui_MouseButton.values()[changedButton], NSGui_MouseButtonState.values()[buttonState], clickCount);
    }

    public NSMouseButtonEventArgs(long source_ptr, long routedEvent_ptr, boolean handled, NSPoint position, int leftButton, int middleButton,
                                  int rightButton, int xButton1Button, int xButton2Button,
                                  NSGui_MouseButton changedButton, NSGui_MouseButtonState buttonState, long clickCount) {
        super(source_ptr, routedEvent_ptr, handled, position, leftButton, middleButton, rightButton, xButton1Button, xButton2Button);
        this.changedButton = changedButton;
        this.buttonState = buttonState;
        this.clickCount = clickCount;
    }
}
