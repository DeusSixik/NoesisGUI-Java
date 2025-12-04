package dev.sixik.noesisgui.nscore;

public class NSTypeMeta extends NSType{

    public NSTypeMeta(int index) {
        super(index);
    }

    public NSTypeMeta(String name) {
        super(name);
    }

    public NSTypeMeta(NSSymbol symbol) {
        super(symbol);
    }

    public NSTypeMeta(long ptr) {
        super(ptr);
    }
}
