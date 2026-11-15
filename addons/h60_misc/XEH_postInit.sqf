#include "script_component.hpp"

private _action = [
    "hct_h60_attach",
    (localize "STR_hct_h60_misc_AttachToBlackhawk"),
    "",
    {[_target] call hct_h60_misc_fnc_attachCRRC;},
    {(count (nearestObjects [_target, [QBASE_CLASS], 10])) > 0}
] call ace_interact_menu_fnc_createAction;
["Rubber_duck_base_F",0,["ACE_MainActions"],_action, true] call ace_interact_menu_fnc_addActionToClass;

private _doorOpenLeft = [
 "hct_h60_cabinDoorLeft", // * 0: Action name <STRING>
 (localize "STR_hct_h60_misc_OpenCloseCabinDoor"),  // * 1: Name of the action shown in the menu <STRING>
 "", // * 2: Icon <STRING>
 {
   private _anim = _target animationPhase "cabinDoor_L";
   _target animateSource ["cabinDoor_L", 1 - _anim];
   playSound3D ["z\vtx\addons\H60_SFX\Sounds\Share\Door.wss", _target, false, getPosASLVisual _target, 3];

   // * Set Internal Wind-washing sound and lock state
   private _state = ["Closed", "Open"] select _anim;
   [_target, "CabinDoor_L", _state] call hct_h60_misc_fnc_interactedCabinDoor;
 }, // * 3: Statement <CODE>
 {private _animPhase = _target animationPhase "cabinDoor_L";
 [_target, "cabinDoor_L", _animPhase] call hct_h60_misc_fnc_canInteractCabinDoor;}, // * 4: Condition <CODE>
 nil, // * 5: Insert children code <CODE> (Optional)
 [], // * 6: Action parameters <ANY> (Optional)
 {_target selectionPosition "cabindoor_L_handle"}, // * 7: Position (Position array, Position code or Selection Name) <ARRAY>, <CODE> or <STRING> (Optional)
 2, // * 8: Distance <NUMBER> (Optional)
 [false,false,false,false,false], // * 9: Other parameters [showDisabled,enableInside,canCollapse,runOnHover,doNotCheckLOS] <ARRAY> (Optional)
 {} // * 10: Modifier function <CODE> (Optional)
];
private _doorOpenRight = [
  "hct_h60_cabinDoorRight",
  (localize "STR_hct_h60_misc_OpenCloseCabinDoor"),
  "",
  {
    private _anim = _target animationPhase "cabinDoor_R";
    _target animateSource ["cabinDoor_R", 1 - _anim];
    playSound3D ["z\vtx\addons\H60_SFX\Sounds\Share\Door.wss", _target, false, getPosASLVisual _target, 3];

    // * Set Internal Wind-washing sound and lock state
    private _state = ["Closed", "Open"] select _anim;
    [_target, "CabinDoor_R", _state] call hct_h60_misc_fnc_interactedCabinDoor;
  },
  {private _animPhase = _target animationPhase "cabinDoor_R";
 [_target, "cabinDoor_R", _animPhase] call hct_h60_misc_fnc_canInteractCabinDoor;},
  nil,
  [],
  {_target selectionPosition "cabindoor_R_handle"},
  2,
  [false,false,false,false,false],
  {}
];

