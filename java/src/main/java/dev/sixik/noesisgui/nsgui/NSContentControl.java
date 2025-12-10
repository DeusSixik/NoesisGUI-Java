package dev.sixik.noesisgui.nsgui;

import dev.sixik.noesisgui.nscore.NSBaseComponent;

public class NSContentControl extends NSControl{

    public NSContentControl(long ptr) {
        super(ptr);
    }

    /**
     * Gets or sets the content of a ContentControl
     */
    public final NSBaseComponent getContent() {
        return new NSBaseComponent(nGetContent(getPtr()));
    }

    /**
     * Gets or sets the content of a ContentControl
     */
    public final void setContent(final NSBaseComponent component) {
        nSetContent(getPtr(), component.getPtr());
    }

    /**
     * Gets or sets the content of a ContentControl
     */
    public final void setContent(final String content) {
        nSetContentString(getPtr(), content);
    }

    /**
     * Gets or sets the format used to display the content of the control as a string.
     */
    public final String getContentStringFormat() {
        return nGetContentStringFormat(getPtr());
    }

    /**
     * Gets or sets the format used to display the content of the control as a string.
     */
    public final void setContentStringFormat(final String value) {
        nSetContentStringFormat(getPtr(), value);
    }

    /**
     * Gets or sets the template used to display the content of the ContentControl
     */
    public final NSDataTemplate getContentTemplate() {
        return new NSDataTemplate(nGetContentTemplate(getPtr()));
    }

    /**
     * Gets or sets the template used to display the content of the ContentControl
     */
    public final void setContentTemplate(final NSDataTemplate template) {
        nSetContentTemplate(getPtr(), template.getPtr());
    }

    /**
     * Gets or sets a DataTemplateSelector that provides custom logic for choosing the template
     * used to display the content
     */
    public final NSDataTemplateSelector getContentTemplateSelector() {
        return new NSDataTemplateSelector(nGetContentTemplateSelector(getPtr()));
    }

    /**
     * Gets or sets a DataTemplateSelector that provides custom logic for choosing the template
     * used to display the content
     */
    public final void setContentTemplateSelector(final NSDataTemplateSelector selector) {
        nSetContentTemplateSelector(getPtr(), selector.getPtr());
    }

    /**
     * Gets a value that indicates whether the ContentControl contains content
     */
    public final boolean getHasContent() {
        return nGetHasContent(getPtr());
    }

    private static native long nGetContent(long ptr);

    private static native void nSetContent(long ptr, long component_ptr);

    private static native void nSetContentString(long ptr, String content);

    private static native String nGetContentStringFormat(long ptr);

    private static native void nSetContentStringFormat(long ptr, String value);

    private static native long nGetContentTemplate(long ptr);

    private static native void nSetContentTemplate(long ptr, long data_template_ptr);

    private static native long nGetContentTemplateSelector(long ptr);

    private static native void nSetContentTemplateSelector(long ptr, long selector_ptr);

    private static native boolean nGetHasContent(long ptr);
}
