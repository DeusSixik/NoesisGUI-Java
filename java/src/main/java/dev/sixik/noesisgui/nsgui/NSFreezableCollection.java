package dev.sixik.noesisgui.nsgui;

public class NSFreezableCollection extends NSBaseFreezableCollection{

    public NSFreezableCollection(long ptr) {
        super(ptr);
    }

//    /**
//     * Gets the element at the specified index
//     */
//    public final T get(final int index) {
//        Object obj = nGet(getPtr(), index);
//        if(obj == null) return null;
//        return (T)obj;
//    }
//
//    /**
//     * Sets the element at the specified index
//     */
//    public final void set(final int index, final T item) {
//        nSet(getPtr(), index, item.getPtr());
//    }
//
//    /**
//     * Adds an item to the collection. Returns The position into which the new element was
//     * inserted, or -1 to indicate that the item was not inserted into the collection
//     */
//    public final void add(final T item) {
//        nAdd(getPtr(), item.getPtr());
//    }
//
//    /**
//     * Inserts an item to the collection at the specified index
//     */
//    public final void insert(final int index, final T item) {
//        nInsert(getPtr(), index, item.getPtr());
//    }
//
//    /**
//     * Determines whether the collection contains a specific value
//     */
//    public final boolean contains(final T item) {
//        return nContains(getPtr(), item.getPtr());
//    }
//
//    /**
//     * Determines the index of a specific item in the collection. Returns -1 if not found
//     */
//    public final int indexOf(final T item) {
//        return nIndexOf(getPtr(), item.getPtr());
//    }
//
//    /**
//     * Removes the first occurrence of a specific object from the collection. Returns true if item
//     * was removed, false to indicate that the item was not found in the collection
//     */
//    public final boolean remove(final T item) {
//        return nRemove(getPtr(), item.getPtr());
//    }
//
//    private static native Object nGet(long ptr, int value);
//
//    private static native void nSet(long ptr, int value, long element_ptr);
//
//    private static native void nAdd(long ptr, long element_ptr);
//
//    private static native void nInsert(long ptr, int index, long element_ptr);
//
//    private static native boolean nContains(long ptr, long element_ptr);
//
//    private static native int nIndexOf(long ptr, long element_ptr);
//
//    private static native boolean nRemove(long ptr, long element_ptr);
}
