package dev.sixik.noesisgui.nscore;

public class NSObjectWithNameScope {

    private NSBaseComponent component;
    private NSINameScope scope;

    public long object_ptr;
    public long scope_ptr;

    public final NSBaseComponent getComponent() {
        if(object_ptr == 0)
            return null;

        if(component == null) {
            component = new NSBaseComponent(object_ptr);
        } else if(component.getPtr() != object_ptr) {
            component = new NSBaseComponent(object_ptr);
        }
        return component;
    }

    public final NSInterface getScope() {
        if(scope_ptr == 0)
            return null;

        if(scope == null) {
            scope = new NSINameScope(scope_ptr);
        } else if(scope.getPtr() != scope_ptr) {
            scope = new NSINameScope(scope_ptr);
        }
        return scope;
    }
}
