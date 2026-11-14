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

if (isNil "_navigationType" || {!(_navigationType in (getArray (_config >> "navigationTypes")))}) then {
    _navigationType = getText (_config >> "defaultNavigationType");
};

if (isNil "_navigationType" || _navigationType isEqualTo "") then {
    // most missiles use ProNav by default
    _navigationType = "ProportionalNavigation";
};

private _seekLastTargetPos = (getNumber ( _config >> "seekLastTargetPos")) == 1;
private _lastKnownPosState = [_seekLastTargetPos];
if (_seekLastTargetPos && {!isNil "_target"}) then {
    _lastKnownPosState set [1, (getPosASL _target)];
} else {
    _lastKnownPosState set [1, [0,0,0]];
};

private _navigationParameters = [
    // set up in navigation type onFired function
];

// default config values to make sure there is backwards compat
private _pitchRate = 30;
private _yawRate = 30;
private _bangBang = false;
if (isNumber (_config >> "pitchRate")) then {
    _pitchRate = getNumber ( _config >> "pitchRate" );
    _yawRate = getNumber ( _config >> "yawRate" );
    _bangBang = (1 == getNumber (_config >> "bangBangGuidance"));
};

// How much this projectile likes to stay toward current velocity
private _stabilityCoefficient = getNumber (_config >> "stabilityCoefficient");

// show a light trail in flight
private _showTrail = (1 == getNumber (_config >> "showTrail"));

private _navigationStateSubclass = _config >> "navigationStates";
private _states = getArray (_navigationStateSubclass >> "states");

private _navigationStateData = [];
private _initialState = "";

if (_states isNotEqualTo []) then {
    _initialState = _states select 0;
    {
        private _stateClass = _navigationStateSubclass >> _x;
        _navigationStateData pushBack [
            getText (_stateClass >> "transitionCondition"),
            getText (_stateClass >> "navigationType"),
            []
        ];
    } forEach _states;
};

private _initialRoll = getNumber (_config >> "initialRoll");
private _initialYaw = getNumber (_config >> "initialYaw");
private _initialPitch = getNumber (_config >> "initialPitch");

private _yawRollPitch = (vectorDir _projectile) call CBA_fnc_vect2Polar;

private _args = [_this,
            [   _shooter,
                [_target, _targetPos, _launchPos, vectorDirVisual vehicle _shooter, CBA_missionTime],
                _seekerType,
                _attackProfile,
                _lockMode,
                _laserInfo,
                _navigationType
            ],
            [
                _pitchRate,
                _yawRate,
                _bangBang,
                _stabilityCoefficient,
                _showTrail
            ],
            [
                getNumber ( _config >> "seekerAngle" ),
                getNumber ( _config >> "seekerAccuracy" ),
                getNumber ( _config >> "seekerMaxRange" ),
                getNumber ( _config >> "seekerMinRange" )
            ],
            [ diag_tickTime, [], [], _lastKnownPosState, _navigationParameters, [_initialYaw + (_yawRollPitch select 1), _initialRoll, _initialPitch + (_yawRollPitch select 2)]],
            [
                // target data from missile. Must be filled by seeker for navigation to work
                [0, 0, 0],  // direction to target
                [0, 0, 0],  // direction to attack profile
                0,          // range to target
                [0, 0, 0],  // target velocity
                [0, 0, 0]   // target acceleration
            ],
            [0, _navigationStateData]
        ];

private _onFiredFunc = getText (configFile >> "ace_missileguidance_SeekerTypes" >> _seekerType >> "onFired");

if (_onFiredFunc != "") then {
    _args call (missionNamespace getVariable _onFiredFunc);
};

_onFiredFunc = getText (configFile >> "ace_missileguidance_AttackProfiles" >> _attackProfile >> "onFired");
if (_onFiredFunc != "") then {
    _args call (missionNamespace getVariable _onFiredFunc);
};

if (_states isEqualTo []) then {
    _onFiredFunc = getText (configFile >> "ace_missileguidance_NavigationTypes" >> _navigationType >> "onFired");
    if (_onFiredFunc != "") then {
        private _navState = (_args call (missionNamespace getVariable _onFiredFunc));
        (_args select 4) set [4, _navState];
    };
} else {
    {
        _onFiredFunc = getText (configFile >> "ace_missileguidance_NavigationTypes" >> _x >> "onFired");
        if (_onFiredFunc != "") then {
            private _navState = (_args call (missionNamespace getVariable _onFiredFunc));
            (_navigationStateData select _forEachIndex) set [2, _navState];
        };
    } forEach getArray (_config >> "navigationTypes");
};

_onFiredFunc = getText (_config >> "onFired");
if (_onFiredFunc != "") then {
    _args call (missionNamespace getVariable _onFiredFunc);
};
if (vtx_uh60_ui_showDebugMessages) then {systemChat format ["vtx hellfire init called with args: %1", _args];};
[ace_missileguidance_fnc_guidancePFH, 0, _args ] call CBA_fnc_addPerFrameHandler;
