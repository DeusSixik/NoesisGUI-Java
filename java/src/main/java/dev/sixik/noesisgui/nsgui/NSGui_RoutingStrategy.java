package dev.sixik.noesisgui.nsgui;

/**
 * Defines the routing strategy of the dependency event.
 */
public enum NSGui_RoutingStrategy {

    /**
     * Event is routed to children elements of the tree
     */
    RoutingStrategy_Tunnel,

    /**
     * Event is routed to the root of the element tree
     */
    RoutingStrategy_Bubble,

    /**
     * Event is routed directly to a specific element in the tree
     */
    RoutingStrategy_Direct
}
