package dev.sixik.noesisgui.nsgui;

public enum NSGui_CaptureMode {

    /// No mouse capture. Mouse input goes to the element under the mouse
    CaptureMode_None,

    /// Mouse capture is applied to a single element. Mouse input goes to the captured element
    CaptureMode_Element,

    /// Mouse capture is applied to a subtree of elements. If the mouse is over a child of the
    /// element with capture, mouse input is sent to the child element. Otherwise, mouse input is
    /// sent to the element with mouse capture
    CaptureMode_SubTree
}
