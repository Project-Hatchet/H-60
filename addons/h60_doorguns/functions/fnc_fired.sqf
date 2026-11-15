/*
 * hct_h60_doorguns_fnc_fired
 *
 * Door-gun firing feedback for the gunner: motion blur that builds over a burst,
 * plus camera shake. One blur effect per client, reused; hct_h60_doorguns_fnc_blurWatch
 * fades it after the burst.
 *
 * (Was a new ppEffect and a spawned waitUntil per burst: a burst started during
 * the previous fade replaced the handle - the old effect leaked - and the old
 * fade then destroyed the new one and emptied the list, so the next shot errored.)
 *
 * params: Fired event handler arguments
 */

params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
if (player != _gunner) exitWith {};

if (isNil "hct_m134_blur") then {
    hct_m134_blur = ppEffectCreate ["DynamicBlur", 401];
};

hct_m134_ppEffectIntensity = hct_m134_ppEffectIntensity + 1;
hct_m134_lastFired = cba_missionTime;

if !(missionNamespace getVariable ["hct_m134_blurWatching", false]) then {
    hct_m134_blurWatching = true;
    hct_m134_blur ppEffectEnable true;
    call hct_h60_doorguns_fnc_blurWatch;
};

private _modifier = (hct_m134_ppEffectIntensity / 100) min 100;
hct_m134_blur ppEffectAdjust [_modifier];
hct_m134_blur ppEffectCommit 0;
addCamShake [1, 1, 100];
