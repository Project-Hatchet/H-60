class CfgUserActions
{
	class hct_Flir_ZoomIn {
		displayName = "FLIR Zoom In";
		tooltip = "Hit this key to zoom the flir mfd in";
		onActivate = "[1] call hct_h60_flir_fnc_keyZoom";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_ZoomOut {
		displayName = "FLIR Zoom Out";
		tooltip = "Hit this key to zoom the flir mfd out";
		onActivate = "[-1] call hct_h60_flir_fnc_keyZoom";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_Aim {
		displayName = "FLIR Slew Aim";
		tooltip = "Hold this key and use mouse or 'Aim <Up|Down|Left|Right>";
		onActivate = "call hct_h60_flir_fnc_FlirAimToggle";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_SlewUp {
		displayName = "FLIR Slew Up";
		tooltip = "Hit this key to zoom the flir mfd up";
		onActivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_up = 1;";		// _this is always true.
		onDeactivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_up = 0;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_SlewDown {
		displayName = "FLIR Slew Down";
		tooltip = "Hit this key to zoom the flir mfd down";
		onActivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_down = 1;";		// _this is always true.
		onDeactivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_down = 0;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_SlewLeft {
		displayName = "FLIR Slew Left";
		tooltip = "Hit this key to zoom the flir mfd left";
		onActivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_left = 1;";		// _this is always true.
		onDeactivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_left = 0;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_SlewRight {
		displayName = "FLIR Slew Right";
		tooltip = "Hit this key to zoom the flir mfd right";
		onActivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_right = 1;";		// _this is always true.
		onDeactivate = "if (hct_h60_flir_isPipHidden) exitWith {false}; hct_h60_flir_right = 0;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_TdcWaypointSet {
		displayName = "TDC Waypoint Set";
		tooltip = "Mark a waypoint at wherever FLIR is currently designating.";
		onActivate = "call hct_h60_flir_fnc_keyTdcWaypointSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_Flir_TdcSlewWaypoint {
		displayName = "TDC Slew Waypoint";
		tooltip = "Slew FLIR to the current group waypoint.";
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
