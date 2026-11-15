class Attributes: Attributes {
  class ace_fastroping_equipFRIES {
    condition = "objectVehicle";
    control = "Checkbox";
    defaultValue = "(false)";
    displayName = "$STR_hct_h60_config_EquipHelicopterWithFRIES";
    expression = "if (_value) then {[_this] call ace_fastroping_fnc_equipFRIES}";
    property = "ace_fastroping_equipFRIES";
    tooltip = "$STR_hct_h60_config_EquipsTheSelectedHelicopterWithAFastRopeInsertio";
    typeName = "BOOL";
  };
  class hct_h60_DoorNumbers {
    displayName = "$STR_hct_h60_config_DoorNumbers";
    tooltip = "$STR_hct_h60_config_N2DigitNumberMarkedWithWhiteTapeInTheAftWindowsOf";
    property = "vtx_attribute_doorNumbers";
    control = "EditShort";
    expression = "[_this, _value] call hct_h60_misc_fnc_setDoorNumbers;";
    defaultValue = "None";
    condition = "objectVehicle";
  };
  class hct_h60_Markings {
    control = "combo";
    property = "vtx_attribute_markings";
    displayName = "$STR_hct_h60_config_EngineCoverMarkings";
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
      class Student {
        name = "Student Driver";
        value = "\z\vtx\addons\uh60_misc\data\markings\markings_studentdriver.paa";
      };
      // class Hatchet {
      //   name = "Hatchet";
      //   value = "\z\vtx\addons\uh60_misc\data\theme\hatchet.paa";
      // };
    }; // Values
  }; // hct_h60_Markings
  class hct_h60_FoldRotorBlades {
    condition = "objectVehicle";
    control = "Checkbox";
    defaultValue = "(false)";
    displayName = "$STR_hct_h60_config_FoldRotorBlades";
    expression = "[_this, parseNumber _value, true] call hct_h60_misc_fnc_fold;";
    property = "vtx_uh60_FoldRotorBlades";
    tooltip = "$STR_hct_h60_config_FoldTheRotorBladesToReduceFootprint";
    typeName = "BOOL";
  };
  class hct_h60_RemoveFuelProbe {
    condition = "objectVehicle";
    control = "Checkbox";
    defaultValue = "(false)";
    displayName = "$STR_hct_h60_config_RemoveFuelProbe";
    expression = "_this animateSource ['FuelProbe_show', [getNumber (configOf _this >> 'AnimationSources' >> 'FuelProbe_show' >> 'initPhase'), 0] select _value, true];";
    property = "vtx_uh60_RemoveFuelProbe";
    tooltip = "$STR_hct_h60_config_RemoveTheFuelProbe";
    typeName = "BOOL";
  };
}; // Attributes
