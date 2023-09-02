/*
 * vtx_uh60_Sound_fnc_EngineEH
 *
 * engine power eventhandler for sound
 *
 * params [vehicle]
 * By: Aaren
 */

params["_vehicle","_types","_state","_status","_status_count"];

private _sound = objNull;
{
  private ["_array","_file","_volume","_freq","_file"];
  _array = getArray (configOf _vehicle >> _x);
  _file = _array # 0;

  //-Exterior or Interior
  if (_forEachIndex == 1) then {
    if ((cameraView == "EXTERNAL") or !(cameraOn isEqualTo _vehicle)) then {
      //Ext
      _file = [_file + ".wss",_file] select ("." in _file);
      _array params ["","_volume","_freq","_range"];

      _sound = playSound3D [_file, _vehicle, false, getPosASL _vehicle, _volume, _freq, _range, 0, true];
    };
  } else {
    //Int
    if (cameraView == "INTERNAL") then {
      _sound = playSound _file;
    };
  };

  //-Player in _vehicle
  if ((cameraOn isEqualTo _vehicle) && !(isNull _sound)) then {
    [{
      params["_cameraView","_sound","_state","_status","_status_count"];

      _exit_state = [
        ({_x == "OFF"} count _status) == _status_count,
        ({_x != "OFF"} count _status) > 0
      ] select (_state == "OFF");

      (cameraView != _cameraView) or (isNull _sound) or (_exit_state)
      },{
        params["_cameraView","_sound","_state"];

        if !(isNull _sound) then {
          deleteVehicle _sound;
        };
    }, [cameraView,_sound,_state,call _status,_status_count]] call CBA_fnc_waitUntilAndExecute;
  };
} foreach _types;
