
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
	aspectRatio = 1/0.725;
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
	sourceIndex=15;
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
class HorizonBankRot {
	type="rotational";
	source="horizonBank";
	center[]={0.5,0.5};
	min=-1.0472;
	max=1.0472;
	minAngle=50;
	maxAngle=-50;
	aspectRatio=1;
};
class Middle{
	type="fixed";
	pos[]={0.5,0.3};
};
class PFD_LEVEL_MIDDLE{
	type="fixed";
	pos[]={0.5,0.28};
};
PITCH_BONES(0.5,0.6,0.28,0.38)

#undef BARTOP
#undef BARBOTTOM
#define BARTOP 0.65
#define BARBOTTOM 0.905
class RPM1
{
	type="linear";
	source="user";
	sourceIndex=19;
	sourceScale=1;
	min=0;
	max=120;
	minPos[]={0,BARTOP};
	maxPos[]={0,BARBOTTOM};
};
class RPM2: RPM1 {
source="user";
sourceIndex=20;
};
class PFD_TRQ: RPM1 {
    source="rtdRotorTorque";
};
class PFD_COLL: RPM1 {
	sourceScale=100;
	source="rtdCollective";
};

class RPM: RPM1 {
    min=0;
    max=12;
	sourceScale=0.7;
	minPos[]={0,BARTOP - 0.1};
	maxPos[]={0,BARBOTTOM};
    source="rpm";
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
	minPos[]={0.4,0};
	maxPos[]={-0.4,0};
};
class PFD_HOVER_VEL_Y: PFD_HOVER_VEL_X {
	source="user";
	sourceIndex=38;
	minPos[]={0,	-0.4};
	maxPos[]={0,	0.4};
};
