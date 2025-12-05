package dev.sixik.noesisgui;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nscore.NSResourceDictionary;
import dev.sixik.noesisgui.nscore.NSUri;
import dev.sixik.noesisgui.nsgui.NSFrameworkElement;
import dev.sixik.noesisgui.nsgui.NSIView;
import dev.sixik.noesisgui.nsgui.NSUIElement;

public class NoesisGui {

    /**
     * Initializes internal subsystems. Make sure to invoke SetLogHandler(), SetErrorHandler(),
     * SetMemoryCallbacks(), etc., before this function. The current implementation does not support
     * calling this function after Shutdown()
     */
    public static void init() {
        nativeInit();
    }

    /**
     * Frees allocated resources and shutdown internal subsystems. Make sure to release all Noesis
     * objects and memory before invoking this function
     */
    public static void shutdown() {
        nativeShutdown();
    }

    /**
     * A UI element created from XAML code.<br><br>
     *
     * <p><strong>Warning:</strong> Lifetime management of this object is entirely your responsibility.
     * When you no longer need this element, call {@link NSBaseComponent#destroy()} to correctly
     * release the underlying native resources.</p>
     */
    public static NSFrameworkElement parseXaml(final String xamlCode) {
        return new NSFrameworkElement(nativeParseXaml(xamlCode));
    }

    public static NSBaseComponent parseXamlToBase(final String xamlCode) {
        return new NSBaseComponent(nativeParseXaml(xamlCode));
    }

    public static NSResourceDictionary parseXamlTheme(final String xamlCode) {
        return new NSResourceDictionary(nativeParseXamlTheme(xamlCode));
    }

    public static void loadApplicationResources(final NSUri uri) {
        nativeLoadApplicationResources(uri.getPtr());
    }

    /**
     * Creates a view with the given root element
     */
    public static NSIView createView(final NSFrameworkElement element) {
        return new NSIView(nativeCreateView(element.getPtr()));
    }

    public static void setThemeProviders() {
        nativeSetThemeProviders();
    }

    public static int toSignedInt(long unsignedValue) {
        if (unsignedValue < 0 || unsignedValue > 0xFFFFFFFFL) {
            throw new IllegalArgumentException();
        }
        return (int) unsignedValue;
    }

    private static native void nativeLoadApplicationResources(long ptr);

    private static native void nativeSetThemeProviders();

    private static native long nativeParseXaml(String xamlCode);

    private static native long nativeParseXamlTheme(String xamlCode);

    private static native long nativeCreateView(long ptr);

    private static native void nativeInit();

    private static native void nativeShutdown();
}
