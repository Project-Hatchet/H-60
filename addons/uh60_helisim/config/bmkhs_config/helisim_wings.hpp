//UH-60 lifting surfaces. Converted from the pre-1.1 bmkhs_uh60_config.hpp stabilator and
//vertical fin with Core's own old span/chord/pos geometry, so each quad sits where the old
//surface did. NOT generated from fm.p3d - Core's generator replaces this file (and resets it).

    class Wings {
        class Wing01 {
            name           = "stabilator";
            facing         = "up";
            numElements    = 5;
            airfoil        = "NACA 0012";
            chordLinePos   = 0.25;
            panels[] =
            {
              {{ -2.090, -7.041, -0.084},{  2.090, -7.041, -0.084},{  2.090, -8.141, -0.084},{ -2.090, -8.141, -0.084}}
            };
        };
        class Wing02 {
            name           = "verticalFin";
            facing         = "right";
            numElements    = 5;
            airfoil        = "NACA 4412";
            chordLinePos   = 0.25;
            panels[] =
            {
              {{  0.031, -6.101, -0.400},{ -0.063, -7.898,  1.600},{ -0.110, -8.797,  1.600},{ -0.031, -7.299, -0.400}}
            };
        };
    };

    //Stabilator incidence, deg. Rows are collective 0 to 1; columns are Core's fixed airspeeds.
    //Resampled from the old 30-200 kt table onto these points.
    //-----------------------Coll-     30     40     50   57.5     80   82.5    100    115    120    140    150    160    165    180
    heliSimStabTable[] =    {
                         {0.00, -25.00, -15.50,  -6.00,  -4.88,  -3.00,  -3.00,  -3.00,  -3.00,  -3.00,  -3.00,  -3.00,  -3.00,  -3.00,  -3.00}
                        ,{1.00, -25.00, -32.50, -23.00, -17.38,  -8.80,  -9.03, -10.50, -14.45, -15.80, -21.00, -14.50, -14.50, -14.50, -14.50}
                        };
