package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSEventArgs;

@FunctionalInterface
public interface NSEventHandler {

    void handler(NSBaseComponent component);
}
