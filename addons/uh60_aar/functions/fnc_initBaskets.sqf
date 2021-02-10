/*
 * vtx_uh60_aar_fnc_initBaskets
 */
params ["_vehicle", "_ropeOrigins"];
private ["_basket", "_rope"];
private _baskets = [];
{
    _basket = "vtx_aar_basket" createVehicle [0,0,0];
    _attachPos = _x vectorAdd [0, -14, -5];
    _basket setVariable ["vtx_aar_attachPos", _attachPos, true];
    _basket attachTo [_vehicle, _attachPos];
    _rope = ropeCreate [_vehicle, _x, 15];
    _basket setVariable ["vtx_aar_tanker", _vehicle, true];
    _basket setVariable ["vtx_aar_rope", _rope, true];
    _basket setVariable ["vtx_aar_ropeOrigin", _x, true];
    _baskets pushBack _basket;
} forEach _ropeOrigins;
_vehicle setVariable ["vtx_aar_baskets", _baskets, true];
