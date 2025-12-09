package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSMouseEventArgs;

@FunctionalInterface
public interface NSMouseEventHandler {

    void handler(NSBaseComponent component, NSMouseEventArgs args);
}
