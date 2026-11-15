/*
 * hct_h60_mfd_fnc_tac_setMapTexture
 */
params ["_vehicle","_textureMode","_mfdIndex"];

_vehicle setVariable [format["hct_h60_mfd_%1_mapTextureMode", _mfdIndex], _textureMode, true];

private _pageIndex = (getUserMFDValue _vehicle) # _mfdIndex;
if (_pageIndex > 2 - 0.01 && _pageIndex < 2 + 0.99) then {
	private _texture = [_vehicle, _mfdIndex] call hct_h60_mfd_fnc_tac_getMapTexture;
	_vehicle setObjectTextureGlobal [_mfdIndex - 15, _texture];
};
