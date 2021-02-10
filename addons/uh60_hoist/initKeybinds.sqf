[
    "UH-60M Blackhawk", "vtx_uh60m_hoistHookUp", "Hoist Hook Up",{
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
    "UH-60M Blackhawk", "vtx_uh60m_hoistHookDown", "Hoist Hook Down",{
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
    "UH-60M Blackhawk", "vtx_uh60m_hoistHookStabilize", "Stabilize Hook",{
        private _heli = vehicle player;
        if !([player] call vtx_uh60_hoist_fnc_canControlHoist) exitWith {};

        private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
        if (_hoist_vars isEqualTo []) exitWith{false};
        _hoist_vars params ["_rope", "_dummy", "_hook"];

        [_heli] call vtx_uh60_hoist_fnc_stabilizeHook;
    }, "", [DIK_APOSTROPHE, [false, false, false]], true
] call CBA_fnc_addKeybind; // '

[
    "UH-60M Blackhawk", "vtx_uh60m_hoistHookGetIn", "Get In Hook From Vehicle",{
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

    }, "", [DIK_V, [true, false, false]], false
] call CBA_fnc_addKeybind; // Shift + V

[
    "UH-60M Blackhawk", "vtx_uh60m_hoistHookLoadIn", "Load Patient in Hook",{
        if !(isNull objectParent player) exitWith {}; // must not in a vehicle

        private _hooks = positionCameraToWorld [0,0,2] nearObjects ["vtx_hook", 2];
        if (_hooks isEqualTo []) exitWith {}; // must see a hook

        private _hook = _hooks # 0;
        if !(crew _hook isEqualTo []) exitWith {}; // hook must be free

        private _dragged = player getVariable "ace_dragging_draggedObject";
        if (isNil "_dragged") exitWith {}; // must be ACE dragging a patient

        [player, _dragged] call ace_dragging_fnc_dropObject;

        [{
            params ["_dragged", "_hook"];
            isNull attachedTo _dragged
        }, {
            params ["_dragged", "_hook"];
            _dragged moveInCargo _hook;
            [_hook getVariable 'vtx_uh60_hoist_heli'] call vtx_uh60_hoist_fnc_stabilizeHook;
        }, [_dragged, _hook]] call CBA_fnc_waitUntilAndExecute;

    }, "", [DIK_V, [false, false, true]], false, 0, true
] call CBA_fnc_addKeybind; // Alt + V
