#define COMPONENT uh60_config
#define COMPONENT_BEAUTIFIED UH60_CONFIG
#include "\z\vtx\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_UH60_CONFIG
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_UH60_CONFIG
    #define DEBUG_SETTINGS DEBUG_SETTINGS_UH60_CONFIG
#endif

#include "\z\vtx\addons\main\script_macros.hpp"

#define MASS_CABINSEATS 110 // 10 kg/seat x11
#define MASS_COCKPITDOORS 10 // ???
//#define MASS_EFS 198 // External Fuel System, 2-station, mistakenly labelled ESSS for now
#define MASS_ESSS 198 // External Stores Support System
//#define MASS_ESSS 368 // External Stores Support System, 4-station, don't have this yet
#define MASS_ERFS 167 // Robertson Guardian 200 Internal Auxiliary Fuel Tank System
#define MASS_FLIR 54 //
#define MASS_GAU21 67 // 37 kg (81.6 lb) + 50 g/rnd x 600 rnd
#define MASS_GUNMOUNT 105 // 25.4 g/rnd x 4000 rnd = 101.6 kg, then add box/struts
#define MASS_GUNNERSEATS 40 // 20 kg/seat x2
#define MASS_HH60FLARES 5 // ???
#define MASS_LASS 103
#define MASS_MAWS 5 // ???
#define MASS_MINIGUN 39 // 39 kg, 85 lb
#define MASS_PROBE 30 // ???
#define MASS_RADAR 74 // AN/APQ-187 Silent Knight
#define MASS_SKIS 5 // ???
