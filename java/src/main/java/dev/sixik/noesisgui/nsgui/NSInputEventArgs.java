package dev.sixik.noesisgui.nsgui;

public class NSInputEventArgs extends NSRoutedEventArgs {

    public NSInputEventArgs(long source_ptr, long routedEvent_ptr, boolean handled) {
        super(source_ptr, routedEvent_ptr, handled);
    }
}
