params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
if (player != _gunner) exitWith {};

vtx_m134_ppEffectIntensity = vtx_m134_ppEffectIntensity + 1;
if (cba_missionTime - vtx_m134_lastFired    > 0.1) then {
    private _blur = ppEffectCreate ["DynamicBlur", 401];
    vtx_m134_ppEffects = [_blur];
    (vtx_m134_ppEffects # 0) ppEffectEnable true;
    vtx_m134_lastFired = cba_missionTime;
    [] spawn {
        waitUntil {
            (cba_missionTime - vtx_m134_lastFired    > 0.1);
        };
        (vtx_m134_ppEffects # 0) ppEffectAdjust [0];
        (vtx_m134_ppEffects # 0) ppEffectCommit 0.5;
        sleep 0.5;
        ppEffectDestroy vtx_m134_ppEffects;
        vtx_m134_ppEffectIntensity = 0;
        vtx_m134_ppEffects = [];
        resetCamShake;
    };
};
vtx_m134_lastFired = cba_missionTime;
private _modifier = (vtx_m134_ppEffectIntensity / 100) min 100;
(vtx_m134_ppEffects # 0) ppEffectAdjust [_modifier];
(vtx_m134_ppEffects # 0) ppEffectCommit 0;
addCamShake [1, 1, 100];
