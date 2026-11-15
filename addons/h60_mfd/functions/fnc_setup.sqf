/*
 * hct_h60_mfd_fnc_setup
 *
 * handles the setup of the mfd system
 *
 * params (array)[(object) vehicle]
 */
params ["_vehicle"];
if (!hct_h60_enabled_mfd) exitWith {
    _vehicle setUserMFDvalue [23,1];
    _vehicle setUserMFDvalue [24,0];
    _vehicle setUserMFDvalue [25,0];
    _vehicle setUserMFDvalue [26,1];
    false
};

_vehicle setUserMFDvalue [23,1];
_vehicle setUserMFDvalue [24,0];
_vehicle setUserMFDvalue [25,0];
_vehicle setUserMFDvalue [26,1];


// Keep the zoom the aircraft already has: every crew member boarding used to
// reset it to 1 (and broadcast that) for everyone aboard. Defaults are broadcast
// once, by the first to set up.
private _zoom = _vehicle getVariable ["MAP_Zoom", -1];
if (_zoom < 0) then {
    _zoom = 1;
    _vehicle setVariable ["MAP_Zoom", 1, true];
    _vehicle setVariable ["MAP_ZoomMult", 1, true];
};
_vehicle animateSource ["MAP1_Scale", 1/_zoom, 1];
_vehicle setUserMFDValue [40, worldSize / _zoom / 2];

hct_h60_mfd_tac_mapPos = [0,0,0];
hct_h60_mfd_tac_cursorPos = [0.5,0.5];
hct_h60_mfd_slewX = 0;
hct_h60_mfd_slewY = 0;
hct_h60_mfd_allowText = true;
hct_h60_tac_hookedObject = nil;

// likewise each screen's map texture: default once, never reset on boarding
{
    private _var = format ["hct_h60_mfd_%1_mapTextureMode", _x];
    if (isNil {_vehicle getVariable _var}) then {
        _vehicle setVariable [_var, "topo", true];
    };
} forEach [23, 24, 25, 26];

hct_h60_mfd_mfsc_focussedMFD = 25;
if (player != driver _vehicle) then {
    hct_h60_mfd_mfsc_focussedMFD = 24;
};
hct_h60_ccfs_gameState = "MENU";
hct_h60_ccfs_playerSelected = player;
hct_h60_ccfs_isHost = false;
hct_h60_ccfs_score = [0,0];
hct_h60_ccfs_paddleMoved = false;
hct_h60_ccfs_paddlePositions = [0.5,0.5];
hct_h60_ccfs_ballPos = [0.5,0.5];
hct_h60_ccfs_serveSide = -1;
hct_h60_ccfs_ballVelocity = [hct_h60_ccfs_serveSide, -1 + (random 2)] vectorMultiply 0.005;
hct_h60_ccfs_lastScore = time;
hct_h60_ccfs_winningScore = 10;

[_vehicle, [0]] enableInfoPanelComponent ["left", "SlingLoadDisplay", false];
[_vehicle, [0]] enableInfoPanelComponent ["left", "SensorsDisplayComponent", false];
[_vehicle, [0]] enableInfoPanelComponent ["left", "MinimapDisplay", false];
[_vehicle, [0]] enableInfoPanelComponent ["right", "SlingLoadDisplay", false];
[_vehicle, [0]] enableInfoPanelComponent ["right", "SensorsDisplayComponent", false];
[_vehicle, [0]] enableInfoPanelComponent ["right", "MinimapDisplay", false];

true
