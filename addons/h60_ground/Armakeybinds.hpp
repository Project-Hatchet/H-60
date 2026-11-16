class CfgUserActions
{
 class hct_ParkingBrake_Toggle {
    displayName = "$STR_hct_h60_ground_ParkingBrake";
		tooltip = "$STR_hct_h60_ground_TogglesTheParkingBrakeLeverWorksUnderSFMWhereThe";
		onActivate = "[hct_vehicle] call hct_h60_ground_fnc_pbToggle;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class hct_LandingLight_Up {
    displayName = "$STR_hct_h60_ground_LandingLightUp";
		tooltip = "$STR_hct_h60_ground_RotateTheLandingLightForward";
		onActivate = "[hct_vehicle, 'landinglight_elev', rad 5] call hct_h60_misc_fnc_animateIncrement";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class hct_LandingLight_Down {
    displayName = "$STR_hct_h60_ground_LandingLightDown";
		tooltip = "$STR_hct_h60_ground_RotateTheLandingLightRearward";
		onActivate = "[hct_vehicle, 'landinglight_elev', rad -5] call hct_h60_misc_fnc_animateIncrement";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class hct_SearchLight_Up {
    displayName = "$STR_hct_h60_ground_SearchLightUp";
		tooltip = "$STR_hct_h60_ground_RotateTheSearchLightForward";
		onActivate = "[hct_vehicle, 'searchlight_elev', rad 5] call hct_h60_misc_fnc_animateIncrement";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class hct_SearchLight_Down {
    displayName = "$STR_hct_h60_ground_SearchLightDown";
		tooltip = "$STR_hct_h60_ground_RotateTheSearchLightRearward";
		onActivate = "[hct_vehicle, 'searchlight_elev', rad -5] call hct_h60_misc_fnc_animateIncrement";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class hct_SearchLight_Right {
    displayName = "$STR_hct_h60_ground_SearchLightRight";
		tooltip = "$STR_hct_h60_ground_RotateTheSearchLightLight";
		onActivate = "[hct_vehicle, 'searchlight_turn', rad -5] call hct_h60_misc_fnc_animateIncrement";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class hct_SearchLight_Left {
    displayName = "$STR_hct_h60_ground_SearchLightLeft";
		tooltip = "$STR_hct_h60_ground_RotateTheSearchLightLeft";
		onActivate = "[hct_vehicle, 'searchlight_turn', rad 5] call hct_h60_misc_fnc_animateIncrement";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
};
class CfgDefaultKeysPresets{};
class UserActionGroups
{
	class hct_KeyBinds_Cockpit {
		name = "H-60 Cockpit"; // Display name of your category.
		isAddon = 1;
		group[] = {
		"hct_ParkingBrake_Toggle",
    "hct_LandingLight_Up",
    "hct_LandingLight_Down",
    "hct_SearchLight_Up",
    "hct_SearchLight_Down",
    "hct_SearchLight_Right",
    "hct_SearchLight_Left"
		}; // List of all actions inside this category.
	};
};
