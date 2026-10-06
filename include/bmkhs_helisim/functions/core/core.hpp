#ifndef BMKHS_HELISIM_CORE_HPP
#define BMKHS_HELISIM_CORE_HPP

#define STABILATOR_MODE_ALWAYSENABLED   2
#define STABILATOR_MODE_JOYSTICKONLY    1
#define STABILATOR_MODE_ALWAYSDISABLED  0

#define HOTAS                   0
#define KEYBOARD                1

//Seconds for the rotor brake to stop a rotor turning at 100%, and the Nr at or above which
//the system refuses to apply it at all.
#define ROTOR_BRAKE_STOP_SEC    45
#define ROTOR_BRAKE_MAX_NR      0.5

#define ISA_STD                 0
#define EUROPE_SUMMER           1
#define EUROPE_WINTER           2
#define MIDDLE_EAST             3
#define CENTRAL_ASIA_SUMMER     4
#define CENTRAL_ASIA_WINTER     5
#define ASIA                    6

#define CASUAL					0
#define REALISTIC				2

#define MIN_TIME_BETWEEN_UPDATES 0.3

#define EPSILON                 0.000001
#define MIN_THRUST              1
#define FEET_TO_METERS          0.3048
#define METERS_TO_FEET          3.28084
#define KG_TO_LBS               2.20462
#define MPS_TO_KNOTS            1.94384
#define MPS_TO_FPM              196.85
#define FPM_TO_MPS              0.00508
#define KNOTS_TO_MPS            0.51444

#define GRAVITY                 9.806
#define MOLAR_MASS_OF_AIR       0.0289644
#define UNIVERSAL_GAS_CONSTANT  8.31432
#define DEG_C_TO_KELVIN         273.15
#define SEA_LEVEL_PRESSURE      29.92
#define STANDARD_TEMP           15
#define IN_MG_TO_HPA            33.8639

#define VEL_ETL                 12.347
#define VEL_VBE                 38.583  //75 kts
#define VEL_VNE                 128.611 //250 kts
#define VEL_VRS                 24.384
#define ISA_STD_DAY_AIR_DENSITY 1.225

#define VRS_SCALAR_EXPONENT     0.3

//Vortex ring state warning bands. Metres per second of descent, because the flight model
//works in metres - the feet per minute are what they were specified in. VEL_VRS is the
//fourth band, fully developed.
#define VRS_BAND_ENTERING       10.160  //2000 fpm
#define VRS_BAND_DEVELOPING     14.897  //2933 fpm
#define VRS_BAND_IMMINENT       19.634  //3867 fpm
//Advance ratio ceiling - the 4.65*mu^2 profile growth diverges past here
#define MU_MAX                  0.35

//FMC hold switch speeds, breakouts and authorities are the aircraft's - class FMC, fmc.hpp

#define CENTER_TRIM_VAL               0.05
#define BETA_G_TAU                    0.60

