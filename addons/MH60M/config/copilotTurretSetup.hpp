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
    gunnerUsesPilotView = 1;
    stabilizedInAxes = 2;
    usePiP = 1;
    startEngine = 0;
    turretFollowFreeLook = 2;
    gunnerName = "Copilot";
    proxyIndex = 3;
    primaryGunner = 0;
    isCopilot = 1;
    turretInfoType = "Rsc_MELB_Turret_UnitInfo";
    inGunnerMayFire = 1;
    gunnerForceOptics = 0;
    class Components: Components {
        class VehicleSystemsDisplayManagerComponentLeft: vtx_VehicleSystemsTemplateLeftPilot {
            class Components: Components {
                ADDGUNNER
                ADDMISSILE
            };
        };
        class VehicleSystemsDisplayManagerComponentRight: vtx_VehicleSystemsTemplateRightPilot {
            class Components: Components {
                ADDGUNNER
                ADDMISSILE
            };
        };
    };
    class MFD {
        class VTX_H60_HDTS_Common: VTX_H60_HDTS_Common {};
        class VTX_H60_HDTS_Copilot: VTX_H60_HDTS_Copilot {};
        class VTX_H60_HDTS_CoPilot_Turret: VTX_H60_HDTS_CoPilot_Turret {};
    };
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
    class OpticsOut {
        class Monocular {
            gunnerOpticsEffect[] = {};
            gunnerOpticsModel = "";
            initAngleX = 0;
            initAngleY = 0;
            initFov = 0.75;
            maxAngleX = 80;
            maxAngleY = 100;
            maxFov = 1.25;
            minAngleX = -80;
            minAngleY = -100;
            minFov = 0.25;
            visionMode[] = {"Normal","NVG"};
        };
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
