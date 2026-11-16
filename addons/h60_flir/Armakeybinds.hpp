class CfgUserActions
{
	class hct_Flir_ZoomIn {
		displayName = "$STR_hct_h60_flir_FLIRZoomIn";
		tooltip = "$STR_hct_h60_flir_HitThisKeyToZoomTheFlirMfdIn";
		onActivate = "[1] call hct_h60_flir_fnc_keyZoom";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_ZoomOut {
		displayName = "$STR_hct_h60_flir_FLIRZoomOut";
		tooltip = "$STR_hct_h60_flir_HitThisKeyToZoomTheFlirMfdOut";
		onActivate = "[-1] call hct_h60_flir_fnc_keyZoom";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_Aim {
		displayName = "$STR_hct_h60_flir_FLIRSlewAim";
		tooltip = "$STR_hct_h60_flir_HoldThisKeyAndUseMouseOrAim";
		onActivate = "call hct_h60_flir_fnc_FlirAimToggle";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_SlewUp {
		displayName = "$STR_hct_h60_flir_FLIRSlewUp";
		tooltip = "$STR_hct_h60_flir_HitThisKeyToZoomTheFlirMfdUp";
		onActivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_up = 1;";		// _this is always true.
		onDeactivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_up = 0;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_SlewDown {
		displayName = "$STR_hct_h60_flir_FLIRSlewDown";
		tooltip = "$STR_hct_h60_flir_HitThisKeyToZoomTheFlirMfdDown";
		onActivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_down = 1;";		// _this is always true.
		onDeactivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_down = 0;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_SlewLeft {
		displayName = "$STR_hct_h60_flir_FLIRSlewLeft";
		tooltip = "$STR_hct_h60_flir_HitThisKeyToZoomTheFlirMfdLeft";
		onActivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_left = 1;";		// _this is always true.
		onDeactivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_left = 0;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_SlewRight {
		displayName = "$STR_hct_h60_flir_FLIRSlewRight";
		tooltip = "$STR_hct_h60_flir_HitThisKeyToZoomTheFlirMfdRight";
		onActivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_right = 1;";		// _this is always true.
		onDeactivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_right = 0;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_TdcWaypointSet {
		displayName = "$STR_hct_h60_flir_TDCWaypointSet";
		tooltip = "$STR_hct_h60_flir_MarkAWaypointAtWhereverFLIRIsCurrentlyDesignatin";
		onActivate = "call hct_h60_flir_fnc_keyTdcWaypointSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_TdcSlewWaypoint {
		displayName = "$STR_hct_h60_flir_TDCSlewWaypoint";
		tooltip = "$STR_hct_h60_flir_SlewFLIRToTheCurrentGroupWaypoint";
		onActivate = "call hct_h60_flir_fnc_keyTdcSlewWaypoint;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
};
class CfgDefaultKeysPresets {};
class UserActionGroups
{
	class hct_KeyBinds_FLIR {
		name = "H-60 FLIR"; // Display name of your category.
		isAddon = 1;
		group[] = {
		"hct_Flir_ZoomIn",
		"hct_Flir_ZoomOut",
		"hct_Flir_Aim",
		"hct_Flir_SlewUp",
		"hct_Flir_SlewDown",
		"hct_Flir_SlewLeft",
		"hct_Flir_SlewRight",
		"hct_Flir_TdcWaypointSet",
		"hct_Flir_TdcSlewWaypoint"
		}; // List of all actions inside this category.
	};
};
