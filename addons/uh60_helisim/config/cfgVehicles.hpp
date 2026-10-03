#include "\bmkhs_helisim\fmOverride.hpp"

class CfgVehicles {
    class Heli_Transport_01_base_F;
    //The H-60 base, reopened with its own parent so its config is extended, not replaced.
    //Every H-60 variant inherits from it.
    class vtx_H60_base: Heli_Transport_01_base_F {
        //Core owns the force coefficients - packs cannot tune them
        BMKHS_FM_OVERRIDE

        #include "bmkhs_uh60_config.hpp"
    };
};
