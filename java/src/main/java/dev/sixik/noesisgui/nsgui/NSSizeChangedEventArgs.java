package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nsdrawing.NSSize;

public class NSSizeChangedEventArgs extends NSRoutedEventArgs {

    public final NSSize newSize;
    public final NSSize previousSize;
    public boolean widthChanged;
    public boolean heightChanged;

    public NSSizeChangedEventArgs(long source_ptr, long routedEvent_ptr, boolean handled,
                                  NSSize newSize, NSSize previousSize,
                                  boolean widthChanged, boolean heightChanged) {
        super(source_ptr, routedEvent_ptr, handled);
        this.newSize = newSize;
        this.previousSize = previousSize;
        this.widthChanged = widthChanged;
        this.heightChanged = heightChanged;
    }
}
