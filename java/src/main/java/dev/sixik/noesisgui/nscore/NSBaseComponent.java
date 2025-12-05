package dev.sixik.noesisgui.nscore;

import java.lang.reflect.InvocationTargetException;
import java.util.function.Function;

public class NSBaseComponent extends NSBaseRefCounted {

    public NSBaseComponent(long ptr) {
        super(ptr);
    }

    /**
     * Deletes an object from memory. Call it only if you have created this object and NoesisGui
     * does not have the ability to manage the object.
     */
    public void destroy() {
        nativeDestroy();
    }

    public final <T extends NSBaseComponent> T castTo(Function<Long, T> constructor) {
        return constructor.apply(getPtr());
    }

    public final <T extends NSBaseComponent> T castTo(Class<T> castClass) throws Exception {
        return castClass.getConstructor(long.class).newInstance(getPtr());
    }

    private native void nativeDestroy();
}
