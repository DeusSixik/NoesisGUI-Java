package dev.sixik.noesisgui.nsgui;

public enum NSGui_RenderFlags {

    /**
     * Toggles wireframe mode when rendering triangles
     */
    WIREFRAME(1),

    /**
     * Each batch submitted to the GPU is given a unique solid color
     */
    COLOR_BATCHES(2),

    /**
     * Displays pixel overdraw using blending layers. Different colors are used for each type
     * of triangles. 'Green' for normal ones, 'Red' for opacities and 'Blue' for clipping masks
     */
    OVERDRAW(4),

    /**
     * Inverts the render vertically
     */
    FLIP_Y(8),

    /**
     * Per-Primitive Antialiasing extrudes the contours of the geometry and smooths them.
     * It is a 'cheap' antialiasing algorithm useful when GPU MSAA is not enabled
     */
    PPAA(16),

    /**
     * Enables subpixel rendering compatible with LCD displays
     */
    LCD(32),

    /**
     * Displays glyph atlas as a small overlay for debugging purposes
     */
    SHOW_GLYPHS(64),

    /**
     * Displays ramp atlas as a small overlay for debugging purposes
     */
    SHOW_RAMPS(128),

    /**
     * Enables testing against the content of the depth buffer
     */
    DEPTH_TESTING(256);

    public final int value;

    NSGui_RenderFlags(int value) {
        this.value = value;
    }
}
