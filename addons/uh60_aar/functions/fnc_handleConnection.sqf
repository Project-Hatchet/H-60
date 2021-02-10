/*
 * vtx_uh60_aar_fnc_handleConnection
 */
params ["_vehicle", "_tanker", "_basket", "_rope", "_frameTime"];
private _probePosModel = (_vehicle getVariable ["vtx_aar_probePos",[0,0,0]]);
private _ropePosModel = (_basket getVariable ["vtx_aar_ropeOrigin",[0,0,0]]);
private _probePos = _vehicle modelToWorldVisualWorld _probePosModel;
private _speedDiff = (vectorMagnitude velocity _vehicle) - (vectorMagnitude velocity _tanker);
if(attachedTo _basket == _vehicle) then {
    private _ropeLength = (_tanker modelToWorldVisualWorld _ropePosModel) distance _probePos;
    ropeUnwind [_rope, 15, _ropeLength + 0.1];
    _vehicle setFuel ((fuel _vehicle) + (vtx_aar_transferRate * _frameTime));
    if (_ropeLength > 30 || _speedDiff < -5) then {
        [_vehicle, _tanker, _basket, _rope] call vtx_uh60_aar_fnc_detachFromHelo;
    };
} else {
    private _connected = [_vehicle, _tanker, _basket, _rope] call vtx_uh60_aar_fnc_isConnectedBasket;
    if (_connected && _speedDiff > 0) then {
        [_vehicle, _tanker, _basket, _rope] call vtx_uh60_aar_fnc_attachToHelo;
    };
};
