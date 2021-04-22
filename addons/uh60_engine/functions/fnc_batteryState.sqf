/*
 * vtx_uh60_engine_fnc_batteryState
 *
 * manages battery state
 *
 * params (array)[(object) vehicle, (string) animation name, (string) animation end state]
 */

#include "defines.hpp"
params ["_vehicle", "_animName", "_animEndState"];

private _poweredAnim = if (BATT_ON_AND_POWERED) then [{1},{0}];
if (ANIM("PowerOnOff") != _poweredAnim) then {
    _vehicle animate ["PowerOnOff",_poweredAnim];
};
private _genAnim = if (ENGINE_GEN_POWERED || APU_GEN_POWERED) then [{1},{0}];
if (ANIM("GeneratorsOnOff") != _genAnim) then {
    _vehicle animate ["GeneratorsOnOff",_genAnim];
    _vehicle animate ["MFD1_hide",_genAnim*-1];
    _vehicle animate ["MFD2_hide",_genAnim*-1];
    _vehicle animate ["MFD4_hide",_genAnim*-1];
};

_vehicle animate ["ESIS_hide",ANIM("Switch_stbyinst")];
[_vehicle] call vtx_uh60_cas_fnc_updateCautionPanel;

if (_poweredAnim == 1) then {
    _vehicle animateSource ["TestLte", 1];
    _vehicle animateSource ["BattGood", 1];
    _vehicle animateSource ["EmerRlse", 1];
};