//Keyboard auto-attitude (CASUAL only - gated purely on bmkhs_helisimRealismSetting; it is
//intrinsic to the casual flight model, not an independently switchable option).
//The keyboard has no proportional axis - a key is fully down or fully up - so a keyboard
//player cannot command an ATTITUDE, only a direction. These assists convert that on/off
//key into a RATE command that integrates a moving attitude TARGET, which a PID then flies
//the airframe to. Holding a key sweeps the target smoothly; releasing simply stops the
//sweep. There is no tap-vs-hold fork and no capture EVENT anywhere - the target is a
//continuous function of key state, so the resulting force-trim is continuous too (the old
//0.15s tap/hold branch snapped the target on release, which is what made it feel notchy).
//
//PITCH and ROLL are deliberately ASYMMETRIC because the two axes mean different things:
//  PITCH target PERSISTS on release. In this force model pitch attitude IS airspeed
//    selection - progressive forward cyclic is the only path to the full speed envelope
//    (NOE 20-40kt, max endurance, max range, Vne). Decaying pitch to level would peg a
//    keyboard player at the single airspeed that wings-level happens to trim to (~90kt).
//  ROLL target DECAYS to wings-level on release. A standing bank carries no information
//    the player wants to keep, and the airframe has a persistent right-roll trim offset
//    (CCW rotor + thrusting tail) that a rate-damping SAS cannot null - SAS has a ZERO
//    setpoint on RATE, so once the rate bleeds off it holds whatever bank it is in. The
//    decay-to-level target plus the PID integrator is what actually removes that offset.
#define AUTO_ATT_PITCH_RATE           6.0     //deg/s of target sweep at full pitch key
#define AUTO_ATT_ROLL_RATE            25.0    //deg/s of target sweep at full roll key
#define AUTO_ATT_ROLL_LEVEL_RATE      20.0    //deg/s the roll target decays back to level
#define AUTO_ATT_KEY_DEADBAND         0.10    //below this the key counts as released
//NOTE: the old AUTO_ATT_TRIM_RATE (a plain lerp into force-trim) is gone - the PILOT HANDS model
//below replaced it, giving the same smoothing plus a rate limit and a proper breakout re-seed.
//If the loop oscillates, lower the PID kp rather than slowing the hands down: a slow output stage
//hides gain problems instead of fixing them, and reintroduces the phase lag that caused the
//original wobble.

//ENVELOPE LIMITS. The keyboard player's technique is to MASH the key: the target sweeps to the
//limit and STAYS there, so the limit is not a safety net, it IS the commanded attitude in normal
//use. That makes the limit values the primary handling knob for keyboard flying.
//
//Two envelopes, selected by the STICKY CONTROL INTERRUPT key (bmkhs_kbStickyInterupt -
//already a hold-type action: true on keydown, false on keyup). Held = EXPANDED. Reusing it keeps
//the "override the automatics" idea in one place instead of adding another bind.
//
//ROLL is limited by TURN RATE, not by a flat bank angle, because the bank needed for a given turn
//rate scales with speed: bank = atan(V * omega / g). A flat limit makes the same key press a tight
//turn when slow and a lazy one when fast; a rate limit gives consistent turn PERFORMANCE across
//the envelope, which is what "mash the key and it turns" should mean. The flat cap still applies
//on top so the bank cannot run away at high speed.
//PITCH is ASYMMETRIC and SCHEDULED, because nose-down authority has to be EARNED with height and
//speed while nose-up never can hurt you (there is no terrain above the aircraft). This is what
//gives a keyboard player - or Preston - a sane ACCELERATION PROFILE out of a hover instead of the
//ability to plant the chin bubble in the dirt by mashing forward at 3 feet:
//
//  NOSE UP   : flat 15 deg, expanded 30. No gates.
//  NOSE DOWN : 5 deg within 5ft AGL, scheduled up to 10 deg with AIRSPEED while still below 50ft,
//              then 15 deg once above 50ft. Expanded 30 deg - the override DOES bypass the gates
//              (deliberate: if the pilot holds override at 3 feet and dives it in, that is on them).
#define AUTO_ATT_PITCH_UP_LIMIT       15.0    //deg, normal   nose-UP clamp
#define AUTO_ATT_PITCH_DN_LIMIT_GND   5.0     //deg, nose-DOWN clamp within GND_AGL of the ground
#define AUTO_ATT_PITCH_DN_LIMIT_LOW   10.0    //deg, nose-DOWN clamp low but at speed (below 50ft)
#define AUTO_ATT_PITCH_DN_LIMIT_HI    15.0    //deg, nose-DOWN clamp above 50ft
#define AUTO_ATT_PITCH_LIMIT_EXP      30.0    //deg, expanded clamp, BOTH directions (override)
#define AUTO_ATT_PITCH_GND_AGL        5.0     //ft AGL, at/below this the ground clamp applies
#define AUTO_ATT_PITCH_DN_SPD_LO      2.572   //  5kt GS, start of the nose-down speed schedule
#define AUTO_ATT_PITCH_DN_SPD_HI      25.722  // 50kt GS, end of the nose-down speed schedule
#define AUTO_ATT_ROLL_LIMIT           30.0    //deg, normal   hard bank cap (rate limit binds first)
#define AUTO_ATT_ROLL_LIMIT_EXP       60.0    //deg, expanded hard bank cap
#define AUTO_ATT_TURN_RATE            3.0     //deg/s, standard rate turn (normal envelope)
#define AUTO_ATT_TURN_RATE_EXP        6.0     //deg/s, double standard rate (expanded envelope)
#define AUTO_ATT_TURN_MIN_BANK        5.0     //deg, floor on the rate-derived bank so a near-hover
                                              //     still has some roll authority (V->0 => bank->0)

