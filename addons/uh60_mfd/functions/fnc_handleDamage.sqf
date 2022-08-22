params ["_vehicle"];
if ((_vehicle getHitPointDamage "mfd1") > 0.4) then {_vehicle animateSource ["MFD1_Hide", 1]};
if ((_vehicle getHitPointDamage "mfd2") > 0.4) then {_vehicle animateSource ["MFD2_Hide", 1]};
if ((_vehicle getHitPointDamage "mfd3") > 0.4) then {_vehicle animateSource ["MFD3_Hide", 1]};
if ((_vehicle getHitPointDamage "mfd4") > 0.4) then {_vehicle animateSource ["MFD4_Hide", 1]};