// testing, update fncs on the fly
//#undef PREP
//#define PREP(var1) TRIPLES(ADDON,fnc,var1) = { call compile preProcessFileLineNumbers '\MAINPREFIX\PREFIX\SUBPREFIX\COMPONENT_F\functions\DOUBLES(fnc,var1).sqf' }

PREP(setMarkPoint);
PREP(setup);
PREP(updateWaypointInfo);
PREP(interaction_pageChange);
PREP(interaction_waypoint);
PREP(perFrame);
PREP(perSecond);
PREP(addWaypoint);
PREP(selectWaypoint);
PREP(hasWaypoint);
PREP(deleteWaypoint);
