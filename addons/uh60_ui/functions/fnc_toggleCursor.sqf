#include "uiDefines.hpp"
/*
 * Author: Ampersand
 * Checks camera view and Zeus state then sets vtx_uh60_ui_isViewInternal for
 * use in vtx_uh60_ui_fnc_perFrame and shows or hides the cursor control
 *
 * Arguments:
 * None
 *
 * Return Value:
 * 0: Drawing Cursor <BOOLEAN>
 *
 * Example:
 * [] call vtx_uh60_ui_fnc_toggleCursor
 *
 * Public: No
 */

vtx_uh60_ui_isViewInternal = cameraView == "INTERNAL" && {isNull curatorCamera};
CTRL(4001120) ctrlShow vtx_uh60_ui_isViewInternal;

vtx_uh60_ui_isViewInternal
