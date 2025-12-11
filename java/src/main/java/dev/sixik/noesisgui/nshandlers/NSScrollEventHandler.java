package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSScrollEventArgs;

@FunctionalInterface
public interface NSScrollEventHandler {

    void handler(NSBaseComponent component, NSScrollEventArgs args);
}
