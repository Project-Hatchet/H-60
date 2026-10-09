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

    //Stabilator incidence, deg - collective rows by airspeed (kts). The AH-64D's schedule, scaled
    //about its -25 deg low-speed end so 0.64 / 140 kt reads -3: the cruise attitude (the mast
    //tilt), so the stabilator is parallel to the airflow there (Core's rig).
    //-----------------------Coll-     30     40     50   57.5     80   82.5    100    115    120    140    150    160    165    180
    heliSimStabTable[] =    {
                         {0.00, -25.00, -14.09,  -3.18,   0.26,   0.26,   0.26,   0.26,   0.26,   0.26,   0.26,   0.26,   0.26,   0.26,   0.26}
                        ,{0.25, -25.00, -16.39,  -7.78,  -3.18,  -2.84,  -0.08,   0.26,   0.26,   0.26,   0.26,   0.26,   0.26,   0.26,   0.26}
                        ,{0.50, -25.00, -17.31,  -9.61,  -8.48,  -8.10,  -5.06,  -4.68,  -2.01,   0.26,   0.26,   0.26,   0.26,   0.26,   0.26}
                        ,{0.75, -25.00, -21.25, -15.76, -14.67, -14.30, -11.39, -11.03,  -8.48,  -6.30,  -5.56,  -2.66,  -1.20,   0.26,   0.26}
                        ,{1.00, -25.00, -26.72, -28.44, -22.70, -22.31, -19.22, -18.83, -16.12, -13.79, -13.02,  -9.92,  -8.37,  -6.82,  -6.06}
                        };
