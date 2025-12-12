package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSBaseComponent;
import dev.sixik.noesisgui.nscore.NSDependencyObject;

/**
 * Represents a control that can be used to present a collection of items.
 * <p>
 * Each ItemsControl type has a corresponding item container type. The corresponding item container
 * for each ItemsControl appends "Item" to its name. For example, for ListBox, the item containers
 * are ListBoxItem controls; for ComboBox, they are ComboBoxItem controls. You can explicitly
 * create a container type for each item in the ItemsControl, but it is not necessary. When you do
 * not explicitly create the container type, one is generated that contains a data item in the item
 * collection.
 * <p>
 * For example, if you bind a collection of string objects to the ItemsSource property
 * of a ListBox, you do not explicitly create ListBoxItem objects, but the ListBox will generate
 * one for each string. You can access a generated item container by using the
 * ItemContainerGenerator property.
 * <p>
 * <strong>XAML Example:</strong>
 * <pre>{@code
 * <ItemsControl>
 *   <ItemsControl.ItemTemplate>
 *     <DataTemplate>
 *       <Grid Margin="0,0,0,5">
 *         <Grid.ColumnDefinitions>
 *           <ColumnDefinition Width="*"/>
 *           <ColumnDefinition Width="100"/>
 *         </Grid.ColumnDefinitions>
 *         <TextBlock Text="{Binding Title}"/>
 *         <ProgressBar Grid.Column="1" Minimum="0" Maximum="100" Value="{Binding Completion}"/>
 *       </Grid>
 *     </DataTemplate>
 *   </ItemsControl.ItemTemplate>
 * </ItemsControl>
 * }</pre>
 *
 * @see <a href="http://msdn.microsoft.com/en-us/library/system.windows.controls.itemscontrol.aspx">
 *      ItemsControl Documentation on MSDN</a>
 * @since 1.0
 */
public class NSItemsControl extends NSControl {

    public NSItemsControl() {
        this(nCreate());
    }

    public NSItemsControl(long ptr) {
        super(ptr);
    }

    /**
     * Gets or sets a value that controls the range of values assigned to the AlternationIndex
     * property attached to each generated container.
     *  * The default value 0 means "do not set AlternationIndex"
     *  * A positive value means "assign AlternationIndex in the range [0, AlternationCount) so
     *    that adjacent containers receive different values"
     */
    public final int getAlternationCount() {
        return nGetAlternationCount(getPtr());
    }

    /**
     * Gets or sets a value that controls the range of values assigned to the AlternationIndex
     * property attached to each generated container.
     *  * The default value 0 means "do not set AlternationIndex"
     *  * A positive value means "assign AlternationIndex in the range [0, AlternationCount) so
     *    that adjacent containers receive different values"
     */
    public final void setAlternationCount(final int value) {
        nSetAlternationCount(getPtr(), value);
    }

    /**
     * Gets the index set on generated containers, when the ItemsControl's AlternationCount
     * property is positive. The AlternationIndex lies in the range [0, AlternationCount), and
     * adjacent containers always get assigned different values
     */
    public static int getAlternationIndex(final NSDependencyObject element) {
        return nGetAlternationIndexStatic(element.getPtr());
    }

    /**
     * Gets or sets a path to a value on the source object to serve as the visual representation
     * of the object
     */
    public final String getDisplayMemberPath() {
        return nGetDisplayMemberPath(getPtr());
    }

    /**
     * Gets or sets a path to a value on the source object to serve as the visual representation
     * of the object
     */
    public final void setDisplayMemberPath(final String path) {
        nSetDisplayMemberPath(getPtr(), path);
    }

    /**
     * Gets a value that indicates whether the ItemsControl contains items
     */
    public final boolean getHasItems() {
        return nGetHasItems(getPtr());
    }

    /**
     * Gets the ItemContainerGenerator associated with this control
     */
    public final NSItemContainerGenerator getItemContainerGenerator() {
        return new NSItemContainerGenerator(nGetItemContainerGenerator(getPtr()));
    }

    /**
     * Gets or sets the Style that is applied to the container element generated for each item.
     */
    public final NSStyle getItemContainerStyle() {
        return new NSStyle(nGetItemContainerStyle(getPtr()));
    }

    /**
     * Gets or sets the Style that is applied to the container element generated for each item.
     */
    public final void setItemContainerStyle(final NSStyle style) {
        nSetItemContainerStyle(getPtr(), style.getPtr());
    }

    /**
     * Gets or sets the ItemsPanelTemplate that defines the Panel that controls the layout of items
     */
    public final NSItemsPanelTemplate getItemsPanel() {
        return new NSItemsPanelTemplate(nGetItemsPanel(getPtr()));
    }

    /**
     * Gets or sets the ItemsPanelTemplate that defines the Panel that controls the layout of items
     */
    public final void setItemsPanel(final NSItemsPanelTemplate value) {
        nItemsPanelTemplate(getPtr(), value.getPtr());
    }

    /**
     * Returns a new instance of the default items panel for this ItemsControl
     */
    public final NSPanel getDefaultItemsPanel() {
        return new NSPanel(nGetDefaultItemsPanel(getPtr()));
    }

