package dev.sixik.noesisgui.nsgui;

public class NSKeyboardFocusChangedEventArgs extends NSKeyboardEventArgs{

    private NSUIElement oldFocus;
    private NSUIElement newFocus;

    public long oldFocus_ptr;
    public long newFocus_ptr;

    public NSKeyboardFocusChangedEventArgs(long source_ptr, long routedEvent_ptr, boolean handled, long oldFocus_ptr, long newFocus_ptr) {
        super(source_ptr, routedEvent_ptr, handled);
        this.oldFocus_ptr = oldFocus_ptr;
        this.newFocus_ptr = newFocus_ptr;
    }


    public final NSUIElement getNewFocus() {
        if(newFocus_ptr == 0)
            return null;

        if(newFocus == null)
            newFocus = new NSUIElement(newFocus_ptr);
        else if(newFocus.getPtr() != newFocus_ptr)
            newFocus = new NSUIElement(newFocus_ptr);

        return newFocus;
    }

    public final NSUIElement getOldFocus() {
        if(oldFocus_ptr == 0)
            return null;

        if(oldFocus == null)
            oldFocus = new NSUIElement(oldFocus_ptr);
        else if(oldFocus.getPtr() != oldFocus_ptr)
            oldFocus = new NSUIElement(oldFocus_ptr);

        return oldFocus;
    }
}
