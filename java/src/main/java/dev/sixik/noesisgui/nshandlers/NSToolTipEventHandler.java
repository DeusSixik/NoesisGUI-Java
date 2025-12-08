package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSToolTipEventArgs;

@FunctionalInterface
public interface NSToolTipEventHandler {

    void handler(NSBaseComponent component, NSToolTipEventArgs args);
}
