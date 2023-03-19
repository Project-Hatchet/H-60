
class HeadingRotation {
  type="rotational";
  source="heading";
  sourceScale = 1;
  center[] = {0.502,0.788};
  min = "0";
  max = "360";
  minAngle = 360;
  maxAngle = 0;
  aspectRatio = 1/0.725;
};
class WaypointDirection {
  type="rotational";
  source="user";
  sourceIndex=0;
  sourceScale = 1;
  center[] = {0,0};
  min = "0";
  max = "360";
  minAngle = 360;
  maxAngle = 0;
  aspectRatio = 1;
};
class HeadingRotationWind : HeadingRotation {
  minAngle = 360;
  maxAngle = 0;
  center[] = {0.27,0.55};
  aspectRatio = 1/0.725;
};
class RotationWind : HeadingRotationWind {
  center[] = {0,0};
  minAngle = 360;
  maxAngle = 0;
  source="windage";
  aspectRatio = 1;
};
class speedRotation : HeadingRotation {
  source="speed";
  center[] = {0.1735,0.2865};
  min = "0";
  max = "102.889";
  minAngle = -180;
  maxAngle = 147.27272;
};
class FD_speedRotation : speedRotation {
  source="user";
  sourceIndex=41;
  center[] = {0.1735,0.287};
  min = "0";
  max = "200";
};
class BALTRotation : HeadingRotation {
  center[] = {0.8155,0.278};
  source="altitudeASL";
  sourceScale = 3.2808399;
  min = "0";
  max = "30000";
  minAngle = 0;
  maxAngle = 10800;
};
class FD_ALTRotation : BALTRotation {
  source="user";
  sourceIndex=14;
  sourceScale = 1;
  center[] = {0.8158,0.285};
  min = "0";
  max = "30000";
  minAngle = 0;
  maxAngle = 10800;
};
class RALTRotation1 : HeadingRotation {
  center[] = {0.8710,0.6255};
  source="altitudeAGL";
  sourceScale = 3.2808399;
  min = "0";
  max = "100";
  minAngle = -180;
  maxAngle = 0;
};
class RALTRotation2 : RALTRotation1 {
  source="altitudeAGL";
  min = "100";
  max = "400";
  minAngle = 0;
  maxAngle = 90;
};
class RALTRotation3 : RALTRotation2 {
  source="altitudeAGL";
  min = "400";
  max = "1000";
  minAngle = 90;
  maxAngle = 135;
};
class FD_RALTRotation1 : RALTRotation1 {
  source="user";
  sourceIndex=12;
  sourceScale = 1;
  min = "0";
  max = "100";
};
class FD_RALTRotation2 : RALTRotation2 {
  source="user";
  sourceIndex=12;
  sourceScale = 1;
};
class FD_RALTRotation3 : RALTRotation3 {
  source="user";
  sourceIndex=12;
  sourceScale = 1;
};
class VSI_R
{
  type="linear";
  source="vspeed";
  sourceScale=1;
  min=-20.32;
  max=20.32;
  minPos[]={1,0.162};
  maxPos[]={1,0.412};
};
class VSI_L : VSI_R
{
  minPos[]={0.958,0.124};
  maxPos[]={0.958,0.450};
};
class VSI_L_Polygon : VSI_R
{
  minPos[]={0.975,0.139380952};
  maxPos[]={0.975,0.434619048};
};
class VSI_R_Polygon : VSI_R
{
  minPos[]={0.99,0.152952381};
  maxPos[]={0.99,0.421047619};
};
#define FUEL_BARS_X 0.2864
#undef FUEL_BARS_Y1
#define FUEL_BARS_Y1 0.68
#undef FUEL_BARS_Y2
#define FUEL_BARS_Y2 0.8
class Fuel
{
  type="linear";
  source="fuel";
  sourceScale=1;
  min=0;
  max=1;
  minPos[]={FUEL_BARS_X,FUEL_BARS_Y1};
  maxPos[]={FUEL_BARS_X,FUEL_BARS_Y2};
};
class ADI_HorizonBankRot {
  type="rotational";
  source="horizonBank";
  center[]={0.5,0.28};
  min=-1.0472;
  max=1.0472;
  minAngle=-60;
  maxAngle=60;
  aspectRatio=1.333;
};
class HorizonBankRot {
  type="rotational";
  source="horizonBank";
  center[]={0.5,0.28};
  min=-1.0472;
  max=1.0472;
  minAngle=60;
  maxAngle=-60;
  aspectRatio=1.333;
};
class Middle{
  type="fixed";
  pos[]={0.5,0.3};
};
class PFD_LEVEL_MIDDLE{
  type="fixed";
  pos[]={0.5,0.28};
};

PITCH_BONES(0.5,0.56,0.28,0.35)
PITCH_LEVEL(P2D5,2.5)
PITCH_LEVEL(P5,5)
PITCH_LEVEL(P7D5,7.5)
PITCH_LEVEL(P10,10)

PITCH_LEVEL(P12D5,12.5)
PITCH_LEVEL(P15,15)
PITCH_LEVEL(P17D5,17.5)
PITCH_LEVEL(P20,20)

PITCH_LEVEL(P22D5,22.5)
PITCH_LEVEL(P25,25)
PITCH_LEVEL(P27D5,27.5)
PITCH_LEVEL(P30,30)

