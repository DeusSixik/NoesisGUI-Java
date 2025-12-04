package dev.sixik.noesisgui.nsgui;

public enum NSGui_DragAction {

    /// The drag and drop can continue
    DragAction_Continue(0),

    /// Drop operation should occur
    DragAction_Drop(1),

    /// Drop operation is canceled
    DragAction_Cancel(2);

    public final int id;

    NSGui_DragAction(int i) {
        this.id = i;
    }
}
