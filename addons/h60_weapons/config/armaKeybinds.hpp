class CfgUserActions
{
  class hct_weapons_fireLaser {
    displayName = "Fire Laser [TOGGLE]";
    tooltip = "Hit this key to toggle the laser designator on/off.";
    onActivate = "[] call hct_h60_weapons_fnc_keyLaserDesignator;";		// _this is always true.
    onDeactivate = "";		// _this is always false.
    onAnalog = "";	// _this is the scalar analog value.
    analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
  };
  class hct_weapons_fireLaserHold : hct_weapons_fireLaser {
    displayName = "Fire Laser [HOLD]";
    tooltip = "Hold this key to activate the laser designator, release to deactivate.";
    onActivate = "[1] call hct_h60_weapons_fnc_keyLaserDesignator;";		// _this is always true.
    onDeactivate = "[0] call hct_h60_weapons_fnc_keyLaserDesignator;";		// _this is always false.
  };
  class hct_weapons_masterArm: hct_weapons_fireLaser {
    displayName = "Master Arm";
    tooltip = "Toggle between Safe and Arm";
    onActivate = "call hct_h60_weapons_fnc_keyMasterArm;";		// _this is always true.
  };
  class hct_weapons_nextWeapon: hct_weapons_fireLaser {
    displayName = "Next Weapon";
    tooltip = "Change the weapon selected by the pilot.";
    onActivate = "call hct_h60_weapons_fnc_keyNextWeapon;";		// _this is always true.
  };
  class hct_weapons_fireSelected {
    displayName = "Fire Selected Weapon";
    tooltip = "Fire the weapon currently selected by the pilot.";
    onActivate = "[true] call hct_h60_weapons_fnc_keyFireSelected;";		// _this is always true.
    onDeactivate = "[false] call hct_h60_weapons_fnc_keyFireSelected;";		// _this is always false.
    onAnalog = "";	// _this is the scalar analog value.
    analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
  };
  class hct_weapons_fireRocket : hct_weapons_fireLaser {
    displayName = "Fire Rockets";
    tooltip = "Hit this key to fire mentioned weapon.";
    onActivate = "[hct_vehicle, 'hct_hydra', 'single'] call hct_h60_weapons_fnc_fireAndResetWeapon;";
  };
  class hct_weapons_fireAPKWS : hct_weapons_fireLaser {
    displayName = "Fire APKWS";
    tooltip = "Hit this key to fire mentioned weapon.";
    onActivate = "[hct_vehicle, 'hct_apkws', 'Medium_AI'] call hct_h60_weapons_fnc_fireAndResetWeapon;";
  };
  class hct_weapons_fireMissile : hct_weapons_fireLaser {
    displayName = "Fire Missile";
    tooltip = "Hit this button to fire a missile, priority - 114K, 114N, APKWS.";
    onActivate = "[hct_vehicle, 'MISSILE'] call hct_h60_weapons_fnc_fireAndResetWeapon;";
  };
  class hct_weapons_irLaser : hct_weapons_fireLaser {
    displayName = "IZLID";
    tooltip = "Hit this button to toggle the IZLID IR laser.";
    onActivate = "[] call hct_h60_weapons_fnc_keyIRLaser;";
  };
  class hct_weapons_irLaserHold : hct_weapons_fireLaser {
    displayName = "IZLID [HOLD]";
    tooltip = "Hold this button to activate the IZLID IR laser, release to deactivate.";
    onActivate = "[1] call hct_h60_weapons_fnc_keyIRLaser;";		// _this is always true.
    onDeactivate = "[0] call hct_h60_weapons_fnc_keyIRLaser;";		// _this is always false.
  };
};
class CfgDefaultKeysPresets {};
class UserActionGroups
{
  class hct_keybinds_weapons {
    name = "H-60 Weapons"; // Display name of your category.
    isAddon = 1;
    group[] = {
      "hct_weapons_masterArm",
      "hct_weapons_nextWeapon",
      "hct_weapons_fireSelected",
      "hct_weapons_fireAPKWS",
      "hct_weapons_fireRocket",
      "hct_weapons_fireLaser",
      "hct_weapons_fireLaserHold",
      "hct_weapons_fireMissile",
      "hct_weapons_irLaser",
      "hct_weapons_irLaserHold"
    }; // List of all actions inside this category.
  };
};
