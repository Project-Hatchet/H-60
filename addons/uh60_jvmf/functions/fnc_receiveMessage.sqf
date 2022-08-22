/*
 * vtx_uh60_jvmf_fnc_receiveMessage
 *
 * Receive a message and store it
 */

VTX_JVMF_MESSAGES pushBack _this;

params ["_ID", "_sender", "_recipient", "_type", "_text", "_data", "_replies"];
// switch (_type) do {
//     case 2: {
// 		_data params ["_name", "_position"];
//         [
//             _name,
//             _position,
//             ""
//         ] call vtx_uh60_fms_fnc_addWaypoint;
//     };
// };

if ((_replies # 0 # 3) != player) then {
	[vehicle player,"NEW JVMF MSG",{},false,false] call vtx_uh60_cas_fnc_registerCautionAdvisory;
};
[vehicle player] call vtx_uh60_jvmf_fnc_drawJVMF;