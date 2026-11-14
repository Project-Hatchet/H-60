/*
 * vtx_uh60_misc_fnc_setup
 *
 * Hatchet module hook: hides the vanilla info-panel pages the H-60's own displays replace.
 *
 * params [(object) vehicle]
 */

params ["_vehicle"];
// Landing/search light state lives on the aircraft (fnc_toggleLights), not here.
vtx_uh60_misc_btn_hold = false;


_vehicle enableInfoPanelComponent ["left", "MinimapDisplayComponent", false];
_vehicle enableInfoPanelComponent ["left", "SlingLoadDisplayComponent", false];
_vehicle enableInfoPanelComponent ["left", "SensorsDisplayComponent", false];
_vehicle enableInfoPanelComponent ["left", "UAVFeedDisplayComponent", false];
_vehicle enableInfoPanelComponent ["left", "TransportFeedDisplayComponent", false];
_vehicle enableInfoPanelComponent ["left", "CrewDisplayComponent", false];
_vehicle enableInfoPanelComponent ["right", "MinimapDisplayComponent", false];
_vehicle enableInfoPanelComponent ["right", "SlingLoadDisplayComponent", false];
_vehicle enableInfoPanelComponent ["right", "SensorsDisplayComponent", false];
_vehicle enableInfoPanelComponent ["right", "UAVFeedDisplayComponent", false];
_vehicle enableInfoPanelComponent ["right", "TransportFeedDisplayComponent", false];
_vehicle enableInfoPanelComponent ["right", "CrewDisplayComponent", false];

true
