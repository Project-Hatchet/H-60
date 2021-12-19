#include "\z\ace\addons\main\script_macros.hpp"

// testing, update fncs on the fly

#define ANIMSRC(name,src,per,init) \
class name { \
  source=QUOTE(src); \
  animPeriod=per; \
  initPhase=init; \
}

//#undef PREP
//#define PREP(var1) TRIPLES(ADDON,fnc,var1) = { call compile preProcessFileLineNumbers '\MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT_F\functions\DOUBLES(fnc,var1).sqf' }

#define POS_MOVE_CABIN_COCKPIT {0.023875,4.2461,-0.577079}
#define ZEUS_EXIT if !(isNull curatorCamera) exitWith {};
