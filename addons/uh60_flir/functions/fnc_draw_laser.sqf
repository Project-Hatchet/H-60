// working left gun script
removeAllMissionEventHandlers "Draw3D";
addMissionEventHandler ["Draw3D", {
    drawLaser [
        laser modeltoWorldVisualWorld (laser selectionPosition ["proxy:\a3\weapons_f\acc\acco_dcl_120_F.002", 1]),
        (laser selectionPosition ["chamber_1", "Memory"]) vectorFromTo (laser selectionPosition ["muzzle_1", "Memory"]), // need pilot/copliot camera direction
        [1000, 0, 0], // bright red
        5,
        5,
        false
    ];
}];

addMissionEventHandler ["Draw3D", {
    drawLaser [
        laser modeltoWorldVisualWorld (laser selectionPosition ["flir_cam_pos", "Memory"]),
        (laser vectorModelToWorld (laser weaponDirection "Laserdesignator_pilotCamera")), // need pilot/copliot camera direction
        [1000, 0, 0], // bright red
        5,
        5,
        false
    ];
}];

@@armaproxy.052
["mountingtexture", "minigun_base_elev_r", "minigun_base_dir_r", "minigun_base_elev_l", "minigun_base_dir_l", "gatling_1", "m134dtexture", "gatling_2", "minigun_safe_cover_r", "minigun_safe_cover_l",
    "flir_dir", "flir_elev", "flirpod", "gau21_dir_l", "gau21_elev_l", "gau21_l", "gau21_dir_r", "gau21_elev_r", "gau21_r", "gau21_l_base", "gau21_r_base", "exterrior_misc", "velka vrtule", "mala vrtule",
    "wheel_1_1", "wheel_1_2", "wheel_2_1", "wheel_1_1_damper", "wheel_1_2_damper", "wheel_2_1_damper", "wheel_2_1_steering", "turbinefan_r", "turbinefan_l", "hoist_hook", "stabilator", "rotorblades",
    "vrotorblades", "rotordive", "hh60flares", "window_r_1", "window_r_2", "window_l_1", "window_l_2", "maws_tubes", "maws_stubs", "markings", "exterrior_hull", "exterrior_tail", "cabindoor_l",
    "cabindoor_r", "cockpit_doors", "essscovers", "collective_left", "collective_right", "cyclic_left", "cyclic_right", "pedal_left_cp", "pedal_left_p", "pedal_right_cp", "pedal_right_p",
    "cockpit_seatcontrols", "cockpit_screens", "cockpit_pedestal", "minigun_safe_r", "minigun_safe_l", "cockpit_frontdash", "cockpit_misc", "gauge_temp_left", "gauge_temp_right", "headingball",
"mitas", "cockpit_cargo", "zasleh", "proxy:\ca\temp\proxies\m113\cargo02.001", "proxy:\ca\temp\proxies\m113\cargo02.002", "proxy:\ca\temp\proxies\m113\cargo03.003", "proxy:\ca\temp\proxies\uh60m\gunner.001", "otochlaven", "trup", "proxy:\a3\data_f\proxies\muzzle_flash\mf_machinegun_m134minigun.001", "proxy:\ca\temp\proxies\m113\cargo02.004", "proxy:\ca\temp\proxies\m113\cargo03.009", "proxy:\ca\temp\proxies\m113\cargo02.010", "proxy:\ca\temp\proxies\m113\cargo02.005", "proxy:\ca\temp\proxies\m113\cargo02.006", "proxy:\ca\temp\proxies\m113\cargo03.007", "proxy:\ca\temp\proxies\m113\cargo03.008", "proxy:\ca\temp\proxies\uh60m\gunner.002", "zasleh_1", "proxy:\a3\data_f\proxies\muzzle_flash\mf_machinegun_m134minigun.002", "otochlaven_1", "proxy:\a3\data_f\proxies\muzzle_flash\mf_machinegun_m134minigun.003", "proxy:\a3\data_f\proxies\muzzle_flash\mf_machinegun_m134minigun.004", "proxy:z\vtx\addons\uh60\esss2x.001", "damagehide", "esss", "proxy:\ca\temp\proxies\uh60m\gunner.004", "gau21_gunnerl", "proxy:\ca\temp\proxies\uh60m\gunner.005", "gau21_gunnerr", "zasleh_12", "cargo1", "cargo2", "cargo3", "cargo4", "cargo5", "cargo6", "cargo7", "cargo8", "m134gunner_l", "m134gunner_r", "proxy:\ca\temp\proxies\m113\cargo03.011", "proxy:\ca\temp\proxies\m113\cargo03.012", "proxy:\ca\temp\proxies\m113\cargo03.013", "proxy:\ca\temp\proxies\m113\cargo03.014", "proxy:\ca\temp\proxies\m113\cargo03.015", "proxy:\ca\temp\proxies\m113\cargo03.016", "proxy:\ca\temp\proxies\m113\cargo03.017", "proxy:\ca\temp\proxies\m113\cargo03.018", "proxy:\ca\temp\proxies\m113\cargo03.019", "proxy:\ca\temp\proxies\m113\cargo03.020", "proxy:\ca\temp\proxies\m113\cargo03.021", "proxy:\ca\temp\proxies\m113\cargo03.023", "proxy:\ca\temp\proxies\m113\cargo03.022", "cabin_seats", "proxy:\ca\temp\proxies\uh60m\gunner.003", "proxy:\ca\temp\proxies\uh60m\pilot.001", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.012", "bankball1", "bankball2", "bankball3", "bankball4", "cockpit_frontdash_tube_balls", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.013", "rotorblurred", "vrotorblurred", "proxy:\a3\weapons_f\acc\acco_dcl_120_f.001", "proxy:\a3\weapons_f\acc\acco_dcl_120_f.002", "proxy:\a3\weapons_f\dynamicloadout\pylonpod_3x_missile_agm_02_f.002", "pylonleft", "proxy:\z\vtx\addons\uh60\lass.001", "lass", "pylonright", "proxy:\a3\weapons_f\dynamicloadout\pylonpod_3x_missile_agm_02_f.001", "plane", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.001", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.002", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.003", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.004", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.005", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.006", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.007", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.008", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.009", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.010", "proxy:z\vtx\addons\uh60\data\cargoseats\cargoseat.011", "fuel_probe", "right_num_2", "right_num_1", "left_num_2", "left_num_1", "proxy:\a3\weapons_f\acc\acco_dcl_120_f.003", "proxy:\z\vtx\addons\uh60\data\fuelprobe\fuel_probe_extending.001", "probe_extend", "proxy:z\vtx\addons\uh60_misc\data\skis\vtx_skis.001", "skis", "proxy:\z\vtx\addons\uh60_misc\data\erfs\erfs_arma.000", "erfs", "glass", "mitaswindow", "cockpit_frontdash_tubes", "* non-planar faces", "* non-linear mapping", "* cannot generate st coordinates", "window_1_2", "window_2_2", "window_2_1", "window_1_1", "gunner_seats", "minigun_mount_l", "minigun_mount_r"]

