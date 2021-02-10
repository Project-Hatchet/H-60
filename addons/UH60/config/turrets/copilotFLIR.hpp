class CopilotTurret: CopilotTurret
{
    weapons[]=
    {
        "Laserdesignator_mounted"
    };
    magazines[]=
    {
        "Laserbatteries"
    };
    // Animation class
    body = "FLIR_DIRECTION";
    gun = "FLIR_ELEVATION";

    // Animation source
    animationSourceBody = "FLIR_DIRECTION";
    animationSourceGun = "FLIR_ELEVATION";
    stabilizedInAxes = 3;
    minElev = -180;
    maxElev = 40;
    initElev = 0;
    minTurn = -180;
    maxTurn = 180;
    initTurn = 0;
    minFov = 0.25;
    maxFov = 0.9;
    initFov = 0.75;
    memoryPointGunnerOptics = "flir_cam_pos";
    gunBeg = "flir_cam_dir";
    gunEnd = "flir_cam_pos";
    gunnerUsesPilotView = false;
    turretFollowFreeLook = 0;
    class ViewGunner
    {
        minAngleX = -65;
        maxAngleX = 85;
        initAngleX = 0;
        minAngleY = -150;
        maxAngleY = 150;
        initAngleY = 0;
        minFov = 0.25;
        maxFov = 0.9;
        initFov = 0.75;
    };
    class OpticsIn
    {
        class Wide
        {
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
            visionMode[] = {"Normal","NVG","Ti"};
            thermalMode[] = {0};
            directionStabilized = 1;
            horizontallyStabilized = 1;
            gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
            opticsPPEffects[] = {"OpticsCHAbera3","OpticsBlur3"};
            gunnerOpticsEffect[] = {"TankCommanderOptics2"};
        };
        class WideT: Wide
        {
            initFov = 0.2;
            minFov = 0.2;
            maxFov = 0.2;
            gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
        };
        class MediumT: WideT
        {
            initFov = 0.1;
            minFov = 0.1;
            maxFov = 0.1;
            gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_medium_F";
        };
        class NarrowT: WideT
        {
            initFov = 0.022;
            minFov = 0.022;
            maxFov = 0.022;
            gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_narrow_F";
        };
        class NarrowT2: WideT
        {
            initFov = 0.0092;
            minFov = 0.0092;
            maxFov = 0.0092;
            gunnerOpticsModel = "\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_narrow_F";
        };
    };
};
