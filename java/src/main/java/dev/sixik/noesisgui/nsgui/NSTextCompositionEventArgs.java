package dev.sixik.noesisgui.nsgui;

public class NSTextCompositionEventArgs extends NSInputEventArgs{

    public final int uniCode;

    public NSTextCompositionEventArgs(long source_ptr, long routedEvent_ptr, boolean handled, int unicode) {
        super(source_ptr, routedEvent_ptr, handled);
        this.uniCode = unicode;
    }

    public final char[] toChars() {
        return Character.toChars(uniCode);
    }

    public final String asString() {
        return new String(Character.toChars(uniCode));
    }
}
