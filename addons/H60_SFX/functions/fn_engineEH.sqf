/*
 * vtx_uh60_Sound_fnc_EngineEH
 *
 * engine power eventhandler for sound
 *
 * params [vehicle]
 * By: Aaren
 */

params["_vehicle","_types","_state","_condition","_status_count"];

if !(isnull (_vehicle getVariable ["vtx_uh60_sound_obj",objNull])) exitWith {};

{
  private ["_array","_file","_volume","_freq","_file","_sound"];
  _array = getArray (configOf _vehicle >> _x);
  _file = _array # 0;

  _sound = objNull;

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
    if ((cameraView == "INTERNAL") && (cameraOn isEqualTo _vehicle)) then {
      _sound = playSound _file;
    };
  };

  if (_sound isEqualType 0) then {
    _sound = objNull;
  };

  //-Player in _vehicle
  if ((cameraOn isEqualTo _vehicle) && !(isNull _sound)) then {
    [{
      params["_vehicle","_cameraView",["_sound",objNull],"_state","_condition","_status_count"];

      _exit = [
        ({_x != "OFF"} count _condition) < _status_count,
        ({_x != "OFF"} count _condition) > 0
      ] select (_state == "OFF");

      (cameraView != _cameraView) || (isNull _sound) || (_exit)
      },{
        params["_vehicle","","_sound"];

        if !(isNull _sound) then {
          deleteVehicle _sound;
          _vehicle setVariable ["vtx_uh60_sound_obj",objNull];
        };
    }, [_vehicle,cameraView,_sound,_state,call _condition,_status_count]] call CBA_fnc_waitUntilAndExecute;
  };
} foreach _types;

_vehicle setVariable ["vtx_uh60_sound_obj",_sound];
