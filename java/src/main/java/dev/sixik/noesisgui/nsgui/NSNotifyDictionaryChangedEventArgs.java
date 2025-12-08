package dev.sixik.noesisgui.nsgui;

public class NSNotifyDictionaryChangedEventArgs {

    public NSGui_NotifyDictionaryChangedAction action;
    public String key;
    public long oldValue_ptr;
    public long newValue_ptr;

    public NSNotifyDictionaryChangedEventArgs(NSGui_NotifyDictionaryChangedAction action, String key, long oldValue_ptr, long newValue_ptr) {
        this.action = action;
        this.key = key;
        this.oldValue_ptr = oldValue_ptr;
        this.newValue_ptr = newValue_ptr;
    }
}
