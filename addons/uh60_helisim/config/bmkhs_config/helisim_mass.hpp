/////////////////////////////////////////////////////////////////////////////////////////////
// Mass and Balance /////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//UH-60: empty mass, datum and empty CG are the pre-1.1 config's (emptyMass 5896,
//centerOfMassRefDatum y 9.70, emptyCenterOfMass 8.70 - empty CG at model y 1.00).
//vtx_uh60.p3d is autocenter = 0 (boundingCenter [0,0,0]), so model and Arma frames coincide.

    //Empty airframe. emptyMom = emptyMass x FS of the empty CG (m) = 5896 x 8.70
    emptyMass         = 5896; //kg
    emptyMom          = 51295.2;

    //Maximum gross mass - bounds the fixed test weight. 22,000 lb.
    maxGrossMass      = 9979; //kg

    //Fuselage station datum and CG limits. The limits are the UH-60's FS 341 / FS 360 in,
    //converted through the datum above (y = fsDatum - FS m). They only draw in the FM debug
    //overlay; check them once the datum is surveyed against the model.
    fsDatum             = 9.70;     //m, station 0 reference
    fwdCgLimit          = 1.039;    //m, FS 341
    aftCgLimit          = 0.556;    //m, FS 360
    //The pre-1.1 config's vertical CoM (centerOfMassRefDatum z).
    comCorrection[]     = {0.0, 0.0, -1.0};
    //Casual mode center of mass
    casualModeCom[]     = {0.0, 1.00, -1.0};

/////////////////////////////////////////////////////////////////////////////////////////////
// Indexed mass items ///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
    //Every mass item is {arm, mass}: arm[] is {lateral, longitudinal, vertical} in metres,
    //right-positive / nose-positive, in the same surveyed frame as fsDatum.

    //SEATS. Occupancy is resolved against fullCrew, so an empty seat adds no mass.
    //  role       - "driver" | "gunner" | "commander" | "turret" | "cargo"
    //  turret[]   - turret path for gunner/commander/turret seats; {} for the driver
    //  cargoIndex - cargo slot for role = "cargo"; -1 otherwise
    //Only the two pilots - every H-60 variant has them. Door gunners, FFV and cargo turrets
    //differ by variant and are not declared yet, so they add no mass. Arms are ESTIMATES.
    numSeats = 2;
    class Seats {
        class Seat01 {  //pilot, right seat
            arm[]      = { 0.550, 4.600,-0.800};
            mass       = 100.0;
            role       = "driver";
            turret[]   = {};
            cargoIndex = -1;
        };
        class Seat02 {  //copilot, left seat - CopilotTurret
            arm[]      = {-0.550, 4.600,-0.800};
            mass       = 100.0;
            role       = "turret";
            turret[]   = {0};
            cargoIndex = -1;
        };
    };

    //No external stations, internal magazines or stores declared yet.
    numStations  = 0;
    numMagazines = 0;
    numStores    = 0;
