vtx_uh60_fmplus_fnc_getEngineConfig = {
  params ["_vehicle"];
  private _config = configFile >> "CfgVehicles" >> typeof _vehicle >> "vtx_SfmPlus";
  private _variables = ["engIdleTQ","engFlyTQ","engStartNG","engIdleNG","engFlyNG","engMaxNG","engStartNP","engIdleNP","engFlyNP"];
  private _values = [];
  if (!(missionnamespace getVariable ["vtx_uh60_sfmplus_engineConfigLoaded", false])) then {
    _values = _variables apply {getNumber (_config >> _x)};
    vtx_uh60_sfmplus_engineConfigValues = _values;
    vtx_uh60_sfmplus_engineConfigLoaded = true;
  };
  vtx_uh60_sfmplus_engineConfigValues
};

vtx_uh60_fmplus_fnc_getEngineState = {
  params ["_vehicle", "_engine"];
  private _output = [
    "vtx_uh60_sfmplus_engState",
    "vtx_uh60_sfmplus_engPowerLeverState",
    "vtx_uh60_sfmplus_engPctNG",
    "vtx_uh60_sfmplus_engPctNP",
    "vtx_uh60_sfmplus_engPctTQ",
    "vtx_uh60_sfmplus_engTGT",
    "vtx_uh60_sfmplus_engOilPSI",
    "vtx_uh60_sfmplus_engFF"
  ] apply {
    (_vehicle getVariable [_x, [-1, -1]]) # _engine
  };

  _output params ["_engState", "_engPowerLeverState", "_engPctNG", "_engPctNP", "_engPctTQ", "_engTGT", "_engOilPSI", "_engFF"];
  private _engineConfig = [_vehicle] call vtx_uh60_fmplus_fnc_getEngineConfig;
  _engineConfig params ["_engIdleTQ","_engFlyTQ","_engStartNG","_engIdleNG","_engFlyNG","_engMaxNG","_engStartNP","_engIdleNP","_engFlyNP"];

  private _engThrottle = if (_engPowerLeverState in ["OFF", "IDLE"]) then {0.0} else {1.0};
  private _engBaseTQ = if (_engPowerLeverState == "OFF") then {0.0} else {_engIdleTQ + (_engFlyTQ - _engIdleTQ) * _engThrottle};
  private _engBaseNG = _engIdleNG + (_engFlyNG - _engIdleNG) * _engThrottle;
  private _engBaseNP = _engIdleNP + (_engFlyNP - _engIdleNP) * _engThrottle;
  _output = _output + [_engThrottle, _engBaseTQ, _engBaseNG, _engBaseNP];
  _output
  //[_engState, _engPowerLeverState, _engPctNG, _engPctNP, _engPctTQ, _engTGT, _engOilPSI, _engFF, _engThrottle, _engBaseTQ, _engBaseNG, _engBaseNP]
};

vtx_uh60_sfmplus_fnc_calculateWeight = {
  params ["_vehicle", "_magazines", "_passengers", "_fuel"];
};

vtx_uh60_sfmplus_fnc_getHoverTorque = {
  params ["_vehicle"];
  private _curGWT_kg     = vtx_uh60_sfmplus_realMass;
  private _config = configFile >> "CfgVehicles" >> typeof _vehicle >> "vtx_SfmPlus";
  private _intHvrTQTable = [getArray (_config >> "hvrTqTable"), _curGWT_kg] call vtx_uh60_sfmplus_fnc_linearInterp;
  _intHvrTQTable select [1,2]
};

vtx_uh60_sfmplus_fnc_getCruiseTorque = {
  params ["_vehicle"];
  private _curGWT_kg     = vtx_uh60_sfmplus_realMass;
  private _config = configFile >> "CfgVehicles" >> typeof _vehicle >> "vtx_SfmPlus";
  private _cruiseTqTable = [getArray (_config >> "cruiseTable"), _curGWT_kg] call vtx_uh60_sfmplus_fnc_linearInterp;
  _cruiseTqTable # 7
};

vtx_uh60_fms_fnc_calculateTQ = {
  params ["_vehicle"];
//--------------------------Coll-----TQ---
};

vtx_uh60_fms_fnc_calculatePerformance = {
  params ["_vehicle"];

};

[vehicle player] call vtx_uh60_fms_fnc_calculatePerformance;