class CfgWeapons {
  class ACE_ItemCore;
  class CBA_MiscItem_ItemInfo;

  class GVAR(item): ACE_ItemCore {
    author = "Ampersand";
    scope = 2;
    displayName = "$STR_A3_CfgVehicles_Land_Stretcher_01_f0"; // Stretcher
    //descriptionShort = CSTRING(bananaDescr);
    model = "\A3\Props_F_Orange\Humanitarian\Camps\Stretcher_01_folded_F.p3d";
    picture = QPATHTOF(data\ui\stretcher_ca.paa);
    icon = QPATHTOF(data\ui\stretcher_icon.paa);
    mapSize = 0.5;
    class ItemInfo: CBA_MiscItem_ItemInfo {
        mass = 150;
    };
  };
};
