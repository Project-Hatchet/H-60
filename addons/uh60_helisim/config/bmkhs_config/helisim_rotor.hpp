/////////////////////////////////////////////////////////////////////////////////////////////
// Rotors - Blade Element Theory ////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//Per-rotor arrays, index 0 = main, 1 = tail. Core reads numRotors and loops.
//Model shaping - inflow, flap dynamics, damping - stays in Core.
//
//UH-60: geometry, blades and pitch ranges from the pre-1.1 UH-60 config. Root cutout is the old
//rotorBladeRootCutoutPct of the radius; blade length is radius minus that cutout. Flap time
//constants and delta-3 are the AH-64D's - nothing UH-60 specific existed for them.

    numRotors            = 2;
    rotorType[]          = {0,      1};          //0 = main, 1 = tail
    rotorDirection[]     = {0,      0};          //0 = ccw, 1 = cw
    rotorNumBlades[]     = {4,      4};
    rotorNumElements[]   = {4.0,    4.0};
    rotorMastLength[]    = {0.00,   0.00};    //m - the old config put the hub at the pivot
    rotorGearRatio[]     = {80.99,  17.57};   //258 / 1190 rpm main / tail at 20900 Np

    //Hub position and disc orientation in model space.
    rotorPivot[]         = {
                            { 0.00,  1.81,  1.50}     //main hub, m
                          , { 0.35, -7.99,  1.77}     //tail hub, m
                          };
    rotorRotation[]      = {
                            {-3.0,  0.0, 0.0}         //main disc, deg - mast tilted forward 3 deg
                          , { 0.0, 70.0, 0.0}         //tail disc, deg - canted 20 deg
                          };

    //Flap response time constants, {longitudinal, lateral} per rotor.
    rotorFlapTimeConst[] = {
                            {2.0, 3.0}                //main
                          , {0.5, 0.5}                //tail
                          };
    rotorAirfoil[]       = {"SC1095", "SC1095"};  //section name, see helisim_airfoils.hpp
    rotorBladeCutout[]   = {1.145,  0.168};   //m, root cutout - 14% / 10% of radius
    rotorBladeLength[]   = {7.033,  1.508};   //m
    rotorBladeChord[]    = {0.527,  0.247};   //m
    rotorBladeTwist[]    = {-16,    -17};     //deg
    rotorBladeMass[]     = {107.226, 7.018};  //kg
    rotorDelta3[]        = {0.5,    0.5};     //pitch-flap coupling

    //Blade pitch ranges - min / mid / max, deg
    rotorPitchMin[]      = {-12.3,  0};
    rotorPitchMid[]      = {0,      0};
    rotorPitchMax[]      = {16.5,   0};
    rotorRollMin[]       = {-8.0,   0};
    rotorRollMid[]       = {0,      0};
    rotorRollMax[]       = {8.0,    0};
    rotorCollMin[]       = {9.9,    -15.6};
    rotorCollMid[]       = {0,      0};
    rotorCollMax[]       = {25.9,   23.0};

    //Model bindings - the aircraft must provide these selections
    rotorAnimSource[]    = {"rotorH",       "rotorV"};
    rotorHitPoint[]      = {"hithrotor",    "hitvrotor"};
