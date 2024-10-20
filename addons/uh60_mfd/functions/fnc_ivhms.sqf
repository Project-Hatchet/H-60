/*
 * vtx_uh60_mfd_fnc_ivhms
 */
params ["_vehicle"];
vtx_uh60_mfd_allowText = false;
{_vehicle setUserMFDValue [_x, 6]} forEach [23, 24, 25, 26];
_vehicle animate ["GeneratorsOnOff",1];
_vehicle animate ["PowerOnOff",1];


// 1 FRAMEWORK STATUS: ACTIVE
private _config = _vehicle getVariable "vxf_config";
_vehicle setUserMFDText [1, if (isNil "_config") then [{"FRAMEWORK STATUS: NOT LOADED"}, {"FRAMEWORK STATUS: ACTIVE"}]];

// 2 AIRCRAFT: RUNNING
_vehicle setUserMFDText [2, if (isEngineOn _vehicle) then [{"AIRCRAFT: RUNNING"}, {"AIRCRAFT: OFF"}]];

// 3 UH-60M
private _vehicleConfig = configOf _vehicle;
private _name = getText (_vehicleConfig >> "displayName");
_vehicle setUserMFDText [3, format["%1 %2", _name, configName _vehicleConfig]];

// 4 DATE 2021/12/04 14:50Z
systemTimeUTC params ["_year", "_month", "_day", "_hour", "_minute", "_second", "_millisecond"];
private _timeStr = format["DATE %1/%2/%3 %4:%5Z", _year, _month, _day, _hour, _minute];
_vehicle setUserMFDText [4, _timeStr];

// MODULES
private _modules = vehicle player getVariable "vxf_modules";
_modulesText =_modules apply {(_x # 0) + (if (_x # 1) then [{"/ACT"},{"/STB"}])} joinString " | ";

// 5 MODULES1
_vehicle setUserMFDText [5,_modulesText select [0,62]];
// 6 MODULES2
_vehicle setUserMFDText [6,_modulesText select [62,62]];
// 7 MODULES3
_vehicle setUserMFDText [7,_modulesText select [124,62]];

// 8 ADVANCED FLIGHT MODEL
_vehicle setUserMFDText [8, if (difficultyEnabledRTD) then [{"FM ADVANCED"}, {"FM STANDARD"}]];

// 9 VXF_DRIVER
_vehicle setUserMFDText [9, configName _config];

// Product info
productVersion params ["_name", "_nameShort", "_version", "_build", "_branch", "", "_os", "_architecture"];
// 10 Arma3 207
_vehicle setUserMFDText [10, format["%1 %2", _nameShort, _version]];
// 11 148579 Diag
_vehicle setUserMFDText [11, format["%1 %2", _build, _branch]];
// 12 Windows x64
_vehicle setUserMFDText [12, format["%1 %2", _os, _architecture]];


// 13 tempMissionSP
_vehicle setUserMFDText [13, missionName];
// 14 1 players
_vehicle setUserMFDText [14, format["%1 PLAYERS", count allPlayers]];
// 15 VR SP
_vehicle setUserMFDText [15, format["%1 %2", worldName, serverName]];
// 16 58.19
_vehicle setUserMFDText [16, str time];

// MODS
private _mods = getLoadedModsInfo apply {((_x # 1) regexReplace ["\W",""]) select [0,15]} joinString "|";
// 17 MODS1
_vehicle setUserMFDText [17, _mods select [0,62]];
// 18 MODS2
_vehicle setUserMFDText [18, _mods select [62,62]];
// 19 MODS3
_vehicle setUserMFDText [19, _mods select [124,62]];