#ifndef BMKHS_HELISIM_FMOVERRIDE_HPP
#define BMKHS_HELISIM_FMOVERRIDE_HPP

//HeliSim IS the flight model. These zero out Arma's built-in rotor-lib forces so
//the two are not fighting each other. Every HeliSim pack must invoke this macro
//inside its vehicle class; the values are Core's to own, not the pack's to tune.
//
//  class my_heli : Helicopter_Base_F {
//      BMKHS_FM_OVERRIDE
//      #include "my_config.hpp"
//  };
//
//The aircraft-specific values (fuelCapacity, maxSpeed, startDuration, ceiling
//altitudes) stay with the pack - only the force coefficients are fixed here.

#define BMKHS_FM_OVERRIDE \
    liftForceCoef          = 0.00; \
    bodyFrictionCoef       = 0.00; \
    cyclicAsideForceCoef   = 0.00; \
    cyclicForwardForceCoef = 0.00; \
    backRotorForceCoef     = 0.00; \
    fuelconsumptionrate    = 0.0;

#endif
