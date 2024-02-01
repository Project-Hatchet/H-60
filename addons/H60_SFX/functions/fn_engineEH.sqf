/*
 * vtx_uh60_Sound_fnc_EngineEH
 *
 * engine power eventhandler for sound
 *
 * By: Aaren
 */

params["_vehicle","_types","_state","_condition","_status_count",["_NotSave",false]];

if !(isnull (_vehicle getVariable ["vtx_uh60_sound_obj",objNull])) exitWith {};

{
  private ["_array","_file","_volume","_freq","_file","_sound"];
  _array = getArray (configOf _vehicle >> _x);
  _file = _array # 0;

  _sound = objNull;

  //-Exterior or Interior
  if (_forEachIndex == 1) then {
    if ((cameraView == "EXTERNAL") || !(cameraOn isEqualTo _vehicle)) then {
      //Ext
      _array params ["","_freq","_range"];
      _sound = _vehicle say3D  [_file, _range, _freq, 2];
    };
  } else {
    //Int
    if ((cameraView == "INTERNAL") && (cameraOn isEqualTo _vehicle)) then {
      _sound = playSound _file;
    };
  };
  
  if !(_NotSave) then {
    _vehicle setVariable ["vtx_uh60_sound_obj",_sound];
  };

  //-Player in _vehicle
  if ((cameraOn isEqualTo _vehicle) && !(isnull _sound)) then {
    [{
      params["_vehicle","_cameraView",["_sound",objNull],"_state","_condition","_status_count"];

      _exit = [
        ({_x != "OFF"} count call _condition) < _status_count,
        ({_x != "OFF"} count call _condition) > 0
      ] select (_state == "OFF");

      (cameraView != _cameraView) || (isnull _sound) || _exit || _exit2
      },{
        params["_vehicle","","_sound"];

        if !(isnull _sound) then {
          deleteVehicle _sound;
          _vehicle setVariable ["vtx_uh60_sound_obj",objNull];
        };
    }, [_vehicle,cameraView,_sound,_state,_condition,_status_count]] call CBA_fnc_waitUntilAndExecute;
  };
} foreach _types;