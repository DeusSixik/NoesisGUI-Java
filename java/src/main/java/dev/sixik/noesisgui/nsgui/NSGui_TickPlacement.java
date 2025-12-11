package dev.sixik.noesisgui.nsgui;

public enum NSGui_TickPlacement {

    /**
     * No tick marks appear
     */
    TickPlacement_None,

    /**
     * Tick marks appear above the Track for a horizontal Slider, or to the left of the Track for
     * a vertical Slider
     */
    TickPlacement_TopLeft,

    /**
     * Tick marks appear below the Track for a horizontal Slider, or to the right of the Track for
     * a vertical Slider
     */
    TickPlacement_BottomRight,

    /**
     * Tick marks appear above and below the Track bar for a horizontal Slider, or to the left and
     * right of the Track for a vertical Slider
     */
    TickPlacement_Both
}
