
// testing, update fncs on the fly
//#undef PREP
//#define PREP(var1) TRIPLES(ADDON,fnc,var1) = { call compile preProcessFileLineNumbers '\MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT_F\functions\DOUBLES(fnc,var1).sqf' }


PREP(apuState);
PREP(batteryState);
PREP(engineEH);
PREP(hasFuelFlow);
PREP(perFrame);
PREP(perSecond);
PREP(rotorBrakeInterlock);
PREP(setup);
PREP(shutdown);
PREP(starterState);
PREP(wheelBrakes);

//New aircraft module stuff
PREP(acftAPU);
PREP(acft_SetAPU);
PREP(acftBattery);
PREP(acftDebug);
PREP(acftEngController);
PREP(acftEngLeverStates);
PREP(acftGenController);
PREP(acftRTDController);
PREP(acftSoundController);
PREP(acftSwitchStates);

PREP(UpdateAPU_State);
