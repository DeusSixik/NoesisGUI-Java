package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSRoutedEventArgs;

@FunctionalInterface
public interface NSRoutedEventHandler {
    void handler(NSBaseComponent component, NSRoutedEventArgs args);
}