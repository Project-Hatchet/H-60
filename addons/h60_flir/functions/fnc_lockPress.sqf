#include "script_component.hpp"
/*
 * hct_h60_flir_fnc_lockPress
 *
 * One press of the FLIR lock key (vehLockTurretView), from whichever input path saw it.
 * Up to four paths report the same press, depending on the view and the device:
 *  - the user-action event (cockpit and PiP; HOTAS bindings, which skip display hooks),
 *  - the display KeyDown/MouseButtonDown hooks in the native gunner view (initKeybinds),
 *  - the same hooks in the scripted fullscreen camera (fnc_scriptedCamera),
 *  - the per-frame poll in the scripted camera (fnc_handleKeyInputs).
 * The lock is a toggle, so two of them on one press locked and released at once. They
 * all come here, and only the first within the debounce window acts.
 *
 * Arguments:
 * As hct_h60_flir_fnc_setStabilization: [] for the pilot camera's own ray, or
 * [camera position ASL, a point along the view ray ASL] for the scripted camera
 *
 * Return Value:
 * True if this press acted
 *
 * Example:
 * [] call hct_h60_flir_fnc_lockPress
 */
#define DEBOUNCE 0.3

if (diag_tickTime < (missionNamespace getVariable ["hct_h60_flir_lockPressNext", 0])) exitWith {false};
hct_h60_flir_lockPressNext = diag_tickTime + DEBOUNCE;
_this call hct_h60_flir_fnc_setStabilization;
true