private _doorOpenRightCpt = ["hct_h60_cptDoorRight", (localize "STR_hct_h60_misc_OpenCloseCockpitDoor"), "", {
  private _condition = (_target doorPhase "Door_RF") > 0;
  _target animateDoor ["Door_RF", [1,0] select _condition];
  playSound3D [
    ["z\vtx\addons\H60_SFX\Sounds\Share\CptDoor_Open.wss","z\vtx\addons\H60_SFX\Sounds\Share\CptDoor_Close.wss"] select _condition,
    _target,
    false,
    _target modelToWorldVisualWorld (_target selectionPosition "cockpitdoor_right"),
    3
  ];
  // * Set Internal Wind-washing sound
  [[_target, "CustomSoundController8", ((1 - (_target animationSourcePhase 'Door_RF')) + (_target animationSourcePhase 'Door_LF')) / 2]] remoteExecCall ["setCustomSoundController", crew _target];

}, {true}, nil, [], {_target selectionPosition "cockpitdoor_right"}, 2, [false,false,false,false,false], {} ];
private _doorOpenLeftCpt = ["hct_h60_cptDoorLeft", (localize "STR_hct_h60_misc_OpenCloseCockpitDoor"), "", {
  private _condition = (_target doorPhase "Door_LF") > 0;
  _target animateDoor ["Door_LF", [1,0] select _condition];
  playSound3D [
    ["z\vtx\addons\H60_SFX\Sounds\Share\CptDoor_Open.wss","z\vtx\addons\H60_SFX\Sounds\Share\CptDoor_Close.wss"] select _condition,
    _target,
    false,
    _target modelToWorldVisualWorld (_target selectionPosition "cockpitdoor_left"),
    3
  ];
  // * Set Internal Wind-washing sound
  [[_target, "CustomSoundController8", ((_target animationSourcePhase 'Door_RF') + (1 - (_target animationSourcePhase 'Door_LF'))) / 2]] remoteExecCall ["setCustomSoundController", crew _target];

}, {true}, nil, [], {_target selectionPosition "cockpitdoor_left"}, 2, [false,false,false,false,false], {} ];

