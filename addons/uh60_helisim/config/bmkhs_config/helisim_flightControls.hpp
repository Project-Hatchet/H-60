/////////////////////////////////////////////////////////////////////////////////////////////
// Flight Controls //////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
    inputLagValue     = 0.95;
    //Casual mode auto pitch target
    autoAttLevelPitch = -3.0;     //deg
    autoAttRollLimit  = 30.0;     //deg, bank commanded by the roll key

/////////////////////////////////////////////////////////////////////////////////////////////
// Control Mixing ///////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
    //Each mix adds control travel to one rotor axis, from one control's position.
    //  source     - "collective" (0..1) or "pedal" (-1..1, + right)
    //  target     - "pitch" (+ fwd), "roll" (+ left) or "yaw" (+ right pedal)
    //  table[]    - {{source position, added travel}, ...}
    //  gate[]     - optional, all must hold - same form as component gates. No gate:
    //               mechanical, always applied.
    //  airspeed[] - optional, {{knots, scale}, ...}
    //From the rig (python/dev/forces.py) at 80 pct of full compensation, so the pilot still
    //holds left pedal with power. YawToPitch reads the tail rotor command (pedal plus the
    //collective yaw mixes). CollectiveToPitch is the rig's leftover - Core has no stabilator downwash.
    //CollectiveAirspeedToYaw is not rig-derived yet.
    class ControlMixing {
        //Mixing unit. Fwd cyclic as collective increases. On the aircraft it cancels rotor
        //downwash on the stabilator, which HeliSim does not model - so this is only the rig's
        //leftover main rotor / CG pitch at 80 pct.
        class CollectiveToPitch {
            source  = "collective";
            target  = "pitch";
            table[] = {
                { 0.0,  0.000},
                { 0.1, -0.001},
                { 0.2, -0.001},
                { 0.3, -0.002},
                { 0.4, -0.003},
                { 0.5, -0.003},
                { 0.6, -0.004},
                { 0.7, -0.004},
                { 0.8, -0.005},
                { 0.9, -0.004},
                { 1.0,  0.001}
            };
        };
        //Mixing unit. More tail rotor pitch (left pedal) as collective increases - torque
        class CollectiveToYaw {
            source  = "collective";
            target  = "yaw";
            table[] = {
                { 0.0,  0.000},
                { 0.1, -0.007},
                { 0.2, -0.014},
                { 0.3, -0.021},
                { 0.4, -0.028},
                { 0.5, -0.035},
                { 0.6, -0.042},
                { 0.7, -0.052},
                { 0.8, -0.062},
                { 0.9, -0.092},
                { 1.0, -0.194}
            };
        };
        //Mixing unit. Left cyclic as collective increases - tail rotor rolling moment and
        //translating tendency
        class CollectiveToRoll {
            source  = "collective";
            target  = "roll";
            table[] = {
                { 0.0,  0.000},
                { 0.1,  0.001},
                { 0.2,  0.001},
                { 0.3,  0.002},
                { 0.4,  0.002},
                { 0.5,  0.002},
                { 0.6,  0.003},
                { 0.7,  0.003},
                { 0.8,  0.002},
                { 0.9, -0.001},
                { 1.0, -0.019}
            };
        };
        //Mixing unit. Aft cyclic as tail rotor pitch increases (left pedal) - canted tail
        //rotor lift
        class YawToPitch {
            source  = "pedal";
            target  = "pitch";
            table[] = {
                {-1.0, -0.173},
                {-0.8, -0.157},
                {-0.6, -0.126},
                {-0.4, -0.084},
                {-0.2, -0.037},
                { 0.0,  0.000},
                { 0.2,  0.037},
                { 0.4,  0.069},
                { 0.6,  0.093},
                { 0.8,  0.109},
                { 1.0,  0.120}
            };
        };
        //Left cyclic as tail rotor pitch increases (left pedal) - tail rotor side thrust above the CG
        class YawToRoll {
            source  = "pedal";
            target  = "roll";
            table[] = {
                {-1.0,  0.251},
                {-0.8,  0.228},
                {-0.6,  0.183},
                {-0.4,  0.121},
                {-0.2,  0.054},
                { 0.0,  0.000},
                { 0.2, -0.055},
                { 0.4, -0.102},
                { 0.6, -0.137},
                { 0.8, -0.161},
                { 1.0, -0.177}
            };
        };
        //No.2 FCC through the yaw trim actuator, on top of collective to yaw. Full mixing
        //0 to 40 kt, decreasing to none at 100 kt. Needs the FMC yaw channel and DC power.
        class CollectiveAirspeedToYaw {
            source     = "collective";
            target     = "yaw";
            table[]    = {
                {0.0, 0.000},
                {1.0, 0.000}
            };
            airspeed[] = {
                {  0, 1.0},
                { 40, 1.0},
                {100, 0.0}
            };
            gate[]     = {"bmkhs_fmcYawOn", "bmkhs_dcBusOn"};
        };
    };

