package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSKeyboardFocusChangedEventArgs;

@FunctionalInterface
public interface NSKeyboardFocusChangedEventHandler {

    void handler(NSBaseComponent component, NSKeyboardFocusChangedEventArgs args);
}