{
    [QBASE_CLASS,0,[],(_x call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
} forEach [_doorOpenLeft, _doorOpenRight, _doorOpenRightCpt, _doorOpenLeftCpt];

_digitOptionsCode = {
    params ["_target", "_player", "_params"];
    _params params ["_first", "_second"];
    private _returns = [];
    for "_i" from 0 to 9 do {
        private _statement = {
            params ["_target", "_player", "_params"];
            _target setObjectTextureGlobal [_params # 1, format ["\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_%1_ca.paa", _params # 0]];
            _target setObjectTextureGlobal [_params # 2, format ["\z\vtx\addons\uh60_misc\data\VTX_Door_Numbers\Num_%1_ca.paa", _params # 0]];
        };
        private _action = ["hct_h60_firstNumber", format [(localize "STR_hct_h60_misc_SetTo"), _i], "", _statement, {true}, nil, [_i, _first, _second], {}, 2] call ace_interact_menu_fnc_createAction;
        _returns pushBack [_action, [], _target]
    };
    _returns
};

hct_h60_markings_options = ("true" configClasses (configFile >> "CfgVehicles" >> QBASE_CLASS >> "Attributes" >> "hct_h60_Markings" >> "values")) apply {[getText (_x >> "name"), getText (_x >> "value")]};
_markingsOptions = {
    params ["_target", "_player", "_params"];
    hct_h60_markings_options apply {
        _x params ["_name", "_path"];
        private _action = [_name, _name, "", {_target setObjectTextureGlobal [19, _this # 2]}, {true}, {}, _path] call ace_interact_menu_fnc_createAction;
        [_action, [], _target]
    }
};
private _editMarkingsLeft = ["hct_h60_editMarkingsLeft", (localize "STR_hct_h60_misc_ChangeMarkings"), "", {}, {!(_target getVariable ["hct_autostarted", false])}, _markingsOptions, [], {[-1,1,0.5]}, 2];
private _editMarkingsRight = ["hct_h60_editMarkingsRight", (localize "STR_hct_h60_misc_ChangeMarkings"), "", {}, {!(_target getVariable ["hct_autostarted", false])}, _markingsOptions, [], {[1,1,0.5]}, 2];
[QBASE_CLASS,0,[],(_editMarkingsLeft call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
[QBASE_CLASS,0,[],(_editMarkingsRight call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;

private _editNumbersLeftFirst = ["hct_h60_paintNumbersLeftFirst" + (str random 1), (localize "STR_hct_h60_misc_ChangeNumberTape"), "", {}, {true}, _digitOptionsCode, [21,23], {(_target selectionPosition "cabindoor_L_handle") vectorAdd [0,-1.2,0.5]}, 1.5];
private _editNumbersRightFirst = ["hct_h60_paintNumbersRightFirst" + (str random 1), (localize "STR_hct_h60_misc_ChangeNumberTape"), "", {}, {true}, _digitOptionsCode, [20,22], {(_target selectionPosition "cabindoor_R_handle") vectorAdd [0,-1.2,0.5]}, 1.5];
private _editNumbersLeft = ["hct_h60_paintNumbersLeft" + (str random 1), (localize "STR_hct_h60_misc_ChangeNumberTape"), "", {}, {true}, _digitOptionsCode, [20,22], {(_target selectionPosition "cabindoor_L_handle") vectorAdd [0,-0.9,0.5]}, 1.5];
private _editNumbersRight = ["hct_h60_paintNumbersRight" + (str random 1), (localize "STR_hct_h60_misc_ChangeNumberTape"), "", {}, {true}, _digitOptionsCode, [21,23], {(_target selectionPosition "cabindoor_R_handle") vectorAdd [0,-0.9,0.5]}, 1.5];
[QBASE_CLASS,0,[],(_editNumbersLeftFirst call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
[QBASE_CLASS,0,[],(_editNumbersRightFirst call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
[QBASE_CLASS,0,[],(_editNumbersLeft call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
[QBASE_CLASS,0,[],(_editNumbersRight call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;

#define CUSTOMIZATION_ACTION_TIME 5
#define WRAP_PROGRESS(FNC) { \
	params ["_target", "_player", "_params"]; \
	[CUSTOMIZATION_ACTION_TIME, [_target, _player, _params], { \
		params ["_args"]; \
		_args params ["_target", "_player", "_params"]; \
		[_target, _player, _params] call FNC; \
	}] call ace_common_fnc_progressBar; \
}

private _customizationOptions = [
	["hct_fuelprobe", (localize "STR_hct_h60_misc_FuelProbe"), ["hct_fuelProbe", "fuelProbe_show", 1, 0, 7], {[1.3,4.1,-1.2]}],
	["hct_hoist", (localize "STR_hct_h60_misc_RescueHoist"), ["hct_hoist", "Hoist_hide", 0, 1, 3], {[1.1,1.9,0.35]}],
	["hct_cockpitdoors", (localize "STR_hct_h60_misc_CockpitDoors"), ["hct_cockpitdoors", "Cockpitdoors_Hide", 0, 1, 3], {[1.1,5.1,-0.7]}]
];

{
	_x params ["_className", "_description", "_addParams", "_position", ["_range", 2]];
	private _addOption = [
		(_className + "_attach"),
		format [(localize "STR_hct_h60_misc_AttachPart"), _description],
		"",
		WRAP_PROGRESS(hct_h60_misc_fnc_addCustomization),
		hct_h60_misc_fnc_canCustomizeVariant,
		nil,
		_addParams,
		_position,
		_range,
		[false,false,false,false,false],
		{}
	];
	private _removeOption = [
		(_className + "_remove"),
		format [(localize "STR_hct_h60_misc_RemovePart"), _description],
		"",
		WRAP_PROGRESS(hct_h60_misc_fnc_removeCustomization),
		hct_h60_misc_fnc_canRemoveCustomization, nil, _addParams, _position, _range, [false,false,false,false,false], {}
	];
	[QBASE_CLASS,0,[],(_addOption call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
	[QBASE_CLASS,0,[],(_removeOption call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
} forEach _customizationOptions;

// MH-60 only - not offered on the UH-60
private _erfsAddParams = ["hct_erfs", "ERFS_show", 1, 0, 3];
private _erfsPosition = {[-0.046875,0.672591,-0.272467]};
private _erfsAddOption = [
	"hct_erfs_attach",
	(localize "STR_hct_h60_misc_AttachERFSTank"),
	"",
	{
		params ["_target", "_player", "_params"];
		[CUSTOMIZATION_ACTION_TIME, [_target, _player, _params], {
			params ["_args"];
			_args params ["_target", "_player", "_params"];
			[_target, _player, _params] call hct_h60_misc_fnc_addCustomization;
			_target animateSource ["CabinSeats_3_Hide", 1];
			{ _target lockCargo [_x, true] } forEach [0, 1, 2, 3];
		}] call ace_common_fnc_progressBar;
	},
	hct_h60_misc_fnc_canCustomizeVariant,
	nil,
	_erfsAddParams,
	_erfsPosition,
	4.5,
	[false,false,false,false,false],
	{}
];
private _erfsRemoveOption = [
	"hct_erfs_remove",
	(localize "STR_hct_h60_misc_RemoveERFSTank"),
	"",
	WRAP_PROGRESS(hct_h60_misc_fnc_removeCustomization),
	hct_h60_misc_fnc_canRemoveCustomization,
	nil,
	_erfsAddParams,
	_erfsPosition,
	4.5,
	[false,false,false,false,false],
	{}
];
// DAPs included (Riverman ruling 2026-09-20): they spawn ERFS-fitted (#626)
// but crews may strip/refit the tanks like on the base M; the conditions
// (toolkit + nearby tank + ERFS_show phase) are class-agnostic already
{
	[_x,0,[],(_erfsAddOption call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
	[_x,0,[],(_erfsRemoveOption call ace_interact_menu_fnc_createAction), true] call ace_interact_menu_fnc_addActionToClass;
} forEach (["erfsService"] call hct_h60_main_fnc_getTraitClasses);

["ace_dragging_startedCarry", {
	params ["_unit", "_target"];
	if (_target isKindOf "hct_erfs") then {
		_target disableCollisionWith _unit;
	};
}] call CBA_fnc_addEventHandler;

["ace_dragging_stoppedCarry", {
	params ["_unit", "_target"];
	if (_target isKindOf "hct_erfs") then {
		_target enableCollisionWith _unit;
	};
}] call CBA_fnc_addEventHandler;

_action = ["hct_skis_add",(localize "STR_hct_h60_misc_InstallSkis"), "", {(_target) animateSource ["skis_show", 1];}, {((_target) animationSourcePhase "skis_show") < 0.1}, nil, [parameters], [1.33319,2.8541,-1.6735]] call ace_interact_menu_fnc_createAction;
[QBASE_CLASS, 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;
_action = ["hct_skis_remove",(localize "STR_hct_h60_misc_UninstallSkis"), "", {(_target) animateSource ["skis_show", 0];}, {((_target) animationSourcePhase "skis_show") > 0.9}, nil, [parameters], [1.33319,2.8541,-1.6735]] call ace_interact_menu_fnc_createAction;
[QBASE_CLASS, 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;

private _modifierFunc = {
  params ["_target", "_player", "_params", "_actionData"];
  if ([_target, ACE_player] call hct_h60_misc_fnc_canUnfold) then {

    _actionData set [1, (localize "STR_hct_h60_misc_Unfold")];
    _actionData set [3, {[_target, 0] call hct_h60_misc_fnc_fold;}];
  };
};
_action = ["hct_fold_blades", (localize "STR_hct_h60_misc_Fold"), "", {[_target, 1] call hct_h60_misc_fnc_fold;}, {[_target, ACE_player] call hct_h60_misc_fnc_canFold}, nil, [], "velka osa", 3, [false, false, false, false, false], _modifierFunc] call ace_interact_menu_fnc_createAction;
[QBASE_CLASS, 0, [], _action, true] call ace_interact_menu_fnc_addActionToClass;

// DAP crew-chief Turn In / Turn Out (the aft MFOS turn-out replacement,
// Riverman rulings 2026-09-17/18): CONTEXTUAL entries in the VEHICLE menu -
// vehicle-class self actions at the ACE_SelfActions root, which is the same
// tree ACE's own "Change Seats" lives in, so the entry shows up beside it,
// not under it and not in the soldier's personal self-interact menu. The
// direction filter in the condition means exactly one of the two labels
// ("Turn Out" / "Turn In") is visible at a time.
{
  private _turnOut = [
    "hct_ccTurnOut", (localize "STR_hct_h60_misc_TurnOut"), "",
    {[_player, false, "out"] call hct_h60_misc_fnc_ccSwap;},
    {[_player, true, "out"] call hct_h60_misc_fnc_ccSwap;}
  ] call ace_interact_menu_fnc_createAction;
  private _turnIn = [
    "hct_ccTurnIn", (localize "STR_hct_h60_misc_TurnIn"), "",
    {[_player, false, "in"] call hct_h60_misc_fnc_ccSwap;},
    {[_player, true, "in"] call hct_h60_misc_fnc_ccSwap;}
  ] call ace_interact_menu_fnc_createAction;
  [_x, 1, ["ACE_SelfActions"], _turnOut, true] call ace_interact_menu_fnc_addActionToClass;
  [_x, 1, ["ACE_SelfActions"], _turnIn, true] call ace_interact_menu_fnc_addActionToClass;
} forEach (["crewChiefTurnOut"] call hct_h60_main_fnc_getTraitClasses);

// The turned-out spots are swap-only: locked where the vehicle is local, so
// they never appear in the door get-in menu, the scroll-wheel seat change,
// or ACE's Change Seats list (ACE skips lockedTurret seats). Event is "init",
// NOT "initPost": CBA only applies "initPost" retroactively after postInit
// has FINISHED (fnc_addClassEventHandler exits early on it), and this
// registration runs during postInit - with "initPost" no Eden-placed DAP
// ever got locked (test-fit 4, seats visible in every menu). The GetIn hook
// covers the stale-menu case from test-fit 5: a unit crewed in at mission
// start builds its action list before/at the init lock and only a lock
// TRANSITION refreshes it, so every boarding re-toggles the locks (see
// fnc_ccLockSeats). fnc_ccSwap unlocks the target for the one scripted
// move, then relocks.
{
  // init: PLAIN lock immediately (a toggle here leaves the seats unlocked at
  // mission start - the next-frame relock doesn't fire reliably in the init
  // window; field-tested 2026-09-20, turned-out seats were enterable until
  // the first get-out), then a delayed toggle at +1s for the menu rebuild
  // (the first ACE action-list build only refreshes on a lock TRANSITION -
  // the "Door Left 1 unreachable until a crew cycle" report)
  [_x, "init", {
    params ["_veh"];
    if (!local _veh) exitWith {};
    [_veh] call hct_h60_misc_fnc_ccLockSeats;
    [{_this call hct_h60_misc_fnc_ccLockSeats}, [_veh, true], 1] call CBA_fnc_waitAndExecute;
  }, true, [], true] call CBA_fnc_addClassEventHandler;
  [_x, "GetIn", {
    params ["_veh"];
    if (!local _veh) exitWith {};
    [_veh, true] call hct_h60_misc_fnc_ccLockSeats;
  }, true, [], true] call CBA_fnc_addClassEventHandler;
  // GetOut keeps the reserved-seat rule honest: a crew chief who dismounts
  // entirely from the turned-out spot (instead of turning back in) frees
  // their crew-chief seat on the reconcile
  [_x, "GetOut", {
    params ["_veh"];
    if (!local _veh) exitWith {};
    [_veh, true] call hct_h60_misc_fnc_ccLockSeats;
  }, true, [], true] call CBA_fnc_addClassEventHandler;
} forEach (["crewChiefTurnOut"] call hct_h60_main_fnc_getTraitClasses);