/////////////////////////////////////////////////////////////////////////////////////////////
// FMC              /////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//Field reference: \bmkhs_helisim\fmc.hpp. PID gains {kp, ki, kd, ki_clamp}, the AH-64D's - retune.
//Every feature works through the pilot-assist servos on the No. 2 (utility) system, and the
//computer needs DC.
    class FMC {
        class Sas {
            gate[]      = {{"UTIL_HYD", 1260}, "bmkhs_dcBusOn"};
            authority[] = {0.2, 0.1, 0.1};   //pitch, roll, yaw
            pitch[]     = {0.1500, 0.0000, 0.0020, 0.0000};
            roll[]      = {0.1000, 0.0000, 0.0020, 0.0000};
            yaw[]       = {0.3000, 0.0500, 0.0250, 0.0500};
        };
        class AttitudeHold {
            gate[]      = {{"UTIL_HYD", 1260}, "bmkhs_dcBusOn"};
            posBelowKts = 5;
            velBelowKts = 40;               //accelerating
            attBelowKts = 30;               //decelerating
            authority   = 0.1;
            posPitch[]  = {0.0900, 0.0070, 0.0720, 0.0070};   //0.6x - it went unstable climbing at high power
            posRoll[]   = {0.0330, 0.0070, 0.0540, 0.0070};
            attPitch[]  = {0.0925, 0.0025, 0.0450, 0.0025};
            attRoll[]   = {0.0400, 0.0015, 0.0180, 0.0015};
        };
        class AltitudeHold {
            gate[]      = {{"UTIL_HYD", 1260}, "bmkhs_dcBusOn"};
            radBelowFt  = 1428;
            radBelowKts = 40;
            engageFpm   = 200;
            collBand    = 0.05;
            dropAboveTq = 0.98;
            rad[]       = {0.0500, 0.0001, 0.0050, 0.0001};
            bar[]       = {0.0010, 0.0000, 0.0008, 0.0000};
        };
        class HeadingHold {
            gate[]      = {{"UTIL_HYD", 1260}, "bmkhs_dcBusOn"};
            hdgBelowKts = 5;
            blendToKts  = 40;
            breakout[]  = {0.05, 0.10, 0.20};   //pedal, by attitude hold sub-mode: pos / vel / att
            authority   = 0.1;
            hdg[]       = {0.0750, 0.0200, 0.0050, 0.0200};
            trn[]       = {0.2500, 0.0600, 0.3000, 1.0000};   //integral holds the pedal that centres the ball
        };
        //The FD panel: RALT, ALTP, ALT, IAS, HDG, FMS (nav) and HVR. Gains are a first cut - tune.
        class FlightDirector {
            gate[]        = {{"UTIL_HYD", 1260}, "bmkhs_dcBusOn"};
            modes[]       = {"ralt", "alt", "altp", "ias", "hdg", "nav", "hvr"};
            class Targets {               //{min, max, step, wraps}
                ralt[] = {0, 1000, 10};   //ft
                alt[]  = {0, 20000, 100}; //ft
                altp[] = {0, 20000, 100}; //ft
                ias[]  = {0, 200, 10};    //kt
                hdg[]  = {0, 360, 1, 1};  //deg
            };
            altGain       = 10;
            vsMaxFpm      = 1000;
            vsAccelFpm    = 200;
            captureFt     = 50;
            iasAccelKts   = 2;
            maxPitchDeg   = 15;
            pitchRateDps  = 3;
            maxBankDeg    = 30;
            bankPerDeg    = 1;
            rollRateDps   = 5;
            bankAboveKts  = 20;
            hvrDecelKts   = 2;
            collAuthority = 1.0;            //full travel - continuous torque is the limit
            cycAuthority  = 0.8;
            pedAuthority  = 0.1;
            vs[]          = {0.0394, 0.0197,  0.0000, 50.8};    //m/s; integral reaches full collective
            ias[]         = {0.9720, 0.0972,  0.0000, 51.4};    //m/s to deg
            pitch[]       = {0.0925, 0.0025,  0.0450, 0.0025};
            roll[]        = {0.0400, 0.0015,  0.0180, 20.0};    //integral trims out a standing bank
            yaw[]         = {0.0750, 0.0200,  0.0050, 0.0200};
            hvrPitch[]    = {0.0900, 0.0070,  0.0720, 0.0070};  //the attitude hold's pos / vel gains
            hvrRoll[]     = {0.0330, 0.0070,  0.0540, 0.0070};
        };
    };

    //Auto-pedal
    pidAutoAttPitch[]   = {0.0925, 0.0025, 0.0220, 0.0025};
    pidAutoAttRoll[]    = {0.0400, 0.0015, 0.0250, 0.0015};
    pidAutoPedalHdg[]   = {0.1000, 0.0050, 0.0500, 30.000};
    pidAutoPedalNtt[]   = {0.0300, 0.0080, 0.0100, 18.750};
    pidAutoPedalAero[]  = {0.6000, 0.5000, 0.4000, 0.2000};
