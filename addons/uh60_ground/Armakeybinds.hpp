class CfgUserActions
{
 class Vtx_ParkingBrake_Toggle {
    displayName = "Parking Brake";
		tooltip = "Toggles the parking brake lever (works under SFM, where the vanilla brake key does nothing).";
		onActivate = "[hct_vehicle] call vtx_uh60_ground_fnc_pbToggle;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_LandingLight_Up {
    displayName = "Landing Light Up";
		tooltip = "Rotate the landing light forward.";
		onActivate = "[hct_vehicle, 'landinglight_elev', rad 5] call vtx_uh60_misc_fnc_animateIncrement";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_LandingLight_Down {
    displayName = "Landing Light Down";
		tooltip = "Rotate the landing light rearward.";
		onActivate = "[hct_vehicle, 'landinglight_elev', rad -5] call vtx_uh60_misc_fnc_animateIncrement";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_SearchLight_Up {
    displayName = "Search Light Up";
		tooltip = "Rotate the Search light forward.";
		onActivate = "[hct_vehicle, 'searchlight_elev', rad 5] call vtx_uh60_misc_fnc_animateIncrement";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_SearchLight_Down {
    displayName = "Search Light Down";
		tooltip = "Rotate the Search light rearward.";
		onActivate = "[hct_vehicle, 'searchlight_elev', rad -5] call vtx_uh60_misc_fnc_animateIncrement";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_SearchLight_Right {
    displayName = "Search Light Right";
		tooltip = "Rotate the Search light light.";
		onActivate = "[hct_vehicle, 'searchlight_turn', rad -5] call vtx_uh60_misc_fnc_animateIncrement";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_SearchLight_Left {
    displayName = "Search Light Left";
		tooltip = "Rotate the Search light left.";
		onActivate = "[hct_vehicle, 'searchlight_turn', rad 5] call vtx_uh60_misc_fnc_animateIncrement";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
};
class CfgDefaultKeysPresets{};
class UserActionGroups
{
	class Vtx_KeyBinds_Cockpit {
		name = "H-60 Cockpit"; // Display name of your category.
		isAddon = 1;
		group[] = {
		"Vtx_ParkingBrake_Toggle",
    "Vtx_LandingLight_Up",
    "Vtx_LandingLight_Down",
    "Vtx_SearchLight_Up",
    "Vtx_SearchLight_Down",
    "Vtx_SearchLight_Right",
    "Vtx_SearchLight_Left"
		}; // List of all actions inside this category.
	};
};
