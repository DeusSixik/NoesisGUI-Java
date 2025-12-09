package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSDragEventArgs;

@FunctionalInterface
public interface NSDragEventHandler {

    void handler(NSBaseComponent component, NSDragEventArgs args);
}
