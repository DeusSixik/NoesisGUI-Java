package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.*;
import dev.sixik.noesisgui.nsdrawing.NSRect;
import dev.sixik.noesisgui.nshandlers.*;

public class NSFrameworkElement extends NSUIElement{

    public NSFrameworkElement(long ptr) {
        super(ptr);
    }

    /**
     * Gets the direction that text and other UI elements flow within any parent element that
     * controls their layout
     */
    public static NSGui_FlowDirection getFlowDirection(final NSDependencyObject object) {
        return NSGui_FlowDirection.values()[nGetFlowDirectionStatic(object.getPtr())];
    }

    /**
     * Sets the direction that text and other UI elements flow within any parent element that
     * controls their layout
     */
    public static void setFlowDirection(final NSDependencyObject object, final NSGui_FlowDirection direction) {
        nSetFlowDirectionStatic(object.getPtr(), direction.ordinal());
    }

    /**
     * Gets the rendered height of this element.
     */
    public final float getActualHeight(){
        return nGetActualHeight(getPtr());
    }

    /**
     * Gets the rendered width of this element.
     */
    public final float getActualWidth(){
        return nGetActualWidth(getPtr());
    }

    /**
     * Gets or sets a value indicating how the element's contents are mixed with the background
     */
    public final NSGui_BlendingMode getBlendingMode() {
        return NSGui_BlendingMode.values()[nGetBlendingMode(getPtr())];
    }

    /**
     * Gets or sets a value indicating how the element's contents are mixed with the background
     */
    public final void setBlendingMode(final NSGui_BlendingMode mode) {
        nSetBlendingMode(getPtr(), mode.ordinal());
    }

    /**
     * Gets or sets the context menu element that should appear whenever the context menu is
     * requested through user interface (UI) from within this element.
     */
    public final NSContextMenu getContextMenu() {
        return new NSContextMenu(nGetContextMenu(getPtr()));
    }

    /**
     * Gets or sets the context menu element that should appear whenever the context menu is
     * requested through user interface (UI) from within this element.
     */
    public final void setContextMenu(final NSContextMenu menu) {
        nSetContextMenu(getPtr(), menu.getPtr());
    }

    /**
     * Gets or sets the cursor that displays when the mouse pointer is over this element.
     */
    public final NSCursor getCursor() {
        return new NSCursor(nGetCursor(getPtr()));
    }

    /**
     * Gets or sets the cursor that displays when the mouse pointer is over this element.
     */
    public final void setCursor(final NSCursor cursor) {
        nSetCursor(getPtr(), cursor.getPtr());
    }

    /**
     * Gets or sets the data context for an element when it participates in data binding
     */
    public final NSBaseComponent getDataContext() {
        return new NSBaseComponent(nGetDataContext(getPtr()));
    }

    /**
     * Gets or sets the data context for an element when it participates in data binding
     */
    public final void setDataContext(final NSBaseComponent context) {
        nSetDataContext(getPtr(), context.getPtr());
    }

    /**
     * Gets or sets the key to use to reference the style for this control, when theme styles are
     * used or defined
     */
    public final NSType getDefaultStyleKey() {
        return new NSType(nGetDefaultStyleKey(getPtr()));
    }

    /**
     * Gets or sets the direction that text and other UI elements flow within any parent element
     * that controls their layout
     */
    public final void setDefaultStyleKey(final NSType type) {
        nSetDefaultStyleKey(getPtr(), type.getPtr());
    }

    /**
     * Gets or sets the direction that text and other UI elements flow within any parent element
     * that controls their layout
     */
    public final NSGui_FlowDirection getFlowDirection() {
        return NSGui_FlowDirection.values()[nGetFlowDirection(getPtr())];
    }

    /**
     * Gets or sets the direction that text and other UI elements flow within any parent element
     * that controls their layout
     */
    public final void setFlowDirection(final NSGui_FlowDirection direction) {
        nSetFlowDirection(getPtr(), direction.ordinal());
    }

    /**
     * Gets or sets a property that enables customization of appearance, effects, or other style
     * characteristics that will apply to this element when it captures keyboard focus
     */
    public final NSStyle getFocusVisualStyle() {
        return new NSStyle(nGetFocusVisualStyle(getPtr()));
    }

