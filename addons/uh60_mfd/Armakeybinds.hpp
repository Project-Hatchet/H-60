class CfgUserActions
{
	class Vtx_MFD_SlewUp {
		displayName = "Slew Cursor Up";
		tooltip = "Moves the MFD Cursor Up";
		onActivate = "['slewY', 1] call vtx_uh60_mfd_fnc_interaction_slew;";		// _this is always true.
		onDeactivate = "['slewY', 0] call vtx_uh60_mfd_fnc_interaction_slew;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
		class Vtx_MFD_SlewDown {
		displayName = "Slew Cursor Down";
		tooltip = "Moves the MFD Cursor Down";
		onActivate = "['slewY', -1] call vtx_uh60_mfd_fnc_interaction_slew;";		// _this is always true.
		onDeactivate = "['slewY', 0] call vtx_uh60_mfd_fnc_interaction_slew;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
		class Vtx_MFD_SlewLeft {
		displayName = "Slew Cursor Left";
		tooltip = "Moves the MFD Cursor Left";
		onActivate = "['slewX', -1] call vtx_uh60_mfd_fnc_interaction_slew;";		// _this is always true.
		onDeactivate = "['slewX', 0] call vtx_uh60_mfd_fnc_interaction_slew;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
		class Vtx_MFD_SlewRight {
		displayName = "Slew Cursor Right";
		tooltip = "Moves the MFD Cursor Right";
		onActivate = "['slewX', 1] call vtx_uh60_mfd_fnc_interaction_slew;";		// _this is always true.
		onDeactivate = "['slewX', 0] call vtx_uh60_mfd_fnc_interaction_slew;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
		class Vtx_MFD_CursorSelect {
		displayName = "Cursor Select";
		tooltip = "Opens the Action Menu on a selected item";
		onActivate = "['slewAction', 1] call vtx_uh60_mfd_fnc_interaction_slew;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
};
class CfgDefaultKeysPresets {};
class UserActionGroups
{
	class Vtx_KeyBinds_MFD {
		name = "H-60 Multi-Function Display"; // Display name of your category.
		isAddon = 1;
		group[] = {
		"Vtx_MFD_SlewUp",
		"Vtx_MFD_SlewDown",
		"Vtx_MFD_SlewLeft",
		"Vtx_MFD_SlewRight",
		"Vtx_MFD_CursorSelect",
		}; // List of all actions inside this category.
	};
};