    /**
     * Gets or sets a collection used to generate the content of the ItemsControl. When the
     * ItemsSource property is set, the Items collection is made read-only and fixed-size
     */
    public final NSBaseComponent getItemsSource() {
        return new NSBaseComponent(nGetItemsSource(getPtr()));
    }

    /**
     * Gets or sets a collection used to generate the content of the ItemsControl. When the
     * ItemsSource property is set, the Items collection is made read-only and fixed-size
     */
    public final void setItemsSource(final NSBaseComponent items) {
        nSetItemsSource(getPtr(), items.getPtr());
    }

    /**
     * Gets or sets the DataTemplate used to display each item.
     */
    public final NSDataTemplate getItemTemplate() {
        return new NSDataTemplate(nGetItemTemplate(getPtr()));
    }

    /**
     * Gets or sets the DataTemplate used to display each item.
     */
    public final void setItemTemplate(final NSDataTemplate template) {
        nSetItemTemplate(getPtr(), template.getPtr());
    }

    /**
     * Gets or sets a DataTemplateSelector that provides custom logic for choosing the template
     * used to display the header
     */
    public final NSDataTemplateSelector getItemTemplateSelector() {
        return new NSDataTemplateSelector(nGetItemTemplateSelector(getPtr()));
    }

    /**
     * Gets or sets a DataTemplateSelector that provides custom logic for choosing the template
     * used to display the header
     */
    public final void setItemTemplateSelector(final NSDataTemplateSelector selector) {
        nSetItemTemplateSelector(getPtr(), selector.getPtr());
    }

    /**
     * Gets the collection used to generate the content of the ItemsControl. When the ItemsSource
     * property is set, the Items collection is made read-only and fixed-size
     */
    public final NSItemCollection getItems() {
        return new NSItemCollection(nGetItems(getPtr()));
    }

    /**
     * Returns the ItemsControl that owns the specified container element.
     */
    public static NSItemsControl itemsControlFromItemContainer(final NSDependencyObject container) {
        return new NSItemsControl(nItemsControlFromItemContainerStatic(container.getPtr()));
    }

    /**
     * Returns the container that owns the given element. If *itemsControl* is not null, returns a
     * container that belongs to the given ItemsControl. If *itemsControl* is null, returns the
     * closest container belonging to any ItemsControl. Returns null if no such container exists
     */
    public static NSDependencyObject containerFromElement(final NSItemsControl itemsControl, final NSDependencyObject element) {
        return new NSDependencyObject(nContainerFromElementStatic(itemsControl.getPtr(), element.getPtr()));
    }

    /**
     * Returns the container belonging to the current ItemsControl that owns the given container
     * element. Returns null if no such container exists
     */
    public final NSDependencyObject containerFromElement(final NSDependencyObject element) {
        return new NSDependencyObject(nContainerFromElement(getPtr(), element.getPtr()));
    }

    /**
     * Returns the ItemsControl that the specified element hosts items for. If IsItemsHost is set
     * to true on element in a style or if element is a panel created by the ItemsPresenter for an
     * ItemsControl, the ItemsControl is returned; otherwise, a null reference
     */
    public static NSItemsControl getItemsOwner(final NSDependencyObject itemsHost) {
        return new NSItemsControl(nGetItemsOwnerStatic(itemsHost.getPtr()));
    }

    /**
     * Determines if the specified item is (or is eligible to be) its own container
     */
    public final boolean isItemItsOwnContainer(final NSBaseComponent item) {
        return nIsItemItsOwnContainer(getPtr(), item.getPtr());
    }

    private static native long nCreate();

    private static native int nGetAlternationCount(long ptr);

    private static native void nSetAlternationCount(long ptr, int value);

    private static native int nGetAlternationIndexStatic(long element_ptr);

    private static native String nGetDisplayMemberPath(long ptr);

    private static native void nSetDisplayMemberPath(long ptr, String value);

    private static native boolean nGetHasItems(long ptr);

    private static native long nGetItemContainerGenerator(long ptr);

    private static native long nGetItemContainerStyle(long ptr);

    private static native void nSetItemContainerStyle(long ptr, long style_ptr);

    private static native long nGetItemsPanel(long ptr);

    private static native void nItemsPanelTemplate(long ptr, long template_ptr);

    private static native long nGetDefaultItemsPanel(long ptr);

    private static native long nGetItemsSource(long ptr);

    private static native void nSetItemsSource(long ptr, long element_ptr);

    private static native long nGetItemTemplate(long ptr);

    private static native void nSetItemTemplate(long ptr, long template_ptr);

    private static native long nGetItemTemplateSelector(long ptr);

    private static native void nSetItemTemplateSelector(long ptr, long selector_ptr);

    private static native long nGetItems(long ptr);

    private static native long nItemsControlFromItemContainerStatic(long element_ptr);

    private static native long nContainerFromElementStatic(long container_ptr, long element_ptr);

    private static native long nContainerFromElement(long ptr, long element_ptr);

    private static native long nGetItemsOwnerStatic(long element_ptr);

    private static native boolean nIsItemItsOwnContainer(long ptr, long element_ptr);
}
