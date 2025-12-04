package dev.sixik.noesisgui.nsgui;

public enum NSGui_DragDropEffects {

    /// A drop would not be allowed
    DragDropEffects_None(0),

    /// A copy operation would be performed
    DragDropEffects_Copy(1),

    /// A move operation would be performed
    DragDropEffects_Move(2),

    /// A link from the dropped data to the original data would be established
    DragDropEffects_Link(4),

    /// A drag scroll operation is about to occur or is occurring in the target
    DragDropEffects_Scroll(0x80000000),

    /// All operation is about to occur data is copied or removed from the drag source, and
    /// scrolled in the drop target
    DragDropEffects_All(DragDropEffects_Copy.id | DragDropEffects_Move.id | DragDropEffects_Scroll.id);

    public final int id;

    NSGui_DragDropEffects(int i) {
        this.id = i;
    }


}
