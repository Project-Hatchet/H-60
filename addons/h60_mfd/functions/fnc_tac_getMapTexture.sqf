/*
 * hct_h60_mfd_fnc_tac_getMapTexture
 */
params ["_vehicle","_mfdIndex"];

private _mode = _vehicle getVariable format["hct_h60_mfd_%1_mapTextureMode", _mfdIndex];

private _fallbackMap = getText (configFile >> "CfgWorlds" >> worldName >> "pictureMap");
private _texture = switch (_mode) do {
	case "topo": {
        private _mapName = format ["z\vtx\addons\uh60_mfd\data\maps\%1_co.paa", worldName];
		["", _mapName] select (fileExists _mapName)
	};
	case "sat": {
		_fallbackMap
	};
	case "cust": {
		["#(rgb,8,8,3)color(0,0,0,1)", "tac.paa"] select (fileExists "tac.paa")
	};
	case "off": {
		"#(rgb,8,8,3)color(0,0,0,1)"
	};
	default {""}; // mode not set yet (fnc_setup not run on this machine)
};
_texture
