params ["_box"];
[_box, true] call ace_arsenal_fnc_initBox;
_box addAction ["<t color='#89f3ff'>ACE Arsenal</t>", {[_this # 0, player, true] call ace_arsenal_fnc_openBox}, nil, 1.5, true, true, "", "_target distance _this < 10"];
_box addAction ["Set Callsign", { 
    ["Set Callsign",[
        ["EDIT", "Callsign", groupID group player]
    ],{
        params ["_values"];   
        _values params ["_groupID"];   
        group player setGroupIdGlobal [_groupID];  
    }] call zen_dialog_fnc_create;  
}, nil, 1.5, false, true, "", "_this == leader _this"];