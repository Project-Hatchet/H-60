class B_Soldier_base_F;                                         // For inheritance to work, the base class has to be defined.
class vtx_uh60_doorgunner: B_Soldier_base_F             // Define of a new class, which parameters are inherited from B_Soldier_base_F, with exception of those defined below.
{
 scope = 2;                                                    // 2 = class is available in the editor; 1 = class is unavailable in the editor, but can be accessed via a macro; 0 = class is unavailable (and used for inheritance only).
 identityTypes[] =    {"LanguageENG_F","Head_NATO","G_NATO_default"};                // Identity Types are explained in the Headgear section of this guide.
 displayName = "Crew Chief";                // The name of the soldier, which is displayed in the editor.
 backpack = "";                // Which backpack the character is wearing.
 weapons[] = {"arifle_Mk20_F", "hgun_P07_khk_F", "Throw", "Put"};                             // Which weapons the character has.
 respawnWeapons[] = {"arifle_Mk20_F", "hgun_P07_khk_F", "Throw", "Put"};                // Which weapons the character respawns with.
 Items[] = {"FirstAidKit", "NVGoggles"};                                // Which items the character has.
 RespawnItems[] = {"FirstAidKit", "NVGoggles"};                 // Which items the character respawns with.
 magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag", "SmokeShell", "SmokeShellGreen", "SmokeShellGreen", "Chemlight_green", "Chemlight_green"};
 respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","16Rnd_9x21_Mag","16Rnd_9x21_Mag", "SmokeShell", "SmokeShellGreen", "SmokeShellGreen", "Chemlight_green", "Chemlight_green"};
 linkedItems[] = {"V_PlateCarrier1_rgr", "H_CrewHelmetHeli_O", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};                             // Which items the character has.
 respawnLinkedItems[] = {"V_PlateCarrier1_rgr", "H_CrewHelmetHeli_O", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};                // Which items the character respawns with.
};
class vtx_uh60_pilot : vtx_uh60_doorgunner {
    displayName = "Pilot";
    linkedItems[] = {"V_TacVest_khk", "H_PilotHelmetHeli_O", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};                             // Which items the character has.
    respawnLinkedItems[] = {"V_TacVest_khk", "H_PilotHelmetHeli_O", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};                // Which items the character respawns with.
};
