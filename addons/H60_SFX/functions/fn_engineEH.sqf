/*
 * vtx_uh60_Sound_fnc_EngineEH
 *
 * engine power eventhandler for sound
 *
 * params [vehicle]
 * By: Aaren
 */

params ["_vehicle"];

if (!local _vehicle) exitWith {};

(_vehicle getVariable ["vtx_uh60_sfmplus_engState", ["OFF", "OFF"]]) params ["_eng1State", "_eng2State"];

//_sounds = [];

_Main_Process = {
  params["_vehicle","_types","_state"];
  {
    private ["_array","_file","_volume","_freq","_file","_sound"];
    _array = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> _x);
    _file = _array # 0;

    //-Exterior or Interior
    if (_forEachIndex == 1) then {
      if ((cameraView == "EXTERNAL") or !(cameraOn isEqualTo _vehicle)) then {
        //Ext
        _file = if ("." in _file) then {
          _file
        } else {
          _file + ".wss"
        };
        _volume = _array # 1;
        _freq = _array # 2;
        _range = _array # 3;

        _sound = playSound3D [_file, _vehicle, false, getPosASL _vehicle, _volume, _freq, _range];
        //_sounds pushback [_sound,_forEachIndex];
      };
    } else {
      //Int
      _sound = playSound _file;
      //_sounds pushback [_sound,_forEachIndex];
    };

    //-Player in _vehicle
    if (cameraOn isEqualTo _vehicle) then {
      [{
        params["_cameraView_old","_sound","_state","_eng_states"];

        _exit_state = if (_state == "OFF") then {
          ({_x != "OFF"} count _eng_states) > 0
        } else {
          ({_x == "OFF"} count _eng_states) == 2
        };

        (cameraView != _cameraView_old) or (isNull _sound) or (_exit_state)
        },{
          params["_cameraView_old","_sound","_state"];

          if (!(isNull _sound)) then {
            deleteVehicle _sound;
          };
      }, [cameraView,_sound,_state,(_vehicle getVariable ["vtx_uh60_sfmplus_engState", ["OFF", "OFF"]])]] call CBA_fnc_waitUntilAndExecute;
    };

    //_vehicle setVariable ["vtx_uh60_engine_SoundEffect",_sounds,true];
  } foreach _types;
};

//-Engine Start
if (((_eng1State == "STARTING") or (_eng2State == "STARTING")) && ((_vehicle getSoundController "RotorSpeed") < 0.6)) then {
  [_vehicle,["vtx_soundEngineOnInt","vtx_soundEngineOnExt"],"ON"] call _Main_Process;
};

//-Engine Off
if ((_eng1State == "OFF") && (_eng2State == "OFF")) then {
  [_vehicle,["vtx_soundEngineOffInt","vtx_soundEngineOffExt"],"OFF"] call _Main_Process;
};
