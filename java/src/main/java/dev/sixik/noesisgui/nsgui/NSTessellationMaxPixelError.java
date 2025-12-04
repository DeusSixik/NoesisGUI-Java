package dev.sixik.noesisgui.nsgui;

public class NSTessellationMaxPixelError {

    public float error;

    public NSTessellationMaxPixelError(float error) {
        this.error = error;
    }

    /// MediumQuality is usually fine for PPAA (non-multisampled) while HighQuality is the
    /// recommended pixel error if you are rendering to a 8x multisampled surface

    public static NSTessellationMaxPixelError LowQuality() {
        return new NSTessellationMaxPixelError(0.7f);
    }

    public static NSTessellationMaxPixelError MediumQuality() {
        return new NSTessellationMaxPixelError(0.4f);
    }

    public static NSTessellationMaxPixelError HighQuality() {
        return new NSTessellationMaxPixelError(0.2f);
    }
 }
