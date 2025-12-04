package dev.sixik.noesisgui.nsgui;

public enum NSGui_DragDropKeyStates {

    /// No state set
    DragDropKeyStates_None(0),

    /// The left mouse button
    DragDropKeyStates_LeftMouseButton(1),

    /// The right mouse button
    DragDropKeyStates_RightMouseButton(2),

    /// The SHIFT key
    DragDropKeyStates_ShiftKey(4),

    /// The CTRL key
    DragDropKeyStates_ControlKey(8),

    /// The middle mouse button
    DragDropKeyStates_MiddleMouseButton(16),

    /// The ALT key
    DragDropKeyStates_AltKey(32);


    public final int id;
    NSGui_DragDropKeyStates(int i) {
        this.id = i;
    }
}
