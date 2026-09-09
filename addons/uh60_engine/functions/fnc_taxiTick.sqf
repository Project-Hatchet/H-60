/*
 * vtx_uh60_engine_fnc_taxiTick
 *
 * SFM ground taxi - ported from the MH-47G (itself from the HWK CH-53E),
 * carrying their 12 documented tuning rounds: SFM helis have no wheel
 * drive, so cyclic input commands a TARGET ground speed and the chain
 * accelerates toward it (converges - no runaway, no static-friction
 * stall), pedals pivot the ship with a speed-scaled turn-radius cap,
 * and upward velocity is clamped while driving so a nose-low hull never
 * unsticks the gear. AFM/RTD untouched - the chain refuses to run there.
 *
 * 60 adaptations vs the 47G original:
 *  - drive gate = engine on + rotor near flight NR (rotorSpeed sound
 *    controller) instead of their virtual-collective band; a raised
 *    collective input (HeliUp held) = TAKEOFF intent and stands the
 *    drive + anti-liftoff clamp down so rolling takeoffs are never
 *    pinned to the ground (their MaxCol standdown, input-flavored).
 *  - all knobs are missionNamespace globals, console-tunable LIVE
 *    (no rebuild per tuning round).
 *
 * Owner-side chain reading the local player's input: taxi drives only
 * when the human at the sticks is on the vehicle owner's machine (the
 * usual case; same limitation as the 47G). Armed/re-armed by fnc_pbArm.
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];

// tuning knobs (one-time init; tweak live from the console, e.g.
// vtx_uh60_taxiMaxKmh = 15;)
if (isNil "vtx_uh60_taxiMaxKmh") then {
    vtx_uh60_taxiSeg       = 0.1;   // seconds per tick
    vtx_uh60_taxiMaxKmh    = 20;    // top taxi speed (rearward taxi prohibited - see below)
    vtx_uh60_taxiStickFull = 0.4;   // effective stick at/above this = full taxi speed
    vtx_uh60_taxiDeadband  = 0.08;  // after the resting-position baseline
    vtx_uh60_taxiAccel     = 0.35;  // m/s per tick breakaway punch (beats SFM static friction)
    vtx_uh60_taxiBreakSpd  = 0.4;   // m/s: below = breakaway punch, above = cruise accel
    vtx_uh60_taxiAccelCrz  = 0.15;  // m/s per tick once rolling (must clear SFM rolling drag)
    vtx_uh60_taxiPedalBite = 0.1;   // near-stationary pivot starter, scaled by |pedal|
    vtx_uh60_taxiYawCap    = 0.35;  // rad/s absolute ceiling on ground yaw
    vtx_uh60_taxiYawFloor  = 0.15;  // rad/s pivot floor when (nearly) stationary
    vtx_uh60_taxiTurnR     = 8;     // min turn radius (m); yaw cap scales as v/R
    vtx_uh60_taxiMinNR     = 0.85;  // rotorSpeed controller floor for the drive
};

if (isNull _vehicle || {!alive _vehicle} || {!local _vehicle}
    || {!isTouchingGround _vehicle}
    || {difficultyEnabledRTD && {isObjectRTD _vehicle}}) exitWith {
    _vehicle setVariable ["vtx_uh60_engine_taxiOn", false];
};

// per-tick gates skip the drive without killing the chain
if ((driver _vehicle) isEqualTo player) then {
    private _rawF = (inputAction "HeliCyclicForward") - (inputAction "HeliCyclicBack");
    private _rawP = (inputAction "HeliRudderRight") - (inputAction "HeliRudderLeft");
    private _nr = _vehicle getSoundController "rotorSpeed";

    // gate-hunt diagnostic (the 47G ghost-hunt pattern): console
    // `vtx_uh60_taxiDebug = true;` -> one RPT line per second naming
    // every gate value, so a dead drive convicts its blocker in one try
    if (!isNil "vtx_uh60_taxiDebug" && {vtx_uh60_taxiDebug}
        && {diag_tickTime - (_vehicle getVariable ["vtx_uh60_taxiDbgT", 0]) > 1}) then {
        _vehicle setVariable ["vtx_uh60_taxiDbgT", diag_tickTime];
        diag_log format ["VTXTAXI nr=%1 brake=%2 heliUp=%3 rawF=%4 rawP=%5 base=%6 touching=%7 spd=%8",
            _nr, _vehicle animationPhase "handle_wheelbrake", inputAction "HeliUp",
            _rawF, _rawP, _vehicle getVariable ["vtx_uh60_taxiBase", [0,0]],
            isTouchingGround _vehicle, speed _vehicle];
    };

    if (_nr < vtx_uh60_taxiMinNR
        || {(_vehicle animationPhase "handle_wheelbrake") > 0.5}) then {
        // LEARN the stick's hands-off level whenever taxiing is
        // impossible (rotor low or brake set) - analog cyclics don't
        // rest at 0, and SFM trim can leak into inputAction (the 47G
        // ghost-creep saga). Slow low-pass; deflections past 0.3 are
        // real input and ignored. Brake ON for two seconds re-zeroes
        // a creeping baseline.
        private _b = _vehicle getVariable ["vtx_uh60_taxiBase", [0, 0]];
        _vehicle setVariable ["vtx_uh60_taxiBase", [
            (_b # 0) * 0.9 + ([_rawF, _b # 0] select (abs _rawF > 0.3)) * 0.1,
            (_b # 1) * 0.9 + ([_rawP, _b # 1] select (abs _rawP > 0.3)) * 0.1]];
    } else {
    // drive gates: brake released, rotor up, and NOT takeoff intent
    // (collective input held = the pilot wants to fly - drive and
    // anti-liftoff clamp both stand down so a rolling takeoff works)
    if ((inputAction "HeliUp") < 0.5) then {
        private _base = _vehicle getVariable ["vtx_uh60_taxiBase", [0, 0]];
        private _fwd = _rawF - (_base # 0);
        private _ped = _rawP - (_base # 1);
        if (abs _fwd < vtx_uh60_taxiDeadband) then { _fwd = 0 };
        if (abs _ped < vtx_uh60_taxiDeadband) then { _ped = 0 };
        if (_fwd != 0 || {_ped != 0}) then {
            private _vel = velocityModelSpace _vehicle;
            // stick fraction -> commanded taxi speed; full speed well
            // below full stick so taxi never needs hull-pitching throws
            private _tgt = (((_fwd / vtx_uh60_taxiStickFull) max -1) min 1)
                * vtx_uh60_taxiMaxKmh / 3.6;
            // NO rearward taxi (TM 1-1520-280-10 Ch.5 prohibition; Riverman
            // ruling 2026-09-08) - the 47G's gentle reverse is removed. Aft
            // cyclic commands target 0: it slows the roll to a stop and
            // never drives the ship backwards.
            _tgt = _tgt max 0;
            // rolling wheels REDIRECT speed (47G round 11): run the
            // controller on total horizontal ground speed and lay it
            // along the nose each tick, so turns don't brake the ship
            private _mag = (sqrt ((_vel # 0) ^ 2 + (_vel # 1) ^ 2))
                * ([1, -1] select ((_vel # 1) < 0));
            // breakaway punch only until rolling, then heavy buildup
            private _acc = [vtx_uh60_taxiAccelCrz, vtx_uh60_taxiAccel]
                select (abs _mag < vtx_uh60_taxiBreakSpd);
            private _vy = _mag + (((_tgt - _mag) max -_acc) min _acc);
            // anti-liftoff (47G round 10): the push rides the hull's
            // forward axis - clamp any upward leak while driving,
            // downward stays so the suspension can settle
            private _vz = (_vel # 2) min 0;
            // pedal bite starts a stationary pivot only (47G round 12:
            // stacked on the redirect it was free accel in turns)
            if (_ped != 0 && {abs _mag < 1}) then {
                _vy = _vy + vtx_uh60_taxiPedalBite * (abs _ped);
            };
            _vehicle setVelocityModelSpace [(_vel # 0) * 0.5, _vy, _vz];
        };
        // ground pivot governor: yaw <= v/R for a real turn radius,
        // floored so slow pedal pivots stay alive
        private _cap = (((abs (velocityModelSpace _vehicle # 1)) / vtx_uh60_taxiTurnR)
            max vtx_uh60_taxiYawFloor) min vtx_uh60_taxiYawCap;
        private _av = angularVelocityModelSpace _vehicle;
        if (abs (_av # 2) > _cap) then {
            _vehicle setAngularVelocityModelSpace [_av # 0, _av # 1,
                _cap * ((_av # 2) / abs (_av # 2))];
        };
        // NO pitch governor (Riverman ruling 2026-09-08 after two rounds
        // of fighting it): SFM applies full rotor pitch authority on the
        // ground and keyboard cyclic is full stick - a rate cap and an
        // attitude floor both failed to keep the tail wheel down without
        // fighting Arma's input model. Accepted as a known SFM limit; the
        // real fix arrives with HeliSim + AH-64-style own input handlers
        // ("sticky" flight controls), where ground cyclic authority is
        // ours to shape.
    };  // takeoff-intent standdown
    };  // learn / drive split
};  // human driver on this machine

[vtx_uh60_engine_fnc_taxiTick, [_vehicle], vtx_uh60_taxiSeg] call CBA_fnc_waitAndExecute;
