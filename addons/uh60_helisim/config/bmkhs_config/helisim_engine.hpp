/////////////////////////////////////////////////////////////////////////////////////////////
// Engine ////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////
    // Engines - the gas turbine model  /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////
    class Engines {
        class Engine01 {
            name            = "eng01";
            damageRole      = "engines";
            damageRoleIndex = 0;

            engineType  = "turboShaftEngine";   //dispatches to bmkhs_fnc_turboShaftEngine
            designRpm   = 20900;                //100% Np, the shaft reference
            npFly       = 1.00;                 //Np in FLY
            maxFuelFlow = 0.033;                //kg/s per unit of fuel - the gauge boundary
            powerKw     = 1066;                 //max continuous, 100% torque

            maxNg = 1.10;                       //mechanical fly weights
            maxNp = 1.196;                      //electrical trip
            //FUEL SYS lever: OFF, DIR (own tank), XFD (the other tank)
            fuelSelector  = "eng1FuelSys";
            fuelSources[] = {"off", "no1Tank", "no2Tank"};

            //Engine limits
            oilPsiLimits[] = {0.22, 1.20};
            ngMin          = 0.63;
            ngLimits[]     = {{1.05, 12, 10}, {1.06, 0, 20}};
            npLimits[]     = {{1.05, 12, 10}, {1.07, 0, 20}};
            tqLimits[]     = {{1.20, 10, 5}, {1.44, 0, 10}};
            tqLimitsSlow[] = {{1.20, 10, 5}, {1.44, 0, 10}};    //dual engine, below 80 kt - fn_updateLimits
            tqLimitsFast[] = {{1.00, 10, 5}, {1.44, 0, 10}};    //dual engine, above 80 kt
            tgtLimits[]    = {{793, 1800, 1000}, {846, 600, 0}, {879, 0, 0}, {949, 0, 2000}};
            tqLimitsSe[]   = {{1.35, 10, 5}, {1.44, 0, 10}};
            tgtLimitsSe[]  = {{793, 1800, 1000}, {846, 600, 0}, {879, 150, 0}, {903, 12, 0}, {949, 0, 2000}};

            //Compressor - stations 2 -> 3.
            class Compressor {
                pressureRatio = 17.0;    //at Ng 1.0
                massFlow      = 4.6;     //kg/s at Ng 1.0, standard day
                inletDiameter = 0.396;   //m - for inlet losses, not yet modelled
                ramRecovery   = 1.0;

                compDrag      = 3.4;     //as compDrag * ng^2
                compDragFloor = 0.10;

                //Airflow trim by FAT, {FAT, multiplier}
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

                lightOffNg = 0.15;       //fuel introduced
                selfSustNg = 0.52;       //starter cuts out
                idleNg     = 0.679;

                ngLimitMax   = 1.022;
                ngLimitBase  = 1.01436;
                ngLimitSlope = 0.0019091;
            };

            //Combustor - stations 3 -> 4.
            class Combustor {
                fuelLhv             = 43000;    //kJ/kg - JP-8
                combustorEfficiency = 0.99;

                maxTgt      = 879;      //deg C - TGT limiter, twin engine
                maxTgtSe    = 903;      //deg C - TGT limiter, single engine
                startTgt    = 851;       //deg C, start limit
                startMinTgt = 80;        //deg C

                residualHeatGain = 0.003;
            };

            class CompressorTurbine {
                turbineEfficiency = 0.88;
                spoolInertia      = 5.0; //how fast Ng answers a torque change
            };

            class PowerTurbine {
                ptEfficiency  = 0.88;    //isentropic efficiency
                ptInertia     = 0.60;    //the free turbine's own inertia
                ptDrag        = 0.06;    //drag on a released turbine, as ptDrag * np^2
                ptDragFloor   = 0.05;    //finishes the stop - windmilling only
            };

            class Governor {
                fuelIdle = 0.784;        //settles Ng at 0.679
                fuelFly  = 3.136;        //WIDE OPEN - the governor cuts back from here

                startFuelBase = 0.50;

                ffwdGain = 1.00;         //collective anticipation

                leverTravelTime = 8.0;   //s, idle to fly
                loadShareGain   = 8.0;

                //Np governor, {kp, ki, kd, ki_clamp}.
                pid[] = {80.0000, 40.0000, 0.0000, 0.0750};

                gate[] = {};             //what the ECU needs to keep metering fuel
            };

            class Starter {
                type   = "pneumatic";
                torque    = 0.45;               //stalled, on the spool, normalised
                runawayNg = 0.25;               //no torque left - where motoring settles
                gate[] = {{"PNEU", 0.85}, "bmkhs_ignitionOn"};   //bleed air, and the master ignition key
            };
        };
        class Engine02 : Engine01 {
            name            = "eng02";
            damageRoleIndex = 1;
            fuelSelector    = "eng2FuelSys";
            fuelSources[]   = {"off", "no2Tank", "no1Tank"};
        };
    };
