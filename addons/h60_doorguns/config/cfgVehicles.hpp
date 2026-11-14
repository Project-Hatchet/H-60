class CfgVehicles {
    class Heli_Transport_01_base_F;
    class vtx_H60_base: Heli_Transport_01_base_F {
        // The door-gun seats' Hatchet interaction (hct_turret_1/2: minigun power,
        // safety, ammo can, windows). Variants that replace the guns (MEDEVAC
        // windows) declare their own hct_turret_1/2.
        #include "hct_minigun.hpp"
    };
};
