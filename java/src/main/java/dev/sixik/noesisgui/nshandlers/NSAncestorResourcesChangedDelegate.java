package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSNotifyDictionaryChangedEventArgs;

@FunctionalInterface
public interface NSAncestorResourcesChangedDelegate {

    void handler(NSBaseComponent component, NSNotifyDictionaryChangedEventArgs args);
}
