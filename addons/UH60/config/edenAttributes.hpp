class Attributes: Attributes {
  class ace_fastroping_equipFRIES {
    condition = "objectVehicle";
    control = "Checkbox";
    defaultValue = "(false)";
    displayName = "Equip helicopter with FRIES";
    expression = "if (_value) then {[_this] call ace_fastroping_fnc_equipFRIES}";
    property = "ace_fastroping_equipFRIES";
    tooltip = "Equips the selected helicopter with a Fast Rope Insertion Extraction System";
    typeName = "BOOL";
  };
  class vtx_uh60_DoorNumbers {
    displayName = "Door Numbers";
    tooltip = "2-digit number marked with white tape in the aft windows of the doors. Enter SPACE for blank.";
    property = "vtx_attribute_doorNumbers";
    control = "EditShort";
    expression = "[_this, _value] call vtx_uh60_misc_fnc_setDoorNumbers;";
    defaultValue = "None";
    condition = "objectVehicle";
  };
};
