class CfgUserActions
{
	class Vtx_HOOK_DEPLOY {
		displayName = "Deploy Hook";
		tooltip = "Deploys the Hoist Hook";
		onActivate = "_canDeploy = [vehicle player] call vtx_uh60_hoist_fnc_canDeployHook; if (_canDeploy) then {[vehicle player] call vtx_uh60_hoist_fnc_deployHook;}";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_HOOK_STOW {
		displayName = "Stow Hook";
		tooltip = "Secures the Hoist Hook";
		onActivate = "[vehicle player] call vtx_uh60_hoist_fnc_secureHook;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_HOOK_LOWER_GROUND {
		displayName = "Cable Extend";
		tooltip = "Lowers the hook to the ground";
		onActivate = "[vehicle player] call vtx_uh60_hoist_fnc_lowerHookToGround;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_HOOK_RAISE_HELI {
		displayName = "Cable Retract";
		tooltip = "Raises the hook to the helicopter";
		onActivate = "[vehicle player] call vtx_uh60_hoist_fnc_raiseHookToHeli;";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_HOOK_LOWER {
		displayName = "Cable Extend (Analog)";
		tooltip = "Progressively lowers the hook";
		onActivate = "vtx_uh60_cable_Extending = true; [vehicle player] spawn vtx_uh60_hoist_fnc_lowerHook;";		// _this is always true.
		onDeactivate = "vtx_uh60_cable_Extending = false";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_HOOK_RAISE {
		displayName = "Cable Retract (Analog)";
		tooltip = "Progressively raises the hook";
		onActivate = "vtx_uh60_cable_Retracting = true; [vehicle player] spawn vtx_uh60_hoist_fnc_raiseHook;";		// _this is always true.
		onDeactivate = "vtx_uh60_cable_Retracting = false";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
}; 
class CfgDefaultKeysPresets{};
class UserActionGroups
{
	class Vtx_KeyBinds_Hoist {
		name = "H-60 Hoist Operator"; // Display name of your category.
		isAddon = 1;
		group[] = {
		"Vtx_HOOK_DEPLOY",
		"Vtx_HOOK_STOW",
		"Vtx_HOOK_LOWER_GROUND",
		"Vtx_HOOK_RAISE_HELI",
		"Vtx_HOOK_LOWER",
		"Vtx_HOOK_RAISE",
		}; // List of all actions inside this category.
	};
};