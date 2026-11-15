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

    //Stabilator incidence, deg TE down negative - by airspeed (kts). One row: no collective term.
    //Placard: 40 at 45, 30 at 60, 20 at 80, 10 at 100, 0 at 150.
    //-----------------------Coll-     30     40     50   57.5     80   82.5    100    115    120    140    150    160    165    180
    heliSimStabTable[] =    {
                         {0.00, -40.00, -40.00, -36.67, -32.50, -20.00, -18.75, -10.00,  -7.00,  -6.00,  -2.00,   0.00,   0.00,   0.00,   0.00}
                        };
