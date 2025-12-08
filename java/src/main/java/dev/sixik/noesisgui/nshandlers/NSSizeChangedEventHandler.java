package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSSizeChangedEventArgs;

@FunctionalInterface
public interface NSSizeChangedEventHandler {

    void handler(NSBaseComponent component, NSSizeChangedEventArgs event);
}
