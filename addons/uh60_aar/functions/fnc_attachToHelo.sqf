params ["_vehicle", "_tanker", "_basket", "_rope"];
_basket setVariable ["vtx_aar_attached", true];
_basket attachTo [_vehicle, (_vehicle getVariable ["vtx_aar_probePos",[0,0,0]])];
_basket setDir 0;
[_basket, [0,0,0], [0,1,0]] ropeAttachTo _rope;
_tanker setVariable ["vtx_aar_rope", _rope, true];
