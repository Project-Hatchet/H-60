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
        gunnerOpticsModel = "";
        opticsPPEffects[] = {"OpticsCHAbera3","OpticsBlur3"};
        gunnerOpticsEffect[] = {"TankCommanderOptics2"};
    };
    class WideT: Wide
    {
        initFov = 0.2;
        minFov = 0.2;
        maxFov = 0.2;
        gunnerOpticsModel = "";
    };
    class MediumT: WideT
    {
        initFov = 0.1;
        minFov = 0.1;
        maxFov = 0.1;
        gunnerOpticsModel = "";
    };
    class NarrowT: WideT
    {
        initFov = 0.022;
        minFov = 0.022;
        maxFov = 0.022;
        gunnerOpticsModel = "";
    };
    class NarrowT2: WideT
    {
        initFov = 0.0092;
        minFov = 0.0092;
        maxFov = 0.0092;
        gunnerOpticsModel = "";
    };
};
stabilizedInAxes = 3;
minElev = -40;
maxElev = 180;
initElev = 0;
minTurn = -180;
maxTurn = 180;
initTurn = 0;
maxXRotSpeed=0.5;
maxYRotSpeed=0.5;
pilotOpticsShowCursor=1;
controllable="True";
