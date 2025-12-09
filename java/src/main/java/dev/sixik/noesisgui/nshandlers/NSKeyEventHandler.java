package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSKeyEventArgs;

@FunctionalInterface
public interface NSKeyEventHandler {

    void handler(NSBaseComponent component, NSKeyEventArgs args);
}
