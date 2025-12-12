package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nshandlers.NSRoutedPropertyChangedEventHandler;

/**
 * Represents a control that displays hierarchical data in a tree structure that has items that
 * can expand and collapse.
 *
 * @see <a href="http://msdn.microsoft.com/en-us/library/system.windows.controls.treeview.aspx">
 * Microsoft Documentation: TreeView Class</a>
 */
public class NSTreeView extends NSItemsControl {

    public NSTreeView() {
        this(nCreate());
    }

    public NSTreeView(long ptr) {
        super(ptr);
    }

    /**
     * Gets the selected item in a TreeView
     */
    public final NSBaseComponent getSelectedItem() {
        return new NSBaseComponent(nGetSelectedItem(getPtr()));
    }

    /**
     * Used by TreeViewItem implementation
     */
    public final void itemClicked(final NSTreeViewItem tvi) {
        nItemClicked(getPtr(), tvi.getPtr());
    }

    /**
     * Used by TreeViewItem implementation
     */
    public final void resetSelectedItem() {
        nResetSelectedItem(getPtr());
    }

    /**
     * Occurs when a new item is selected in the tree
     */
    public final void selectedItemChangedEvent(final NSRoutedPropertyChangedEventHandler<NSBaseComponent> event) {
        nSelectedItemChanged(getPtr(), event);
    }

    private static native long nCreate();

    private static native long nGetSelectedItem(long ptr);

    private static native void nItemClicked(long ptr, long element_ptr);

    private static native void nResetSelectedItem(long ptr);

    private static native void nSelectedItemChanged(long ptr, NSRoutedPropertyChangedEventHandler<NSBaseComponent> event);
}
