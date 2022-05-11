/*
 * vtx_uh60_mfd_fnc_tac_getMapTexture
 */
params ["_vehicle"];

private _texture = switch (vtx_uh60_mfd_mapTextureMode) do {
	case "topo": {
        private _mapName = format ["z\vtx\addons\uh60_mfd\data\maps\%1.paa", worldName];
		_mapName
	};
	case "sat": {
		private _fallbackMap = getText (configFile >> "CfgWorlds" >> worldName >> "pictureMap");
		_fallbackMap
	};
	case "cust": {
		"tac.paa"
	};
	case "off": {
		"#(rgb,8,8,3)color(0,0,0,1)"
	};
};
_texture