class CfgUserActions
{
	class Vtx_RALT_Toggle {
		displayName = "ARM/DISARM RALT Hold";
		tooltip = "Toggles the Radar Altitude Hold Mode";
		onActivate = "[hct_vehicle, 'RALT'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_ALTP_Toggle {
		displayName = "ARM/DISARM ALTP Hold";
		tooltip = "Toggles the Barometric Altitude Preselect Mode";
		onActivate = "[hct_vehicle, 'ALTP'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_BALT_Toggle {
		displayName = "ARM/DISARM ALT Hold";
		tooltip = "Toggles the Barometric Altitude Hold Mode";
		onActivate = "[hct_vehicle, 'ALT'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_IAS_Toggle {
		displayName = "ARM/DISARM IAS Hold";
		tooltip = "Toggles the Indicated Airspeed Hold Mode. NOT AVAILABLE IN AFM";
		onActivate = "[hct_vehicle, 'IAS'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_HDG_Toggle {
		displayName = "ARM/DISARM HDG Hold";
		tooltip = "Toggles the Heading Hold Mode. NOT AVAILABLE IN AFM";
		onActivate = "[hct_vehicle, 'HDG'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_FMS_Toggle {
		displayName = "ARM/DISARM FMS Coupling";
		tooltip = "Toggles the FMS Coupled Mode";
		onActivate = "[hct_vehicle, 'FMS'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_RALT_Increase {
		displayName = "Increase RALT Hold";
		tooltip = "Increases the Radar Altitude Hold Mode";
		onActivate = "[hct_vehicle, 1, ['FD_1_ROT',0.1,2.5,1,[0,10],true]] call hct_interaction_fnc_knobAnimate; [hct_vehicle, 'RALT'] call vtx_uh60_fd_fnc_spinKnob;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_ALTP_Increase {
		displayName = "Increase ALTP Hold";
		tooltip = "Increases the Barometric Altitude Preselect Mode";
		onActivate = "[hct_vehicle, 1, ['FD_2_ROT',0.1,5,1,[0,20],true]] call hct_interaction_fnc_knobAnimate; [hct_vehicle, 'ALTP'] call vtx_uh60_fd_fnc_spinKnob;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_BALT_Increase {
		displayName = "Increase ALT Hold";
		tooltip = "Increases the Barometric Altitude Hold Mode";
		onActivate = "[hct_vehicle, 1, ['FD_3_ROT',0.1,5,1,[0,20],true]] call hct_interaction_fnc_knobAnimate; [hct_vehicle, 'ALT'] call vtx_uh60_fd_fnc_spinKnob;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_IAS_Increase {
		displayName = "Increase IAS Hold";
		tooltip = "Increases the Indicated Airspeed Hold Mode. NOT AVAILABLE IN AFM";
		onActivate = "[hct_vehicle, 1, ['FD_1_ROT',0.1,0.325,1,[0,2],true]] call hct_interaction_fnc_knobAnimate; [hct_vehicle, 'IAS'] call vtx_uh60_fd_fnc_spinKnob;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_HDG_Increase {
		displayName = "Increase HDG Hold";
		tooltip = "Increases the Heading Hold Mode. NOT AVAILABLE IN AFM";
		onActivate = "['FD_5_ROT',0.138889,4.5,1,[-1,11],true] call hct_interaction_fnc_knobAnimate; [hct_vehicle, 'HDG'] call vtx_uh60_fd_fnc_spinKnob;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_RALT_Decrease {
		displayName = "Decrease RALT Hold";
		tooltip = "Decreases the Radar Altitude Hold Mode";
		onActivate = "[hct_vehicle, -1, ['FD_1_ROT',0.1,2.5,1,[0,10],true]] call hct_interaction_fnc_knobAnimate; [hct_vehicle, 'RALT'] call vtx_uh60_fd_fnc_spinKnob;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_ALTP_Decrease {
		displayName = "Decrease ALTP Hold";
		tooltip = "Decreases the Barometric Altitude Preselect Mode";
		onActivate = "[hct_vehicle, -1, ['FD_2_ROT',0.1,5,1,[0,20],true]] call hct_interaction_fnc_knobAnimate; [hct_vehicle, 'ALTP'] call vtx_uh60_fd_fnc_spinKnob;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_BALT_Decrease {
		displayName = "Decrease ALT Hold";
		tooltip = "Decreases the Barometric Altitude Hold Mode";
		onActivate = "[hct_vehicle, -1, ['FD_3_ROT',0.1,5,1,[0,20],true]] call hct_interaction_fnc_knobAnimate; [hct_vehicle, 'ALT'] call vtx_uh60_fd_fnc_spinKnob;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_IAS_Decrease {
		displayName = "Decrease IAS Hold";
		tooltip = "Decreases the Indicated Airspeed Hold Mode. NOT AVAILABLE IN AFM";
		onActivate = "[hct_vehicle, -1, ['FD_1_ROT',0.1,0.325,1,[0,2],true]] call hct_interaction_fnc_knobAnimate; [hct_vehicle, 'IAS'] call vtx_uh60_fd_fnc_spinKnob;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_HDG_Decrease {
		displayName = "Decrease HDG Hold";
		tooltip = "Decreases the Heading Hold Mode. NOT AVAILABLE IN AFM";
		onActivate = "['FD_5_ROT',0.138889,4.5,1,[-1,11],true] call hct_interaction_fnc_knobAnimate; [hct_vehicle, 'HDG'] call vtx_uh60_fd_fnc_spinKnob;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
};
class CfgDefaultKeysPresets{};
class UserActionGroups
{
	class Vtx_KeyBinds_FDDCP {
		name = "H-60 Flight Director Display Control Panel"; // Display name of your category.
		isAddon = 1;
		group[] = {
		"Vtx_RALT_Toggle",
		"Vtx_ALTP_Toggle",
		"Vtx_BALT_Toggle",
		"Vtx_IAS_Toggle",
		"Vtx_HDG_Toggle",
		"Vtx_RALT_Increase",
		"Vtx_ALTP_Increase",
		"Vtx_BALT_Increase",
		"Vtx_IAS_Increase",
		"Vtx_HDG_Increase",
    "Vtx_RALT_Decrease",
    "Vtx_ALTP_Decrease",
    "Vtx_BALT_Decrease",
    "Vtx_IAS_Decrease",
    "Vtx_HDG_Decrease",
		"Vtx_FMS_Toggle"
		}; // List of all actions inside this category.
	};
};
