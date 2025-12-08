package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSDependencyPropertyChangedEventArgs;

@FunctionalInterface
public interface NSDependencyPropertyChangedEventHandler {

    void handler(NSBaseComponent component, NSDependencyPropertyChangedEventArgs args);
}
