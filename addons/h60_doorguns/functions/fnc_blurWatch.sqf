/*
 * vtx_uh60_doorguns_fnc_blurWatch
 *
 * Waits for the door-gun burst to end (0.1 s without a shot), fades the blur out
 * over 0.5 s, then switches it off and resets the build-up and camera shake. If the
 * gunner fires again during the fade it re-arms instead, so a burst never ends
 * with nothing watching it.
 *
 * params: none
 */

[{cba_missionTime - vtx_m134_lastFired > 0.1}, {
    vtx_m134_blur ppEffectAdjust [0];
    vtx_m134_blur ppEffectCommit 0.5;
    [{
        if (cba_missionTime - vtx_m134_lastFired > 0.5) then {
            vtx_m134_blur ppEffectEnable false;
            vtx_m134_ppEffectIntensity = 0;
            vtx_m134_blurWatching = false;
            resetCamShake;
        } else {
            call vtx_uh60_doorguns_fnc_blurWatch; // fired again during the fade
        };
    }, [], 0.5] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_waitUntilAndExecute;
