package dev.sixik.noesisgui.nsgui;

/**
 * Describes the action that caused the DictionaryChanged event
 */
public enum NSGui_NotifyDictionaryChangedAction {
    /**
     * One item was added to the dictionary
     */
    NotifyDictionaryChangedAction_Add,

    /**
     * One item was removed from the dictionary
     */
    NotifyDictionaryChangedAction_Remove,

    /**
     * One item was replaced in the dictionary
     */
    NotifyDictionaryChangedAction_Replace,

    /**
     * The content of the dictionary was cleared
     */
    NotifyDictionaryChangedAction_Reset,

    /**
     * The content of the dictionary is going to be cleared
     */
    NotifyDictionaryChangedAction_PreReset
}
