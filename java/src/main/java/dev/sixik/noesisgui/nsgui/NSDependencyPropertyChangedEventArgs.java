package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSDependencyProperty;

/**
 * DependencyPropertyChangedEventArgs. Args passed on property changed event notification.
 */
public class NSDependencyPropertyChangedEventArgs {

    private NSDependencyProperty property;

    public long prop_ptr;
    public long oldValue_ptr;
    public long newValue_ptr;

    public NSDependencyPropertyChangedEventArgs() {

    }

    public NSDependencyPropertyChangedEventArgs(long prop_ptr, long oldValue_ptr, long newValue_ptr) {
        this.prop_ptr = prop_ptr;
        this.oldValue_ptr = oldValue_ptr;
        this.newValue_ptr = newValue_ptr;
    }

    public final NSDependencyProperty getProperty() {
        if(prop_ptr == 0)
            return null;

        if(property == null) {
            property = new NSDependencyProperty(prop_ptr);
        } else if(property.getPtr() != prop_ptr) {
            property = new NSDependencyProperty(prop_ptr);
        }

        return property;
    }
}
