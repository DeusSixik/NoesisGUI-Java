package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nsdrawing.NSPoint;

public class NSTouchEventArgs extends NSInputEventArgs {

    public NSPoint touchPoint;
    public long touchDevice;

    public NSTouchEventArgs(long source_ptr, long routedEvent_ptr, boolean handled,
                            NSPoint touchPoint, long touchDevice) {
        super(source_ptr, routedEvent_ptr, handled);
        this.touchPoint = touchPoint;
        this.touchDevice = touchDevice;
    }
}
