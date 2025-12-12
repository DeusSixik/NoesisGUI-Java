package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSBaseComponent;

public class NSRoutedPropertyChangedEventArgsBaseComponent extends NSRoutedPropertyChangedEventArgs<NSBaseComponent> {

    public NSRoutedPropertyChangedEventArgsBaseComponent(long source_ptr, long routedEvent_ptr, boolean handled, long oldValue, long newValue) {
        super(source_ptr, routedEvent_ptr, handled, new NSBaseComponent(oldValue), new NSBaseComponent(newValue));
    }
}
