/////////////////////////////////////////////////////////////////////////////////////////////
// Hitpoints ////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
    //HeliSim-role hitpoints only. The rest live in uh60_config (cfgVehiclesParts\hitPoints.hpp).
    //BMKHS_HITPOINT(class, selection, armor, radius, minimalHit, explosionShielding, role, index)
    class HitPoints
    {
        //--- Powerplant ----------------------------------------------------------
        BMKHS_HITPOINT(hitengine1, "hitengine1", 0.072, 0.59, 0.1, 0.46, "engines", 0)
        BMKHS_HITPOINT(hitengine2, "hitengine2", 0.072, 0.59, 0.1, 0.46, "engines", 1)
        BMKHS_HITPOINT_ENGINE_PASSTHROUGH("0.5 * (HitEngine1 + HitEngine2)")
        BMKHS_HITPOINT(ApuHit, "ApuHit", 0.048, 0.46, 0.1, 0.4, "apu", 0)

        //--- Drivetrain ----------------------------------------------------------
        BMKHS_HITPOINT(MainRotorGearBox, "MainRotorGearBox", 0.072, 0.44, 0.1, 0.599, "transmission", 0)
        BMKHS_HITPOINT(TailIntermediateGearBox, "TailIntermediateGearBox", 0.036, 0.22, 0.1, 0.3, "intermediateGearbox", 0)
        BMKHS_HITPOINT(TailGearBox, "TailGearBox", 0.072, 0.69, 0.1, 0.36, "tailRotorGearbox", 0)

        //--- Rotors --------------------------------------------------------------
        BMKHS_HITPOINT(hithrotor, "hithrotor", 10.35, 0.47, 130, 3000, "mainRotor", 0)
        BMKHS_HITPOINT(hitvrotor, "hitvrotor", 0.054, 0.24, 0.1, 0.27, "tailRotor", 0)

        //--- Stabilator ----------------------------------------------------------
        BMKHS_HITPOINT(RearAutoStab, "RearAutoStab", 0.012, 0.14, 0.1, 0.1, "stabilator", 0)

        //--- Electrical ----------------------------------------------------------
        BMKHS_HITPOINT(Battery1, "Battery1", 0.031333, 0.21, 0.1, 0.261, "battery1", 0)
        BMKHS_HITPOINT(Battery2, "Battery2", 0.031333, 0.21, 0.1, 0.261, "battery2", 0)
    };
