/*
 * Author: Ampersand
 * Take up helicopter's hoist cable to 0.5 m
 *
 * Arguments:
 * 0: Helicopter <OBJECT>
 *
 * Return Value:
 * 0: Success <BOOLEAN>
 *
 * Example:
 * [_heli] call vtx_uh60_hoist_fnc_raiseHookToHeli
 */

params ["_heli"];
if !(local _heli) exitWith {[_heli] remoteExecCall ["vtx_uh60_hoist_fnc_raiseHookToHeli", _heli]};

private _hoist_vars = _heli getVariable ["vtx_uh60_hoist_vars", []];
if (_hoist_vars isEqualTo []) exitWith{false};
_hoist_vars params ["_rope", "_dummy", "_hook"];

_hoistPos = [1.405, 2.03, 0.45];
ropeUnwind [_rope, 1.5, 0.5];


// Added by Fawks
// Monitor the hook while it is being raised.
// If the hook goes underground teleport it above ground.

[_rope, _hook] spawn {
  params ["_rope", "_hook"];
  waitUntil {
    _hookPos = getPosATL _hook;
    if ((_hookPos # 2) > 10) then {
      true
    } else {
      if ((_hookPos) # 2 < 0) then {
        _hook setPos [_hookPos # 0, _hookPos # 1, 5];
      };
      sleep 1;
      false
    };
  };
};
/*
[{
	params ["_heli", "_hoistPos", "_dummy", "_rope"];
	private _dummyPos = getPos _dummy;
	// set dummy velocity to below and toward hoist
	private _vectorDir = (_dummyPos vectorFromTo _hoistPos) vectorAdd (_dummyPos vectorFromTo [_hoistPos # 0, _hoistPos # 1, _dummyPos # 2]);
	if !((_dummyPos distance _hoistPos) < (ropeLength _rope)) then {
		_dummy setVelocity _vectorDir;
	};
	((_dummyPos distance _hoistPos) < 1.2) || {(ropeLength _rope < 0.5) || (ropeUnwound _rope)}
}, {
	//params ["_heli", "_hoistPos", "_dummy", "_rope"];
	//_dummy attachTo [_heli, _hoistPos vectorAdd [0,0,-1]];
}, [_heli, _hoistPos, _dummy, _rope]] call CBA_fnc_waitUntilAndExecute;
*/

true;
