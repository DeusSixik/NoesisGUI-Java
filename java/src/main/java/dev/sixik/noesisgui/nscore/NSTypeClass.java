package dev.sixik.noesisgui.nscore;

public class NSTypeClass extends NSTypeMeta {

    public NSTypeClass(int index) {
        super(index);
    }

    public NSTypeClass(String name) {
        super(name);
    }

    public NSTypeClass(NSSymbol symbol) {
        super(symbol);
    }

    public NSTypeClass(long ptr) {
        super(ptr);
    }
}
