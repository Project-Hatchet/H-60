class OpticsIn {
    class Wide {
        opticsDisplayName = "TRK COR";
        initAngleX = 0;
        minAngleX = -360;
        maxAngleX = 360;
        initAngleY = 0;
        minAngleY = -15;
        maxAngleY = 85;
        initFov = 0.3;
        minFov = 0.3;
        maxFov = 0.3;
        visionMode[] = {"Normal", "NVG", "Ti"};
        thermalMode[] = {0, 1};
        directionStabilized = 1;
        horizontallyStabilized = 1;

        //gunnerOpticsModel = "\A3\Weapons_F\empty";
        //gunnerOpticsModel = "\z\vtx\addons\UH60\vtx_uh60_viewCargo.p3d";
        gunnerOpticsModel = "\z\vtx\addons\uh60_flir\data\vtx_flir_optics_w.p3d";
        //gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";

        opticsPPEffects[] = {"OpticsCHAbera3","OpticsBlur3"};
        gunnerOpticsEffect[] = {"TankCommanderOptics2"};
    };
    class WideT: Wide {
        initFov = 0.2;
        minFov = 0.2;
        maxFov = 0.2;
        gunnerOpticsModel = "\z\vtx\addons\uh60_flir\data\vtx_flir_optics_w2.p3d";
    };
    class MediumT: WideT {
        initFov = 0.1;
        minFov = 0.1;
        maxFov = 0.1;
        gunnerOpticsModel = "\z\vtx\addons\uh60_flir\data\vtx_flir_optics_m.p3d";
    };
    class NarrowT: WideT {
        initFov = 0.022;
        minFov = 0.022;
        maxFov = 0.022;
        gunnerOpticsModel = "\z\vtx\addons\uh60_flir\data\vtx_flir_optics_n.p3d";
    };
    class NarrowT2: WideT {
        initFov = 0.0092;
        minFov = 0.0092;
        maxFov = 0.0092;
        gunnerOpticsModel = "\z\vtx\addons\uh60_flir\data\vtx_flir_optics_n2.p3d";
    };
};
