class CfgUserActions
{
	class hct_HOOK_DEPLOY {
		displayName = "Deploy Hook";
		tooltip = "Deploys the Hoist Hook";
		onActivate = "_canDeploy = [player] call hct_h60_hoist_fnc_canControlHoist && {[vehicle player] call hct_h60_hoist_fnc_canDeployHook}; if (_canDeploy) then {[vehicle player] call hct_h60_hoist_fnc_deployHook;}";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_HOOK_STOW {
		displayName = "Stow Hook";
		tooltip = "Secures the Hoist Hook";
		onActivate = "if ([player] call hct_h60_hoist_fnc_canControlHoist) then {[vehicle player] call hct_h60_hoist_fnc_secureHook;};";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_HOOK_LOWER_GROUND {
		displayName = "Cable Extend";
		tooltip = "Lowers the hook to the ground";
		onActivate = "if ([player] call hct_h60_hoist_fnc_canControlHoist) then {[vehicle player] call hct_h60_hoist_fnc_lowerHookToGround;};";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_HOOK_RAISE_HELI {
		displayName = "Cable Retract";
		tooltip = "Raises the hook to the helicopter";
		onActivate = "if ([player] call hct_h60_hoist_fnc_canControlHoist) then {[vehicle player] call hct_h60_hoist_fnc_raiseHookToHeli;};";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_HOOK_LOWER {
		displayName = "Cable Extend (Analog)";
		tooltip = "Progressively lowers the hook";
		onActivate = "[vehicle player, true] call hct_h60_hoist_fnc_lowerHook;";		// _this is always true.
		onDeactivate = "[vehicle player, false] call hct_h60_hoist_fnc_lowerHook;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_HOOK_RAISE {
		displayName = "Cable Retract (Analog)";
		tooltip = "Progressively raises the hook";
		onActivate = "[vehicle player, true] call hct_h60_hoist_fnc_raiseHook;";		// _this is always true.
		onDeactivate = "[vehicle player, false] call hct_h60_hoist_fnc_raiseHook;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
  class hct_HOOK_STABILIZE {
		displayName = "Stabilize Hoist Hook";
		tooltip = "Stabilizes the Hoist Hook from swinging excessively";
		onActivate = "_canControl = [player] call hct_h60_hoist_fnc_canControlHoist; if (_canControl) then {[vehicle player] call hct_h60_hoist_fnc_stabilizeHook;}";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
};
class CfgDefaultKeysPresets{};
class UserActionGroups
{
	class hct_KeyBinds_Hoist {
		name = "H-60 Hoist Operator"; // Display name of your category.
		isAddon = 1;
		group[] = {
		"hct_HOOK_DEPLOY",
		"hct_HOOK_STOW",
		"hct_HOOK_LOWER_GROUND",
		"hct_HOOK_RAISE_HELI",
		"hct_HOOK_LOWER",
		"hct_HOOK_RAISE",
    "hct_HOOK_STABILIZE",
		}; // List of all actions inside this category.
	};
};
