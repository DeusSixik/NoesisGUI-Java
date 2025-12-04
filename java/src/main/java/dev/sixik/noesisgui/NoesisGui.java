package dev.sixik.noesisgui;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nsgui.NSUIElement;

public class NoesisGui {

    /**
     * A UI element created from XAML code.<br><br>
     *
     * <p><strong>Warning:</strong> Lifetime management of this object is entirely your responsibility.
     * When you no longer need this element, call {@link NSBaseComponent#destroy()} to correctly
     * release the underlying native resources.</p>
     */
    public static NSUIElement parseXaml(String xamlCode) {
        return new NSUIElement(nativeParseXaml(xamlCode));
    }

    private static native long nativeParseXaml(String xamlCode);


    public static int toSignedInt(long unsignedValue) {
        if (unsignedValue < 0 || unsignedValue > 0xFFFFFFFFL) {
            throw new IllegalArgumentException();
        }
        return (int) unsignedValue;
    }
}
