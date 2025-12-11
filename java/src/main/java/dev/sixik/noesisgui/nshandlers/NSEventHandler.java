package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;

@FunctionalInterface
public interface NSEventHandler {

    void handler(NSBaseComponent component);
}
