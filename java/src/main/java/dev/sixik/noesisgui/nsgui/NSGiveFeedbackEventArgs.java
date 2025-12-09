package dev.sixik.noesisgui.nsgui;

public class NSGiveFeedbackEventArgs extends NSRoutedEventArgs {

    public final int effects;
    public final boolean useDefaultCursors;

    public NSGiveFeedbackEventArgs(long source_ptr, long routedEvent_ptr, boolean handled, int effects, boolean useDefaultCursors) {
        super(source_ptr, routedEvent_ptr, handled);
        this.effects = effects;
        this.useDefaultCursors = useDefaultCursors;
    }
}
