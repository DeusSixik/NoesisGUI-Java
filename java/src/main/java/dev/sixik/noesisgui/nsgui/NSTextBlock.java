package dev.sixik.noesisgui.nsgui;

/**
 * Provides a lightweight control for displaying small amounts of text content.
 * <p>
 * A TextBlock can contain a string in its {@code Text} property or {@code Inline} flow content elements, such
 * as Bold, Hyperlink, and InlineUIContainer, in its {@code Inlines} property.
 * <p>
 * TextBlock is designed to be lightweight, and is geared specifically at integrating small
 * portions of flow content into a user interface (UI). TextBlock is optimized for single-line
 * display, and provides good performance for displaying up to a few lines of content.
 * <p>
 * Horizontally aligning text within a TextBlock is done with the {@code TextAlignment} property.
 * Aligning the TextBlock within the layout of the page is done with the {@code HorizontalAlignment} and
 * {@code VerticalAlignment} properties.
 *
 * <h3>XAML Example:</h3>
 * <pre>{@code
 * <Page xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation">
 *   <StackPanel>
 *     <TextBlock TextWrapping="Wrap">
 *       <Bold>TextBlock</Bold> is designed to be <Italic>lightweight</Italic>,
 *       and is geared specifically at integrating <Italic>small</Italic> portions
 *       of flow content into a UI.
 *     </TextBlock>
 *     <Button Width="100" Margin="10">Click Me</Button>
 *     <TextBlock TextWrapping="Wrap" Background="DarkSalmon" TextAlignment="Center">
 *       By default, a TextBlock provides no UI beyond simply displaying its contents.
 *     </TextBlock>
 *     <Button Width="100" Margin="10">Click Me</Button>
 *   </StackPanel>
 * </Page>
 * }</pre>
 *
 * @see <a href="http://msdn.microsoft.com/en-us/library/system.windows.controls.textblock.aspx">
 *      Microsoft Documentation: TextBlock Class</a>
 */
public class NSTextBlock extends NSFrameworkElement {

    public NSTextBlock() {
        this(nCreate());
    }

    public NSTextBlock(long ptr) {
        super(ptr);
    }

    /**
     * Gets or sets the Brush used to fill the background of content area.
     */
    public final NSBrush getBackground() {
        return new NSBrush(nGetBackground(getPtr()));
    }

    /**
     * Gets or sets the Brush used to fill the background of content area.
     */
    public final void setBackground(final NSBrush brush) {
        nSetBackground(getPtr(), brush.getPtr());
    }

    /**
     * Gets or sets the uniform spacing between characters, in units of 1/1000 of an em.
     */
    public final int getCharacterSpacing() {
        return nGetCharacterSpacing(getPtr());
    }

    /**
     * Gets or sets the uniform spacing between characters, in units of 1/1000 of an em.
     */
    public final void setCharacterSpacing(final int spacing) {
        nSetCharacterSpacing(getPtr(), spacing);
    }

    /**
     * Gets or sets the preferred top-level font family for the TextBlock.
     */
    public final NSFontFamily getFontFamily() {
        return new NSFontFamily(nGetFontFamily(getPtr()));
    }

    /**
     * Gets or sets the preferred top-level font family for the TextBlock.
     */
    public final void setFontFamily(final NSFontFamily fontFamily) {
        nSetFontFamily(getPtr(), fontFamily.getPtr());
    }

    /**
     * Gets or sets the top-level font size for the TextBlock.
     */
    public final float getFontSize() {
        return nGetFontSize(getPtr());
    }

    /**
     * Gets or sets the top-level font size for the TextBlock.
     */
    public final void setFontSize(final float value) {
        nSetFontSize(getPtr(), value);
    }

    /**
     * Gets or sets the top-level font stretch for the TextBlock.
     */
    public final NSGui_FontStretch getFontStretch() {
        return NSGui_FontStretch.values()[nGetFontStretch(getPtr())];
    }

    /**
     * Gets or sets the top-level font stretch for the TextBlock.
     */
    public final void setFontStretch(final NSGui_FontStretch fontStretch) {
        nSetFontStretch(getPtr(), fontStretch.ordinal());
    }

    /**
     * Gets or sets the top-level font style for the TextBlock.
     */
    public final NSGui_FontStyle getFontStyle() {
        return NSGui_FontStyle.values()[nGetFontStyle(getPtr())];
    }

