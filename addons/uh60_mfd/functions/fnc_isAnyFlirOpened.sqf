/*
 * Author: Ampersand
 * Checks if any MFD is on the FLIR page
 *
 * Arguments:
 * NONE
 *
 * Return Value:
 * 0: FLIR on any MFD <BOOLEAN>
 *
 * Example:
 * [] call vtx_uh60_mfd_fnc_isAnyFlirOpened
 */

#include "..\config\mfdDefines.hpp"

scopeName "main";

{
 if ((getUserMFDValue hatchet_vehicle) # _x > MFD_PAGE_FLIR - 0.99 && (getUserMFDValue hatchet_vehicle) # _x < MFD_PAGE_FLIR + 0.99) then {
   true breakOut "main";
 };
} count [MFD_1_PAGE_INDEX, MFD_2_PAGE_INDEX, MFD_3_PAGE_INDEX, MFD_4_PAGE_INDEX];

false
