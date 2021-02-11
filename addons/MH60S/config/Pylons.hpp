class TransportPylonsComponent
{
    uiPicture = "z\vtx\addons\MH60M\Data\UI\vtx_mh60m_dap_3den_ca.paa";
    class Pylons
    {
        class pylons1
        {
            attachment = "VTX_M230_Chaingun_L";
            priority = 5;
            hardpoints[] = {"DAR", "DAGR", "B_SHIEKER", "SCALPEL_1RND_EJECTOR", "RHS_HP_LONGBOW_RACK","RHS_HP_FFAR_ARMY", "RHS_HP_MELB","RHS_HP_MELB_L","CUP_NATO_HELO_UH60", "VTX_ST_L"};
            UIposition[] = {0.59, 0.41};
        };
        class pylons2: pylons1
        {
            attachment = "PylonRack_4Rnd_ACE_Hellfire_AGM114K";
            hardpoints[] = {"DAR", "DAGR", "B_SHIEKER", "SCALPEL_1RND_EJECTOR", "RHS_HP_LONGBOW_RACK","RHS_HP_FFAR_ARMY", "RHS_HP_MELB","RHS_HP_MELB_R","CUP_NATO_HELO_UH60", "VTX_ST_R"};
            mirroredMissilePos = 1;
            UIposition[] = {0.08, 0.41};
        };
    };
    class Presets
    {
        class Empty
        {
            displayName = "Empty";
            attachment[] = {};
        };
        class Default
        {
            displayName = "Default";
            attachment[] = {"PylonWeapon_300Rnd_20mm_shells", "PylonRack_19Rnd_Rocket_Skyfire"};
        };
        class Rocket
        {
            displayName = "Rocket";
            attachment[] = {"PylonRack_19Rnd_Rocket_Skyfire", "PylonRack_19Rnd_Rocket_Skyfire"};
        };
        class Guided
        {
            displayName = "Guided";
            attachment[] = {"PylonRack_12Rnd_PG_missiles", "PylonRack_12Rnd_PG_missiles"};
        };
        class AT
        {
            displayName = "AT";
            attachment[] = {"PylonRack_4Rnd_ACE_Hellfire_AGM114K", "PylonRack_4Rnd_ACE_Hellfire_AGM114K"};
        };
    };
}; // TransportPylonsComponent
