#include "\bmkhs_helisim\fmOverride.hpp"

class CfgVehicles {
    class Heli_Transport_01_base_F;
    class vtx_H60_base: Heli_Transport_01_base_F {
        BMKHS_FM_OVERRIDE

        #include "\bmkhs_helisim\hitPoints.hpp"
        #include "bmkhs_config\helisim_hitpoints.hpp"
        #include "bmkhs_uh60_config.hpp"
    };

    //Variant seats - SEATS_* in helisim_mass.hpp
    class vtx_UH60M: vtx_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_UH60M }; };
    class vtx_UH60M_MEDEVAC: vtx_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_MEDEVAC }; };
    class vtx_S70i: vtx_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_S70I }; };
    class vtx_UH60M_SLICK: vtx_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_SLICK }; };
    class vtx_HH60: vtx_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_MH60M }; };
    class vtx_MH60M: vtx_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_MH60M }; };
    class vtx_MH60M_DAP: vtx_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_DAP }; };
    class vtx_MH60M_DAP_MLASS: vtx_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_DAP }; };
};
