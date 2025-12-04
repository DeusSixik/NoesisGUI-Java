package dev.sixik.noesisgui.nsgui;

/**
* Specifies the direction within a user interface (UI) in which a desired focus change request is
* attempted. The direction is either based on tab order or by relative direction in layout.
**/
public enum NSGui_FocusNavigationDirection {

    /**
     * Move focus to the next focusable element in tab order. Not supported for PredictFocus.
     */
    FocusNavigationDirection_Next,

    /**
     * Move focus to the previous focusable element in tab order. Not supported for PredictFocus.
     */
    FocusNavigationDirection_Previous,

    /**
     * Move focus to the first focusable element in tab order. Not supported for PredictFocus.
     */
    FocusNavigationDirection_First,

    /**
     * Move focus to the last focusable element in tab order. Not supported for PredictFocus.
     */
    FocusNavigationDirection_Last,

    /**
     * Move focus to another focusable element to the left of the currently focused element.
     */
    FocusNavigationDirection_Left,

    /**
     * Move focus to another focusable element to the right of the currently focused element.
     */
    FocusNavigationDirection_Right,

    /**
     * Move focus to another focusable element upwards from the currently focused element.
     */
    FocusNavigationDirection_Up,

    /**
     * Move focus to another focusable element downwards from the currently focused element.
     */
    FocusNavigationDirection_Down
}
