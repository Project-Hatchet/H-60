params ["_shooter","_weapon","","_mode","_ammo","","_projectile"];

if (!(_ammo isKindOf "MissileBase")) exitWith {};

if (ace_missileguidance_enabled < 1 || {!local _projectile} ) exitWith {};

if ( !isPlayer _shooter && { ace_missileguidance_enabled < 2 } ) exitWith {};


private _configs = configProperties [(configFile >> "CfgAmmo" >> _ammo), "configName _x == ""ace_missileguidance""", false];
if ((count _configs) < 1) exitWith {};

private _config = configFile >> "CfgAmmo" >> _ammo >> "ace_missileguidance";

private _target = _shooter getVariable ["ace_missileguidance_target", nil];
private _targetPos = _shooter getVariable ["ace_missileguidance_targetPosition", nil];
private _seekerType = _shooter getVariable ["ace_missileguidance_seekerType", nil];
private _attackProfile = _shooter getVariable ["ace_missileguidance_attackProfile", nil];
if ((getNumber (configFile >> "CfgAmmo" >> _ammo >> "ace_missileguidance" >> "useModeForAttackProfile")) == 1) then {
    _attackProfile = getText (configFile >> "CfgWeapons" >> _weapon >> _mode >> "ace_missileguidance_attackProfile")
};
private _lockMode = _shooter getVariable ["ace_missileguidance_lockMode", nil];

private _laserCode = [vehicle player, "PRI CHAN"] call vtx_uh60_weapons_fnc_getLaserCode;
private _laserInfo = [_laserCode, ACE_DEFAULT_LASER_WAVELENGTH, ACE_DEFAULT_LASER_WAVELENGTH];

private _launchPos = getPosASL (vehicle _shooter);

if (isNil "_seekerType" || {!(_seekerType in (getArray (_config >> "seekerTypes")))}) then {
    _seekerType = getText (_config >> "defaultSeekerType");
};
if (isNil "_attackProfile" || {!(_attackProfile in (getArray (_config >> "attackProfiles")))}) then {
    _attackProfile = getText (_config >> "defaultAttackProfile");
};
if (isNil "_lockMode" || {!(_lockMode in (getArray (_config >> "seekerLockModes")))}) then {
    _lockMode = getText (_config >> "defaultSeekerLockMode");
};

private _seekLastTargetPos = (getNumber ( _config >> "seekLastTargetPos")) == 1;
private _lastKnownPosState = [_seekLastTargetPos];
if (_seekLastTargetPos && {!isNil "_target"}) then {
    _lastKnownPosState set [1, (getPosASL _target)];
} else {
    _lastKnownPosState set [1, [0,0,0]];
};

private _args = [_this,
            [   _shooter,
                [_target, _targetPos, _launchPos],
                _seekerType,
                _attackProfile,
                _lockMode,
                _laserInfo
            ],
            [
                getNumber ( _config >> "minDeflection" ),
                getNumber ( _config >> "maxDeflection" ),
                getNumber ( _config >> "incDeflection" )
            ],
            [
                getNumber ( _config >> "seekerAngle" ),
                getNumber ( _config >> "seekerAccuracy" ),
                getNumber ( _config >> "seekerMaxRange" ),
                getNumber ( _config >> "seekerMinRange" )
            ],
            [ diag_tickTime, [], [], _lastKnownPosState]
        ];

private _onFiredFunc = getText (configFile >> "ace_missileguidance_SeekerTypes" >> _seekerType >> "onFired");

if (_onFiredFunc != "") then {
    _args call (missionNamespace getVariable _onFiredFunc);
};

_onFiredFunc = getText (configFile >> "ace_missileguidance_AttackProfiles" >> _attackProfile >> "onFired");
if (_onFiredFunc != "") then {
    _args call (missionNamespace getVariable _onFiredFunc);
};

_onFiredFunc = getText (_config >> "onFired");
if (_onFiredFunc != "") then {
    _args call (missionNamespace getVariable _onFiredFunc);
};

[ace_missileguidance_fnc_guidancePFH, 0, _args ] call CBA_fnc_addPerFrameHandler;