//THREE REGIMES, mirroring the auto-pedal's three. Auto-attitude IS the pilot's hands on the cyclic
//(the auto-pedal is their feet) - and specifically a MACHINE pilot: perfect, tireless, and with no
//use for the FMC hold modes. The holds are REALISTIC-ONLY, for the human pilot who does tire; auto-
//attitude neither drives them nor defers to them, it simply flies. What the hands are TRYING to
//achieve changes with flight phase, because a hand that only knows how to hold an attitude cannot
//hold a hover:
//
//  POS (hover, < 5kt)      -> both axes hold POSITION over the ground. Attitude is not a goal here,
//                             it is a RESULT: pitch and bank can never be exactly zero because the
//                             aircraft settles wherever the forces balance (tail thrust, CG, wind).
//                             The loop nulls ground velocity and an integrator finds the STANDING
//                             cyclic offset that cancels those forces - exactly what a real pilot's
//                             hand does. Keys command a reposition VELOCITY; release re-captures the
//                             datum where the aircraft now is.
//
//  VEL (transition)        -> ROLL nulls LATERAL ground velocity; PITCH holds FORWARD velocity.
//                             Roll is the critical one: the pedals are holding NOSE-TO-TAIL trim in
//                             this regime (velocity vector on the nose), so any lateral drift makes
//                             the pedals chase a sideways velocity vector and the two loops fight
//                             each other. The hands must kill the drift with bank so the feet have
//                             something sane to trim to.
//
//  ATT (cruise)            -> both axes hold the swept PITCH/ROLL target. Only reached when the
//                             aircraft is genuinely in cruise.
//
//GATE: the ATT regime requires BOTH fast AND high - the same LOW-OR-SLOW rule the auto-pedal uses
//for aerodynamic trim. Below 50kt **OR** below 50ft the aircraft is still in the velocity world:
//NOE flight can sit well above 50ft while masked and is still nose-to-tail, and a fast run down low
//is likewise. Both gates must clear before attitude becomes the thing being held.
//
//All boundaries are BLENDED by weight, never switched, so the cyclic cannot step at a handover.
//Every regime's PID runs only while it carries weight (a PID whose output is multiplied by zero
//must not integrate, or it winds up against an error it is not allowed to correct and the windup
//leaks into the trim when the weight comes back). Each regime keeps its own gains: the error units
//differ (m/s of ground velocity vs degrees of attitude) and the numbers are not comparable.
#define AUTO_ATT_POS_SPD_LO           2.572   //  5kt GS - fully POS (position hold) below this
#define AUTO_ATT_POS_SPD_HI           7.717   // 15kt GS - fully out of POS above this
#define AUTO_ATT_ATT_SPD_LO           23.150  // 45kt GS - start of the VEL->ATT speed gate
#define AUTO_ATT_ATT_SPD_HI           28.290  // 55kt GS - fully fast enough for ATT above this
#define AUTO_ATT_ATT_AGL_LO           40.0    //ft AGL  - start of the VEL->ATT height gate
#define AUTO_ATT_ATT_AGL_HI           60.0    //ft AGL  - fully high enough for ATT above this
#define AUTO_ATT_HOVER_VEL_RATE       2.5     //m/s of commanded ground velocity at full cyclic key
#define AUTO_ATT_HOVER_VEL_LIMIT      5.0     //m/s cap on that commanded reposition velocity
#define AUTO_ATT_VEL_ACCEL_RATE       4.0     //m/s per second of commanded FORWARD velocity sweep
#define AUTO_ATT_VEL_CMD_LIMIT        30.0    //m/s cap on commanded forward velocity (~58kt, past
                                              //     which the ATT regime has taken over anyway)

