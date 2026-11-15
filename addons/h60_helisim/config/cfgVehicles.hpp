#include "\bmkhs_helisim\fmOverride.hpp"

class CfgVehicles {
    class Heli_Transport_01_base_F;
    class hct_H60_base: Heli_Transport_01_base_F {
        BMKHS_FM_OVERRIDE

        #include "\bmkhs_helisim\hitPoints.hpp"
        #include "bmkhs_config\helisim_hitpoints.hpp"
        #include "bmkhs_uh60_config.hpp"
    };

    // Per-variant seats (numSeats + Seats) live in each variant PBO, built from the
    // SEATS_* macros in bmkhs_config\helisim_seats.hpp.
};
