#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"vtx_MH60M", "vtx_MH60M_DAP"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"vtx_UH60"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#define COPILOTVIEW \
initFov=1; \
minFov=0.25; \
maxFov=0.80000001; \
initAngleX=0; \
minAngleX=-75; \
maxAngleX=89; \
initAngleY=0; \
minAngleY=-150; \
maxAngleY=150; \
MOVE_LEFT = -0.2; \
MOVE_RIGHT = 0.5; \
minMoveY = -0.2; \
maxMoveY = 0.1; \
minMoveZ = -0.2; \
maxMoveZ = 0.25;

#include "config\cfgVehicles.hpp"
#include "config\cfgWeapons.hpp"