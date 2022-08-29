/*
 * vtx_uh60_mfd_fnc_tac_setMapTexture
 */
params ["_vehicle","_textureMode"];
vtx_uh60_mfd_mapTextureMode = _textureMode;
{
	private _pageIndex = (getUserMFDValue _vehicle) # _x;
	if (_pageIndex > 2 - 0.01 && _pageIndex < 2 + 0.99) then {
		private _texture = [_vehicle] call vtx_uh60_mfd_fnc_tac_getMapTexture;
		_vehicle setObjectTexture [_x - 15, _texture];
		// systemChat str [_x - 8, _texture];
	};
} forEach [23, 24, 25, 26];