    /**
     * Gets or sets the top-level font style for the TextBlock.
     */
    public final void setFontStyle(final NSGui_FontStyle style) {
        nSetFontStyle(getPtr(), style.ordinal());
    }

    /**
     * Gets or sets the top-level font weight for the TextBlock.
     */
    public final NSGui_FontWeight getFontWeight() {
        return NSGui_FontWeight.get(nGetFontWeight(getPtr()));
    }

    /**
     * Gets or sets the top-level font weight for the TextBlock.
     */
    public final void setFontWeight(final NSGui_FontWeight weight) {
        nSetFontWeight(getPtr(), weight.value);
    }

    /**
     * Gets or sets the Brush to apply to the text contents of the TextBlock.
     */
    public final NSBrush getForeground() {
        return new NSBrush(nGetForeground(getPtr()));
    }

    /**
     * Gets or sets the Brush to apply to the text contents of the TextBlock.
     */
    public final void setForeground(final NSBrush brush) {
        nSetForeground(getPtr(), brush.getPtr());
    }

    /**
     * Gets an InlineCollection containing the top-level Inline elements that comprise the
     * contents of the TextBlock
     */
    public final NSInlineCollection getInlines() {
        return new NSInlineCollection(nGetInlines(getPtr()));
    }

    /**
     * Indicates if this TextBlock contains any inlines (avoids creating Inlines if not needed)
     */
    public final boolean hasInlines() {
        return nHasInlines(getPtr());
    }

    /**
     * Gets or sets the height of each line of content
     */
    public final float getLineHeight() {
        return nGetLineHeight(getPtr());
    }

    /**
     * Gets or sets the height of each line of content
     */
    public final void setLineHeight(final float value) {
        nSetLineHeight(getPtr(), value);
    }

    /**
     * Gets or sets the mechanism by which a line box is determined for each line of text
     */
    public final NSGui_LineStackingStrategy getLineStackingStrategy() {
        return NSGui_LineStackingStrategy.values()[nGetLineStackingStrategy(getPtr())];
    }

    /**
     * Gets or sets the mechanism by which a line box is determined for each line of text
     */
    public final void setLineStackingStrategy(final NSGui_LineStackingStrategy stackingStrategy) {
        nSetLineStackingStrategy(getPtr(), stackingStrategy.ordinal());
    }

    /**
     * Gets or sets the padding inside a control
     */
    public final NSThickness getPadding() {
        final NSThickness thickness = new NSThickness();
        getPadding(thickness);
        return thickness;
    }

    /**
     * Gets or sets the padding inside a control
     */
    public final void getPadding(final NSThickness thickness) {
        nGetPadding(getPtr(), thickness);
    }

    /**
     * Gets or sets the padding inside a control
     */
    public final void setPadding(final NSThickness thickness) {
        nSetPadding(getPtr(), thickness);
    }

    /**
     * Gets or sets the Brush used to stroke the text
     */
    public final NSBrush getStroke() {
        return new NSBrush(nGetStroke(getPtr()));
    }

    /**
     * Gets or sets the Brush used to stroke the text
     */
    public final void setStroke(final NSBrush brush) {
        nSetStroke(getPtr(), brush.getPtr());
    }

    /**
     * Gets or sets the width (in pixels) of the text stroke
     */
    public final float getStrokeThickness() {
        return nGetStrokeThickness(getPtr());
    }

    /**
     * Gets or sets the width (in pixels) of the text stroke
     */
    public final void setStrokeThickness(final float value) {
        nSetStrokeThickness(getPtr(), value);
    }

    /**
     * Gets or sets text alignment
     */
    public final NSGui_TextAlignment getTextAlignment() {
        return NSGui_TextAlignment.values()[nGetTextAlignment(getPtr())];
    }

    /**
     * Gets or sets text alignment
     */
    public final void setTextAlignment(final NSGui_TextAlignment alignment) {
        nSetTextAlignment(getPtr(), alignment.ordinal());
    }

    /**
     * Gets or sets the text decoration to apply to the text
     */
    public final NSGui_TextDecorations getTextDecorations() {
        return NSGui_TextDecorations.values()[nGetTextDecorations(getPtr())];
    }

    /**
     * Gets or sets the text decoration to apply to the text
     */
    public final void setTextDecorations(final NSGui_TextDecorations decorations) {
        nSetTextDecorations(getPtr(), decorations.ordinal());
    }

    /**
     * Gets or sets text string
     */
    public final String getText() {
        return nGetText(getPtr());
    }

