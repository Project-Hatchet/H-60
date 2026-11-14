private _classes = ("(getNumber (_x >> 'scope') >= 1) && {configName _x isKindOf ['vtx_H60_base', configFile >> 'CfgVehicles']}" configClasses (configFile >> "CfgVehicles")) apply {configName _x};
private _origin = (getPosATL player) vectorAdd [0, 60, 0];
private _results = [];
diag_log "VTX class matrix: start";
{
    private _cls = _x;
    private _pos = _origin vectorAdd [(_forEachIndex mod 5) * 30, floor (_forEachIndex / 5) * 30, 0];
    private _veh = createVehicle [_cls, _pos, [], 0, "CAN_COLLIDE"];
    private _row = if (isNull _veh) then {
        [_cls, "CREATE FAILED"]
    } else {
        private _turrets = allTurrets [_veh, true];
        private _pylons = getPylonMagazines _veh;
        private _anims = animationNames _veh;
        private _seats = fullCrew [_veh, "", true];
        [_cls, "ok", "turrets", count _turrets, "seats", count _seats, "pylons", count _pylons, "anims", count _anims, "mass", getMass _veh, "textures", count getObjectTextures _veh]
    };
    _results pushBack _row;
    diag_log format ["VTX class matrix: %1", _row];
    if (!isNull _veh) then { deleteVehicle _veh; };
} forEach _classes;
diag_log format ["VTX class matrix: done, %1 classes", count _results];
hint format ["VTX class matrix done: %1 classes. See RPT.", count _results];
_results
