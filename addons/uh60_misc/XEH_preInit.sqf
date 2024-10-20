#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// private _mh60 = "vtx_MH60S" createVehicle [0,0,0];
// deleteVehicle _mh60;
// ["vtx_uh60m", "vtx_HH60", "vtx_MH60M", ""]

// diag_log str ["STARTING PRE-LOADING of H-60", systemTime];
// {
// 	diag_log str ["LOADING", _x];
// 	private _veh = _x createVehicleLocal [0,0,0];
// 	deleteVehicle _veh;
// } forEach ["VTX_UH60M", "VTX_MH60M", "vtx_MH60M_DAP", "vtx_MH60M_DAP_MLASS"];
// diag_log str ["FINISHED PRE-LOADING of H-60", systemTime];

ADDON = true;
