package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSBaseComponent;

public class NSDragEventArgs extends NSRoutedEventArgs {

    private NSBaseComponent component;

    public final long data_ptr;
    public final int keyStates;
    public final int allowedEffects;
    public final int effects;

    public NSDragEventArgs(long source_ptr, long routedEvent_ptr, boolean handled,
                           long data_ptr, int keyStates, int allowedEffects, int effects) {
        super(source_ptr, routedEvent_ptr, handled);
        this.data_ptr = data_ptr;
        this.keyStates = keyStates;
        this.allowedEffects = allowedEffects;
        this.effects = effects;
    }

    public final NSBaseComponent getData() {
        if(data_ptr == 0)
            return null;

        if(component == null)
            component = new NSBaseComponent(data_ptr);
        else if(component.getPtr() != data_ptr)
            component = new NSBaseComponent(data_ptr);

        return component;
    }
}