proxy:\a3\weapons_f\acc\acco_dcl_120_F.001
a3\weapons_f\acc\acco_dcl_120_F
laser selectionPosition ["proxy:\a3\weapons_f\acc\acco_dcl_120_F.001", 1]
@@armaproxy.052

addMissionEventHandler ["Draw3D", {
    drawLaser [
        laser modeltoWorldVisualWorld (laser selectionPosition ["flir_cam_pos", "Memory"]),
        (laser vectorModelToWorld (laser weaponDirection "Laserdesignator_pilotCamera")), // need pilot/copliot camera direction wrong var
        [1000, 0, 0], // bright red
        20,
        5,
        false
    ];
}];

// model space
laser modeltoWorldVisualWorld (laser selectionPosition ["proxy:\a3\weapons_f\acc\acco_dcl_120_F.001", 1])

// working door gun

addMissionEventHandler ["Draw3D", {
    drawLaser [
        laser modeltoWorldVisualWorld (laser selectionPosition ["proxy:\a3\weapons_f\acc\acco_dcl_120_F.001", 1]),
        (laser selectionPosition ["chamber_1", "Memory"]) vectorFromTo (laser selectionPosition ["muzzle_1", "Memory"]), // need pilot/copliot camera direction
        [1000, 0, 0], // bright red
        5,
        5,
        false
    ];
}];

