package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSTextCompositionEventArgs;

@FunctionalInterface
public interface NSTextCompositionEventHandler {

    void handler(NSBaseComponent component, NSTextCompositionEventArgs args);
}
