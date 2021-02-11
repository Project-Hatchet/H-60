params ["_vehicle", "_tanker", "_basket", "_rope"];
_basket setVariable ["vtx_aar_attached", false];
detach _basket;
_basket attachTo [_tanker, _basket getVariable "vtx_aar_attachPos"];
ropeUnwind [_rope, 1, 15];