    /**
     * Gets or sets text string
     */
    public final void setText(final String value) {
        nSetText(getPtr(), value);
    }

    /**
     * Gets or sets the text trimming behavior to employ when content overflows the content area
     */
    public final NSGui_TextTrimming getTextTrimming() {
        return NSGui_TextTrimming.values()[nGetTextTrimming(getPtr())];
    }

    /**
     * Gets or sets the text trimming behavior to employ when content overflows the content area
     */
    public final void setTextTrimming(final NSGui_TextTrimming textTrimming) {
        nSetTextTrimming(getPtr(), textTrimming.ordinal());
    }

    /**
     * Gets or sets text wrapping
     */
    public final NSGui_TextWrapping getTextWrapping() {
        return NSGui_TextWrapping.values()[nGetTextWrapping(getPtr())];
    }

    /**
     * Gets or sets text wrapping
     */
    public final void setTextWrapping(final NSGui_TextWrapping wrapping) {
        nSetTextWrapping(getPtr(), wrapping.ordinal());
    }

    /**
     * Indicates if first inline is generated from Text property
     */
    public final boolean firstInlineIsFromText() {
        return nFirstInlineIsFromText(getPtr());
    }

    /**
     * Gets the currently effective typography variations for the text contents of this TextBlock
     */
    public final NSTypography getTypography() {
        final NSTypography typography = new NSTypography();
        getTypography(typography);
        return typography;
    }

    /**
     * Gets the currently effective typography variations for the text contents of this TextBlock
     */
    public final void getTypography(final NSTypography typography) {
        nGetTypography(getPtr(), typography);
    }

    /**
     * Sets the currently effective typography variations for the text contents of this TextBlock
     */
    public final void setTypography(final NSTypography typography) {
        nSetTypography(getPtr(), typography);
    }

    /**
     * Returns the object used to layout and render text for this TextBlock
     */
    public final NSFormattedText getFormattedText() {
        return new NSFormattedText(nGetFormattedText(getPtr()));
    }

    private static native long nCreate();

    private static native long nGetBackground(long ptr);

    private static native void nSetBackground(long ptr, long brush_ptr);

    private static native int nGetCharacterSpacing(long ptr);

    private static native void nSetCharacterSpacing(long ptr, int value);

    private static native long nGetFontFamily(long ptr);

    private static native void nSetFontFamily(long ptr, long fontFamily_ptr);

    private static native float nGetFontSize(long ptr);

    private static native void nSetFontSize(long ptr, float value);

    private static native int nGetFontStretch(long ptr);

    private static native void nSetFontStretch(long ptr, int value);

    private static native int nGetFontStyle(long ptr);

    private static native void nSetFontStyle(long ptr, int value);

    private static native int nGetFontWeight(long ptr);

    private static native void nSetFontWeight(long ptr, int value);

    private static native long nGetForeground(long ptr);

    private static native void nSetForeground(long ptr, long brush_ptr);

    private static native long nGetInlines(long ptr);

    private static native boolean nHasInlines(long ptr);

    private static native float nGetLineHeight(long ptr);

    private static native void nSetLineHeight(long ptr, float value);

    private static native int nGetLineStackingStrategy(long ptr);

    private static native void nSetLineStackingStrategy(long ptr, int value);

    private static native void nGetPadding(long ptr, NSThickness thickness);

    private static native void nSetPadding(long ptr, NSThickness thickness);

    private static native long nGetStroke(long ptr);

    private static native void nSetStroke(long ptr, long brush_ptr);

    private static native float nGetStrokeThickness(long ptr);

    private static native void nSetStrokeThickness(long ptr, float value);

    private static native int nGetTextAlignment(long ptr);

    private static native void nSetTextAlignment(long ptr, int value);

    private static native int nGetTextDecorations(long ptr);

    private static native void nSetTextDecorations(long ptr, int value);

    private static native String nGetText(long ptr);

    private static native void nSetText(long ptr, String value);

    private static native int nGetTextTrimming(long ptr);

    private static native void nSetTextTrimming(long ptr, int value);

    private static native int nGetTextWrapping(long ptr);

    private static native void nSetTextWrapping(long ptr, int value);

    private static native boolean nFirstInlineIsFromText(long ptr);

    private static native void nGetTypography(long ptr, NSTypography typography);

    private static native void nSetTypography(long ptr, NSTypography typography);

    private static native long nGetFormattedText(long ptr);
}
