/////////////////////////////////////////////////////////////////////////////////////////////
// Engine ////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////
    // Engines - the gas turbine model  /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////
    //UH-60: two T700s on Core's built-in T700-701C compressor map. Values carried from the
    //AH-64D pack (same engine, same 20900 rpm Np and 481 Nm torque reference as the pre-1.1
    //UH-60 config) - check the limits against the UH-60 -10 before relying on them.
    //numEngines is declared at the top of bmkhs_uh60_config.hpp, beside useSystems - it is
    //the airframe's count, not an engine's property. No hitpoints here, so it IS the count.
    class Engines {
        class Engine01 {
            name            = "eng01";
            damageRole      = "engines";
            damageRoleIndex = 0;

            //Whole-assembly properties - not owned by any one section.
            engineType  = "turboShaftEngine";   //dispatches to bmkhs_fnc_turboShaftEngine
            designRpm   = 20900;                //100% Np, the shaft reference
            npFly       = 1.00;                 //governed Np in FLY, as a fraction of designRpm
            maxFuelFlow = 0.033;                //kg/s per unit of fuel - the gauge boundary
            powerKw     = 1066;                 //maximum continuous - the torque reference, refTq

            //Hard shutdowns - both CUT FUEL rather than restricting it.
            maxNg = 1.10;                       //mechanical fly weights
            maxNp = 1.196;                      //electrical trip

            //Engine limits
            oilPsiLimits[] = {0.23, 1.20};
            ngMin          = 0.63;
            ngLimits[]     = {{1.022, 12, 10}, {1.051, 0, 20}};
            npLimits[]     = {{1.05, 12, 10}, {1.21, 0, 20}};
            tqLimits[]     = {{1.00, 6, 5}, {1.15, 0, 10}};
            tgtLimits[]    = {{810, 1800, 1000}, {870, 600, 0}, {878, 0, 0}, {949, 0, 2000}};
            tqLimitsSe[]   = {{1.10, 150, 10}, {1.22, 6, 2}, {1.25, 0, 4}};
            tgtLimitsSe[]  = {{810, 1800, 1000}, {870, 600, 0}, {878, 150, 0}, {896, 12, 0}, {949, 0, 2000}};

            //Compressor - stations 2 -> 3.
            class Compressor {
                pressureRatio = 17.0;    //at Ng 1.0
                massFlow      = 4.6;     //kg/s at Ng 1.0, standard day
                inletDiameter = 0.396;   //m - for inlet losses, not yet modelled
                ramRecovery   = 1.0;     //share of the ram pressure rise the inlet keeps

                //Spooling down only - an unfired compressor is pure load, and that stops it.
                compDrag      = 3.4;     //as compDrag * ng^2
                compDragFloor = 0.10;    //finishes the stop - ng^2 alone only asymptotes

                //Airflow trim by FAT, {FAT, multiplier} - dials the engine onto its charts.
                airflowTable[] = {
                     {-40, 0.9430}
                    ,{-30, 0.9486}
                    ,{-20, 0.9456}
                    ,{-10, 0.9482}
                    ,{  0, 0.9156}
                    ,{ 10, 0.9543}
                    ,{ 15, 1.0000}
                    ,{ 20, 1.0567}
                    ,{ 30, 1.1648}
                    ,{ 40, 1.2354}
                };

                //Start thresholds - discrete events the model branches on.
                lightOffNg = 0.15;       //fuel introduced
                selfSustNg = 0.52;       //starter cuts out
                //Where the start fuel ramp reaches full and residual heat has faded. Raise it
                //to hold fuel lean longer and peak cooler.
                idleNg     = 0.679;

                //Ng limiter - ngLimitMax min (ngLimitBase + ngLimitSlope * FAT).
                ngLimitMax   = 1.022;
                ngLimitBase  = 1.01436;
                ngLimitSlope = 0.0019091;
            };

            //Combustor - stations 3 -> 4.
            class Combustor {
                fuelLhv             = 43000;    //kJ/kg - JP-8
                combustorEfficiency = 0.99;

                maxTgt      = 867;      //deg C - TGT limiter, twin engine
                maxTgtSe    = 896;      //deg C - TGT limiter, single engine
                startTgt    = 851;       //deg C - the transient START limit, not the peak
                startMinTgt = 80;        //deg C - below this before the power lever is moved

                //How violently an un-purged engine runs away, latched from TGT at the lever.
                residualHeatGain = 0.003;
            };

            //Compressor turbine - stations 4 -> 4.5. Drives the compressor, steps Ng; TGT is read here.
            class CompressorTurbine {
                turbineEfficiency = 0.88;
                spoolInertia      = 5.0; //how fast Ng answers a torque change
            };

            //The free turbine - stations 4.5 -> 5. Np is state with its own torque balance.
            class PowerTurbine {
                ptEfficiency  = 0.88;    //isentropic efficiency
                ptInertia     = 0.60;    //the free turbine's own inertia
                ptDrag        = 0.06;    //drag on a released turbine, as ptDrag * np^2
                ptDragFloor   = 0.05;    //finishes the stop - windmilling only
            };

            //The ECU - what it schedules, and the ceilings it will not pass.
            class Governor {
                //Minimum fuel the power lever schedules.
                fuelIdle = 0.784;        //settles Ng at 0.679
                fuelFly  = 3.136;        //WIDE OPEN - the governor cuts back from here

                //Fuel metered at light-off as a fraction of idle fuel. Sets the start PEAK.
                startFuelBase = 0.50;

                ffwdGain = 1.00;         //collective anticipation - the load demand spindle

                leverTravelTime = 8.0;   //seconds, idle to fly - the fuel ramp, Np and the lever animation
                loadShareGain   = 8.0;   //how hard an engine below its matched partners trims up to them

                //Np governor, {kp, ki, kd, ki_clamp}.
                pid[] = {80.0000, 40.0000, 0.0000, 0.0750};

                gate[] = {};             //nothing gates it - no systems modelled yet
            };

            //Air turbine or electric, and what it needs available before the spool turns.
            class Starter {
                type   = "pneumatic";
                torque    = 0.45;               //stalled, on the spool, normalised
                runawayNg = 0.25;               //no torque left - where motoring settles
                gate[] = {};                    //no systems modelled yet - nothing gates it
            };
        };
        class Engine02 : Engine01 {
            name            = "eng02";
            damageRoleIndex = 1;
        };
    };
