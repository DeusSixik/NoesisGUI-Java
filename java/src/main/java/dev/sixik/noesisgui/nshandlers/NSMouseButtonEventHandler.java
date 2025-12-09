package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSMouseButtonEventArgs;

@FunctionalInterface
public interface NSMouseButtonEventHandler {

    void handler(NSBaseComponent component, NSMouseButtonEventArgs args);
}
