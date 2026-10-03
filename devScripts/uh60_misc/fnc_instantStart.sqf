/*
 * Instantly start up the helicopter
 */

_allVariables = (allVariables cameraOn)
  select {_x select [0,4] == "vtx_"}
  apply {
    [_x, cameraOn getVariable _x, true]
  };

_animations = animationNames cameraOn apply {[_x, cameraOn animationPhase _x, true]};

_allVariables = [["vtx_uh60_flir_boot_time",cba_missionTime-25,true],["vtx_cas_queue",4,true],["vtx_uh60_acft_apustate","ON",true],["vtx_uh60_acft_apugenswitchstate","ON",true],["vtx_uh60_acft_apustartdelay_sec",5,true],["vtx_uh60_acft_battbusstate","ON",true],["vtx_uh60_acft_eng1pwrctrlleverstate","FLY",true],["vtx_uh60_acft_apufuelswitchstate","ON",true],["vtx_uh60_acft_eng1fuelsysleverstate","DIR",true],["vtx_uh60_acft_dcbusstate","ON",true],["vtx_uh60_acft_mikswitchstate","ON",true],["vtx_uh60_acft_stbyinstbatt",1800,true],["vtx_uh60_acft_batt1switchstate","ON",true],["vtx_uh60_acft_apugenstate","ON",true],["vtx_uh60_flir_targets",0,true],["vtx_cas_rotorignored",false,true],["vtx_uh60_mfd_26_maptexturemode","topo",true],["vtx_uh60_acft_batt2switchstate","ON",true],["vtx_uh60_acft_eng2genstate","ON",true],["vtx_uh60_acft_stbyinstswitchstate","ON",true],["vtx_uh60_acft_eng2genswitchstate","ON",true],["vtx_uh60_mfd_25_maptexturemode","topo",true],["vtx_uh60_hellfire_lasercodeindex",0,true],["vtx_uh60_acft_eng2starterstate","OFF",true],["vtx_uh60_acft_airsrceswitchstate","APU",true],["vtx_uh60_estarted",true,true],["vtx_uh60_acft_apupwrswitchstate","ON",true],["vtx_uh60_mfd_24_maptexturemode","topo",true],["vtx_uh60_acft_eng1starterstate","OFF",true],["vtx_uh60_acft_eng1genswitchstate","ON",true],["vtx_uh60_acft_eng1genstate","ON",true],["vtx_uh60_acft_acbusstate","ON",true],["vtx_uh60_acft_eng2pwrctrlleverstate","FLY",true],["vtx_uh60_acft_apurpm_pct",0.900196,true],["vtx_uh60_acft_eng2fuelsysleverstate","DIR",true],["vtx_uh60_flir_stowed",true,true],["vtx_uh60_mfd_23_maptexturemode","topo",true]];
_animations = [["switch_lights_collision",0.5,true],["switch_lights_position",0.5,true],["switch_lights_cockpit",0.5,true],["comm1_rot",0,true],["comm2_rot",0,true],["comm3_rot",0,true],["comm4_rot",0,true],["comm1r_rot",0,true],["comm2r_rot",0,true],["comm3r_rot",0,true],["comm4r_rot",0,true],["mvol_rot",0,true],["mvolr_rot",0,true],["tx_rot",0,true],["txr_rot",0,true],["fd_1_rot",0.5,true],["fd_2_rot",0.5,true],["fd_3_rot",0.5,true],["fd_4_rot",0.5,true],["fd_5_rot",0.5,true],["fdr_1_rot",0.5,true],["fdr_2_rot",0.5,true],["fdr_3_rot",0.5,true],["fdr_4_rot",0.5,true],["fdr_5_rot",0.5,true],["rotorbrakegauge",0,true],["gauge_temp_left",0.614581,true],["gauge_temp_right",0.614581,true],["knob_lightupperconsole",0,true],["knob_lightlowerconsole",0,true],["knob_lightinstpanel",0,true],["lever_engpower1z_off",0.85,true],["lever_engpower1z_idle1",0.85,true],["lever_engpower1z_idle2",0.85,true],["lever_engpower1z_fly",0.85,true],["lever_engpower2z_off",0.85,true],["lever_engpower2z_idle1",0.85,true],["lever_engpower2z_idle2",0.85,true],["lever_engpower2z_fly",0.85,true],["lever_fuelsys1",0.6,true],["lever_fuelsys2",0.6,true],["lever_engpower1",0.85,true],["lever_engpower2",0.85,true],["lever_rotorbrake",0,true],["mfd1_hide",0,true],["mfd2_hide",0,true],["mfd3_hide",0,true],["mfd4_hide",0,true],["esis_hide",0,true],["poweronoff",1,true],["generatorsonoff",1,true],["acclow",0,true],["apufail",0,true],["apuon",1,true],["battlow",0,true],["emerrlse",0,true],["oilhot",0,true],["testlte",0,true],["cautioneng1out",0,true],["cautioneng2out",0,true],["cautionfire",0,true],["cautionmastercaution",0,true],["cautionlowrpm",0,true],["switch_fuelboostpump1",0.5,true],["switch_fuelboostpump2",0.5,true],["switch_batt1",0,true],["switch_batt2",0,true],["switch_stbyinst",0,true],["switch_airsce",0,true],["switch_ignition",1,true],["switch_fuelpump",0,true],["switch_apucont",0,true],["switch_apugen",0,true],["switch_gen1",0,true],["switch_gen2",0,true],["switch_egi1",1,true],["switch_egi2",1,true],["switch_ralt_enable",1,true],["handle_wheelbrake",1,true],["wheelbrakes_down",1,true]];

_allVariables apply {cameraOn setVariable _x;};
_animations apply {cameraOn animate _x;};

cameraOn engineOn true;

0 spawn {
  sleep 0.5;
  [cameraOn, ["MFD_3", "mfd_any", "B_MFD3_14"]] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
  [cameraOn, ["MFD_3", "tac", "B_MFD3_15"]] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
  [cameraOn, ["MFD_3", "flir", "stowed", "B_MFD3_1"]] call hct_interaction_fnc_scriptedInteract;  sleep 0.5;
};
