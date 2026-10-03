class CfgUserActions
{
  class vtx_weapons_fireLaser {
    displayName = "Fire Laser [TOGGLE]";
    tooltip = "Hit this key to toggle the laser designator on/off.";
    onActivate = "[] call vtx_uh60_weapons_fnc_keyLaserDesignator;";		// _this is always true.
    onDeactivate = "";		// _this is always false.
    onAnalog = "";	// _this is the scalar analog value.
    analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
  };
  class vtx_weapons_fireLaserHold : vtx_weapons_fireLaser {
    displayName = "Fire Laser [HOLD]";
    tooltip = "Hold this key to activate the laser designator, release to deactivate.";
    onActivate = "[1] call vtx_uh60_weapons_fnc_keyLaserDesignator;";		// _this is always true.
    onDeactivate = "[0] call vtx_uh60_weapons_fnc_keyLaserDesignator;";		// _this is always false.
  };
  class vtx_weapons_masterArm: vtx_weapons_fireLaser {
    displayName = "Master Arm";
    tooltip = "Toggle between Safe and Arm";
    onActivate = "call vtx_uh60_weapons_fnc_keyMasterArm;";		// _this is always true.
  };
  class vtx_weapons_nextWeapon: vtx_weapons_fireLaser {
    displayName = "Next Weapon";
    tooltip = "Change the weapon selected by the pilot.";
    onActivate = "call vtx_uh60_weapons_fnc_keyNextWeapon;";		// _this is always true.
  };
  class vtx_weapons_fireSelected {
    displayName = "Fire Selected Weapon";
    tooltip = "Fire the weapon currently selected by the pilot.";
    onActivate = "[true] call vtx_uh60_weapons_fnc_keyFireSelected;";		// _this is always true.
    onDeactivate = "[false] call vtx_uh60_weapons_fnc_keyFireSelected;";		// _this is always false.
    onAnalog = "";	// _this is the scalar analog value.
    analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
  };
  class vtx_weapons_fireRocket : vtx_weapons_fireLaser {
    displayName = "Fire Rockets";
    tooltip = "Hit this key to fire mentioned weapon.";
    onActivate = "[hct_vehicle, 'vtx_hydra', 'single'] call vtx_uh60_weapons_fnc_fireAndResetWeapon;";
  };
  class vtx_weapons_fireAPKWS : vtx_weapons_fireLaser {
    displayName = "Fire APKWS";
    tooltip = "Hit this key to fire mentioned weapon.";
    onActivate = "[hct_vehicle, 'vtx_apkws', 'Medium_AI'] call vtx_uh60_weapons_fnc_fireAndResetWeapon;";
  };
  class vtx_weapons_fireMissile : vtx_weapons_fireLaser {
    displayName = "Fire Missile";
    tooltip = "Hit this button to fire a missile, priority - 114K, 114N, APKWS.";
    onActivate = "[hct_vehicle, 'MISSILE'] call vtx_uh60_weapons_fnc_fireAndResetWeapon;";
  };
  class vtx_weapons_irLaser : vtx_weapons_fireLaser {
    displayName = "IZLID";
    tooltip = "Hit this button to toggle the IZLID IR laser.";
    onActivate = "[] call vtx_uh60_weapons_fnc_keyIRLaser;";
  };
  class vtx_weapons_irLaserHold : vtx_weapons_fireLaser {
    displayName = "IZLID [HOLD]";
    tooltip = "Hold this button to activate the IZLID IR laser, release to deactivate.";
    onActivate = "[1] call vtx_uh60_weapons_fnc_keyIRLaser;";		// _this is always true.
    onDeactivate = "[0] call vtx_uh60_weapons_fnc_keyIRLaser;";		// _this is always false.
  };
};
class CfgDefaultKeysPresets {};
class UserActionGroups
{
  class vtx_keybinds_weapons {
    name = "H-60 Weapons"; // Display name of your category.
    isAddon = 1;
    group[] = {
      "vtx_weapons_masterArm",
      "vtx_weapons_nextWeapon",
      "vtx_weapons_fireSelected",
      "vtx_weapons_fireAPKWS",
      "vtx_weapons_fireRocket",
      "vtx_weapons_fireLaser",
      "vtx_weapons_fireLaserHold",
      "vtx_weapons_fireMissile",
      "vtx_weapons_irLaser",
      "vtx_weapons_irLaserHold"
    }; // List of all actions inside this category.
  };
};
