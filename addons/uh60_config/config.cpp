#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {"vtx_UH60M", "vtx_UH60M_Slick", "vtx_UH60M_MEDEVAC", "vtx_S70M"};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        // Phase 1 PR A: uh60_config owns the vehicle declarations and loads
        // EARLY. The old screen-addon edges (mfd/fms/anvishud/doorguns) are
        // gone: the MFD template mounts below resolve by name when the config
        // is read, so the screen addons may load after us (load-order
        // experiment, 2026-09-05). Every addon that re-opens our classes now
        // declares an edge on vtx_UH60_config instead.
        requiredAddons[] = {"vtx_UH60"};
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

#include "config\CfgVehicles.hpp"
