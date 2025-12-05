package dev.sixik.noesisgui.nsgui;

/**
 *  Indicates where an element should be displayed on the horizontal axis relative to the
 *  allocated layout slot of the parent element
 */
public enum NSGui_HorizontalAlignment {

    /**
     * Element aligned to the left of the layout slot for the parent
     */
    HorizontalAlignment_Left,

    /**
     * Element aligned to the center of the layout slot for the parent
     */
    HorizontalAlignment_Center,

    /**
     * Element aligned to the right of the layout slot for the parent
     */
    HorizontalAlignment_Right,

    /**
     * Element stretched to fill the entire layout slot of the parent
     */
    HorizontalAlignment_Stretch
}
