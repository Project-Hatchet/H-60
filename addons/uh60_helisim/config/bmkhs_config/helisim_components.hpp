/////////////////////////////////////////////////////////////////////////////////////////////
// Components ///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

    class Producers {
        class Apu {
            damageRole   = "apu";
            variableName = "apuRPM_pct";
            gate[]       = {"bmkhs_apuBtnOn", {"BATT", 0.25}, "bmkhs_apuFuelAvail",
                            "bmkhs_fuelPumpOn", "bmkhs_accHydPsiStartOk"};
            nominal      = 1.0;
            rampSeconds  = 5;             //spool to operating RPM
            stateName    = "apuOn";       //running once it is up to speed
            stateAbove   = 0.85;
            networked    = 1;
            fuelSource   = "no1Tank";     //tank variableName it draws from
            fuelFlow     = 175;           //lb/h while running
            output       = "APU_DRIVE";
        };
        class ApuBleed {
            variableName = "apuBleed";
            output       = "PNEU";
            drivenBy[]   = {"APU_DRIVE", 0.85};   //up to speed before it has air to give
            gate[]       = {"vtx_uh60_helisim_airSrcApu"};
            nominal      = 1.0;
            rampSeconds  = 0;
        };
        class EngineBleed {
            variableName = "engBleed";
            output       = "PNEU";
            gate[]       = {"bmkhs_engBleedAvail", "vtx_uh60_helisim_airSrcEng"};
            nominal      = 1.0;
            rampSeconds  = 0;
        };
        class Transmission {
            damageRole   = "transmission";
            variableName = "xmsnDrive";
            drivenBy[]   = {"Nr"};        //any rotation; the pumps set their own floor
            rampSeconds  = 0;             //no nominal: it carries whatever Nr is doing
            torqueFrom   = "bmkhs_engPctTq";
            torqueSum    = 1;
            tqLimitsFrom = "tqLimits";      //twin: the engines' limits, times their count
            tqLimitsSeFrom = "tqLimitsSe";  //single engine: one engine carries it all
            jittersTorque = 1;
            breaksOnFailure[] = {"mainRotor", "tailRotor", "bmkhs_engineOverspeed"};   //unloaded, the engines overspeed
            class Outputs {
                class Accessories { circuit = "ACCESSORY_DRIVE"; };
                class TailDrive   { circuit = "TAIL_DRIVE"; };
            };
        };

        class No1Pump {
            variableName = "priHydPsi";
            output       = "PRI_HYD";
            drivenBy[]   = {"ACCESSORY_DRIVE", 0.45};   //below this it loses drive
            requires     = "bmkhs_priLevel_pct";
            requiresAbove = 0.1;          //fraction - below this it loses prime
            nominal      = 3000;          //psi
            increment    = 10;            //gauges move in tens
            networked    = 1;             //cautions read these in the crew station
            rampSeconds  = 0.5;           //s
        };
        class No2Pump {
            variableName = "utilHydPsi";
            output       = "UTIL_HYD";
            drivenBy[]   = {"ACCESSORY_DRIVE", 0.45};
            requires     = "bmkhs_utilLevel_pct";
            requiresAbove = 0.1;
            nominal      = 3000;
            increment    = 10;
            networked    = 1;
            rampSeconds  = 0.5;
        };

        class Gen1 {
            variableName = "gen1";
            output       = "AC";
            drivenBy[]   = {"ACCESSORY_DRIVE", 0.85};
            gate[]       = {"bmkhs_gen1SwOn"};
            nominal      = 1;             //on/off, not volts
            rampSeconds  = 0;             //a contactor closes, it does not spool
            networked    = 1;
        };
        class Gen2 {
            variableName = "gen2";
            output       = "AC";
            drivenBy[]   = {"ACCESSORY_DRIVE", 0.85};
            gate[]       = {"bmkhs_gen2SwOn"};
            nominal      = 1;
            rampSeconds  = 0;
            networked    = 1;
        };
        class ApuGen {
            variableName = "apuGen";
            output       = "AC";
            drivenBy[]   = {"APU_DRIVE", 0.85};
            gate[]       = {"bmkhs_apuGenSwOn"};
            nominal      = 1;
            rampSeconds  = 0;
            networked    = 1;
        };
    };

    class Converters {
        class IntermediateGearbox {
            damageRole   = "intermediateGearbox";
            variableName = "igb";
            input[]      = {"TAIL_DRIVE"};
            output       = "TAIL_DRIVE_IGB";
        };
        class TailRotorGearbox {
            damageRole   = "tailRotorGearbox";
            variableName = "tgb";
            input[]      = {"TAIL_DRIVE_IGB"};
            output       = "TAIL_ROTOR_DRIVE";
        };
        class Converter {
            variableName = "conv";
            input[]      = {"AC"};        //any AC at all
            output       = "DC";
            nominal      = 1;
        };
    };

    class Storage {
        class PriReservoir {
            variableName    = "priLevel_pct";
            nominal         = 1.0;         //fraction
            networked       = 1;
        };
        class UtilReservoir {
            variableName    = "utilLevel_pct";
            output          = "UTIL_HYD_LEVEL";   //so a consumer can read what is left
            nominal         = 1.0;
            networked       = 1;
        };

        class Battery1 {
            damageRole      = "battery1";
            variableName    = "batt1Power_pct";
            output          = "BATT";
            rechargedBy[]   = {"AC"};
            gate[]          = {"bmkhs_batt1SwitchOn"};
            nominal         = 1.0;        //published as a fraction
            stopBelow       = 0.25;       //too flat to hold a bus up
            startRecharge   = 60;         //sec off a live bus
            emerDischarge   = 900;        //15 min on the battery alone
            networked       = 1;
        };
        class Battery2 {
            damageRole      = "battery2";
            variableName    = "batt2Power_pct";
            output          = "BATT";
            rechargedBy[]   = {"AC"};
            gate[]          = {"bmkhs_batt2SwitchOn"};
            nominal         = 1.0;
            stopBelow       = 0.25;
            startRecharge   = 60;
            emerDischarge   = 900;
            networked       = 1;
        };

        class Accumulator {
            variableName    = "accHydPsi";
            output          = "UTIL_HYD";
            networked       = 1;
            rechargedBy[]   = {"ACCESSORY_DRIVE", 0.45};  //same drive the pumps need
            gate[]          = {"bmkhs_emerHydOn"};
            startedBy       = "bmkhs_apuBtnOn";
            nominal         = 3000;       //psi at full charge
            startAbove      = 2600;       //psi needed to turn the APU over at all
            startRecharge   = 1.0;        //sec to refill, once the pumps are turning
            stopBelow       = 1650;       //psi, nitrogen precharge
            emerDischarge   = 90;         //sec of emergency pressure
        };
    };

    class Circuits {
        class AcBus {
            variableName = "acBusOn";
            circuit      = "AC";
            minValue     = 1;
            networked    = 1;
        };
        class DcBus {
            variableName = "dcBusOn";
            circuit      = "DC";
            minValue     = 1;
            networked    = 1;
        };
        class BattBus {
            variableName = "battBusOn";
            circuit      = "BATT";
            minValue     = 0.25;
            networked    = 1;
        };
        class Pneumatics {
            variableName = "pneuAvail";
            circuit      = "PNEU";
            minValue     = 0.85;
            networked    = 1;
        };
    };

    class Consumers {
        class FlightControls {
            variableName = "fltCtrlsSupplied";
            suppliedBy[] = {{"PRI_HYD", 1260}, {"UTIL_HYD", 1260}};   //psi
        };
        class TailRotor {
            variableName = "tailRtrSupplied";
            suppliedBy[] = {{"PRI_HYD", 1260}, {"UTIL_HYD_LEVEL", 0.1}};
        };
        class TailRotorDrive {
            variableName = "tailRtrDriven";
            suppliedBy[] = {{"TAIL_ROTOR_DRIVE", 0.01}};
        };
    };
