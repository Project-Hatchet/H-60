class CfgUserActions
{
	class Vtx_Flir_ZoomIn {
		displayName = "FLIR Zoom In";
		tooltip = "Hit this key to zoom the flir mfd in";
		onActivate = "[1] call vtx_uh60_flir_fnc_keyZoom";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_Flir_ZoomOut {
		displayName = "FLIR Zoom Out";
		tooltip = "Hit this key to zoom the flir mfd out";
		onActivate = "[-1] call vtx_uh60_flir_fnc_keyZoom";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_Flir_Aim {
		displayName = "FLIR Slew Aim";
		tooltip = "Hold this key and use mouse or 'Aim <Up|Down|Left|Right>";
		onActivate = "call vtx_uh60_flir_fnc_FlirAimToggle";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_Flir_SlewUp {
		displayName = "FLIR Slew Up";
		tooltip = "Hit this key to zoom the flir mfd up";
		onActivate = "if (vtx_uh60_flir_isPipHidden) exitWith {false}; vtx_uh60_flir_up = 1;";		// _this is always true.
		onDeactivate = "if (vtx_uh60_flir_isPipHidden) exitWith {false}; vtx_uh60_flir_up = 0;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_Flir_SlewDown {
		displayName = "FLIR Slew Down";
		tooltip = "Hit this key to zoom the flir mfd down";
		onActivate = "if (vtx_uh60_flir_isPipHidden) exitWith {false}; vtx_uh60_flir_down = 1;";		// _this is always true.
		onDeactivate = "if (vtx_uh60_flir_isPipHidden) exitWith {false}; vtx_uh60_flir_down = 0;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_Flir_SlewLeft {
		displayName = "FLIR Slew Left";
		tooltip = "Hit this key to zoom the flir mfd left";
		onActivate = "if (vtx_uh60_flir_isPipHidden) exitWith {false}; vtx_uh60_flir_left = 1;";		// _this is always true.
		onDeactivate = "if (vtx_uh60_flir_isPipHidden) exitWith {false}; vtx_uh60_flir_left = 0;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_Flir_SlewRight {
		displayName = "FLIR Slew Right";
		tooltip = "Hit this key to zoom the flir mfd right";
		onActivate = "if (vtx_uh60_flir_isPipHidden) exitWith {false}; vtx_uh60_flir_right = 1;";		// _this is always true.
		onDeactivate = "if (vtx_uh60_flir_isPipHidden) exitWith {false}; vtx_uh60_flir_right = 0;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
};
class CfgDefaultKeysPresets {};
class UserActionGroups
{
	class Vtx_KeyBinds_FLIR {
		name = "H-60 FLIR"; // Display name of your category.
		isAddon = 1;
		group[] = {
		"Vtx_Flir_ZoomIn",
		"Vtx_Flir_ZoomOut",
		"Vtx_Flir_Aim",
		"Vtx_Flir_SlewUp",
		"Vtx_Flir_SlewDown",
		"Vtx_Flir_SlewLeft",
		"Vtx_Flir_SlewRight",
		}; // List of all actions inside this category.
	};
};