    /**
     * Gets or sets a property that enables customization of appearance, effects, or other style
     * characteristics that will apply to this element when it captures keyboard focus
     */
    public final void setFocusVisualStyle(final NSStyle style) {
        nSetFocusVisualStyle(getPtr(), style.getPtr());
    }

    /**
     * Gets or sets a value that indicates whether this FrameworkElement should force the UI to
     * render the cursor as declared by this element's Cursor property.
     */
    public final boolean getForceCursor() {
        return nGetForceCursor(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether this FrameworkElement should force the UI to
     * render the cursor as declared by this element's Cursor property.
     */
    public final void setForceCursor(final boolean value) {
        nSetForceCursor(getPtr(), value);
    }

    /**
     * Gets or sets the suggested height of the element.
     */
    public final float getHeight() {
        return nGetHeight(getPtr());
    }

    /**
     * Gets or sets the suggested height of the element.
     */
    public final void setHeight(final float value) {
        nSetHeight(getPtr(), value);
    }

    /**
     * Gets or sets the horizontal alignment characteristics applied to this element when it is
     * composed within a parent element, such as a panel or items control
     */
    public final NSGui_HorizontalAlignment getHorizontalAlignment() {
        return NSGui_HorizontalAlignment.values()[nGetHorizontalAlignment(getPtr())];
    }

    /**
     * Gets or sets the horizontal alignment characteristics applied to this element when it is
     * composed within a parent element, such as a panel or items control
     */
    public final void setHorizontalAlignment(final NSGui_HorizontalAlignment alignment) {
        nSetHorizontalAlignment(getPtr(), alignment.ordinal());
    }

    /**
     * Gets or sets the context for input used by this element. The input scope, which modifies
     * how input from alternative input methods is interpreted
     */
    public final NSGui_InputScope getInputScope() {
        return NSGui_InputScope.fromValue(nGetInputScope(getPtr()));
    }

    /**
     * Gets or sets the context for input used by this element. The input scope, which modifies
     * how input from alternative input methods is interpreted
     */
    public final void setInputScope(final NSGui_InputScope scope) {
        nSetInputScope(getPtr(), scope.value);
    }

    /**
     * Gets or sets a graphics transformation that should apply to this element when layout is
     * performed
     */
    public final NSTransform getLayoutTransform() {
        return new NSTransform(nGetLayoutTransform(getPtr()));
    }

    /**
     * Gets or sets a graphics transformation that should apply to this element when layout is
     * performed
     */
    public final void setLayoutTransform(final NSTransform transform) {
        nSetLayoutTransform(getPtr(), transform.getPtr());
    }

    /**
     * Gets or sets the outer margin of an element.
     */
    public final void getMargin(final NSThickness out) {
        nGetMargin(getPtr(), out);
    }

    /**
     * Gets or sets the outer margin of an element.
     */
    public final NSThickness getMargin() {
        final NSThickness thickness = new NSThickness();
        getMargin(thickness);
        return thickness;
    }

    /**
     * Gets or sets the outer margin of an element.
     */
    public final void setMargin(final NSThickness thickness) {
        nSetMargin(getPtr(), thickness);
    }

    /**
     * Gets or sets the maximum height constraint of the element.
     */
    public final float getMaxHeight() {
        return nGetMaxHeight(getPtr());
    }

    /**
     * Gets or sets the maximum height constraint of the element.
     */
    public final void setMaxHeight(final float value) {
        nSetMaxHeight(getPtr(), value);
    }

    /**
     * Gets or sets the maximum width constraint of the element.
     */
    public final float getMaxWidth() {
        return nGetMaxWidth(getPtr());
    }

    /**
     * Gets or sets the maximum width constraint of the element.
     */
    public final void setMaxWidth(final float value) {
        nSetMaxWidth(getPtr(), value);
    }

    /**
     * Gets or sets the minimum height constraint of the element.
     */
    public final float getMinHeight() {
        return nGetMinHeight(getPtr());
    }

    /**
     * Gets or sets the minimum height constraint of the element.
     */
    public final void setMinHeight(final float value) {
        nSetMinHeight(getPtr(), value);
    }

    /**
     * Gets or sets the minimum width constraint of the element.
     */
    public final float getMinWidth() {
        return nGetMinWidth(getPtr());
    }

    /**
     * Gets or sets the minimum width constraint of the element.
     */
    public final void setMinWidth(final float value) {
        nSetMinWidth(getPtr(), value);
    }

    /**
     * Gets or sets the identifying name of the element. The name provides a reference so that
     * code-behind, such as event handler code, can refer to a markup element after it is
     * constructed during processing by a XAML processor.
     */
    public final String getName() {
        return nGetName(getPtr());
    }

    /**
     * Gets or sets the identifying name of the element. The name provides a reference so that
     * code-behind, such as event handler code, can refer to a markup element after it is
     * constructed during processing by a XAML processor.
     */
    public final void setName(final String name) {
        nSetName(getPtr(), name);
    }

    /**
     * Gets or sets a value that indicates whether this element incorporates style properties from
     * theme styles
     */
    public final boolean getOverridesDefaultStyle() {
        return nGetOverridesDefaultStyle(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether this element incorporates style properties from
     * theme styles
     */
    public final void setOverridesDefaultStyle(final boolean value) {
        nSetOverridesDefaultStyle(getPtr(), value);
    }

    /**
     * Gets or sets a value that indicates whether antialiasing geometry is generated for this
     * element. This property is inherited down by the visual tree
     */
    public final NSGui_PPAAMode getPPAAMode() {
        return NSGui_PPAAMode.values()[nGetPPAAMode(getPtr())];
    }

    /**
     * Gets or sets a value that indicates whether antialiasing geometry is generated for this
     * element. This property is inherited down by the visual tree
     */
    public final void setPPAAMode(final NSGui_PPAAMode mode) {
        nSetPPAAMode(getPtr(), mode.ordinal());
    }

    /**
     * Gets or sets the value of the contraction of each vertex along the normal for PPAA. This
     * property is inherited down by the visual tree
     */
    public final float getPPAAIn() {
        return nGetPPAAIn(getPtr());
    }

    /**
     * Gets or sets the value of the contraction of each vertex along the normal for PPAA. This
     * property is inherited down by the visual tree
     */
    public final void setPPAAIn(final float value) {
        nSetPPAAIn(getPtr(), value);
    }

    /**
     * Gets or sets the value of the extrusion of each vertex along the normal for PPAA. This
     * property is inherited down by the visual tree
     */
    public final float getPPAAOut() {
        return nGetPPAAOut(getPtr());
    }

    /**
     * Gets or sets the value of the extrusion of each vertex along the normal for PPAA. This
     * property is inherited down by the visual tree
     */
    public final void setPPAAOut(final float value) {
        nSetPPAAOut(getPtr(), value);
    }

    /**
     * Gets or sets the style used by this element when it is rendered
     */
    public final NSStyle getStyle() {
        return new NSStyle(nGetStyle(getPtr()));
    }

    /**
     * Gets or sets the style used by this element when it is rendered
     */
    public final void setStyle(final NSStyle style) {
        nSetStyle(getPtr(), style.getPtr());
    }

    /**
     * Gets or sets an arbitrary object value that can be used to store custom information about
     * this element
     */
    public final NSBaseComponent getTag() {
        return new NSBaseComponent(nGetTag(getPtr()));
    }

    /**
     * Gets or sets an arbitrary object value that can be used to store custom information about
     * this element
     */
    public final void setTag(final NSBaseComponent component) {
        nSetTag(getPtr(), component.getPtr());
    }

    /**
     * Gets or sets an arbitrary object value that can be used to store custom information about
     * this element
     */
    public final void setTag(final String tag) {
        nSetTagString(getPtr(), tag);
    }

    /**
     * Gets or sets the tool-tip object that is displayed for this element in the user interface
     */
    public final NSBaseComponent getToolTip() {
        return new NSBaseComponent(nGetToolTip(getPtr()));
    }

    /**
     * Gets or sets the tool-tip object that is displayed for this element in the user interface
     */
    public final void setToolTip(final NSBaseComponent component) {
        nSetToolTip(getPtr(), component.getPtr());
    }

    /**
     * Gets or sets the tool-tip object that is displayed for this element in the user interface
     */
    public final void setTooltip(final String tooltip) {
        nSetToolTipString(getPtr(), tooltip);
    }

    /**
     * Gets or sets a value that indicates whether layout rounding should be applied to this
     * element's size and position during layout
     */
    public final boolean getUseLayoutRounding() {
        return nGetUseLayoutRounding(getPtr());
    }

    /**
     * Gets or sets a value that indicates whether layout rounding should be applied to this
     * element's size and position during layout
     */
    public final void setUseLayoutRounding(final boolean value) {
        nSetUseLayoutRounding(getPtr(), value);
    }

    /**
     * Gets or sets the vertical alignment characteristics applied to this element when it is
     * composed within a parent element such as a panel or items control.
     */
    public final NSGui_VerticalAlignment getVerticalAlignment() {
        return NSGui_VerticalAlignment.values()[nGetVerticalAlignment(getPtr())];
    }

    /**
     * Gets or sets the vertical alignment characteristics applied to this element when it is
     * composed within a parent element such as a panel or items control.
     */
    public final void setVerticalAlignment(final NSGui_VerticalAlignment alignment) {
        nSetVerticalAlignment(getPtr(), alignment.ordinal());
    }

    /**
     * Gets or sets the width of the element
     */
    public final float getWidth() {
        return nGetWidth(getPtr());
    }

    /**
     * Gets or sets the width of the element
     */
    public final void setWidth(final float width) {
        nSetWidth(getPtr(), width);
    }

    /**
     * Get the trigger collection
     */
    public final NSTriggerCollection getTriggers() {
        return new NSTriggerCollection(nGetTriggers(getPtr()));
    }

    /**
     * Returns a binding expression if the target property has an active binding; otherwise,
     * returns null
     */
    public final NSBindingExpression getBindingExpression(final NSDependencyProperty dp) {
        return new NSBindingExpression(nGetBindingExpression(getPtr(), dp.getPtr()));
    }

    /**
     * Attaches a binding to this element, based on the provided binding object
     * @return The binding expression just set
     */
    public final NSBaseBindingExpression setBinding(final NSDependencyProperty dp, final NSBaseBinding baseBinding) {
        return new NSBaseBindingExpression(nSetBinding(getPtr(), dp.getPtr(), baseBinding.getPtr()));
    }

    /**
     * Attaches a binding to this element, based on the provided source property name as a path
     * qualification to the data source
     * @return The binding expression just set
     */
    public final NSBindingExpression setBinding(final NSDependencyProperty dp, final String path) {
        return new NSBindingExpression(nSetBindingString(getPtr(), dp.getPtr(), path));
    }

    /**
     * Sets up a resource reference in the target property to search for a resource with
     * the specified name
     */
    public final void setResourceReference(final NSDependencyProperty dp, final String name) {
        nSetResourceReference(getPtr(), dp.getPtr(), name);
    }

    /**
     * Gets a value that indicates whether this element has been loaded for presentation.
     */
    public final boolean isLoaded() {
        return nIsLoaded(getPtr());
    }

    /**
     * Attempts to bring this element into view, within any scrollable regions it
     * is contained within.
     */
    public final void bringIntoView() {
        nBringIntoView(getPtr());
    }

    /**
     * Attempts to bring the provided region size of this element into view, within
     * any scrollable regions it is contained within.
     */
    public final void bringIntoView(final NSRect targetRectangle) {
        nBringIntoViewRect(getPtr(), targetRectangle);
    }

    /**
     * Gets the TimeManager that controls current element
     */
    public final NSITimeManager getTimeManager() {
        return new NSITimeManager(nGetTimeManager(getPtr()));
    }

    /**
     * Gets the logical parent element of this element
     */
    public final NSFrameworkElement getParent() {
        return new NSFrameworkElement(nGetParent(getPtr()));
    }

    /**
     * Called on every Measure. Returns true if Visuals were added to the tree
     */
    public final boolean applyTemplate() {
        return nApplyTemplate(getPtr());
    }

    /**
     * Gets the logical parent or the templated parent when logical parent is not available
     */
    public final NSFrameworkElement getParentOrTemplatedParent() {
        return new NSFrameworkElement(nGetParentOrTemplatedParent(getPtr()));
    }

    /**
     * Gets or sets the template parent of this element. This property is not relevant if the
     * element was not created through a template
     */
    public final NSFrameworkElement getTemplatedParent() {
        return new NSFrameworkElement(nGetTemplatedParent(getPtr()));
    }

    /**
     * Gets or sets the template parent of this element. This property is not relevant if the
     * element was not created through a template
     */
    public final void setTemplatedParent(final NSFrameworkElement templatedParent, final NSFrameworkTemplate frameworkTemplate) {
        nSetTemplatedParent(getPtr(), templatedParent.getPtr(), frameworkTemplate.getPtr());
    }

    /**
     * Gets applied template on this element
     */
    public final NSFrameworkTemplate getFrameworkTemplate() {
        return new NSFrameworkTemplate(nGetFrameworkTemplate(getPtr()));
    }

    /**
     * Clears current template
     */
    public final void clearFrameworkTemplate() {
        nClearFrameworkTemplate(getPtr());
    }

    /**
     * Returns a clone of this element. Used when applying a template
     */
    public final NSFrameworkElement clone(final NSFrameworkElement parent, final NSFrameworkElement templatedParent, NSFrameworkTemplate template) {
        return new NSFrameworkElement(nClone(getPtr(), parent.getPtr(), templatedParent.getPtr(), template.getPtr()));
    }

    /**
     * Gets root for VisualState management
     */
    public final NSFrameworkElement getStateGroupsRoot() {
        return new NSFrameworkElement(nGetStateGroupsRoot(getPtr()));
    }

    public final NSFrameworkElement findName(final String name) {
        return new NSFrameworkElement(nFindName(getPtr(), name));
    }

    public final NSObjectWithNameScope findNameAndScope(final String name) {
        final NSObjectWithNameScope scope = new NSObjectWithNameScope();
        findNameAndScope(name, scope);
        return scope;
    }

    public final void findNameAndScope(final String name, final NSObjectWithNameScope out) {
        nFindNameAndScope(getPtr(), name, out);
    }

    public final void registerName(final String name, final NSBaseComponent component) {
        nRegisterName(getPtr(), name, component.getPtr());
    }

    public final void unregisterName(final String name) {
        nUnregisterName(getPtr(), name);
    }

    public final void updateName(final String name, final NSBaseComponent component) {
        nUpdateName(getPtr(), name, component.getPtr());
    }

    public final NSBaseComponent findResource(final String key) {
        return new NSBaseComponent(nFindResource(getPtr(), key));
    }

    /**
     * Gets or sets the locally-defined resource dictionary
     */
    public final NSResourceDictionary getResources() {
        return new NSResourceDictionary(nGetResources(getPtr()));
    }

    /**
     * Gets or sets the locally-defined resource dictionary
     */
    public final void setResources(final NSResourceDictionary dictionary) {
        nSetResources(getPtr(), dictionary.getPtr());
    }

    /**
     * Attached specified named object to code-behind field
     */
    public final boolean connectField(final NSBaseComponent obj, final String name) {
        return nConnectField(getPtr(), obj.getPtr(), name);
    }

    /**
     * Attaches specified event to code-behind content. Return false when code-behind does not
     * define the specified event handler
     */
    public final boolean connectEvent(final NSBaseComponent source, final String event, final String handler) {
        return nConnectEvent(getPtr(), source.getPtr(), event, handler);
    }

    /**
     * Occurs just before any context menu on the element is closed
     */
    public final void contextMenuClosingEvent(final NSContextMenuEvent event) {
        nContextMenuClosing(getPtr(), event);
    }

    /**
     * Occurs when any context menu on the element is opened
     */
    public final void contextMenuOpeningEvent(final NSContextMenuEvent event) {
        nContextMenuOpening(getPtr(), event);
    }

    /**
     * Occurs when the element is laid out, rendered, and ready for interaction
     */
    public final void loadedEvent(final NSRoutedEventHandler event) {
        nLoaded(getPtr(), event);
    }

    /**
     * Occurs when this element xaml gets reloaded as a result of a hot-reload operation
     */
    public final void reloadedEvent(final NSRoutedEventHandler event) {
        nReloaded(getPtr(), event);
    }

    /**
     * Occurs when the element is removed from within an element tree of loaded elements
     */
    public final void unloadedEvent(final NSRoutedEventHandler event) {
        nUnloaded(getPtr(), event);
    }

    /**
     * Occurs when BringIntoView is called on this element
     */
    public final void requestBringIntoViewEvent(final NSRequestBringIntoViewEventHandler event) {
        nRequestBringIntoView(getPtr(), event);
    }

    /**
     * Occurs when either ActualHeight or ActualWidth properties change value on this element
     */
    public final void sizeChangedEvent(final NSSizeChangedEventHandler event) {
        nSizeChanged(getPtr(), event);
    }

    /**
     * Occurs when either ActualHeight or ActualWidth properties change value on this element
     */
    public final void toolTipClosingEvent(final NSToolTipEventHandler event) {
        nToolTipClosing(getPtr(), event);
    }

    /**
     * Occurs just before any tooltip on the element is closed
     */
    public final void toolTipOpeningEvent(final NSToolTipEventHandler event) {
        nToolTipOpening(getPtr(), event);
    }

    /**
     * Occurs when the data context for this element changes
     */
    public final void dataContextChangedEvent(final NSDependencyPropertyChangedEventHandler event) {
        nDataContextChanged(getPtr(), event);
    }

    /**
     * Occurs when this element is initialized
     */
    public final void initializedEvent(final NSEventHandler event) {
        nInitialized(getPtr(), event);
    }

    /**
     * Notifies when an ancestor has changed its parent
     */
    public final void ancestorChangedEvent(final NSAncestorChangedDelegate event) {
        nAncestorChanged(getPtr(), event);
    }

    private static native int nGetFlowDirectionStatic(long objPtr);

    private static native void nSetFlowDirectionStatic(long objPtr, int flowDirection);

    private static native float nGetActualHeight(long ptr);

    private static native float nGetActualWidth(long ptr);

    private static native int nGetBlendingMode(long ptr);

    private static native void nSetBlendingMode(long ptr, int value);

    private static native long nGetContextMenu(long ptr);

    private static native void nSetContextMenu(long ptr, long contextPtr);

    private static native long nGetCursor(long ptr);

    private static native void nSetCursor(long ptr, long cursorPtr);

    private static native long nGetDataContext(long ptr);

    private static native void nSetDataContext(long ptr, long cursorPtr);

    private static native long nGetDefaultStyleKey(long ptr);

    private static native void nSetDefaultStyleKey(long ptr, long type_ptr);

    private static native int nGetFlowDirection(long ptr);

    private static native void nSetFlowDirection(long ptr, int value);

    private static native long nGetFocusVisualStyle(long ptr);

    private static native void nSetFocusVisualStyle(long ptr, long style_ptr);

    private static native boolean nGetForceCursor(long ptr);

    private static native void nSetForceCursor(long ptr, boolean value);

    private static native float nGetHeight(long ptr);

    private static native void nSetHeight(long ptr, float value);

    private static native int nGetHorizontalAlignment(long ptr);

    private static native void nSetHorizontalAlignment(long ptr, int value);

    private static native int nGetInputScope(long ptr);

    private static native void nSetInputScope(long ptr, int value);

    private static native long nGetLayoutTransform(long ptr);

    private static native void nSetLayoutTransform(long ptr, long transform_ptr);

    private static native void nGetMargin(long ptr, NSThickness out);

    private static native void nSetMargin(long ptr, NSThickness in);

    private static native float nGetMaxHeight(long ptr);

    private static native void nSetMaxHeight(long ptr, float value);

    private static native float nGetMaxWidth(long ptr);

    private static native void nSetMaxWidth(long ptr, float value);

    private static native float nGetMinHeight(long ptr);

    private static native void nSetMinHeight(long ptr, float value);

    private static native float nGetMinWidth(long ptr);

    private static native void nSetMinWidth(long ptr, float value);

    private static native String nGetName(long ptr);

    private static native void nSetName(long ptr, String str);

    private static native boolean nGetOverridesDefaultStyle(long ptr);

    private static native void nSetOverridesDefaultStyle(long ptr, boolean value);

    private static native int nGetPPAAMode(long ptr);

    private static native void nSetPPAAMode(long ptr, int index);

    private static native float nGetPPAAIn(long ptr);

    private static native void nSetPPAAIn(long ptr, float value);

    private static native float nGetPPAAOut(long ptr);

    private static native void nSetPPAAOut(long ptr, float value);

    private static native void nSetStyle(long ptr, long style_ptr);

    private static native long nGetStyle(long ptr);

    private static native long nGetTag(long ptr);

    private static native void nSetTag(long ptr, long component_ptr);

    private static native void nSetTagString(long ptr, String value);

    private static native long nGetToolTip(long ptr);

    private static native void nSetToolTip(long ptr, long component_ptr);

    private static native void nSetToolTipString(long ptr, String tooltip);

    private static native boolean nGetUseLayoutRounding(long ptr);

    private static native void nSetUseLayoutRounding(long ptr, boolean value);

    private static native int nGetVerticalAlignment(long ptr);

    private static native void nSetVerticalAlignment(long ptr, int alight);

    private static native float nGetWidth(long ptr);

    private static native void nSetWidth(long ptr, float w);

    private static native long nGetTriggers(long ptr);

    private static native long nGetBindingExpression(long ptr, long dp_ptr);

    private static native long nSetBinding(long ptr, long dp_ptr, long base_ptr);

    private static native long nSetBindingString(long ptr, long dp_ptr, String path);

    private static native void nSetResourceReference(long ptr, long dp_ptr, String name);

    private static native boolean nIsLoaded(long ptr);

    private static native void nBringIntoView(long ptr);

    private static native void nBringIntoViewRect(long ptr, NSRect rect);

    private static native long nGetTimeManager(long ptr);

    private static native long nGetParent(long ptr);

    private static native boolean nApplyTemplate(long ptr);

    private static native long nGetParentOrTemplatedParent(long ptr);

    private static native long nGetTemplatedParent(long ptr);

    private static native void nSetTemplatedParent(long ptr, long templatedParent_ptr, long frameworkTemplate_ptr);

    private static native long nGetFrameworkTemplate(long ptr);

    private static native void nClearFrameworkTemplate(long ptr);

    private static native long nClone(long ptr, long parent_ptr, long templatedParent_ptr, long template_ptr);

    private static native long nGetStateGroupsRoot(long ptr);

    private static native long nFindName(long ptr, String name);

    private static native void nFindNameAndScope(long ptr, String name, NSObjectWithNameScope scope);

    private static native void nRegisterName(long ptr, String name, long component_ptr);

    private static native void nUnregisterName(long ptr, String name);

    private static native void nUpdateName(long ptr, String name, long component_ptr);

    private static native long nFindResource(long ptr, String key);

    private static native long nGetResources(long ptr);

    private static native void nSetResources(long ptr, long resource_ptr);

    private static native boolean nConnectField(long ptr, long object_ptr, String name);

    private static native boolean nConnectEvent(long ptr, long source_ptr, String event, String name);

    private static native void nContextMenuClosing(long ptr, NSContextMenuEvent closing);

    private static native void nContextMenuOpening(long ptr, NSContextMenuEvent opening);

    private static native void nLoaded(long ptr, NSRoutedEventHandler event);

    private static native void nReloaded(long ptr, NSRoutedEventHandler event);

    private static native void nUnloaded(long ptr, NSRoutedEventHandler event);

    private static native void nRequestBringIntoView(long ptr, NSRequestBringIntoViewEventHandler event);

    private static native void nSizeChanged(long ptr, NSSizeChangedEventHandler event);

    private static native void nToolTipClosing(long ptr, NSToolTipEventHandler event);

    private static native void nToolTipOpening(long ptr, NSToolTipEventHandler event);

    private static native void nDataContextChanged(long ptr, NSDependencyPropertyChangedEventHandler event);

    private static native void nInitialized(long ptr, NSEventHandler event);

    private static native void nAncestorChanged(long ptr, NSAncestorChangedDelegate event);
}