//PILOT HANDS MODEL - the cyclic equivalent of the auto-pedal's PILOT FEET model, and it exists for
//the same reason: the machine pilot stands in for a human, and a human does not apply a fresh PID
//solution 60 times a second. Two limits model that, applied to the BLENDED regime output so a
//regime handover is smoothed too:
//  RATE - maximum cyclic travel per second. A hand cannot step from one stick position to another
//         instantly. Faster than the feet (0.35): hands are quicker and more precise than legs.
//  TAU  - first-order lag time constant (s). Rolls off high-frequency PID content. Shorter than the
//         feet (0.45) for the same reason.
//ORDER MATTERS - lag FIRST, then rate-limit the lagged result (see the auto-pedal note; limiting
//first converges to a fraction of the commanded value and gets worse at higher frame rates).
//On BREAKOUT the filter state is re-seeded to where the stick actually is, so when the pilot lets
//go the machine pilot picks up from that position instead of rate-limiting back from a stale one.
#define AUTO_ATT_CYCLIC_RATE          1.200   //full cyclic sweep in ~0.8s
#define AUTO_ATT_CYCLIC_TAU           0.150   //s, first-order lag on the hands
//Position-recovery integral: biases the VELOCITY SETPOINT toward the datum, so the loop does not
//merely stop the drift, it flies back to where it started.
//POSITION RECOVERY -> velocity setpoint. This converts "how far off datum am I" into "how fast
//should I fly back", and the velocity loop then chases that setpoint.
//
//It is now PROPORTIONAL (metres of error -> m/s of return), not an accumulating integral. The
//integral form saturated: measured in a real hover it sat pinned at its clamp (int 0.300 = the
//ki_clamp, setpoint 0.400 = the ICLAMP) while the aircraft drifted aft at 4.7 m/s. The loop was
//asking to return at 0.4 m/s against a drift ten times faster, so the position error grew without
//bound, the integral could never unwind, and it read as "the cyclic never puts in enough" - it
//genuinely wasn't asking for enough. A proportional term cannot saturate like that: the further
//off the datum, the faster the commanded return, all the way up to the cap.
//
//PKP: m/s of return per metre of error. 0.5 = 1 m off datum -> come back at 0.5 m/s.
//PCLAMP: ceiling on the commanded return speed. Must be comfortably above normal drift rates or
//it re-creates the same saturation; 4.0 m/s is a brisk reposition, not a lunge.
//If it OVERSHOOTS the datum and oscillates, lower PKP (it is chasing too hard). If it drifts and
//never comes back, raise PKP. The velocity PID gains are a separate concern - tune this first.
//PCLAMP measured too hot at 4.0: combined with the velocity loop's gains it drove the cyclic
//output to full deflection (out R/P both 1.000) and oscillated violently. A real pilot recovering
//drift does not ask for 4 m/s of return - keep the commanded return modest and let the loop
//converge, rather than demanding a fast recovery the airframe can only chase with full stick.
//NOTE: `HOV set` sitting exactly on PCLAMP is NOT automatically a problem to fix. In a hover that
//has drifted off datum, wanting maximum return velocity is the correct answer - the cap is doing
//its job. Raising it to 2.5 alongside a lead increase made the aircraft much worse. Change this
//only in isolation, and only if the aircraft cannot recover position at all.
#define AUTO_ATT_HOVER_POS_PKP        0.3000  //m/s of return velocity per metre of position error
#define AUTO_ATT_HOVER_POS_PCLAMP     1.5000  //m/s ceiling on the commanded return velocity
//Fraction of the CURRENT cyclic trim seeded into the hover integrators on regime entry, to avoid
//the wind-up-from-zero transient (see the seed block in fn_getInput). Deliberately well under 1.0:
//the settled trim is kp*error + ki*integral, so seeding the FULL trim as integral over-seeds it
//and the loop stacks its kp term on top - measured as the integral railing and near-full forward
//cyclic. This puts the integral in the right neighbourhood and lets it converge the rest.
#define AUTO_ATT_HOVER_SEED_FRAC      0.4000  //share of current trim seeded into the integral

