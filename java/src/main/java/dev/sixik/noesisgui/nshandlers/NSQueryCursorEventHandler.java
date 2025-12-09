package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSQueryContinueDragEventArgs;
import dev.sixik.noesisgui.nsgui.NSQueryCursorEventArgs;

@FunctionalInterface
public interface NSQueryCursorEventHandler {

    void handler(NSBaseComponent component, NSQueryCursorEventArgs args);
}
