package dev.sixik.noesisgui.nsgui;

public class NSRoutedPropertyChangedEventArgs<T> extends NSRoutedEventArgs{

    public final T oldValue;
    public final T newValue;

    public NSRoutedPropertyChangedEventArgs(long source_ptr, long routedEvent_ptr, boolean handled,
                                            T oldValue, T newValue) {
        super(source_ptr, routedEvent_ptr, handled);
        this.oldValue = oldValue;
        this.newValue = newValue;
    }
}
