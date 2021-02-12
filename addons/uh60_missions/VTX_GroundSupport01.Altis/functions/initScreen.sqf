params ["_screen"];
_screen addAction ["ACE Spectate", {[true, false, false] call ace_spectator_fnc_setSpectator}, nil, -8, false, true, "", "_this distance _target < 10"];
_screen addAction ["BIS Camera", {["Exit"] call BIS_fnc_camera;}, nil, -8, true, true, "", "_this distance _target < 10"];