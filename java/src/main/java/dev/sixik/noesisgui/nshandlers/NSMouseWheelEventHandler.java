package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSMouseWheelEventArgs;

@FunctionalInterface
public interface NSMouseWheelEventHandler {

    void handler(NSBaseComponent component, NSMouseWheelEventArgs args);
}
