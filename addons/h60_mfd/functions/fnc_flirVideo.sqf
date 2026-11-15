#include "..\script_component.hpp"
/*
 * hct_h60_mfd_fnc_flirVideo
 *
 * The FLIR and sling-camera feed on the MFDs, at the right aspect on any monitor.
 * Arma renders the feed camera at the monitor's aspect; put straight on the 4:3 MFD
 * face as a render target it was squeezed into the screen (about 1.3x on 16:9,
 * 2.7x on 32:9). The face instead shows a ui() display (config flirVideo.hpp) whose
 * picture is laid out from this client's own aspect and cropped to the screen, so
 * every crew member sees an undistorted image whatever their monitor.
 *
 * Arguments:
 * 0: Mode <STRING>
 *    "texture" - the texture for an MFD overlay face (hct_h60_mfd_fnc_switchPage)
 *    "onLoad"  - the display's config onLoad: registers it and starts its redraw
 *    "layout"  - places the picture for the current screen aspect
 * 1: [display] for "onLoad" and "layout" <ARRAY>
 *
 * Return Value:
 * The texture for "texture", else nothing
 *
 * Example:
 * _vehicle setObjectTexture [_selection, ["texture"] call hct_h60_mfd_fnc_flirVideo]
 */
#define FACE_ASPECT (4 / 3) // the MFD screen face, width : height (the TAC cursor maths uses the same 4:3)

params [["_mode", "", [""]], ["_args", []]];

switch (_mode) do {
    case "texture": {
        // measured here, outside the ui() display, whose screen commands describe its own texture
        GVAR(screenAspect) = (safeZoneW / pixelW) / (safeZoneH / pixelH);
        "#(rgb,1024,1024,1)ui(hct_h60_mfd_flirVideo,hct_h60_mfd_flirVideo)"
    };
    case "onLoad": {
        _args params ["_display"];
        ["layout", [_display]] call FUNC(flirVideo);
        // A ui() display is not redrawn by itself: redraw it each frame while a feed camera
        // runs, and lay it out again if the screen's aspect changed (fnc_perFrame measures it)
        private _pfh = [{
            params ["_args", "_handle"];
            _args params ["_display"];
            if (isNull _display) exitWith {[_handle] call CBA_fnc_removePerFrameHandler};
            if (isNil "hct_h60_flir_camera" && {isNil "hct_h60_mfd_slingCam"}) exitWith {};
            if ((_display getVariable [QGVAR(flirVideoAspect), 0]) != (missionNamespace getVariable [QGVAR(screenAspect), 16 / 9])) then {
                ["layout", [_display]] call FUNC(flirVideo);
            };
            displayUpdate _display;
        }, 0, [_display]] call CBA_fnc_addPerFrameHandler;
        _display setVariable [QGVAR(flirVideoPfh), _pfh];
        _display displayAddEventHandler ["Unload", {
            params ["_display"];
            [_display getVariable [QGVAR(flirVideoPfh), -1]] call CBA_fnc_removePerFrameHandler;
        }];
    };
    case "layout": {
        _args params ["_display"];
        private _aspect = missionNamespace getVariable [QGVAR(screenAspect), 16 / 9];
        _display setVariable [QGVAR(flirVideoAspect), _aspect];
        // The render target at the screen's aspect. A render target is square whatever size it
        // is given, so it grows by the power of two nearest that aspect to keep its texels from
        // stretching across the wide image (the AH-64's fza_ihadss_fnc_r2tTexture)
        private _size = 512 * 2 ^ (round (ln _aspect / ln 2) max 0);
        private _picture = (_display displayCtrl 100) controlsGroupCtrl 101;
        _picture ctrlSetText format ["#(argb,%1,%1,1)r2t(hct_h60_flir_feed,%2)", round _size, _aspect];
        // Fill the face and crop what overflows (the group clips it): an image wider than the
        // 4:3 screen loses its sides, a narrower one its top and bottom
        private _w = 1;
        private _h = 1;
        if (_aspect >= FACE_ASPECT) then {_w = _aspect / FACE_ASPECT} else {_h = FACE_ASPECT / _aspect};
        _picture ctrlSetPosition [(1 - _w) / 2, (1 - _h) / 2, _w, _h];
        _picture ctrlCommit 0;
    };
};
