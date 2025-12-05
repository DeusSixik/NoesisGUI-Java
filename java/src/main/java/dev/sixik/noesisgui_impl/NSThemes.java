package dev.sixik.noesisgui_impl;

import dev.sixik.noesisgui.nscore.NSUri;

public class NSThemes {

    public static NSUri darkRed() {
        return new NSUri(nativeDarkRed());
    }

    public static NSUri lightRed() {
        return new NSUri(nativeLightRed());
    }

    public static NSUri darkGreen() {
        return new NSUri(nativeDarkGreen());
    }

    public static NSUri lightGreen() {
        return new NSUri(nativeLightGreen());
    }

    public static NSUri darkBlue() {
        return new NSUri(nativeDarkBlue());
    }

    public static NSUri lightBlue() {
        return new NSUri(nativeLightBlue());
    }

    public static NSUri darkOrange() {
        return new NSUri(nativeDarkOrange());
    }

    public static NSUri lightOrange() {
        return new NSUri(nativeLightOrange());
    }

    public static NSUri darkEmerald() {
        return new NSUri(nativeDarkEmerald());
    }

    public static NSUri lightEmerald() {
        return new NSUri(nativeLightEmerald());
    }

    public static NSUri darkPurple() {
        return new NSUri(nativeDarkPurple());
    }

    public static NSUri lightPurple() {
        return new NSUri(nativeLightPurple());
    }

    public static NSUri darkCrimson() {
        return new NSUri(nativeDarkCrimson());
    }

    public static NSUri lightCrimson() {
        return new NSUri(nativeLightCrimson());
    }

    public static NSUri darkLime() {
        return new NSUri(nativeDarkLime());
    }

    public static NSUri lightLime() {
        return new NSUri(nativeLightLime());
    }

    public static NSUri darkAqua() {
        return new NSUri(nativeDarkAqua());
    }

    public static NSUri lightAqua() {
        return new NSUri(nativeLightAqua());
    }

    public static void destroy(final NSUri theme){
        nativeDestroy(theme.getPtr());
    }

    private static native long nativeDarkRed();

    private static native long nativeLightRed();

    private static native long nativeDarkGreen();

    private static native long nativeLightGreen();

    private static native long nativeDarkBlue();

    private static native long nativeLightBlue();

    private static native long nativeDarkOrange();

    private static native long nativeLightOrange();

    private static native long nativeDarkEmerald();

    private static native long nativeLightEmerald();

    private static native long nativeDarkPurple();

    private static native long nativeLightPurple();

    private static native long nativeDarkCrimson();

    private static native long nativeLightCrimson();

    private static native long nativeDarkLime();

    private static native long nativeLightLime();

    private static native long nativeDarkAqua();

    private static native long nativeLightAqua();

    private static native void nativeDestroy(long ptr);
}
