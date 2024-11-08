class CfgUserActions
{
	class Vtx_RALT_Toggle {
		displayName = "ARM/DISARM RALT Hold";
		tooltip = "Toggles the Radar Altitude Hold Mode";
		onActivate = "[vehicle player, 'RALT'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_ALTP_Toggle {
		displayName = "ARM/DISARM ALTP";
		tooltip = "Toggles the Barometric Altitude Preselect Mode";
		onActivate = "[vehicle player, 'ALTP'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_BALT_Toggle {
		displayName = "ARM/DISARM ALT Hold";
		tooltip = "Toggles the Barometric Altitude Hold Mode";
		onActivate = "[vehicle player, 'ALT'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_IAS_Toggle {
		displayName = "ARM/DISARM IAS Hold";
		tooltip = "Toggles the Indicated Airspeed Hold Mode. NOT AVAILABLE IN AFM";
		onActivate = "[vehicle player, 'IAS'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_HDG_Toggle {
		displayName = "ARM/DISARM HDG Hold";
		tooltip = "Toggles the Heading Hold Mode. NOT AVAILABLE IN AFM";
		onActivate = "[vehicle player, 'HDG'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_FMS_Toggle {
		displayName = "ARM/DISARM FMS Coupling";
		tooltip = "Toggles the FMS Coupled Mode";
		onActivate = "[vehicle player, 'FMS'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
}; 
class CfgDefaultKeysPresets{};
class UserActionGroups
{
	class Vtx_KeyBinds_FDDCP {
		name = "H-60 Flight Director Diplay Control Panel"; // Display name of your category.
		isAddon = 1;
		group[] = {
		"Vtx_RALT_Toggle",
		"Vtx_ALTP_Toggle",
		"Vtx_BALT_Toggle",
		"Vtx_IAS_Toggle",
		"Vtx_HDG_Toggle",
		"Vtx_FMS_Toggle",
		}; // List of all actions inside this category.
	};
};