params ["_tanker"];
private _alt = (getPos _tanker) # 2;
private _baskets = _vehicle getVariable ["vtx_aar_baskets", []];
private _diff = (getPosASLVisual _tanker) vectordiff (getPosASL _tanker);
private ["_rope"];
{
    _rope = _x getVariable "vtx_aar_rope";
    if (_alt < 50) then {
        ropeUnwind [_rope, 5, 0.1];
        if (ropeLength _rope < 1) then {
            if (!isObjectHidden _x) then {
                [_x, true] remoteExec ["hideObjectGlobal", 2];
            };
        };
    } else {
        if (ropeLength _rope < 1) then {
            ropeUnwind [_rope, 5, 20];
            if (isObjectHidden _x) then {
                [_x, false] remoteExec ["hideObjectGlobal", 2];
            };
        };
    };
    private _ropeEndPos = AGLtoASL ((ropeEndPosition _rope) # 1);
    if (!(_x getVariable ["vtx_aar_attached", false])) then {
        _x setPosASL (_ropeEndPos vectorAdd _diff vectorAdd [0,0,-0.5]);
        _x setDir (getDir _tanker);
    };
} forEach _baskets;
