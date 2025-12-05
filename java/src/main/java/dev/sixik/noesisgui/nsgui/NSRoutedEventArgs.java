package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nscore.NSRoutedEvent;

public class NSRoutedEventArgs extends NSEventArgs {

    protected NSBaseComponent component;
    protected NSRoutedEvent event;

    public long source_ptr;
    public long routedEvent_ptr;
    public boolean handled = false;

    public NSRoutedEventArgs() {

    }

    public NSRoutedEventArgs(long source_ptr, long routedEvent_ptr, boolean handled) {
        this.source_ptr = source_ptr;
        this.routedEvent_ptr = routedEvent_ptr;
        this.handled = handled;
    }

    public NSBaseComponent getSource() {
        if (source_ptr == 0)
            return null;

        if (component == null)
            component = new NSBaseComponent(source_ptr);
        else if (component.getPtr() != source_ptr) {
            component = new NSBaseComponent(source_ptr);
        }

        return component;
    }

    public NSRoutedEvent getRoutedEvent() {
        if (routedEvent_ptr == 0)
            return null;

        if (event == null)
            event = new NSRoutedEvent(routedEvent_ptr);
        else if (event.getPtr() != routedEvent_ptr)
            event = new NSRoutedEvent(routedEvent_ptr);

        return event;
    }
}
