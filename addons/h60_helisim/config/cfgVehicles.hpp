#include "\bmkhs_helisim\fmOverride.hpp"

class CfgVehicles {
    class Heli_Transport_01_base_F;
    class hct_H60_base: Heli_Transport_01_base_F {
        BMKHS_FM_OVERRIDE

        #include "\bmkhs_helisim\hitPoints.hpp"
        #include "bmkhs_config\helisim_hitpoints.hpp"
        #include "bmkhs_uh60_config.hpp"
    };

    //Variant seats - SEATS_* in helisim_mass.hpp. hct_MH60M_DAP_MLASS inherits the DAP's.
    class hct_UH60M: hct_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_UH60M }; };
    class hct_UH60M_MEDEVAC: hct_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_MEDEVAC }; };
    class hct_UH60M_SLICK: hct_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_SLICK }; };
    class hct_S70i: hct_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_S70I }; };
    class hct_HH60: hct_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_MH60M }; };
    class hct_MH60M: hct_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_MH60M }; };
    class hct_MH60M_DAP: hct_H60_base { class BMKHS_HeliSim: BMKHS_HeliSim { SEATS_DAP }; };
};
