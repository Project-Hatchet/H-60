/*
 * vtx_uh60_fms_fnc_perSecond
 *
 * handles occasional updates of data for FMS
 *
 * params (array)[(object) vehicle]
 */

params ["_vehicle"];

if (missionNamespace getVariable ["vtx_uh60m_disabled_waypts", false]) then {
    _this call vtx_uh60_fms_fnc_updateWaypointInfo;
};

#include "..\config\fmsDefines.hpp"

private _fms = if (player == driver _vehicle) then [{ FMS_R_PAGE_INDEX }, { FMS_L_PAGE_INDEX }];
private _strings = switch ((getUserMFDValue _vehicle) # _fms) do {
    case FMS_PAGE_PERFORMANCE: {
        private _weight = weightRTD _vehicle;
        private _state = _vehicle animationPhase "Fuelprobe_Extend";
        private _stateText = "NOT INSTALLED";
        if (_vehicle animationSourcePhase "Fuelprobe_Show" > 0) then {
            _stateText = "RETRACTED";
            if (_state > 0.05 && _state < 0.95) then {
                _stateText = "MOVING";
            } else {
                if (_state > 0.95) then { _stateText = "EXTENDED"; };
            };
        };
        [
            str ceil (missionNamespace getVariable ["vtx_uh60_engine_fuelConsumption",0]),
            missionNamespace getVariable ["vtx_uh60_engine_fuelTime","--:--:--"],
            str floor (missionNamespace getVariable ["vtx_uh60_engine_fuelRange",0]),
            str round (((_weight # 0) + (_weight # 1) + (_weight # 3) + (_weight # 4)) * 2.20462),
            _stateText
        ]
    };
    case FMS_PAGE_NAV_WAYPOINT: {
        private _waypointIndex = currentWaypoint group player;
        private _wayPoint = [group player, _waypointIndex];
        private _position = waypointPosition _wayPoint;
        private _gridArea = [worldName] call ace_common_fnc_getMGRSdata;
        private _grid = [_position] call ace_common_fnc_getMapGridFromPos;
        private _str = format ["%1    %2    %3    %4", _gridArea select 0, _gridArea select 1, _grid select 0, _grid select 1];
        [_str, format["%1/%2", _waypointIndex + 1, count (waypoints group player)], "", "",""]
    };
    case FMS_PAGE_NAV_IMPORT: {
        private _autoCycle = _vehicle getVariable ["vtx_uh60_fms_import_autoCycle", false];
        [(if(_autoCycle)then[{"ON"},{"OFF"}]), "", "", "",""]
    };
    case FMS_PAGE_NAV_LOCATIONS_LIST: {
        private _locationTypes = ["Airport","Area","BorderCrossing","CityCenter","CivilDefense","CulturalProperty","DangerousForces","Flag","FlatArea","FlatAreaCity","FlatAreaCitySmall","Hill","HistoricalSite","Invisible","Mount","Name","NameCity","NameCityCapital","NameMarine","NameVillage","RockArea","SafetyZone","Strategic","StrongpointArea","VegetationBroadleaf","VegetationFir","VegetationPalm","VegetationVineyard","ViewPoint"];
        if (!fms_locations_page_open) then {
            private _places = [];
            {
                if (text _x != "") then {
                    _places pushBack [(text _x), _x];
                };
            } foreach (nearestLocations [getpos player, _locationTypes, 15000]);
            _places sort true;
            fms_locations_page_list = _places;
        };
        private _pageCount = ceil ((count fms_locations_page_list) / 4);
        fms_locations_page_index = fms_locations_page_index max 0 min (_pageCount - 1);
        private _strings = [format["%1/%2", fms_locations_page_index + 1, _pageCount], "", "", "",""];
        private _fmsPrintStart = fms_locations_page_index * 4;
        for "_i" from 0 to 3 do {
            if (_fmsPrintStart + _i < count fms_locations_page_list) then {
                _strings set [_i + 1, fms_locations_page_list # (_fmsPrintStart + _i) # 0];
            };
        };
        _strings
    };
    case FMS_PAGE_NAV_LOCATIONS_SEL: {
        if (isNil "fms_locations_selected") exitWith {["", "", "", "",""]};
        private _location = fms_locations_selected;
        private _gridArea = [worldName] call ace_common_fnc_getMGRSdata;
        private _grid = [(locationPosition _location)] call ace_common_fnc_getMapGridFromPos;
        private _direction = round (_vehicle getDir (locationPosition _location));
        private _distance = round ((_vehicle distance (locationPosition _location)) * 0.000539957);
        private _str = format ["%1    %2    %3    %4", _gridArea select 0, _gridArea select 1, _grid select 0, _grid select 1];
        [text _location, _str, format["HDG %1 / %2 NM", _direction, _distance], "", ""]
    };
    default {
        ["", "", "", "",""]
    };
};

fms_locations_page_open = (((getUserMFDValue _vehicle) # _fms) == FMS_PAGE_NAV_LOCATIONS_LIST);

{ // forEach [20, 21, 22, 23,24];
    _vehicle setUserMFDText [_x, _strings # _forEachIndex];
} forEach [20, 21, 22, 23,24];
