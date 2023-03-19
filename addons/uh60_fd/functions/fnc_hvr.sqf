params ["_vehicle", "_frameTime"];
if (!isAutoHoverOn _vehicle) then {
  player action ["AutoHover", _vehicle];
};