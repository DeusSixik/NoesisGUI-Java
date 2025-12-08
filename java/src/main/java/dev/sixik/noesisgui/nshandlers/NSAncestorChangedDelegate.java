package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nsgui.NSFrameworkElement;

@FunctionalInterface
public interface NSAncestorChangedDelegate {

    void handler(NSFrameworkElement element);
}
