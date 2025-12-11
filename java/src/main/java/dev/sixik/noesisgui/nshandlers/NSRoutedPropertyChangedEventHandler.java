package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSRoutedPropertyChangedEventArgs;

@FunctionalInterface
public interface NSRoutedPropertyChangedEventHandler<T> {

    void handler(NSBaseComponent component, NSRoutedPropertyChangedEventArgs<T> args);
}
