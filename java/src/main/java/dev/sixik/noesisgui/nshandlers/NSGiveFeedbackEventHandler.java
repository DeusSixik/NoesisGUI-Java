package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSGiveFeedbackEventArgs;

@FunctionalInterface
public interface NSGiveFeedbackEventHandler {

    void handle(NSBaseComponent component, NSGiveFeedbackEventArgs args);
}
