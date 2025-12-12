package dev.sixik.noesisgui.nsgui;

public class NSPropertyChangedEventArgs extends NSEventArgs {

    public final String symbol;

    public NSPropertyChangedEventArgs(String symbol) {
        this.symbol = symbol;
    }
}
