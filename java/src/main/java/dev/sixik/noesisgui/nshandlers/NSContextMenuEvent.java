package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSContextMenuEventArgs;

@FunctionalInterface
public interface NSContextMenuEvent {
    void handler(NSBaseComponent component, NSContextMenuEventArgs args);
}
