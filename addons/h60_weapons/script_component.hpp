#define COMPONENT h60_weapons
#define COMPONENT_PATH uh60_weapons
#define COMPONENT_BEAUTIFIED H60_WEAPONS
#include "\z\vtx\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_H60_WEAPONS
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_H60_WEAPONS
    #define DEBUG_SETTINGS DEBUG_SETTINGS_H60_WEAPONS
#endif

#include "\z\vtx\addons\main\script_macros.hpp"

#define PYLON_POS_MAX 2
#define PYLON_POS_MIN -1

#define IS_MASTER_ARM if (hct_vehicle getVariable ["hct_h60_weapons_masterArm_isSafe", true]) exitWith {}
