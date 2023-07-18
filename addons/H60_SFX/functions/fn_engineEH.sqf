/*
 * vtx_uh60_Sound_fnc_EngineEH
 *
 * engine power eventhandler for sound
 *
 * params [vehicle]
 * By: Aaren
 */

params ["_vehicle"];

(_vehicle getVariable ["vtx_uh60_sfmplus_engState", ["OFF", "OFF"]]) params ["_eng1State", "_eng2State"];

_Main_Process = {
  params["_vehicle","_types","_state"];
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
        _volume = _array # 1;
        _freq = _array # 2;
        _range = _array # 3;

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
        params["_cameraView_old","_sound","_state","_eng_states"];

        _exit_state = [
          ({_x == "OFF"} count _eng_states) == 2,
          ({_x != "OFF"} count _eng_states) > 0
        ] select(_state == "OFF");

        (cameraView != _cameraView_old) or (isNull _sound) or (_exit_state)
        },{
          params["_cameraView_old","_sound","_state"];

          if !(isNull _sound) then {
            deleteVehicle _sound;
          };
      }, [cameraView,_sound,_state,(_vehicle getVariable ["vtx_uh60_sfmplus_engState", ["OFF", "OFF"]])]] call CBA_fnc_waitUntilAndExecute;
    };
  } foreach _types;
};

private _rotorspeed = _vehicle getSoundController "RotorSpeed";

//-Engine Start
if (((_eng1State == "STARTING") or (_eng2State == "STARTING")) && (_rotorspeed < 0.6)) then {
  [_vehicle,["vtx_soundEngineOnInt","vtx_soundEngineOnExt"],"ON"] call _Main_Process;
};

//-Engine Off
if (((_eng1State == "OFF") or (_eng2State == "OFF")) && (_rotorspeed != 0)) then {
  [_vehicle,["vtx_soundEngineOffInt","vtx_soundEngineOffExt"],"OFF"] call _Main_Process;
};
