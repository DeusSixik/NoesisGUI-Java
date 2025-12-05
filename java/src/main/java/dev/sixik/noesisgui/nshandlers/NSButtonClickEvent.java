package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nsgui.NSRoutedEventArgs;

@FunctionalInterface
public interface NSButtonClickEvent {

    void onClick(NSRoutedEventArgs args);
}
