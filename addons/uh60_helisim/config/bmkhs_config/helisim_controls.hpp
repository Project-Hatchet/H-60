//UH-60 cockpit controls. Either pilot works any of them.
//hctInteraction: the Hatchet interaction that moves this control (interaction >> path).
//Its animLabels are in the same order as Positions. See docs/HATCHET.md.

class Controls {
    class Batt1Switch {
        variableName = "batt1Switch";
        hctInteraction[] = {"startUp", "b_batt1"};
        rest         = 0;
        wraps        = 1;
        networked    = 1;
        class Positions {
            class Off { displayName = "No.1 Battery - Off"; value = 0;  };
            class On  { displayName = "No.1 Battery - On";  value = 1;  };
        };
    };
    class Batt2Switch {
        variableName = "batt2Switch";
        hctInteraction[] = {"startUp", "b_batt2"};
        rest         = 0;
        wraps        = 1;
        networked    = 1;
        class Positions {
            class Off { displayName = "No.2 Battery - Off"; value = 0;  };
            class On  { displayName = "No.2 Battery - On";  value = 1;  };
        };
    };

    class ApuBtn {
        variableName = "apuBtn";
        hctInteraction[] = {"startUp", "apucont"};
        rest         = 0;
        wraps        = 1;
        networked    = 1;
        class Positions {
            class Off { displayName = "APU CONT - Off"; value = 0;  };
            class On  { displayName = "APU CONT - On";  value = 1;  };
        };
    };

    //FUEL PUMP - APU BOOST feeds the APU
    class FuelPump {
        variableName = "fuelPump";
        hctInteraction[] = {"startUp", "fuelPump"};
        rest         = 0;
        wraps        = 1;
        networked    = 1;
        class Positions {
            class Off      { displayName = "Fuel Pump - Off";       value = 0;  };
            class ApuBoost { displayName = "Fuel Pump - APU Boost"; value = 1;  };
        };
    };

    class AirSource {
        variableName = "airSource";
        hctInteraction[] = {"startUp", "b_airsce"};
        rest         = 1;
        networked    = 1;
        class Positions {
            class Eng { displayName = "Air Source - ENG"; value = 1;  };
            class Off { displayName = "Air Source - Off"; value = 0;  };
            class Apu { displayName = "Air Source - APU"; value = 2;  };
        };
    };

    //Generator switches
    class Gen1Switch {
        variableName = "gen1Sw";
        hctInteraction[] = {"startUp", "b_gen1"};
        rest         = 0;
        wraps        = 1;
        networked    = 1;
        class Positions {
            class Off { displayName = "No.1 Generator - Off"; value = 0;  };
            class On  { displayName = "No.1 Generator - On";  value = 1;  };
        };
    };
    class Gen2Switch {
        variableName = "gen2Sw";
        hctInteraction[] = {"startUp", "b_gen2"};
        rest         = 0;
        wraps        = 1;
        networked    = 1;
        class Positions {
            class Off { displayName = "No.2 Generator - Off"; value = 0;  };
            class On  { displayName = "No.2 Generator - On";  value = 1;  };
        };
    };
    class ApuGenSwitch {
        variableName = "apuGenSw";
        hctInteraction[] = {"startUp", "b_apugen"};
        rest         = 0;
        wraps        = 1;
        networked    = 1;
        class Positions {
            class Off { displayName = "APU Generator - Off"; value = 0;  };
            class On  { displayName = "APU Generator - On";  value = 1;  };
        };
    };

    class StbyInst {
        variableName = "stbyInst";
        hctInteraction[] = {"startUp", "b_stbyinst"};
        rest         = 0;
        wraps        = 1;
        networked    = 1;
        class Positions {
            class Off { displayName = "Standby Instrument - Off"; value = 0;  };
            class Arm { displayName = "Standby Instrument - Arm"; value = 1;  };
        };
    };

    //Master ignition key, gates both starters
    class Ignition {
        variableName = "ignition";
        hctInteraction[] = {"startUp", "b_ignition"};
        rest         = 0;
        wraps        = 1;
        networked    = 1;
        class Positions {
            class Off { displayName = "Master Ignition - Off"; value = 0;  };
            class On  { displayName = "Master Ignition - On";  value = 1;  };
        };
    };

    //Starter buttons, START springs back
    class Eng1Start {
        variableName  = "eng1StartSw";
        hctInteraction[] = {"startUp", "b_starter1"};
        rest          = 0;
        networked     = 1;
        class Positions {
            class Off   { displayName = "Engine 1 Starter - Off";   value = 0;  };
            class Start { displayName = "Engine 1 Starter - Start"; value = 1; springsBack = 1;  };
        };
    };
    class Eng2Start {
        variableName  = "eng2StartSw";
        hctInteraction[] = {"startUp", "b_starter2"};
        rest          = 0;
        networked     = 1;
        class Positions {
            class Off   { displayName = "Engine 2 Starter - Off";   value = 0;  };
            class Start { displayName = "Engine 2 Starter - Start"; value = 1; springsBack = 1;  };
        };
    };

    class Eng1FuelSys {
        variableName = "eng1FuelSys";
        hctInteraction[] = {"startUp", "b_fuelsys1"};
        rest         = 0;
        networked    = 1;
        class Positions {
            class Off { displayName = "Engine 1 Fuel System - Off"; value = 0;  };
            class Dir { displayName = "Engine 1 Fuel System - DIR"; value = 1;  };
            class Xfd { displayName = "Engine 1 Fuel System - XFD"; value = 2;  };
        };
    };
    class Eng2FuelSys {
        variableName = "eng2FuelSys";
        hctInteraction[] = {"startUp", "b_fuelsys2"};
        rest         = 0;
        networked    = 1;
        class Positions {
            class Off { displayName = "Engine 2 Fuel System - Off"; value = 0;  };
            class Dir { displayName = "Engine 2 Fuel System - DIR"; value = 1;  };
            class Xfd { displayName = "Engine 2 Fuel System - XFD"; value = 2;  };
        };
    };

    class RotorBrake {
        variableName = "rotorBrake";
        hctInteraction[] = {"startUp", "l_rotorbrake"};
        rest         = 0;
        wraps        = 1;
        networked    = 1;
        class Positions {
            class Off   { displayName = "Rotor Brake - Off";   value = 0;  };
            class On    { displayName = "Rotor Brake - On";    value = 1;  };
        };
    };

    //Power control levers, Off/Idle/Fly. FLY blocked by the rotor brake
    class Eng1PowerLever {
        variableName = "eng1PwrLvr";
        hctInteraction[] = {"startUp", "powerContRFM", "b_engpowercont1"};
        rest         = 0;
        networked    = 1;
        class Positions {
            class Off  { displayName = "Engine 1 PCL - Off";  value = 0.0;  };
            class Idle { displayName = "Engine 1 PCL - Idle"; value = 0.25;  };
            class Fly  { displayName = "Engine 1 PCL - Fly";  value = 1.0;
                         inhibitedBy[] = {"bmkhs_rotorBrakeOn"};  };
        };
    };
    class Eng2PowerLever {
        variableName = "eng2PwrLvr";
        hctInteraction[] = {"startUp", "powerContRFM", "b_engpowercont2"};
        rest         = 0;
        networked    = 1;
        class Positions {
            class Off  { displayName = "Engine 2 PCL - Off";  value = 0.0;  };
            class Idle { displayName = "Engine 2 PCL - Idle"; value = 0.25;  };
            class Fly  { displayName = "Engine 2 PCL - Fly";  value = 1.0;
                         inhibitedBy[] = {"bmkhs_rotorBrakeOn"};  };
        };
    };
};
