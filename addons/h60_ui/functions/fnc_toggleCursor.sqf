#include "uiDefines.hpp"
/*
 * Author: Ampersand
 * Checks camera view and Zeus state then sets hct_h60_ui_isViewInternal for
 * use in hct_h60_ui_fnc_perFrame and shows or hides the cursor control
 *
 * Arguments:
 * None
 *
 * Return Value:
 * 0: Drawing Cursor <BOOLEAN>
 *
 * Example:
 * [] call hct_h60_ui_fnc_toggleCursor
 *
 * Public: No
 */

hct_h60_ui_isViewInternal = cameraView == "INTERNAL" && {isNull curatorCamera};
CTRL(4001120) ctrlShow hct_h60_ui_isViewInternal;

hct_h60_ui_isViewInternal
