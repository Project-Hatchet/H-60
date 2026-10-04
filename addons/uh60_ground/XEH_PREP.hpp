
// testing, update fncs on the fly
//#undef PREP
//#define PREP(var1) TRIPLES(ADDON,fnc,var1) = { call compile preProcessFileLineNumbers '\MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT_F\functions\DOUBLES(fnc,var1).sqf' }


PREP(pbArm);
PREP(pbHoldTick);
PREP(pbToggle);
PREP(perSecond);
PREP(setup);
PREP(taxiTick);
PREP(wheelBrakes);


