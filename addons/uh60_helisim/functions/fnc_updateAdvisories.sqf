/* ----------------------------------------------------------------------------
Function: vtx_uh60_helisim_fnc_updateCautions

Description:
    ...

Parameters:
    ...

Returns:
    ...

Examples:
    ...

Author:
    BradMick
---------------------------------------------------------------------------- */
params ["_vehicles"];

#define ADVISORY(MESSAGE,CONDITION) \
    if(CONDITION) then { \
        [_vehicle, MESSAGE, {CONDITION}, false, true] call vtx_uh60_cas_fnc_registerCautionAdvisory; \
    };

ADVISORY("WOW", _vehicle getVariable "bmkhs_onGround")

ADVISORY("BOOST PUMP 1 ON",((_this # 0) animationPhase "Switch_fuelboostpump1" == 0))
ADVISORY("BOOST PUMP 2 ON",((_this # 0) animationPhase "Switch_fuelboostpump2" == 0))

if ((_this # 0) magazineTurretAmmo ["60Rnd_CMFlareMagazine",[-1]] < 30 && (_this # 0) magazineTurretAmmo ["60Rnd_CMFlareMagazine",[-1]] > 0) then {
    [_vehicle, "FLARE LOW", {((_this # 0) magazineTurretAmmo ["60Rnd_CMFlareMagazine",[-1]] < 30 && (_this # 0) magazineTurretAmmo ["60Rnd_CMFlareMagazine",[-1]] > 0)}, false, true] call vtx_uh60_cas_fnc_registerCautionAdvisory;
};
if ((_this # 0) magazineTurretAmmo ["60Rnd_CMFlareMagazine",[-1]] == 0) then {
    [_vehicle, "FLARE OUT", {((_this # 0) magazineTurretAmmo ["60Rnd_CMFlareMagazine",[-1]] == 0)}, false, true] call vtx_uh60_cas_fnc_registerCautionAdvisory;
};

ADVISORY("LANDING LIGHT ON",(vtx_uh60_misc_landingLightOn))

ADVISORY("LRD LASE DES",(!(isNull (laserTarget _vehicle))))

[_vehicle, true] call vtx_uh60_cas_fnc_clearCautionsList;