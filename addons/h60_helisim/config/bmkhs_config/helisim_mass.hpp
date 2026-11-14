/////////////////////////////////////////////////////////////////////////////////////////////
// Mass and Balance /////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

    //Empty airframe, empty CG at FS 8.70 m
    emptyMass         = 5896; //kg
    emptyMom          = 51295.2;

    //22,000 lb
    maxGrossMass      = 9979; //kg

    //Datum and CG limits, FS 341 / 360 in
    fsDatum             = 10.44;     //m, station 0 reference
    fwdCgLimit          = 1.780;    //m, FS 341
    aftCgLimit          = 1.180;    //m, FS 364.5
    comCorrection[]     = {0.0, 0.0, 0.3};
    //Casual mode center of mass
    casualModeCom[]     = {0.0, 1.81, 1.77};

/////////////////////////////////////////////////////////////////////////////////////////////
// Indexed mass items ///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
    //Arms are {right, forward, up} in m. Seat and equipment arms are estimates.

    //Pilots on every variant. Each variant adds its own seats from Seat03 (cfgVehicles.hpp).
    //Arms measured in game (occupant's chest). S-70i and Slick door gun seats use the UH-60M arms.
    #include "helisim_seats.hpp"

    numSeats = 2;
    class Seats {
        SEAT_DRIVER(Seat01, 0.53, 4.44,-0.33)     //pilot, right seat
        SEAT_TURRET(Seat02, 0,-0.58, 4.44,-0.33)  //copilot, left seat
    };

    //Masses from uh60_config MASS_* defines. ERFS fuel is in helisim_fuel.hpp.
    numEquipment = 27;
    class Equipment {
        //--- Stores support ---------------------------------------------------
        class Equipment01 {  //ESSS - External Stores Support System
            animation      = "ESSS_show";
            installedPhase = 1;
            mass           = 198;
            arm[]          = { 0.000, 0.600,  0.400};
        };
        class Equipment02 {  //LASS
            animation      = "LASS_show";
            installedPhase = 1;
            mass           = 103;
            arm[]          = { 0.000, 0.600,  0.400};
        };
        class Equipment03 {  //MLASS
            animation      = "MLASS_show";
            installedPhase = 1;
            mass           = 103;
            arm[]          = { 0.000, 0.600,  0.400};
        };
        class Equipment04 {  //EGMS - External Gun Mount System
            animation      = "EGMS_show";
            installedPhase = 1;
            mass           = 100;
            arm[]          = { 0.000, 0.600,  0.000};
        };

        class Equipment05 {  //ERFS, empty
            animation      = "ERFS_show";
            installedPhase = 1;
            mass           = 167;
            arm[]          = {-0.047, 0.673, -0.272};
        };
        class Equipment06 {  //MITAS
            animation      = "MITAS_show";
            installedPhase = 1;
            mass           = 0;
            arm[]          = { 0.000, 0.000,  0.000};
        };
        class Equipment07 {  //Refuelling probe ???
            animation      = "Fuelprobe_show";
            installedPhase = 1;
            mass           = 30;
            arm[]          = { 0.900, 4.800, -0.300};
        };

        //--- Sensors --------------------------------------------------------------
        class Equipment08 {  //FLIR pod
            animation      = "RADAR_HIDE";
            installedPhase = 0;
            mass           = 74;
            arm[]          = { 0.000, 5.600, -1.100};
        };
        class Equipment09 {  //FLIR turret
            animation      = "FLIR_HIDE";
            installedPhase = 0;
            mass           = 54;
            arm[]          = { 0.000, 5.800, -1.100};
        };

        //--- Rescue -----------------------------------------------------------------
        class Equipment10 {  //Rescue hoist - Collins 42325
            animation      = "Hoist_hide";
            installedPhase = 0;
            mass           = 50;
            arm[]          = { 1.200, 1.500,  0.900};
        };

        //--- Weapons ------------------------------------------------------------------
        class Equipment11 {  //GAU-21 left
            animation      = "GAU21_L_Hide";
            installedPhase = 0;
            mass           = 37;   //dry - belt is a magazine
            arm[]          = {-1.100, 1.000, -0.300};
        };
        class Equipment12 {  //GAU-21 right
            animation      = "GAU21_R_Hide";
            installedPhase = 0;
            mass           = 37;   //dry - belt is a magazine
            arm[]          = { 1.100, 1.000, -0.300};
        };
        class Equipment13 {  //Minigun left
            animation      = "Minigun_L_hide";
            installedPhase = 0;
            mass           = 39;
            arm[]          = {-1.150, 2.900, -0.200};
        };
        class Equipment14 {  //Minigun right
            animation      = "Minigun_R_hide";
            installedPhase = 0;
            mass           = 39;
            arm[]          = { 1.150, 2.900, -0.200};
        };
        class Equipment15 {  //Minigun mount left
            animation      = "Minigun_Mount_L_hide";
            installedPhase = 0;
            mass           = 3.4;   //dry - belt is a magazine
            arm[]          = {-0.950, 2.900, -0.500};
        };
        class Equipment16 {  //Minigun mount right
            animation      = "Minigun_Mount_R_hide";
            installedPhase = 0;
            mass           = 3.4;   //dry - belt is a magazine
            arm[]          = { 0.950, 2.900, -0.500};
        };

        //--- Cabin ------------------------------------------------------------------------
        class Equipment17 {  //Gunner seats, x2
            animation      = "GunnerSeats_Hide";
            installedPhase = 0;
            mass           = 30.8;
            arm[]          = { 0.000, 2.900, -0.700};
        };
        class Equipment18 {  //Cabin seats, row 1
            animation      = "CabinSeats_1_Hide";
            installedPhase = 0;
            mass           = 24.9;
            arm[]          = { 0.000, 1.800, -0.700};
        };
        class Equipment19 {  //Cabin seats, row 2
            animation      = "CabinSeats_2_Hide";
            installedPhase = 0;
            mass           = 33.1;
            arm[]          = { 0.000, 0.800, -0.700};
        };
        class Equipment20 {  //Cabin seats, row 3
            animation      = "CabinSeats_3_Hide";
            installedPhase = 0;
            mass           = 33.1;
            arm[]          = { 0.000, -0.300, -0.700};
        };
        class Equipment21 {  //Cockpit doors ???
            animation      = "Cockpitdoors_Hide";
            installedPhase = 0;
            mass           = 10;
            arm[]          = { 0.000, 4.300, -0.300};
        };

        //--- Exterior kit -----------------------------------------------------------------
        class Equipment22 {  //Skis ???
            animation      = "Skis_show";
            installedPhase = 1;
            mass           = 5;
            arm[]          = { 0.000, 1.000, -1.900};
        };
        class Equipment23 {  //MH-60M exterior kit ???
            animation      = "MH60MMisc_show";
            installedPhase = 1;
            mass           = 200;
            arm[]          = { 0.000, 1.500,  0.000};
        };
        class Equipment24 {  //MAWS tubes
            animation      = "MAWS_Tubes_Show";
            installedPhase = 1;
            mass           = 0;
            arm[]          = { 0.000, 0.000,  0.000};
        };
        class Equipment25 {  //HH-60 radar
            animation      = "HH60GRadar_show";
            installedPhase = 1;
            mass           = 0;
            arm[]          = { 0.000, 0.000,  0.000};
        };
        class Equipment26 {  //HH-60 FLIR
            animation      = "HH60GFlir_show";
            installedPhase = 1;
            mass           = 0;
            arm[]          = { 0.000, 0.000,  0.000};
        };
        class Equipment27 {  //HH-60 flare dispensers ???
            animation      = "HH60Flares_show";
            installedPhase = 1;
            mass           = 5;
            arm[]          = { 0.000, -2.500, -0.400};
        };
    };

    //Internal rounds - counted per round left, all magazines matching each entry.
    numMagazines = 4;
    class Magazines {
        class Mag01 {  //door M134 belts, both doors
            match        = "2000rnd_65x39";
            arm[]        = { 0.000, 2.900, -0.500};
            massPerRound = 0.0254;
        };
        class Mag02 {  //GAU-21
            match        = "600rnd_127x99";
            arm[]        = {-1.100, 1.000, -0.300};
            massPerRound = 0.050;
        };
        class Mag03 {  //DAP 2x M134
            match        = "5000rnd_762x51";
            arm[]        = { 0.000, 2.900, -0.500};
            massPerRound = 0.0254;
        };
        class Mag04 {  //flares, estimate
            match        = "cmflaremagazine";
            arm[]        = { 0.000, -2.500, -0.400};
            massPerRound = 0.25;
        };
    };

    //Pylon stations, one pylon each, at the jettison offsets (uh60_weapons fnc_jettisonAll).
    //Pylons 3 and 4 are MLASS only.
    numStations = 4;
    class Stations {
        class Station01 { arm[] = {-2.000, 2.400, -1.400}; pylons[] = {1}; };
        class Station02 { arm[] = { 2.000, 2.400, -1.400}; pylons[] = {2}; };
        class Station03 { arm[] = {-2.800, 2.300, -1.400}; pylons[] = {3}; };
        class Station04 { arm[] = { 2.800, 2.300, -1.400}; pylons[] = {4}; };
    };

    //Pylon stores, matched against the pylon magazine. First match wins.
    numStores = 6;
    class Stores {
        class Store01 {  //Hellfire, M299 launcher
            match        = "hellfire";
            launcherMass = 65.0;
            massPerRound = 48.0;
            isTank       = 0;
        };
        class Store02 {  //M261 with M229
            match        = "m261_m229";
            launcherMass = 36.3;
            massPerRound = 13.9;
            isTank       = 0;
        };
        class Store03 {  //M261 with APKWS
            match        = "m261_apkws";
            launcherMass = 36.3;
            massPerRound = 15.8;
            isTank       = 0;
        };
        class Store04 {  //M261 with DAGR
            match        = "m261_dagr";
            launcherMass = 36.3;
            massPerRound = 15.8;
            isTank       = 0;
        };
        class Store05 {  //M230 30mm pod, estimate
            match        = "m230_chaingun";
            launcherMass = 120.0;
            massPerRound = 0.34;
            isTank       = 0;
        };
        class Store06 {  //20mm gun pod (vanilla), estimate
            match        = "300rnd_20mm";
            launcherMass = 100.0;
            massPerRound = 0.26;
            isTank       = 0;
        };
    };