addMissionEventHandler ["Draw3D", {
    drawLaser [
        laser modeltoWorldVisualWorld (laser selectionPosition ["muzzle_1", "Memory"]),
        (laser selectionPosition ["chamber_1", "Memory"]) vectorFromTo (laser selectionPosition ["muzzle_1", "Memory"]), // need pilot/copliot camera direction
        [1000, 0, 0], // bright red
        20,
        5,
        false
    ];
}];

tempObject = createSimpleObject [_model, [0, 0, 0], true];

chamber_1
P:\a3\weapons_f\acc\acco_dcl_120_F
(laser selectionPosition ["", "Memory"]) vectorFromTo (laser selectionPosition ["", "Memory"])

gunBeg[] = {
    "muzzle_1", "muzzle_2"
};
gunEnd[] = {
    "chamber_1", "chamber_2"
};

addMissionEventHandler ["Draw3D", {
    drawLaser [
        laser modeltoWorldVisualWorld (laser selectionPosition ["flir_cam_pos", "Memory"]),
        getCameraViewDirection laser,
        [1000, 0, 0], // bright red
        20,
        5,
        false
    ];
}];

addMissionEventHandler ["Draw3D", {
    drawLaser [
        laser modeltoWorldVisualWorld (laser selectionPosition ["flir_cam_pos", "Memory"]),
        getCameraViewDirection laser,
        20,
        5,
        false
    ];
}];

plane vectorModelToWorld (laser weaponDirection "Laserdesignator_pilotCamera")

laser weaponDirection "Laserdesignator_pilotCamera" vectorMultiply 100;

laser weaponDirection "Laserdesignator_pilotCamera";
flir_direction
mple 1:
phase = test animationSourcePhase "flir_direction";
cam = (laser selectionPosition ["flir_cam_pos", "Memory"]) vectorFromTo (laser selectionPosition ["flir_cam_dir", "Memory"])

pos = laser selectionPosition ["flir_cam_pos", "Memory"];

laser weaponDirection "Laserdesignator_mounted";

laser modeltoWorldVisualWorld (laser selectionPosition ["flir_cam_pos", "Memory"]) vectorAdd (laser weaponDirection "Laserdesignator_pilotCamera" vectorMultiply 10)

_beg vectorAdd (bob weaponDirection currentWeapon bob vectorMultiply 100

pos = (laser selectionPosition ["flir_cam_pos", "Memory"]) vectorFromTo (laser selectionPosition ["flir_cam_dir", "Memory"]);

eye = getCameraViewDirection player
"FLIR_ELEVATION"
lasereye = eyePos player vectorAdd [0, 0, 0.1];
// returns [4198.91, 1446.04, 23.049]
laserpod = laser selectionPosition ["flir_cam_pos", "Memory"];
// returns [-0.00523894, 6.47153, -1.6362]
lasereye;
laserpod;

lasereye = eyePos laser vectorAdd [0, 0, 0.1];

getCameraViewDirection

addMissionEventHandler ["Draw3D", {
    drawLaser [
        eyePos player vectorAdd [0, 0, 0.1],
        getCameraViewDirection laser,
        [1000, 0, 0], // bright red
        20,
        5,
        false
    ];
}];