//DIRECT INTEGRAL SEED - the trim-fraction seed above is only a fallback for the first entry of a
//session (when no settled value is known yet). Once the loop has held a steady hover, the value
//its integral CONVERGED TO is a far better seed than any fraction guessed off the trim, so that
//converged value is remembered and re-seeded on the next entry.
//
//Why this matters: measured, the pitch integral settles PINNED at its 0.55 clamp, but the
//trim-fraction seed only lands around 0.35 - so on every entry the loop still had ~0.2 of integral
//to climb while the aircraft was already drifting, and that climb is what oscillated (2.5 cycles
//before it caught up). Seeding the converged value removes the climb entirely.
//
//"Settled" = the loop is holding station: drift under SEED_LEARN_VEL on both axes. Only then is
//the integral a trustworthy representation of the standing hover offset.
#define AUTO_ATT_HOVER_SEED_LEARN_VEL 0.2500  //m/s - below this on both axes, the hover is settled
                                              //      and its integral is worth remembering

//ACCELERATION LEAD - what makes the machine pilot ANTICIPATE instead of chase.
//
//A velocity-error loop is inherently reactive: it cannot act until the aircraft is ALREADY
//moving, so it is forever correcting a drift that has happened. A real pilot does not fly that
//way - they feel the aircraft START to go and lead with cyclic before any drift exists, which
//is why hand-flying a hover works at all.
//
//The PID's kd term is a poor substitute: it differentiates the VELOCITY ERROR, which is the same
//lagging signal, and it is noisy. This instead feeds the airframe's own measured ACCELERATION
//(bmkhs_accelX/Y - the smoothed derivative of the very velocity the loop nulls, so it is
//already in the same frame and needs no sign conversion) as a SEPARATE lead term. Cyclic goes in
//as the aircraft begins to accelerate, not after it has built speed.
//
//Sign: acceleration ADDS to the velocity error in the same sense - "moving right AND accelerating
//right" needs more correction than "moving right but already slowing". Effectively this makes the
//loop act on a short-horizon PREDICTION of velocity (vel + accel*horizon) rather than on velocity
//alone. KLEAD is that horizon in seconds: 0.35 = "correct for where it will be in a third of a
//second". Too large and it over-anticipates and hunts; too small and it reverts to reactive.
//TUNING HISTORY - 0.35 is the best value found so far, do not raise it without testing:
//  0.35 - measurably good. Lateral drift nearly killed (0.195 m/s), output well clear of the
//         rails (0.106/0.220), no oscillation.
//  0.60 - MUCH worse. Over-anticipation: the loop acts on predicted motion far enough ahead that
//         its own correction becomes the next frame's acceleration, so it drives itself. The
//         lead term is positive feedback if the horizon exceeds the loop's response time.
#define AUTO_ATT_ACCEL_LEAD           0.3500  //s, prediction horizon on measured acceleration
#define AUTO_ATT_ACCEL_LEAD_CLAMP     2.0000  //m/s cap on the lead contribution (keeps a noisy
                                              //     accel spike from railing the command)
#define AUTO_ATT_HOVER_POS_DEADBAND   0.30    //m, position error ignored inside this (no hunting)

