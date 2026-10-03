/////////////////////////////////////////////////////////////////////////////////////////////
// Flight Controls //////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
    //UH-60: the old config's inputLagValue (0.95); FMC gains are the AH-64D's - retune for the UH-60.
    inputLagValue     = 0.95;
    //Casual mode auto pitch target
    autoAttLevelPitch = -5.0;     //deg
    autoAttRollLimit  = 30.0;     //deg, bank commanded by the roll key

/////////////////////////////////////////////////////////////////////////////////////////////
// FMC Gains        /////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//PID gains, {kp, ki, kd, ki_clamp}. These are the tuning that defines how the
//aircraft handles - one set does not carry across airframes.

    //Position / velocity hold
    pidRoll[]           = {0.0550, 0.0070, 0.0900, 0.0070};
    pidPitch[]          = {0.1500, 0.0070, 0.1200, 0.0070};
    //Attitude hold
    pidRollAtt[]        = {0.0400, 0.0015, 0.0180, 0.0015};
    pidPitchAtt[]       = {0.0925, 0.0025, 0.0450, 0.0025};
    //Altitude hold
    pidRadAlt[]         = {0.0500, 0.0001, 0.0050, 0.0001};
    pidBarAlt[]         = {0.0010, 0.0000, 0.0008, 0.0000};
    //Heading hold
    pidHdgHold[]        = {0.0750, 0.0200, 0.0050, 0.0200};
    //Turn coordination. Error is lateral g and the output is clamped to +-0.1 in
    //fn_fmcHeadingHold, so size these against that rather than the +-1 gauge.
    pidTrnCoord[]       = {0.2500, 0.0600, 0.3000, 0.1500};
    //SAS
    pidSasPitch[]       = {0.1500, 0.0000, 0.0020, 0.0000};
    pidSasRoll[]        = {0.1000, 0.0000, 0.0020, 0.0000};
    pidSasYaw[]         = {0.3000, 0.0500, 0.0250, 0.0500};
    //Auto-pedal
    pidAutoAttPitch[]   = {0.0925, 0.0025, 0.0220, 0.0025};
    pidAutoAttRoll[]    = {0.0400, 0.0015, 0.0250, 0.0015};
    pidAutoPedalHdg[]   = {0.1000, 0.0050, 0.0500, 30.000};
    pidAutoPedalNtt[]   = {0.0300, 0.0080, 0.0100, 18.750};
    pidAutoPedalAero[]  = {0.6000, 0.5000, 0.4000, 0.2000};
