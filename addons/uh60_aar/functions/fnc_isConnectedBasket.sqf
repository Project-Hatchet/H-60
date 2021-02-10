/*
 * vtx_uh60_aar_fnc_isConnectedBasket
 */
params ["_vehicle", "_tanker", "_basket", "_rope"];
private _connected = false;
private _probePosModel = (_vehicle getVariable ["vtx_aar_probePos",[0,0,0]]);
private _ropePosModel = (_basket getVariable ["vtx_aar_ropeOrigin",[0,0,0]]);
private _probePos = _vehicle modelToWorldVisualWorld _probePosModel;
private _ropeEndPos = AGLtoASL ((ropeEndPosition _rope) # 1);
private _diff = (getPosASLVisual _tanker) vectordiff (getPosASL _tanker);
private _ropeEndPosPhysx = _ropeEndPos vectorAdd _diff;
private _vectDiff = acos ((vectorDir _vehicle) vectorDotProduct (vectorDir _tanker));
private _speedDiff = (vectorMagnitude velocity _vehicle) - (vectorMagnitude velocity _tanker);
private _distance = _ropeEndPosPhysx distance _probePos;
private _vectDiffToProbe = acos ((vectorDir _tanker) vectorDotProduct (_probePos vectorFromTo _ropeEndPosPhysx));

private _modelSpaceDiff = _probePosModel vectordiff (_vehicle worldToModelVisual _ropeEndPosPhysx);
private _forwardDist = -(_modelSpaceDiff # 1);


if (_vectDiffToProbe < 45 && _speedDiff > 0 && _distance < vtx_uh60_aar_basketSize) then { vtx_uh60_aar_enteredBasket = true; };
if (_distance > vtx_uh60_aar_basketSize) then { vtx_uh60_aar_enteredBasket = false; };
(_forwardDist < 0.1 && vtx_uh60_aar_enteredBasket);