//Auto-pedal AERODYNAMIC-TRIM gates. The pedals hold NOSE-TO-TAIL trim (velocity vector on the nose)
//whenever the aircraft is LOW **OR** SLOW, and only switch to AERODYNAMIC trim (ball centered) when
//it is BOTH high enough AND fast enough - i.e. genuinely in cruise. Altitude alone is not sufficient:
//NOE flight can sit well above 50ft while masked behind terrain or trees and is still a nose-to-tail
//regime. Each gate is a BAND, not a step, so the handover ramps instead of jolting the tail.
//Altitude is blended against the exact radar altitude, bmkhs_radAlt - a displayed one rounded to
//10ft above 50ft would quantize this band into a staircase.
#define AUTOPEDAL_NTT_AGL_FT          40.0    //ft  - below this: nose-to-tail
#define AUTOPEDAL_AERO_AGL_FT         60.0    //ft  - above this: high enough for aero trim
#define AUTOPEDAL_AERO_SPD_LO         23.15   //m/s - 45kts, below this: nose-to-tail
#define AUTOPEDAL_AERO_SPD_HI         28.29   //m/s - 55kts, above this: fast enough for aero trim

//Auto-pedal PILOT FEET model. The auto-pedal stands in for a human on the pedals, so it must not
//react like an automaton - no instant response, no chasing a ball that is a hair off centre.
//  DEADBAND - error inside this is ignored entirely (a pilot accepts a small standing skid). The
//             band is SUBTRACTED outside it so the response stays continuous, with no step at the edge.
//             0.01g is roughly where the ball becomes visibly off centre (full scale is 0.15g).
//  RATE     - maximum pedal travel per second. Feet have mass and the pedals have breakout force;
//             0.35 = a full pedal sweep takes ~3s, an unhurried but purposeful correction.
//  TAU      - first-order lag time constant (s). Rolls off the high-frequency content the PID
//             produces from a noisy lateral-g signal. Larger = smoother/lazier feet.
//DEADBAND 0.010 -> 0.004. The loop stops correcting inside the deadband, so it sets the floor on
//how well the ball can be centred - at 0.010 g a visible offset was left standing. 0.004 is below
//the ball's own resolution but still above the frame-to-frame noise floor.
#define AUTOPEDAL_AERO_DEADBAND_G     0.004
#define AUTOPEDAL_NTT_DEADBAND_DEG    0.750
//Keyboard pedal fade, in and back out. A key is on or off; the pedal it drives is not.
#define AUTOPEDAL_KB_FADE_TIME        2.000
//Forward speed at which the pedals hand over from heading hold to nose-to-tail trim
#define AUTOPEDAL_NTT_SPD             5.144   //10kt forward

//AUTO ATTITUDE (CASUAL + KEYBOARD). Drives the aircraft to wings level so a keyboard player is
//not fighting the pitch-up the airframe develops with forward airspeed. There is no attitude
//TARGET and no capture - the setpoint is always zero, so there is nothing to snap.
//It never fights an input: authority fades out with stick deflection and returns as it centres.
#define AUTOATT_KEY_DEADBAND          0.10    //below this the key counts as released
#define AUTOATT_SPD_LO                7.717   //15kt GS - assist starts fading in
#define AUTOATT_SPD_HI                15.433  //30kt GS - assist at full authority
#define AUTOATT_ROLL_IN_TIME          0.250   //s, roll target sweep into the bank
#define AUTOATT_ROLL_OUT_TIME         1.000   //s, roll target sweep back to level
#define AUTOATT_PITCH_OUT_CLAMP       0.07    //max share of the cyclic the pitch assist may command
#define AUTOATT_ROLL_OUT_CLAMP        0.80    //max share of the cyclic the roll assist may command

//Force-vector debug drawing. This was previously #ifdef __A3_DEBUG__, which is dead
//code under HEMTT - that macro is hardcoded to 0 in a lookup the #ifdef existence
//check never consults, so every block was compiled out unconditionally and the
//debug graphics could never draw. Gate on the CBA setting instead so it is
//togglable at runtime.
#define BMKHS_FM_DEBUG (!isNil "bmkhs_fmDebug" && {bmkhs_fmDebug})

//The forces readout is its own switch, so the window can be had without the hint
//and the 3D debug graphics that BMKHS_FM_DEBUG brings with it. Every force
//generator tests this before publishing its row.
#define BMKHS_FORCES_DEBUG (!isNil "bmkhs_forcesDebug" && {bmkhs_forcesDebug})

#endif
