package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSTouchEventArgs;

@FunctionalInterface
public interface NSTouchEventHandler {

    void handler(NSBaseComponent component, NSTouchEventArgs args);
}
