/*
 * vtx_uh60_mfd_fnc_tac_getMapTexture
 */
params ["_vehicle"];

private _fallbackMap = getText (configFile >> "CfgWorlds" >> worldName >> "pictureMap");
private _texture = switch (vtx_uh60_mfd_mapTextureMode) do {
	case "topo": {
        private _mapName = format ["z\vtx\addons\uh60_mfd\data\maps\%1.paa", worldName];
		if (fileExists _mapName) then {_mapName} else {""};
	};
	case "sat": {
		_fallbackMap
	};
	case "cust": {
		if (fileExists "tac.paa") then {"tac.paa"} else {"#(rgb,8,8,3)color(0,0,0,1)"};
	};
	case "off": {
		"#(rgb,8,8,3)color(0,0,0,1)"
	};
};
_texture