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
  class vtx_uh60_Markings {
    control = "combo";
    property = "vtx_attribute_markings";
    displayName = "Engine Cover Markings";
    tooltip = "";
    expression = "_this setObjectTextureGlobal [19, _value];";
    defaultValue = "";
    typeName = "STRING";
    condition = "objectVehicle";
    class Values {
      class None {
        name = "None";
        value = "a3\ui_f\data\IGUI\Cfg\Targeting\Empty_ca.paa";
      };
      class Vanilla {
        name = "7645";
        value = "z\vtx\addons\UH60\Data\Exterior\Markings\Markings_ca.paa";
      };
      class GrimReaper {
        name = "Grim Reaper";
        value = "\z\vtx\addons\uh60_misc\data\markings\markings_grimreaper_ca.paa";
      };
      class GunSlinger {
        name = "Gun Slinger";
        value = "\z\vtx\addons\uh60_misc\data\markings\markings_gunslinger_ca.paa";
      };
      class HeavyMetal {
        name = "Heavy Metal";
        value = "\z\vtx\addons\uh60_misc\data\markings\markings_heavymetal_ca.paa";
      };
      class IronMaiden {
        name = "Iron Maiden";
        value = "\z\vtx\addons\uh60_misc\data\markings\markings_ironmaiden_ca.paa";
      };
      class RazorsEdge {
        name = "Razor's Edge";
        value = "\z\vtx\addons\uh60_misc\data\markings\markings_razorsedge_ca.paa";
      };
      class RudeDude {
        name = "Rude Dude";
        value = "\z\vtx\addons\uh60_misc\data\markings\markings_rudedude_ca.paa";
      };
      class Thrasher {
        name = "Thrasher";
        value = "\z\vtx\addons\uh60_misc\data\markings\markings_thrasher_ca.paa";
      };
      class Thunderstruck {
        name = "Thunderstruck";
        value = "\z\vtx\addons\uh60_misc\data\markings\markings_thunderstruck_ca.paa";
      };
      class Venom {
        name = "Venom";
        value = "\z\vtx\addons\uh60_misc\data\markings\markings_venom_ca.paa";
      };
      class Hatchet {
        name = "Venom";
        value = "\z\vtx\addons\uh60_misc\data\theme\hatchet.paa";
      };
    }; // Values
  }; // vtx_uh60_Markings
}; // Attributes
