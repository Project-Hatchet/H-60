#define COMPONENT uh60_hoist
#define COMPONENT_BEAUTIFIED UH60_Hoist
#include "\z\vtx\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define CBA_DEBUG_SYNCHRONOUS
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_UH60_HOIST
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_UH60_HOIST
    #define DEBUG_SETTINGS DEBUG_SETTINGS_UH60_HOIST
#endif

#include "\z\vtx\addons\main\script_macros.hpp"

#define MAX_ROPE_LENGTH 88.3 // 290 feet
#define MAX_HOIST_SPEED 1.778 // 350 feet per minute
#define NEAR_END_THRESHOLD 3.048 // 10 feet
#define NEAR_END_SPEED 0.254 // 50 feet per minute
