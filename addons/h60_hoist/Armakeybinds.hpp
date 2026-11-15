class CfgUserActions
{
	class hct_HOOK_DEPLOY {
		displayName = "$STR_hct_h60_hoist_DeployHook";
		tooltip = "$STR_hct_h60_hoist_DeploysTheHoistHook";
		onActivate = "_canDeploy = [player] call hct_h60_hoist_fnc_canControlHoist && {[vehicle player] call hct_h60_hoist_fnc_canDeployHook}; if (_canDeploy) then {[vehicle player] call hct_h60_hoist_fnc_deployHook;}";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_HOOK_STOW {
		displayName = "$STR_hct_h60_hoist_StowHook";
		tooltip = "$STR_hct_h60_hoist_SecuresTheHoistHook";
		onActivate = "if ([player] call hct_h60_hoist_fnc_canControlHoist) then {[vehicle player] call hct_h60_hoist_fnc_secureHook;};";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_HOOK_LOWER_GROUND {
		displayName = "$STR_hct_h60_hoist_CableExtend";
		tooltip = "$STR_hct_h60_hoist_LowersTheHookToTheGround";
		onActivate = "if ([player] call hct_h60_hoist_fnc_canControlHoist) then {[vehicle player] call hct_h60_hoist_fnc_lowerHookToGround;};";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_HOOK_RAISE_HELI {
		displayName = "$STR_hct_h60_hoist_CableRetract";
		tooltip = "$STR_hct_h60_hoist_RaisesTheHookToTheHelicopter";
		onActivate = "if ([player] call hct_h60_hoist_fnc_canControlHoist) then {[vehicle player] call hct_h60_hoist_fnc_raiseHookToHeli;};";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_HOOK_LOWER {
		displayName = "$STR_hct_h60_hoist_CableExtendAnalog";
		tooltip = "$STR_hct_h60_hoist_ProgressivelyLowersTheHook";
		onActivate = "[vehicle player, true] call hct_h60_hoist_fnc_lowerHook;";		// _this is always true.
		onDeactivate = "[vehicle player, false] call hct_h60_hoist_fnc_lowerHook;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class hct_HOOK_RAISE {
		displayName = "$STR_hct_h60_hoist_CableRetractAnalog";
		tooltip = "$STR_hct_h60_hoist_ProgressivelyRaisesTheHook";
		onActivate = "[vehicle player, true] call hct_h60_hoist_fnc_raiseHook;";		// _this is always true.
		onDeactivate = "[vehicle player, false] call hct_h60_hoist_fnc_raiseHook;";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
  class hct_HOOK_STABILIZE {
		displayName = "$STR_hct_h60_hoist_StabilizeHoistHook";
		tooltip = "$STR_hct_h60_hoist_StabilizesTheHoistHookFromSwingingExcessively";
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
