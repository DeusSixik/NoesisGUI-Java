package dev.sixik.noesisgui.nscore;

import dev.sixik.noesisgui.nsgui.NSGui_RoutingStrategy;

public class NSRoutedEvent extends NSBaseComponent{

    public NSRoutedEvent(long ptr) {
        super(ptr);
    }

    /**
     * Gets event name
     */
    public final String getName() {
        return nGetName(getPtr());
    }

    /**
     * Gets or sets event owner type
     */
    public final NSTypeClass getOwnerType() {
        return new NSTypeClass(nGetOwnerType(getPtr()));
    }

    /**
     * Gets or sets event owner type
     */
    public final void setOwnerType(final NSTypeClass owner) {
        nSetOwnerType(getPtr(), owner.getPtr());
    }

    /**
     * Gets or sets event routing strategy
     */
    public final NSGui_RoutingStrategy getRoutingStrategy() {
        return NSGui_RoutingStrategy.values()[nGetRoutingStrategy(getPtr())];
    }

    /**
     * Gets or sets event routing strategy
     */
    public final void setRoutingStrategy(final NSGui_RoutingStrategy strategy) {
        nSetRoutingStrategy(getPtr(), strategy.ordinal());
    }

    private static native String nGetName(long ptr);

    private static native long nGetOwnerType(long ptr);

    private static native void nSetOwnerType(long ptr, long owner);

    private static native int nGetRoutingStrategy(long ptr);

    private static native void nSetRoutingStrategy(long ptr, int index);
}
