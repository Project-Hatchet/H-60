class CfgUserActions
{
  class hct_weapons_fireLaser {
    displayName = "$STR_hct_h60_weapons_FireLaserTOGGLE";
    tooltip = "$STR_hct_h60_weapons_HitThisKeyToToggleTheLaserDesignatorOnOff";
    onActivate = "[] call hct_h60_weapons_fnc_keyLaserDesignator;";		// _this is always true.
    onDeactivate = "";		// _this is always false.
    onAnalog = "";	// _this is the scalar analog value.
    analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
  };
  class hct_weapons_fireLaserHold : hct_weapons_fireLaser {
    displayName = "$STR_hct_h60_weapons_FireLaserHOLD";
    tooltip = "$STR_hct_h60_weapons_HoldThisKeyToActivateTheLaserDesignatorReleaseTo";
    onActivate = "[1] call hct_h60_weapons_fnc_keyLaserDesignator;";		// _this is always true.
    onDeactivate = "[0] call hct_h60_weapons_fnc_keyLaserDesignator;";		// _this is always false.
  };
  class hct_weapons_masterArm: hct_weapons_fireLaser {
    displayName = "$STR_hct_h60_weapons_MasterArm";
    tooltip = "$STR_hct_h60_weapons_ToggleBetweenSafeAndArm";
    onActivate = "call hct_h60_weapons_fnc_keyMasterArm;";		// _this is always true.
  };
  class hct_weapons_nextWeapon: hct_weapons_fireLaser {
    displayName = "$STR_hct_h60_weapons_NextWeapon";
    tooltip = "$STR_hct_h60_weapons_ChangeTheWeaponSelectedByThePilot";
    onActivate = "call hct_h60_weapons_fnc_keyNextWeapon;";		// _this is always true.
  };
  class hct_weapons_fireSelected {
    displayName = "$STR_hct_h60_weapons_FireSelectedWeapon";
    tooltip = "$STR_hct_h60_weapons_FireTheWeaponCurrentlySelectedByThePilot";
    onActivate = "[true] call hct_h60_weapons_fnc_keyFireSelected;";		// _this is always true.
    onDeactivate = "[false] call hct_h60_weapons_fnc_keyFireSelected;";		// _this is always false.
    onAnalog = "";	// _this is the scalar analog value.
    analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
  };
  class hct_weapons_fireRocket : hct_weapons_fireLaser {
    displayName = "$STR_hct_h60_weapons_FireRockets";
    tooltip = "$STR_hct_h60_weapons_HitThisKeyToFireMentionedWeapon";
    onActivate = "[hct_vehicle, 'hct_hydra', 'single'] call hct_h60_weapons_fnc_fireAndResetWeapon;";
  };
  class hct_weapons_fireAPKWS : hct_weapons_fireLaser {
    displayName = "$STR_hct_h60_weapons_FireAPKWS";
    tooltip = "$STR_hct_h60_weapons_HitThisKeyToFireMentionedWeapon";
    onActivate = "[hct_vehicle, 'hct_apkws', 'Medium_AI'] call hct_h60_weapons_fnc_fireAndResetWeapon;";
  };
  class hct_weapons_fireMissile : hct_weapons_fireLaser {
    displayName = "$STR_hct_h60_weapons_FireMissile";
    tooltip = "$STR_hct_h60_weapons_HitThisButtonToFireAMissilePriority114K114NAPKWS";
    onActivate = "[hct_vehicle, 'MISSILE'] call hct_h60_weapons_fnc_fireAndResetWeapon;";
  };
  class hct_weapons_irLaser : hct_weapons_fireLaser {
    displayName = "$STR_hct_h60_weapons_IZLID";
    tooltip = "$STR_hct_h60_weapons_HitThisButtonToToggleTheIZLIDIRLaser";
    onActivate = "[] call hct_h60_weapons_fnc_keyIRLaser;";
  };
  class hct_weapons_irLaserHold : hct_weapons_fireLaser {
    displayName = "$STR_hct_h60_weapons_IZLIDHOLD";
    tooltip = "$STR_hct_h60_weapons_HoldThisButtonToActivateTheIZLIDIRLaserReleaseTo";
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
