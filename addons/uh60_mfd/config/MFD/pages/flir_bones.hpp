class FLIR_Level0
{
    pos0[] = {0.5, 0.5};
    pos10[] = {0.5+(0.1*0.75), 0.6};
    type = "horizon";
    angle = 0;
};
class FLIR_LevelP5:FLIR_Level0{angle=5;};
class FLIR_LevelM5:FLIR_Level0{angle=-5;};
class FLIR_LevelP10:FLIR_Level0{angle=10;};
class FLIR_LevelM10:FLIR_Level0{angle=-10;};
class FLIR_LevelP15:FLIR_Level0{angle=15;};
class FLIR_LevelM15:FLIR_Level0{angle=-15;};
class FLIR_LevelP20:FLIR_Level0{angle=20;};
class FLIR_LevelM20:FLIR_Level0{angle=-20;};
class FLIR_LevelP25:FLIR_Level0{angle=25;};
class FLIR_LevelM25:FLIR_Level0{angle=-25;};
class FLIR_LevelP30:FLIR_Level0{angle=30;};
class FLIR_LevelM30:FLIR_Level0{angle=-30;};
class FLIR_LevelP35:FLIR_Level0{angle=35;};
class FLIR_LevelM35:FLIR_Level0{angle=-35;};
class FLIR_LevelP40:FLIR_Level0{angle=40;};
class FLIR_LevelM40:FLIR_Level0{angle=-40;};
class FLIR_LevelP45:FLIR_Level0{angle=45;};
class FLIR_LevelM45:FLIR_Level0{angle=-45;};

class FLIR_Center {
  type="fixed";
  pos[]={0.5,0.5};
};

class FLIR_VelocityVector
{
    type = "vector";
    source = "velocity";
    pos0[] = {0.5, 0.5};
    pos10[] = {1, 1};
}; // FLIR_VelocityVector

class FLIR_HorizonBankRot {
    type="rotational";
    source="horizonBank";
    center[]={0.5,0.5};
    min=-1.0472;
    max=1.0472;
    minAngle=-45;
    maxAngle=45;
    aspectRatio=1;
};
class FLIR_HorizonBankRot_nav
{
    type="rotational";
    source="horizonBank";
    center[]={0.5,0.5};
    min=-3.1416;
    max=3.1416;
    minAngle=-180;
    maxAngle=180;
    aspectRatio=1;
};
class FLIR_DIR_BONE
{
    type="vector";
    source="pilotcamera";
    pos0[] =   {0.50,0.10};
    pos10[] =   {0.53,0.10};
};
class FLIR_ELEV_BONE
{
    type="vector";
    source="pilotcamera";
    pos0[] =   {0.08,0.5};
    pos10[] =   {0.08 ,0.518};
};
class FLIR_HELLFIRE_REF
{
    type="vector";
    source="pilotcamera";
    pos0[] =   {0.50,0.50};
    pos10[] =   {0.47*(4/3),0.60};
};