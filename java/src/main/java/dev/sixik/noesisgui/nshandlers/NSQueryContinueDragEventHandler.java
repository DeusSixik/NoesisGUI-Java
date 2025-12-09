package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSQueryContinueDragEventArgs;

@FunctionalInterface
public interface NSQueryContinueDragEventHandler {

    void handler(NSBaseComponent component, NSQueryContinueDragEventArgs args);
}
