params ["_vehicle"];

//Engine 1
//--Fuel system lever
private _eng1FuelSysLeverPos   = _vehicle animationPhase "Lever_fuelsys1";  //0.0 = OFF, 0.6 = DIR, 1.0 = XFD
private _eng1FuelSysLeverState = _vehicle getVariable "vtx_uh60_acft_eng1FuelSysLeverState";
if (_eng1FuelSysLeverPos <= 0.10) then {
    _eng1FuelSysLeverState = "OFF";
};
if (_eng1FuelSysLeverPos == 0.60) then {
    _eng1FuelSysLeverState = "DIR";
};
if (_eng1FuelSysLeverPos >= 0.90) then {
    _eng1FuelSysLeverState = "XFD";
};
_vehicle setVariable ["vtx_uh60_acft_eng1FuelSysLeverState", _eng1FuelSysLeverState];
//--Power control lever
private _eng1PwrCtrlLeverPos   = _vehicle animationPhase "Lever_engpower1"; //0.0 = OFF, 0.23 = IDLE, 0.85 = FLY
private _eng1PwrCtrlLeverState = _vehicle getVariable "vtx_uh60_acft_eng1PwrCtrlLeverState";
if (_eng1PwrCtrlLeverPos <= 0.10) then {
    _eng1PwrCtrlLeverState = "OFF";
};
if (_eng1PwrCtrlLeverPos == 0.23) then {
    _eng1PwrCtrlLeverState = "IDLE";
};
if (_eng1PwrCtrlLeverPos >= 0.80) then {
    _eng1PwrCtrlLeverState = "FLY";
};
_vehicle setVariable ["vtx_uh60_acft_eng1PwrCtrlLeverState", _eng1PwrCtrlLeverState];

//systemChat format ["Eng 1 Fuel Sys Lvr Pos %1 / Pwr Ctrl Lvr Pos %2", _eng1FuelSysLeverPos, _eng1PwrCtrlLeverPos];

//Engine 2
//--Fuel system lever
private _eng2FuelSysLeverPos   = _vehicle animationPhase "Lever_fuelsys2";  //0.0 = OFF, 0.6 = DIR, 1.0 = XFD
private _eng2FuelSysLeverState = _vehicle getVariable "vtx_uh60_acft_eng2FuelSysLeverState";
if (_eng2FuelSysLeverPos <= 0.10) then {
    _eng2FuelSysLeverState = "OFF";
};
if (_eng2FuelSysLeverPos == 0.60) then {
    _eng2FuelSysLeverState = "DIR";
};
if (_eng2FuelSysLeverPos >= 0.90) then {
    _eng2FuelSysLeverState = "XFD";
};
_vehicle setVariable ["vtx_uh60_acft_eng2FuelSysLeverState", _eng2FuelSysLeverState];
//--Power control lever
private _eng2PwrCtrlLeverPos   = _vehicle animationPhase "Lever_engpower2"; //0.0 = OFF, 0.23 = IDLE, 0.85 = FLY
private _eng2PwrCtrlLeverState = _vehicle getVariable "vtx_uh60_acft_eng2PwrCtrlLeverState";
if (_eng2PwrCtrlLeverPos <= 0.10) then {
    _eng2PwrCtrlLeverState = "OFF";
};
if (_eng2PwrCtrlLeverPos == 0.23) then {
    _eng2PwrCtrlLeverState = "IDLE";
};
if (_eng2PwrCtrlLeverPos >= 0.80) then {
    _eng2PwrCtrlLeverState = "FLY";
};
_vehicle setVariable ["vtx_uh60_acft_eng2PwrCtrlLeverState", _eng2PwrCtrlLeverState];

//systemChat format ["Eng 2 Fuel Sys Lvr Pos %1 / Pwr Ctrl Lvr Pos %2", _eng2FuelSysLeverPos, _eng2PwrCtrlLeverPos];

//systemChat format ["SFM Plus Power Levers = %1", _vehicle getVariable "vtx_uh60_sfmplus_engPowerLeverState"];