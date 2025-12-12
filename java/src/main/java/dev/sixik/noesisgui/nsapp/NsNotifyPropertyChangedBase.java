package dev.sixik.noesisgui.nsapp;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nshandlers.NSPropertyChangedEventHandler;

public class NsNotifyPropertyChangedBase extends NSBaseComponent implements NSINotifyPropertyChanged, AutoCloseable {

    public NsNotifyPropertyChangedBase() {
        this(nCreate());
    }

    public NsNotifyPropertyChangedBase(long ptr) {
        super(ptr);
    }

    /**
     * Occurs when a property value changes
     */
    @Override
    public final void propertyChangedEvent(NSPropertyChangedEventHandler event) {
        nPropertyChanged(getPtr(), event);
    }

    public final void raisePropertyChanged(final String name) {
        nRaisePropertyChanged(getPtr(), name);
    }

    private static native long nCreate();

    private static native void nPropertyChanged(long ptr, NSPropertyChangedEventHandler event);

    private static native void nRaisePropertyChanged(long ptr, String name);

    @Override
    public void close() {
        if (getPtr() != 0) {
            release();
            clearPtr();
        }
    }
}
