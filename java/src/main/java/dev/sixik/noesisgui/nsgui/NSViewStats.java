package dev.sixik.noesisgui.nsgui;

public class NSViewStats {

    public float frameTime;
    public float updateTime;
    public float renderTime;

    public long triangles;
    public long draws;
    public long batches;

    public long tessellations;
    public long flushes;
    public long geometrySize;

    public long masks;
    public long opacities;
    public long renderTargetSwitches;

    public long uploadedRamps;
    public long rasterizedGlyphs;
    public long discardedGlyphTiles;
}
