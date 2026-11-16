/*
 * Author: Ampersand
 * Set hct_h60_flir_isPipHidden for faster perFrame
 *
 * Arguments:
 * NONE
 *
 * Return Value:
 * 0: New Effect <ARRAY>
 *
 * Example:
 * call hct_h60_flir_fnc_setIsPipHidden
 */

hct_h60_flir_isPipHidden = isNil "hct_h60_flir_camera" ||
  {cameraView isNotEqualTo "INTERNAL"} ||
  {hct_h60_flir_isVisibleMap} ||
  {hct_h60_flir_featureCamera != ""} ||
  {!isNull curatorCamera}
