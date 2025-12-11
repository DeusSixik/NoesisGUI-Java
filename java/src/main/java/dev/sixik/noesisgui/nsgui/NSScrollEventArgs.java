package dev.sixik.noesisgui.nsgui;

public class NSScrollEventArgs extends NSRoutedEventArgs {

    public final float newValue;
    public final NSGui_ScrollEventType scrollEventType;

    public NSScrollEventArgs(long source_ptr, long routedEvent_ptr, boolean handled,
                             float newValue, int scrollEventType) {
        super(source_ptr, routedEvent_ptr, handled);
        this.newValue = newValue;
        this.scrollEventType = NSGui_ScrollEventType.values()[scrollEventType];
    }
}
