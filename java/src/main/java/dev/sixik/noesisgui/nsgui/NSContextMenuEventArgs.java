package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSDependencyObject;

public class NSContextMenuEventArgs extends NSRoutedEventArgs{

    private NSDependencyObject object;

    public long targetElement_ptr;
    public float cursorLeft;
    public float cursorTop;

    public NSContextMenuEventArgs(long source_ptr, long routedEvent_ptr, boolean handled, long targetElement_ptr, float cursorLeft, float cursorTop) {
        super(source_ptr, routedEvent_ptr, handled);
        this.targetElement_ptr = targetElement_ptr;
        this.cursorLeft = cursorLeft;
        this.cursorTop = cursorTop;
    }

    public final NSDependencyObject getTargetElement() {
        if (targetElement_ptr == 0)
            return null;

        if (object == null)
            object = new NSDependencyObject(targetElement_ptr);
        else if (object.getPtr() != targetElement_ptr) {
            object = new NSDependencyObject(targetElement_ptr);
        }

        return object;
    }
}
