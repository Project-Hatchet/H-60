class CfgUserActions {
  class Vtx_RALT_Toggle {
    displayName = "ARM/DISARM RALT Hold";
    tooltip = "Toggles the Radar Altitude Hold Mode";
    onActivate = "[hct_vehicle, 'RALT'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.

    onDeactivate = "";		// _this is always false.
    onAnalog = "";	// _this is the scalar analog value.
    analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
  };
  class Vtx_ALTP_Toggle: Vtx_RALT_Toggle {
    displayName = "ARM/DISARM ALTP Hold";
    tooltip = "Toggles the Barometric Altitude Preselect Mode";
    onActivate = "[hct_vehicle, 'ALTP'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
  };
  class Vtx_ALT_Toggle: Vtx_RALT_Toggle {
    displayName = "ARM/DISARM ALT Hold";
    tooltip = "Toggles the Barometric Altitude Hold Mode";
    onActivate = "[hct_vehicle, 'ALT'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
  };
  class Vtx_IAS_Toggle: Vtx_RALT_Toggle {
    displayName = "ARM/DISARM IAS Hold";
    tooltip = "Toggles the Indicated Airspeed Hold Mode. NOT AVAILABLE IN AFM";
    onActivate = "[hct_vehicle, 'IAS'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
  };
  class Vtx_HDG_Toggle: Vtx_RALT_Toggle {
    displayName = "ARM/DISARM HDG Hold";
    tooltip = "Toggles the Heading Hold Mode. NOT AVAILABLE IN AFM";
    onActivate = "[hct_vehicle, 'HDG'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
  };
  class Vtx_FMS_Toggle: Vtx_RALT_Toggle {
    displayName = "ARM/DISARM FMS Coupling";
    tooltip = "Toggles the FMS Coupled Mode";
    onActivate = "[hct_vehicle, 'FMS'] call vtx_uh60_fd_fnc_modeSet;";		// _this is always true.
  };
  class Vtx_RALT_Increase: Vtx_RALT_Toggle {
    displayName = "Increase RALT Hold";
    tooltip = "Increases the Radar Altitude Hold Mode";
    onActivate = "[hct_vehicle, ['misc', format ['KnobFD%1_RALT', ['Left', 'Right'] select (driver hct_vehicle == hct_player)]], 1] call hct_interaction_fnc_scriptedInteract;";		// _this is always true.
  };
  class Vtx_ALTP_Increase: Vtx_RALT_Toggle {
    displayName = "Increase ALTP Hold";
    tooltip = "Increases the Barometric Altitude Preselect Mode";
    onActivate = "[hct_vehicle, ['misc', format ['KnobFD%1_ALTP', ['Left', 'Right'] select (driver hct_vehicle == hct_player)]], 1] call hct_interaction_fnc_scriptedInteract;";		// _this is always true.
  };
  class Vtx_ALT_Increase: Vtx_RALT_Toggle {
    displayName = "Increase ALT Hold";
    tooltip = "Increases the Barometric Altitude Hold Mode";
    onActivate = "[hct_vehicle, ['misc', format ['KnobFD%1_BALT', ['Left', 'Right'] select (driver hct_vehicle == hct_player)]], 1] call hct_interaction_fnc_scriptedInteract;";		// _this is always true.
  };
  class Vtx_IAS_Increase: Vtx_RALT_Toggle {
    displayName = "Increase IAS Hold";
    tooltip = "Increases the Indicated Airspeed Hold Mode. NOT AVAILABLE IN AFM";
    onActivate = "[hct_vehicle, ['misc', format ['KnobFD%1_IAS', ['Left', 'Right'] select (driver hct_vehicle == hct_player)]], 1] call hct_interaction_fnc_scriptedInteract;";		// _this is always true.
  };
  class Vtx_HDG_Increase: Vtx_RALT_Toggle {
    displayName = "Increase HDG Hold";
    tooltip = "Increases the Heading Hold Mode. NOT AVAILABLE IN AFM";
    onActivate = "[hct_vehicle, ['misc', format ['KnobFD%1_HDG', ['Left', 'Right'] select (driver hct_vehicle == hct_player)]], 1] call hct_interaction_fnc_scriptedInteract;";		// _this is always true.
  };
  class Vtx_RALT_Decrease: Vtx_RALT_Toggle {
    displayName = "Decrease RALT Hold";
    tooltip = "Decreases the Radar Altitude Hold Mode";
    onActivate = "[hct_vehicle, ['misc', format ['KnobFD%1_RALT', ['Left', 'Right'] select (driver hct_vehicle == hct_player)]], -1] call hct_interaction_fnc_scriptedInteract;";		// _this is always true.
  };
  class Vtx_ALTP_Decrease: Vtx_RALT_Toggle {
    displayName = "Decrease ALTP Hold";
    tooltip = "Decreases the Barometric Altitude Preselect Mode";
    onActivate = "[hct_vehicle, ['misc', format ['KnobFD%1_ALTP', ['Left', 'Right'] select (driver hct_vehicle == hct_player)]], -1] call hct_interaction_fnc_scriptedInteract;";		// _this is always true.
  };
  class Vtx_ALT_Decrease: Vtx_RALT_Toggle {
    displayName = "Decrease ALT Hold";
    tooltip = "Decreases the Barometric Altitude Hold Mode";
    onActivate = "[hct_vehicle, ['misc', format ['KnobFD%1_BALT', ['Left', 'Right'] select (driver hct_vehicle == hct_player)]], -1] call hct_interaction_fnc_scriptedInteract;";		// _this is always true.
  };
  class Vtx_IAS_Decrease: Vtx_RALT_Toggle {
    displayName = "Decrease IAS Hold";
    tooltip = "Decreases the Indicated Airspeed Hold Mode. NOT AVAILABLE IN AFM";
    onActivate = "[hct_vehicle, ['misc', format ['KnobFD%1_IAS', ['Left', 'Right'] select (driver hct_vehicle == hct_player)]], -1] call hct_interaction_fnc_scriptedInteract;";		// _this is always true.
  };
  class Vtx_HDG_Decrease: Vtx_RALT_Toggle {
    displayName = "Decrease HDG Hold";
    tooltip = "Decreases the Heading Hold Mode. NOT AVAILABLE IN AFM";
    onActivate = "[hct_vehicle, ['misc', format ['KnobFD%1_HDG', ['Left', 'Right'] select (driver hct_vehicle == hct_player)]], -1] call hct_interaction_fnc_scriptedInteract;";		// _this is always true.
  };
}; // CfgUserActions
class CfgDefaultKeysPresets {};
class UserActionGroups {
  class Vtx_KeyBinds_FDDCP {
    name = "H-60 Flight Director Display Control Panel"; // Display name of your category.
    isAddon = 1;
    group[] = {
      "Vtx_RALT_Toggle",
      "Vtx_ALTP_Toggle",
      "Vtx_ALT_Toggle",
      "Vtx_IAS_Toggle",
      "Vtx_HDG_Toggle",
      "Vtx_RALT_Increase",
      "Vtx_ALTP_Increase",
      "Vtx_ALT_Increase",
      "Vtx_IAS_Increase",
      "Vtx_HDG_Increase",
      "Vtx_RALT_Decrease",
      "Vtx_ALTP_Decrease",
      "Vtx_ALT_Decrease",
      "Vtx_IAS_Decrease",
      "Vtx_HDG_Decrease",
      "Vtx_FMS_Toggle"
    }; // List of all actions inside this category.
  };
}; // UserActionGroups
