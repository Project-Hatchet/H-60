#define COMPONENT uh60_code
#define COMPONENT_BEAUTIFIED UH60_CODE
#include "\z\vtx\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_UH60_CODE
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_UH60_CODE
    #define DEBUG_SETTINGS DEBUG_SETTINGS_UH60_CODE
#endif

#include "\z\vtx\addons\main\script_macros.hpp"

#define MASS_CABINSEATS 1100 // 10 kg/seat x11
#define MASS_COCKPITDOORS 10 // ???
#define MASS_ERFS 100 // ???
#define MASS_ESSS 1500 // ??? 500 Gal avgas is ~1400 kg
#define MASS_FLIR 54 // ???
#define MASS_GAU21 67 // 37 kg (81.6 lb) + 50 g/rnd x 600 rnd
#define MASS_GUNMOUNT 105 // 25.4 g/rnd x 4000 rnd = 101.6 kg, then add box/struts
#define MASS_GUNNERSEATS 25 // (10 kg/seat + a bit) x2
#define MASS_LASS 100
#define MASS_MAWS 5 // ???
#define MASS_MINIGUN 39 // 39 kg, 85 lb
#define MASS_PROBE 100
#define MASS_RADAR 74 // AN/APQ-187 Silent Knight
#define MASS_SKIS 10 // ???
