/*
 * vtx_uh60_jvmf_fnc_perSecond
 *
 * Handles per second updates
 *
 */
params ["_vehicle"];

_this call vtx_uh60_jvmf_fnc_drawJVMF;

// ctab stuff
if (isNil "cTab_userMarkerLists") exitWith {}; // ctab markers present
private _bluforMarkers = [cTab_userMarkerLists,call cTab_fnc_getPlayerEncryptionKey,[]] call cTab_fnc_getFromPairs;

{
	private _id = _x # 0;
	if (vtx_uh60_jvmf_importedCtabMarkersList find _id == -1) then { // import
		private _jvmfMessage = _x call vtx_uh60_jvmf_fnc_ctabToJvmf;
		_jvmfMessage call vtx_uh60_jvmf_fnc_receiveMessage;
		vtx_uh60_jvmf_importedCtabMarkersList pushBack _id;
	};
} forEach _bluforMarkers;