PITCH_LEVEL(P32D5,32.5)
PITCH_LEVEL(P35,35)
PITCH_LEVEL(P37D5,37.5)
PITCH_LEVEL(P40,40)

PITCH_LEVEL(P50,50)
PITCH_LEVEL(P55,55)
PITCH_LEVEL(P60,70)
PITCH_LEVEL(P70,70)
PITCH_LEVEL(P90,90)

#undef BARTOP
#undef BARBOTTOM
#define BARTOP 0.65
#define BARBOTTOM 0.905
class PFD_Q1 {
  type="linear";
  source="user";
  sourceIndex=22;
  sourceScale=1;
  min=0;
  max=120;
  minPos[]={0,BARTOP};
  maxPos[]={0,BARBOTTOM};
};
class PFD_Q2 {
  type="linear";
  source="user";
  sourceIndex=48;
  sourceScale=1;
  min=0;
  max=120;
  minPos[]={0,BARTOP};
  maxPos[]={0,BARBOTTOM};
};
/*
class PFD_TRQ { 
  type="linear";
  source="user";
  //source="rtdRotorTorque";
  sourceIndex=22;
  sourceScale=1;
  min=0;
  max=120;
  minPos[]={0,BARTOP};
  maxPos[]={0,BARBOTTOM};
};

class PFD_COLL {
  type="linear";
  source="user";
  //source="rtdCollective";
  sourceIndex=48;
  sourceScale=1;
  min=0;
  max=120;
  minPos[]={0,BARTOP};
  maxPos[]={0,BARBOTTOM};
};
*/

class PFD_RPM {
    type="linear";
  source="user";
  //source="rpm";
  sourceIndex=17;
  sourceScale=1;
  min=0;
  max=120;
  minPos[]={0,BARTOP};
  maxPos[]={0,BARBOTTOM};
};

class PFD_HSI_CENTER {
  type="fixed";
  pos[]={0.502,0.788};
};

#define HSI_HVR_10KTS 0.04
class PFD_HOVER_VEL_X {
  type="linear";
  source="user";
  sourceIndex=37;
  sourceScale=0.51444563338;
  min=-1;
  max=1;
  minPos[]={0.155,0};
  maxPos[]={-0.155,0};
};
class PFD_HOVER_VEL_Y: PFD_HOVER_VEL_X {
  source="user";
  sourceIndex=38;
  minPos[]={0,  -0.155};
  maxPos[]={0,  0.155};
};

class PFD_WP_VEH_DIR {
  type="rotational";
  source="heading";
  sourceIndex=0;
  sourceScale = 1;
  center[] = {0,0};
  min = "0";
  max = "360";
  minAngle = 0;
  maxAngle = 360;
  aspectRatio = 1;
};
class PFD_WP_DIR {
  type="rotational";
  source="user";
  sourceIndex=0;
  sourceScale = 1;
  center[] = {0.502,0.788};
  min = "0";
  max = "360";
  minAngle = 0;
  maxAngle = 360;
  aspectRatio = 1;
};
class PFD_WP_DIST {
  type="linear";
  source="user";
  sourceIndex=1;
  sourceScale=1;
  min=0;
  max=100;
  minPos[]={0,-0.155};
  maxPos[]={0,0};
};


class PFD_ARC_CENTER {
  type="fixed";
  pos[]={0.502,0.994-0.05};
};
class ARC_HeadingRotation {
  type="rotational";
  source="heading";
  sourceScale = 1;
  center[] = {0.502,0.994};
  min = "0";
  max = "360";
  minAngle = 360;
  maxAngle = 0;
  aspectRatio = 1/0.725;
};

class PFD_ARC_WP1_Dir {
  type="rotational";
  source="user";
  sourceIndex=2;
  sourceScale = 1;
  center[] = {0.502,0.994-0.05};
  min = "-360";
  max = "360";
  minAngle = -360;
  maxAngle = 360;
  aspectRatio = 1/0.725;
};
class PFD_ARC_WP1_DIST {
    type="linear";
  source="user";
  sourceIndex=3;
  sourceScale=1;
  min=0;
  max=1;
  minPos[]={0,0.5};
  maxPos[]={0,0};
};

class PFD_ARC_WP2_Dir: PFD_ARC_WP1_Dir {
  source="user";
  sourceIndex=4;
};
class PFD_ARC_WP2_DIST: PFD_ARC_WP1_DIST {
  source="user";
  sourceIndex=5;
};

class PFD_ARC_WP3_Dir: PFD_ARC_WP1_Dir {
  source="user";
  sourceIndex=6;
};
class PFD_ARC_WP3_DIST: PFD_ARC_WP1_DIST {
  source="user";
  sourceIndex=7;
};

class PFD_ARC_WP4_Dir: PFD_ARC_WP1_Dir {
  source="user";
  sourceIndex=8;
};
class PFD_ARC_WP4_DIST: PFD_ARC_WP1_DIST {
  source="user";
  sourceIndex=9;
};

class PFD_ARC_WP5_Dir: PFD_ARC_WP1_Dir {
  source="user";
  sourceIndex=33;
};
class PFD_ARC_WP5_DIST: PFD_ARC_WP1_DIST {
  source="user";
  sourceIndex=34;
};

class PFD_ARC_WP6_Dir: PFD_ARC_WP1_Dir {
  source="user";
  sourceIndex=35;
};
class PFD_ARC_WP6_DIST: PFD_ARC_WP1_DIST {
  source="user";
  sourceIndex=36;
};
