class CfgUserActions
{
	class vtx_weapons_fireLaser {
		displayName = "Fire Laser";
		tooltip = "Hit this key to fire mentioned weapon.";
		onActivate = "[vehicle player, 'Laserdesignator_pilotCamera', 'Laserdesignator_pilotCamera'] call vtx_uh60_weapons_fnc_fireAndResetWeapon;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class vtx_weapons_fireHellfireK : vtx_weapons_fireLaser {
		displayName = "Fire 114K";
		tooltip = "Hit this key to fire mentioned weapon.";
		onActivate = "[vehicle player, 'vtx_hellfire_launcher', 'vtx_hellfire_launcher'] call vtx_uh60_weapons_fnc_fireAndResetWeapon;";		// _this is always true.
	};
	class vtx_weapons_fireHellfireN : vtx_weapons_fireLaser {
		displayName = "Fire 114N";
		tooltip = "Hit this key to fire mentioned weapon.";
		onActivate = "[vehicle player, 'vtx_hellfire_launcher_N', 'vtx_hellfire_launcher_N'] call vtx_uh60_weapons_fnc_fireAndResetWeapon;";		// _this is always true.
	};
	class vtx_weapons_fireAPKWS : vtx_weapons_fireLaser {
		displayName = "Fire APKWS";
		tooltip = "Hit this key to fire mentioned weapon.";
		onActivate = "[vehicle player, 'vtx_apkws', 'Medium_AI'] call vtx_uh60_weapons_fnc_fireAndResetWeapon;";		// _this is always true.
	};
	class vtx_weapons_fireMissile : vtx_weapons_fireLaser {
		displayName = "Fire Missile";
		tooltip = "Hit this button to fire a missile, priority - 114K, 114N, APKWS.";
		onActivate = "[vehicle player, 'MISSILE'] call vtx_uh60_weapons_fnc_fireAndResetWeapon;";		// _this is always true.
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
		"vtx_weapons_fireHellfireK",
		"vtx_weapons_fireHellfireN",
		"vtx_weapons_fireLaser",
		"vtx_weapons_fireMissile"
		}; // List of all actions inside this category.
	};
};