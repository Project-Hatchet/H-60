class CfgUserActions
{
	class Vtx_Flir_ZoomIn {
		displayName = "Stow / Switch Weapon";
		tooltip = "Put a Weapon on your back or Swtich to the one allready there";
		onActivate = "[1] call vtx_uh60_flir_fnc_keyZoom";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
	class Vtx_Flir_ZoomOut {
		displayName = "Stow / Switch Weapon";
		tooltip = "Put a Weapon on your back or Swtich to the one allready there";
		onActivate = "[-1] call vtx_uh60_flir_fnc_keyZoom";		// _this is always true.
		onDeactivate = "";		// _this is always false.
		onAnalog = "";	// _this is the scalar analog value.
		analogChangeThreshold = 0.1; // Minimum change required to trigger the onAnalog EH (default: 0.01).
	};
};
class CfgDefaultKeysPresets
{
	class Arma2 // Arma2 is inherited by all other presets.
	{
		class Mappings
		{
			Vtx_Flir_ZoomIn[] = {
				13, // DIK_K
				"", // 256 is the bitflag for "doubletap", 0x25 is the DIK code for K.
				"" // 0x00010000 is the bitflag for "mouse button".
			};
			Vtx_Flir_ZoomOut[] = {
				12, // DIK_K
				"", // 256 is the bitflag for "doubletap", 0x25 is the DIK code for K.
				"" // 0x00010000 is the bitflag for "mouse button".
			};
		};
	};
}
class UserActionGroups
{
	class PTF_KeyBinds {
		name = "H-60 Keybinds"; // Display name of your category.
		isAddon = 1;
		group[] = {"Vtx_Flir_ZoomIn","Vtx_Flir_ZoomOut"}; // List of all actions inside this category.
	};
};