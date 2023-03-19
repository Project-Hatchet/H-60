class CfgGroups
{
  class West
  {
    name = $STR_A3_CfgGroups_West0;
    side = TWest;

    class Guerilla
    {
      name = $STR_A3_cfggroups_Indep_Guerilla0;
      class Infantry
      {
        name = $STR_A3_cfggroups_West_BLU_F_Infantry0;
                                // cost: 3.8
        class GS04_IRG_InfSquad6
        {
          name = $STR_A3_CfgGroups_West_BLU_F_Infantry_BUS_InfSquad0;
          side = TWest;
          faction = BLU_G_F;
          class Unit0  {side = TWest; vehicle = B_G_soldier_SL_F; rank = "SERGEANT";};
          class Unit1  {side = TWest; vehicle = B_G_medic_F; rank = "CORPORAL";};
          class Unit2  {side = TWest; vehicle = B_G_Soldier_GL_F; rank = "PRIVATE";};
          class Unit3  {side = TWest; vehicle = B_G_Soldier_AR_F; rank = "PRIVATE";};
          class Unit4  {side = TWest; vehicle = B_G_Soldier_LAT_F; rank = "PRIVATE";};
          class Unit5  {side = TWest; vehicle = B_G_Soldier_F; rank = "PRIVATE";};
        };
                                // cost: 2.6
        class GS04_IRG_InfTeam
        {
          name = $STR_A3_CfgGroups_West_BLU_F_Infantry_BUS_InfSquad0;
          side = TWest;
          faction = BLU_G_F;
          class Unit0  {side = TWest; vehicle = B_G_Soldier_TL_F; rank = "CORPORAL";};
          class Unit1  {side = TWest; vehicle = B_G_Soldier_AR_F; rank = "PRIVATE";};
          class Unit2  {side = TWest; vehicle = B_G_Soldier_M_F; rank = "PRIVATE";};
          class Unit3  {side = TWest; vehicle = B_G_Soldier_F; rank = "PRIVATE";};
        };
      };
      class Motorized
      {
        name = $STR_A3_cfggroups_Indep_Guerilla_Motorized_MTP0;
                                // cost: 4.5
        class GS04_IRG_MotInf_Offroad
        {
          name = $STR_A3_cfggroups_Indep_Guerilla_Motorized_MTP_IRG_MotInfTeam0;
          side = TWest;
          faction = BLU_G_F;
          class Unit0  {side = TWest; vehicle = B_G_Soldier_TL_F; rank = "SERGEANT";};
          class Unit1  {side = TWest; vehicle = B_G_Soldier_AR_F; rank = "CORPORAL";};
          class Unit2  {side = TWest; vehicle = B_G_Soldier_LAT_F; rank = "PRIVATE";};
          class Unit3  {side = TWest; vehicle = B_G_Soldier_F; rank = "PRIVATE";};
          class Unit4  {side = TWest; vehicle = B_G_Soldier_A_F; rank = "PRIVATE";};
          class Unit5  {side = TWest; vehicle = B_G_Offroad_01_F; rank = "PRIVATE";};
        };
                                /*
                                // cost: 5.2
        class GS04_IRG_MotInf_Truck
        {
          name = $STR_A3_cfggroups_Indep_Guerilla_Motorized_MTP_IRG_MotInfTeam0;
          side = TWest;
          faction = BLU_G_F;
          class Unit0  {side = TWest; vehicle = B_G_soldier_SL_F; rank = "SERGEANT";};
          class Unit1  {side = TWest; vehicle = B_G_medic_F; rank = "CORPORAL";};
          class Unit2  {side = TWest; vehicle = B_G_Soldier_GL_F; rank = "CORPORAL";};
          class Unit3  {side = TWest; vehicle = B_G_Soldier_AR_F; rank = "PRIVATE";};
          class Unit4  {side = TWest; vehicle = B_G_Soldier_LAT_F; rank = "PRIVATE";};
          class Unit5  {side = TWest; vehicle = B_G_Soldier_M_F; rank = "PRIVATE";};
          class Unit6  {side = TWest; vehicle = B_G_Soldier_F; rank = "PRIVATE";};
          class Unit7     {side = TWest; vehicle = B_G_Van_01_transport_F; rank = "PRIVATE";};
        };
                                */
                                /*
                                // cost: 1.2
                                class GS04_IRG_MotInf_Quad
        {
          name = $STR_A3_cfggroups_Indep_Guerilla_Motorized_MTP_IRG_MotInfTeam0;
          side = TWest;
          faction = BLU_G_F;
          class Unit0  {side = TWest; vehicle = B_G_Quadbike_01_F; rank = "CORPORAL";};
          class Unit1  {side = TWest; vehicle = B_G_Soldier_GL_F; rank = "PRIVATE";};
        };
                                */
                                // cost: 2.2
                                class GS04_IRG_MotInf_Team_HMG
        {
          name = $STR_A3_cfggroups_Indep_Guerilla_Motorized_MTP_IRG_MotInfTeam0;
          side = TWest;
          faction = BLU_G_F;
          class Unit0  {side = TWest; vehicle = B_G_Offroad_01_armed_F; rank = "PRIVATE";};
        };
      };
    };
  };
  class East
  {
    name = $STR_A3_CfgGroups_East0;
    side = TEast;
    class OPF_F
    {
      name = $STR_A3_CfgGroups_East_OPF_F0;
      class Infantry
      {
        name = $STR_A3_CfgGroups_West_BLU_F_Infantry0;
                                // cost: 6.6
        class GS04_OIA_InfSquad
        {
          name = $STR_A3_CfgGroups_West_BLU_F_Infantry_BUS_InfSquad0;
          side = TEast;
          faction = OPF_F;
          class Unit0   {side = TEast; vehicle = O_SoldierU_SL_F; rank = "SERGEANT";};
          class Unit1   {side = TEast; vehicle = O_soldierU_medic_F; rank = "CORPORAL";};
          class Unit2   {side = TEast; vehicle = O_SoldierU_GL_F; rank = "CORPORAL";};
          class Unit3   {side = TEast; vehicle = O_soldierU_AR_F; rank = "PRIVATE";};
          class Unit4   {side = TEast; vehicle = O_soldierU_LAT_F; rank = "PRIVATE";};
          class Unit5   {side = TEast; vehicle = O_soldierU_M_F; rank = "PRIVATE";};
          class Unit6   {side = TEast; vehicle = O_soldierU_F; rank = "PRIVATE";};
          class Unit7   {side = TEast; vehicle = O_soldierU_F; rank = "PRIVATE";};
        };
                                // cost: 2.4
        class GS04_OIA_InfTeam
        {
          name = $STR_A3_CfgGroups_West_BLU_F_Infantry_BUS_InfSquad0;
          side = TEast;
          faction = OPF_F;
          class Unit0  {side = TEast; vehicle = O_soldierU_TL_F; rank = "CORPORAL";};
          class Unit1  {side = TEast; vehicle = O_soldierU_AR_F; rank = "PRIVATE";};
          class Unit2  {side = TEast; vehicle = O_soldierU_M_F; rank = "PRIVATE";};
          class Unit3  {side = TEast; vehicle = O_soldierU_F; rank = "PRIVATE";};
        };
                                /*
                                // cost: 14.4
        class GS04_OIA_InfTeam_Sniper
        {
          name = $STR_A3_CfgGroups_West_BLU_F_Infantry_BUS_SniperTeam0;
          side = TEast;
          faction = OPF_F;
          class Unit0  {side = TEast; vehicle = O_spotter_F; rank = "SERGEANT";};
          class Unit1  {side = TEast; vehicle = O_sniper_F; rank = "CORPORAL";};
          class Unit2  {side = TEast; vehicle = O_sniper_F; rank = "CORPORAL";};
          class Unit3  {side = TEast; vehicle = O_sniper_F; rank = "CORPORAL";};
        };
                                */
                                // cost: 2.6
        class GS04_OIA_InfTeam_MG
        {
          name = $STR_A3_CfgGroups_West_BLU_F_Infantry_BUS_InfSquad0;
          side = TEast;
          faction = OPF_F;
          class Unit0  {side = TEast; vehicle = O_soldierU_TL_F; rank = "CORPORAL";};
          class Unit1  {side = TEast; vehicle = O_soldierU_AR_F; rank = "PRIVATE";};
          class Unit2  {side = TEast; vehicle = O_soldierU_AR_F; rank = "PRIVATE";};
          class Unit3  {side = TEast; vehicle = O_soldierU_AAR_F; rank = "PRIVATE";};
        };
      };
    };
  };
};
