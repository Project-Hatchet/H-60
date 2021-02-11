/*
 * Author: Yax
 * handle getting in and out of hook while it's attached to the player
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Fast rope Dummy <OBJECT>
 * 2: Hook <OBJECT>
 * 3: Rope <OBJECT>
 * 4: Helicopter <OBJECT>
 *
 * Return Value: nil
 *
 * Example:
 * ["_unit", "_helper", "_hook", "_rope", "_ropeOrigin"] call vtx_uh60_hoist_fnc_attachedHook
 * [player, attachedTo vehicle player, vehicle player, (ropes ropeAttachedTo attachedTo vehicle player) # 0, ropeAttachedTo attachedTo vehicle player] call vtx_uh60_hoist_fnc_attachedHook
 */
 //vtx_uh60_hoist_fnc_attachedHook={
params ["_unit", "_helper", "_hook", "_rope", "_heli"];
if (isNull _rope) exitWith {
    diag_log "vtx_uh60_hoist_fnc_attachedHook";
    diag_log "rope is objNull";
};
private _length = ropeLength _rope;
private _distance = ((ropeEndPosition _rope) # 0) distance ((ropeEndPosition _rope) # 1);
private _isHookMoving = (speed _helper > 0.1);
private _isRopeStretched = (_distance > _length + 0.4);
private _isPlayerOnHook = vehicle _unit == _hook;
private _isAboveGround = getPos _hook # 2 < 0; // handle swimming
if !_isAboveGround then {
    private _isAboveGroundIntersect = lineIntersectsSurfaces [
        getPosASL _unit vectorAdd [0,-0.3,1],
        (getPosASL _unit) vectorAdd [0,-0.3,-0.5],
        _unit,
        _hook
    ];
    _isAboveGround = (count _isAboveGroundIntersect) > 0;
};
systemChat str [_isAboveGround, _isRopeStretched, round _distance, round _length];
if (_isRopeStretched && !_isPlayerOnHook) then {
    detach _helper;
    _unit moveInCargo _hook;
};
if (_isPlayerOnHook && _isAboveGround && !_isRopeStretched) then {
    moveOut _unit;
    _helper attachTo [_unit, [0,0.15,0.2],"pelvis"];
};
