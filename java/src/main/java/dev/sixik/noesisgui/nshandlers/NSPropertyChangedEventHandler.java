package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSPropertyChangedEventArgs;

@FunctionalInterface
public interface NSPropertyChangedEventHandler {

    void handler(NSBaseComponent component, NSPropertyChangedEventArgs args);
}
