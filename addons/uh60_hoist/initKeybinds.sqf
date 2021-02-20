[
    "UH-60M Blackhawk", "vtx_uh60m_hoistHookUp", LSTRING(HoistHookUp),{
        private _heli = vehicle player;
        if !([player] call vtx_uh60_hoist_fnc_canControlHoist) exitWith {};

        private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
        if (_hoist_vars isEqualTo []) exitWith{false};
        _hoist_vars params ["_rope", "_dummy", "_hook"];

        if ([_heli] call vtx_uh60_hoist_fnc_canSecureHook) exitWith {[_heli] call vtx_uh60_hoist_fnc_secureHook};

        private _ropeLength = ropeLength _rope;
        if (ropeUnwound _rope && {_ropeLength > 0.5}) exitWith {
            ropeUnwind [
                _rope,
                [MAX_HOIST_SPEED, NEAR_END_SPEED] select (_ropeLength < NEAR_END_THRESHOLD), // slow speed near cable extreme
                (_ropeLength - 0.1) max 0.5
            ];
        };
    }, "", [DIK_APOSTROPHE, [true, false, false]], true
] call CBA_fnc_addKeybind; // Shift + '

[
    "UH-60M Blackhawk", "vtx_uh60m_hoistHookDown", LSTRING(HoistHookDown),{
        private _heli = vehicle player;
        if !([player] call vtx_uh60_hoist_fnc_canControlHoist) exitWith {};

        private _canDeployHook = [_heli] call vtx_uh60_hoist_fnc_canDeployHook;
        if (_canDeployHook) exitWith{[_heli] call vtx_uh60_hoist_fnc_deployHook};
        private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
        _hoist_vars params ["_rope", "_dummy", "_hook"];

        private _ropeLength = ropeLength _rope;
        if (ropeUnwound _rope && {_ropeLength < MAX_ROPE_LENGTH}) exitWith {
            ropeUnwind [
                _rope,
                [MAX_HOIST_SPEED, NEAR_END_SPEED] select (MAX_ROPE_LENGTH - _ropeLength < NEAR_END_THRESHOLD), // slow speed near cable extreme
                (_ropeLength + 0.1) min MAX_ROPE_LENGTH
            ];
        };
    }, "", [DIK_APOSTROPHE, [false, true, false]], true
] call CBA_fnc_addKeybind; // Ctrl + '

[
    "UH-60M Blackhawk", "vtx_uh60m_hoistHookStabilize", LSTRING(StabilizeHook),{
        private _heli = vehicle player;
        if !([player] call vtx_uh60_hoist_fnc_canControlHoist) exitWith {};

        private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
        if (_hoist_vars isEqualTo []) exitWith{false};
        _hoist_vars params ["_rope", "_dummy", "_hook"];

        [_heli] call vtx_uh60_hoist_fnc_stabilizeHook;
    }, "", [DIK_APOSTROPHE, [false, false, false]], true
] call CBA_fnc_addKeybind; // '

[
    "UH-60M Blackhawk", "vtx_uh60m_hoistHookGetIn", LSTRING(MoveFromHeliToHook),{
        if (isNull objectParent player) exitWith {}; // must be in a vehicle

        private _hooks = positionCameraToWorld [0,0,2] nearObjects ["vtx_hook", 2];
        if (_hooks isEqualTo []) exitWith {}; // must see a hook

        private _hook = _hooks # 0;
        if !(crew _hook isEqualTo []) exitWith {}; // hook must be free

        moveOut player;
        [{
            isNull objectParent player
        }, {
            params ["_hook"];
            player moveInCargo _hook;
            [_hook getVariable 'vtx_uh60_hoist_heli'] call vtx_uh60_hoist_fnc_stabilizeHook;
        }, [_hook]] call CBA_fnc_waitUntilAndExecute;

    }, ""
] call CBA_fnc_addKeybind;
