package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSRequestBringIntoViewEventArgs;

@FunctionalInterface
public interface NSRequestBringIntoViewEventHandler {

    void handler(NSBaseComponent component, NSRequestBringIntoViewEventArgs args);
}
