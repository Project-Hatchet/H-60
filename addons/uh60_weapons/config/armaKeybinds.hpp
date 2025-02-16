class CfgUserActions
{
	class vtx_weapons_fireLaser {
		displayName = "Fire Laser";
		tooltip = "Hit this key to fire mentioned weapon.";
		onActivate = "(driver vehicle player) forceWeaponFire ['Laserdesignator_pilotCamera', 'Laserdesignator_pilotCamera']";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class vtx_weapons_fireRockets : vtx_weapons_fireLaser {
		displayName = "Fire FFAR Rockets";
		tooltip = "Hit this key to fire mentioned weapon.";
		onActivate = "(driver vehicle player) forceWeaponFire ['vtx_hydra', 'Single']";		// _this is always true.
	};
	class vtx_weapons_fireHellfire : vtx_weapons_fireLaser {
		displayName = "Fire Hellfire";
		tooltip = "Hit this key to fire mentioned weapon.";
		onActivate = "(driver vehicle player) forceWeaponFire ['vtx_hellfire_launcher', 'vtx_hellfire_launcher']";		// _this is always true.
	};
	class vtx_weapons_fireAPKWS : vtx_weapons_fireLaser {
		displayName = "Fire APKWS";
		tooltip = "Hit this key to fire mentioned weapon.";
		onActivate = "(driver vehicle player) forceWeaponFire ['vtx_apkws', 'Medium_AI']";		// _this is always true.
	};
};
class CfgDefaultKeysPresets {};
class UserActionGroups
{
	class Vtx_KeyBinds_FLIR {
		name = "H-60 Weapons"; // Display name of your category.
		isAddon = 1;
		group[] = {
		"vtx_weapons_fireAPKWS",
		"vtx_weapons_fireHellfire",
		"vtx_weapons_fireLaser",
		"vtx_weapons_fireRockets"
		}; // List of all actions inside this category.
	};
};