class CfgUserActions
{
	class Vtx_Batt1_ON {
		displayName = "#1 Battery On";
		tooltip = "Flips the BATT 1 Switch On";
		onActivate = "[vehicle player, ['startup', 'b_batt1'], 'ON'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
  class Vtx_Batt1_OFF {
    displayName = "#1 Battery Off";
		tooltip = "Flips the BATT 1 Switch Off";
		onActivate = "[vehicle player, ['startup', 'b_batt1'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
  };
  class Vtx_Batt2_ON {
		displayName = "#2 Battery On";
		tooltip = "Flips the BATT 2 Switch On";
		onActivate = "[vehicle player, ['startup', 'b_batt2'], 'ON'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
  class Vtx_Batt2_OFF {
    displayName = "#2 Battery Off";
		tooltip = "Flips the BATT 2 Switch Off";
		onActivate = "[vehicle player, ['startup', 'b_batt2'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
  };
 class Vtx_Gen1_ON {
    displayName = "#1 Generator On";
		tooltip = "Flips the #1 Generator Switch On";
		onActivate = "[vehicle player, ['startup', 'b_gen1'], 'ON'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01). 
 };
 class Vtx_Gen1_OFF {
    displayName = "#1 Generator Off";
		tooltip = "Flips the #1 Generator Switch Off";
		onActivate = "[vehicle player, ['startup', 'b_gen1'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01). 
 };
 class Vtx_Gen2_ON {
    displayName = "#2 Generator On";
		tooltip = "Flips the #2 Generator Switch On";
		onActivate = "[vehicle player, ['startup', 'b_gen2'], 'ON'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01). 
 };
 class Vtx_Gen2_OFF {
    displayName = "#2 Generator Off";
		tooltip = "Flips the #2 Generator Switch Off";
		onActivate = "[vehicle player, ['startup', 'b_gen2'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
};
class Vtx_AirSource_OFF {
    displayName = "Air SCE Off";
		tooltip = "Turns the Air Source Off";
		onActivate = "[vehicle player, ['startup', 'b_airsce'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01). 
 };
 class Vtx_AirSource_APU {
    displayName = "Air SCE APU";
		tooltip = "Sets the Air Source to APU";
		onActivate = "[vehicle player, ['startup', 'b_airsce'], 'APU'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_AirSource_ENG {
    displayName = "Air SCE ENG";
		tooltip = "Sets the Air Source to Engine";
		onActivate = "[vehicle player, ['startup', 'b_airsce'], 'ENG'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01). 
 };
class Vtx_FuelPump_OFF {
    displayName = "Fuel Pump Off";
		tooltip = "Turns the Fuel Pump Switch Off";
		onActivate = "[vehicle player, ['startup', 'fuelPump'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01). 
 };
 class Vtx_FuelPump_APU {
    displayName = "Fuel Pump APU";
		tooltip = "Turns the Fuel Pump Switch to APU Boost";
		onActivate = "[vehicle player, ['startup', 'fuelPump'], 'APU BOOST'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_APU_ON {
    displayName = "APU On";
		tooltip = "Toggles the APU Control Switch On";
		onActivate = "[vehicle player, ['startup', 'apucont'], 'ON'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01). 
 };
 class Vtx_APU_OFF {
    displayName = "APU Off";
		tooltip = "Toggles the APU Control Switch Off";
		onActivate = "[vehicle player, ['startup', 'apucont'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_GenAPU_ON {
    displayName = "APU Generator On";
		tooltip = "Toggles the APU GEN Switch On";
		onActivate = "[vehicle player, ['startup', 'b_apugen'], 'ON'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01). 
 };
 class Vtx_GenAPU_OFF {
    displayName = "APU Generator Off";
		tooltip = "Toggles the APU GEN Switch OFF";
		onActivate = "[vehicle player, ['startup', 'b_apugen'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_ESIS_OFF {
    displayName = "STBY INST Off";
		tooltip = "Toggles the Standby Instrument Switch OFF";
		onActivate = "[vehicle player, ['startup', 'b_stbyinst'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_ESIS_ON {
    displayName = "STBY INST Arm";
		tooltip = "Toggles the Standby Instrument Switch ON";
		onActivate = "[vehicle player, ['startup', 'b_stbyinst'], 'ARM'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_FUEL1_SYS_OFF {
    displayName = "#1 FUEL SYS Off";
		tooltip = "Moves the #1 Fuel Selector Lever to the OFF Position";
		onActivate = "[vehicle player, ['startup', 'b_fuelsys1'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_FUEL1_SYS_DIR {
    displayName = "#1 FUEL SYS Direct";
		tooltip = "Moves the #1 Fuel Selector Lever to the Direct Position";
		onActivate = "[vehicle player, ['startup', 'b_fuelsys1'], 'DIR'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_FUEL1_SYS_XFD {
    displayName = "#1 FUEL SYS XFD";
		tooltip = "Moves the #1 Fuel Selector Lever to the Crossfeed Position";
		onActivate = "[vehicle player, ['startup', 'b_fuelsys1'], 'XFD'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_FUEL2_SYS_OFF {
    displayName = "#2 FUEL SYS Off";
		tooltip = "Moves the #2 Fuel Selector Lever to the OFF Position";
		onActivate = "[vehicle player, ['startup', 'b_fuelsys2'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_FUEL2_SYS_DIR {
    displayName = "#2 FUEL SYS Direct";
		tooltip = "Moves the #2 Fuel Selector Lever to the Direct Position";
		onActivate = "[vehicle player, ['startup', 'b_fuelsys2'], 'DIR'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_FUEL2_SYS_XFD {
    displayName = "#2 FUEL SYS XFD";
		tooltip = "Moves the #2 Fuel Selector Lever to the Crossfeed Position";
		onActivate = "[vehicle player, ['startup', 'b_fuelsys2'], 'XFD'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_ENG_IGN_OFF {
    displayName = "ENG Ignition Off";
		tooltip = "Toggles the Engine Ignition Switch OFF";
		onActivate = "[vehicle player, ['startup', 'b_ignition'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_ENG_IGN_ON {
    displayName = "ENG Ignition On";
		tooltip = "Toggles the Engine Ignition Switch ON";
		onActivate = "[vehicle player, ['startup', 'b_ignition'], 'ON'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_ENG1_Starter {
    displayName = "Toggle #1 Starter";
		tooltip = "Engages/Disengages the #1 Engine Starter";
		onActivate = "[vehicle player, ['startup', 'b_starter1']] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_ENG2_Starter {
    displayName = "Toggle #2 Starter";
		tooltip = "Engages/Disengages the #2 Engine Starter";
		onActivate = "[vehicle player, ['startup', 'b_starter2']] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_PCL1_OFF {
    displayName = "#1 PCL Off";
		tooltip = "Moves the #1 PCL to the OFF Position";
		onActivate = "[vehicle player, ['startup', 'powerContRTD', 'b_engpowercont1'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_PCL1_IDLE {
    displayName = "#1 PCL Idle";
		tooltip = "Moves the #1 PCL to the Idle Position";
		onActivate = "[vehicle player, ['startup', 'powerContRTD', 'b_engpowercont1'], 'IDLE'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_PCL1_FLY {
    displayName = "#1 PCL Fly";
		tooltip = "Moves the #1 PCL to the Fly Position";
		onActivate = "[vehicle player, ['startup', 'powerContRTD', 'b_engpowercont1'], 'FLY'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_PCL2_OFF {
    displayName = "#2 PCL Off";
		tooltip = "Moves the #2 PCL to the OFF Position";
		onActivate = "[vehicle player, ['startup', 'powerContRTD', 'b_engpowercont2'], 'OFF'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_PCL2_IDLE {
    displayName = "#2 PCL Idle";
		tooltip = "Moves the #2 PCL to the Idle Position";
		onActivate = "[vehicle player, ['startup', 'powerContRTD', 'b_engpowercont2'], 'IDLE'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
 };
 class Vtx_PCL2_FLY {
    displayName = "#2 PCL Fly";
		tooltip = "Moves the #2 PCL to the Fly Position";
		onActivate = "[vehicle player, ['startup', 'powerContRTD', 'b_engpowercont2'], 'FLY'] call vxf_interaction_fnc_scriptedInteract;";		// _this is always true.
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
		"Vtx_Batt1_ON",
    "Vtx_Batt1_OFF",
    "Vtx_Batt2_ON",
    "Vtx_Batt2_OFF",
    "Vtx_Gen1_OFF",
    "Vtx_Gen1_ON",
    "Vtx_Gen2_OFF",
    "Vtx_Gen2_ON",
    "Vtx_AirSource_OFF",
    "Vtx_AirSource_APU",
    "Vtx_AirSource_ENG",
    "Vtx_FuelPump_OFF",
    "Vtx_FuelPump_APU",
    "Vtx_APU_OFF",
    "Vtx_APU_ON",
    "Vtx_GenAPU_OFF",
    "Vtx_GenAPU_ON",
    "Vtx_ESIS_OFF",
    "Vtx_ESIS_ON",
    "Vtx_FUEL1_SYS_OFF",
    "Vtx_FUEL1_SYS_DIR",
    "Vtx_FUEL1_SYS_XFD",
    "Vtx_FUEL2_SYS_OFF",
    "Vtx_FUEL2_SYS_DIR",
    "Vtx_FUEL2_SYS_XFD",
    "Vtx_ENG_IGN_OFF",
    "Vtx_ENG_IGN_ON",
    "Vtx_ENG1_Starter",
    "Vtx_ENG2_Starter",
    "Vtx_PCL1_OFF",
    "Vtx_PCL1_IDLE",
    "Vtx_PCL1_FLY",
    "Vtx_PCL2_OFF",
    "Vtx_PCL2_IDLE",
    "Vtx_PCL2_FLY",
		}; // List of all actions inside this category.
	};
};