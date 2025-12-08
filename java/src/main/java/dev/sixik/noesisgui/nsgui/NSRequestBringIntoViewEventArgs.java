package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSDependencyObject;
import dev.sixik.noesisgui.nsdrawing.NSRect;

public class NSRequestBringIntoViewEventArgs extends NSRoutedEventArgs {

    private NSDependencyObject dependencyObject;

    public long targetObject_ptr;
    public NSRect targetRect = new NSRect();

    public NSRequestBringIntoViewEventArgs() {

    }

    public NSRequestBringIntoViewEventArgs(long source_ptr, long routedEvent_ptr, boolean handled, long targetObject_ptr, NSRect targetRect) {
        super(source_ptr, routedEvent_ptr, handled);
        this.targetObject_ptr = targetObject_ptr;
        this.targetRect = targetRect;
    }

    public final NSDependencyObject getTargetObject() {
        if (targetObject_ptr == 0)
            return null;

        if (dependencyObject == null)
            dependencyObject = new NSDependencyObject(targetObject_ptr);
        else if (dependencyObject.getPtr() != targetObject_ptr) {
            dependencyObject = new NSDependencyObject(targetObject_ptr);
        }

        return dependencyObject;
    }

}
