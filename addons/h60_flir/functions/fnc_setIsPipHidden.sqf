/*
 * Author: Ampersand
 * Set vtx_uh60_flir_isPipHidden for faster perFrame
 *
 * Arguments:
 * NONE
 *
 * Return Value:
 * 0: New Effect <ARRAY>
 *
 * Example:
 * call vtx_uh60_flir_fnc_setIsPipHidden
 */

vtx_uh60_flir_isPipHidden = isNil "vtx_uh60_flir_camera" ||
  {cameraView isNotEqualTo "INTERNAL"} ||
  {vtx_uh60_flir_isVisibleMap} ||
  {vtx_uh60_flir_featureCamera != ""} ||
  {!isNull curatorCamera}
