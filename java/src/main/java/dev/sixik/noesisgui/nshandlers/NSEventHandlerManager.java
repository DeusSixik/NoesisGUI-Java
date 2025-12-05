package dev.sixik.noesisgui.nshandlers;

import dev.sixik.noesisgui.nsgui.NSIView;

public class NSEventHandlerManager {


    public static void subscribe(NSIView view,
                                 String elementName,
                                 NSButtonClickEvent event) {
        nativeSubscribeButtonClickEvent(view.getPtr(), elementName, event);
    }

    private static native void nativeSubscribeButtonClickEvent(long viewPtr,
                                                               String elementName,
                                                               NSButtonClickEvent event);
}
