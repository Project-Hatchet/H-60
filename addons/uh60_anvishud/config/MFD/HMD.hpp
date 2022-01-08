borderBottom = 0;
borderLeft = 0;
borderRight = 0;
borderTop = 0;
color[] = {0.082,0.608,0.039,1};
enableParallax = 0;
helmetDown[] = {0,-0.065,0};
helmetMountedDisplay = 1;
helmetPosition[] = {-0.0325,0.0325,0.1};
helmetRight[] = {0.065,0,0};
topLeft = ""; // not used because HMD, but still needed
topRight = ""; // not used because HMD, but still needed
bottomLeft = ""; // not used because HMD, but still needed
font="RobotoCondensedLight";
class material {
	ambient[] = {1, 1, 1, 1};
	diffuse[] = {0.5, 0.5, 0.5, 1};
	emissive[] = {100, 100, 100, 50};
};
class Bones {
	#define POS10X 0.765
	#define POS10Y 0.76
	class WPPoint
	{
		type = "vector";
		source = "wppointtoview";
		pos0[] = {0.5, 0.5};
		pos10[] = {POS10X, POS10Y};
	}; // WPPoint
	class WP_DIR_BONE
	{
		type="vector";
		source="wppoint";
		pos0[] = 	{0.500,0.128};
		pos10[] = 	{0.63 ,0.128};
	};
	class WP_DIR_LIMITS
	{
		type = "limit";
		limits[] = {0.2,0,0.8,1};
	};
	class VelocityVector
	{
		type = "vector";
		source = "velocitytoview";
		pos0[] = {0.5, 0.5};
		pos10[] = {POS10X, POS10Y};
	}; // VelocityVector
	class HUDCenter
	{
		type = "fixed";
		pos[] = {0.5, 0.5};
	}; // HUDCenter
	class ForwardVector
	{
		type = "vector";
		source = "forward";
		pos0[] = {0, 0};
		pos10[] = {POS10X, POS10Y};
	}; // ForwardVector
	class Airport1
	{
		type = "vector";
		source = "airportCorner1toView";
		pos0[] = {0.5, 0.5};
		pos10[] = {POS10X, POS10Y};
	}; // Airport1
	class Airport2: Airport1
	{
		source = "airportCorner2toView";
	}; // Airport2
	class Airport3: Airport1
	{
		source = "airportCorner3toView";
	}; // Airport3
	class Airport4: Airport1
	{
		source = "airportCorner4toView";
	}; // Airport4
	class RPM
	{
		type="linear";
	    source="rpm";
	    min=0;
	    max=12;
		sourceScale=0.7;
		minPos[]={0,0.4};
		maxPos[]={0,0.8};
	};
	#include "pitchLadder_bones.hpp"
	#include "horizonBank_bones.hpp"
	class rtdCollectiveBar
	{
		type="linear";
	    source="rtdCollective";
	    min=0;
	    max=1;
		sourceScale=1;
		minPos[]={0,0.57};
		maxPos[]={0,0.8};
	};
	class VSIBar
	{
		type="linear";
		source = "vspeed";
		sourceScale=1.9685;
		min=-20.32;
		max=20.32;
		minPos[]={0.85,0.55};
		maxPos[]={0.85,0.75};
	};
	class AltitudeEdge
	{
		type="linear";
	    source="altitudeAGL";
		min=0;
		max=50;
		sourceScale=1;
		minPos[]={0.95,0.5};
		maxPos[]={0.95,0.8};
	};
	class RALT_AP
	{
		type="linear";
	    source="user";
		sourceIndex=12;
		min=0;
		max=1000;
		sourceScale=1;
		minPos[]={0.95,0.5};
		maxPos[]={0.95,0.8};
	};
	class tfr_elevate_c {
		type="linear";
		source="user";
		sourceIndex=37;
		sourceScale=1;
		min=-1;
		max=1;
		minPos[]={0,-0.3};
		maxPos[]={0,0.3};
	};
	#define HSI_HVR_10KTS 0.04
	class PFD_HOVER_VEL_X {
		type="linear";
		source="user";
		sourceIndex=37;
		sourceScale=0.51444563338;
		min=-1;
		max=1;
		minPos[]={(HSI_HVR_10KTS*4),0};
		maxPos[]={-(HSI_HVR_10KTS*4),0};
	};
	class PFD_HOVER_VEL_Y: PFD_HOVER_VEL_X {
		source="user";
		sourceIndex=38;
		minPos[]={0,	-(HSI_HVR_10KTS*4)};
		maxPos[]={0,	(HSI_HVR_10KTS*4)};
	};
	class PlaneOrientation
	{
		type="fixed";
		pos[]={0.5,0.5};
	};
	class Limit0109
	{
		type = "limit";
		limits[] = {0.1,0.1,0.9,0.9};
	};
	class Slip_Ball_X
	{
		type="vector";
		source="velocity";
		pos0[]=	{0.500,0.9425};
		pos10[]={0.515,0.9425};
	};
	class GforceX_Slip
	{
		type="linear";
		source="gmeterX";
		sourceScale=1;
		max=0.15;
		min=-0.15;
		minPos[]={"0.5+0.1","0.9-0.04-0.02"};
		maxPos[]={"0.5-0.1","0.9-0.04-0.02"};						
	};
	class DVE_WP_VEH_DIR {
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
	class DVE_WP_DIR {
		type="rotational";
		source="user";
		sourceIndex=0;
		sourceScale = 1;
		center[] = {0.5,0.5};
		min = "0";
		max = "360";
		minAngle = 0;
		maxAngle = 360;
		aspectRatio = 1;
	};
	class DVE_WP_DIST {
		type="linear";
		source="user";
		sourceIndex=1;
		sourceScale=1;
		min=0;
		max=100;
		minPos[]={0,-0.5};
		maxPos[]={0,0};
	};
	class ImpactPoint
	{
		type = "vector";
		source = "impactpointtoview";
		pos0[] = {0.5, 0.5};
		pos10[] = {POS10X, POS10Y};
	}; // ImpactPoint
	class PilotCameraToView
	{
		type = "vector";
		source = "pilotcameratoview";
		pos0[] = {0.5, 0.5};
		pos10[] = {POS10X, POS10Y};
	}; // WPPoint
}; // Bones
class Draw {
	condition="(user15>-1)";
	class Outline {
		type="line";
		width = 0;
		points[] ={
			{{0, 0}, 1},
			{{1, 0}, 1},
			{{1, 1}, 1},
			{{0, 1}, 1},
			{{0, 0}, 1}
		}; // points
	}; // WP_Point_Square
	#define WP_BOX_SIZE 0.03
	class WP_Point_Square {
		type="line";
		width = 3;
		points[] ={
			{"WPPoint", { 0   , -0.001},1},
			{"WPPoint", { 0   ,  0.001},1},{},
			{"WPPoint", { 0   , -0.025},1},
			{"WPPoint", { 0.025, 0.0},1},
			{"WPPoint", { 0.015, 0.015},1},
			{"WPPoint", {-0.015, 0.015},1},
			{"WPPoint", {-0.025, 0.0},1},
			{"WPPoint", { 0   , -0.025},1}
		}; // points
	}; // WP_Point_Square
	class Center_Cross {
		type="line";
		width = 3;
		points[] ={
			{"HUDCenter", {-0.12, 0}, 1},
			{"HUDCenter", {-0.05, 0}, 1},
			{"HUDCenter", {-0.05, 0.03}, 1},
			{},
			{"HUDCenter", {0.12, 0}, 1},
			{"HUDCenter", {0.05, 0}, 1},
			{"HUDCenter", {0.05, 0.03}, 1}
		}; // points
	}; // Center_Cross
	class VelocityLine {
		condition="(speed > 3)";
		class VelocityLineDraw
		{
			type = "line";
			width = 4;
			points[] = {{"VelocityVector", {0, -0.0196581}, 1}, {"VelocityVector", {0.01, -0.0170239}, 1}, {"VelocityVector", {0.01732, -0.00982906}, 1}, {"VelocityVector", {0.02, 0}, 1}, {"VelocityVector", {0.01732, 0.00982906}, 1}, {"VelocityVector", {0.01, 0.0170239}, 1}, {"VelocityVector", {0, 0.0196581}, 1}, {"VelocityVector", {-0.01, 0.0170239}, 1}, {"VelocityVector", {-0.01732, 0.00982906}, 1}, {"VelocityVector", {-0.02, 0}, 1}, {"VelocityVector", {-0.01732, -0.00982906}, 1}, {"VelocityVector", {-0.01, -0.0170239}, 1}, {"VelocityVector", {0, -0.0196581}, 1}, {}, {"VelocityVector", {0.04, 0}, 1}, {"VelocityVector", {0.02, 0}, 1}, {}, {"VelocityVector", {-0.04, 0}, 1}, {"VelocityVector", {-0.02, 0}, 1}, {}, {"VelocityVector", {0, -0.0393162}, 1}, {"VelocityVector", {0, -0.0196581}, 1}, {}};
		}; // VelocityLineDraw
	}; // VelocityLine

	#define POWER_X 0.1
	#define POWER_OFFSET 0.05
	class SLIP_DCLT_HIDE {
		condition=COND_FULL_ONLY;
		class Slip_bars
		{
			type="line";
			width=4;
			points[]=
			{
				{{"0.5-0.018","1-0.04"},1},
				{{"0.5-0.018","1-0.075"},1},
				{},
				{{"0.5+0.018","1-0.04"},1},
				{{"0.5+0.018","1-0.075"},1},
				{},
				{{"0.5+0.15","1-0.04"},1},
				{{"0.5-0.15","1-0.04"},1},
			};
		};
		class Slip_ball
		{
			type = "line";
			width = 6.0;
			points[]=
			{
				{"Slip_Ball_X",1,{"0 * 0.75","-0.02 * 0.75"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.75","-0.01732 * 0.75"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.75","-0.0099999998 * 0.75"},1},
				{"Slip_Ball_X",1,{"0.02 * 0.75","0 * 0.75"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.75","0.0099999998 * 0.75"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.75","0.01732 * 0.75"},1},
				{"Slip_Ball_X",1,{"0 * 0.75","0.02 * 0.75"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.75","0.01732 * 0.75"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.75","0.0099999998 * 0.75"},1},
				{"Slip_Ball_X",1,{"-0.02 * 0.75","0 * 0.75"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.75","-0.0099999998 * 0.75"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.75","-0.01732 * 0.75"},1},
				{"Slip_Ball_X",1,{"0 * 0.75","-0.02 * 0.75"},1},
				{},
				{"Slip_Ball_X",1,{"0 * 0.6","-0.02 * 0.6"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.6","-0.01732 * 0.6"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.6","-0.0099999998 * 0.6"},1},
				{"Slip_Ball_X",1,{"0.02 * 0.6","0 * 0.6"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.6","0.0099999998 * 0.6"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.6","0.01732 * 0.6"},1},
				{"Slip_Ball_X",1,{"0 * 0.6","0.02 * 0.6"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.6","0.01732 * 0.6"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.6","0.0099999998 * 0.6"},1},
				{"Slip_Ball_X",1,{"-0.02 * 0.6","0 * 0.6"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.6","-0.0099999998 * 0.6"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.6","-0.01732 * 0.6"},1},
				{"Slip_Ball_X",1,{"0 * 0.6","-0.02 * 0.6"},1},
				{},
				{"Slip_Ball_X",1,{"0 * 0.5","-0.02 * 0.5"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.5","-0.01732 * 0.5"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.5","-0.0099999998 * 0.5"},1},
				{"Slip_Ball_X",1,{"0.02 * 0.5","0 * 0.5"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.5","0.0099999998 * 0.5"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.5","0.01732 * 0.5"},1},
				{"Slip_Ball_X",1,{"0 * 0.5","0.02 * 0.5"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.5","0.01732 * 0.5"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.5","0.0099999998 * 0.5"},1},
				{"Slip_Ball_X",1,{"-0.02 * 0.5","0 * 0.5"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.5","-0.0099999998 * 0.5"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.5","-0.01732 * 0.5"},1},
				{"Slip_Ball_X",1,{"0 * 0.5","-0.02 * 0.5"},1},
				{},
				{"Slip_Ball_X",1,{"0 * 0.4","-0.02 * 0.4"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.4","-0.01732 * 0.4"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.4","-0.0099999998 * 0.4"},1},
				{"Slip_Ball_X",1,{"0.02 * 0.4","0 * 0.4"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.4","0.0099999998 * 0.4"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.4","0.01732 * 0.4"},1},
				{"Slip_Ball_X",1,{"0 * 0.4","0.02 * 0.4"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.4","0.01732 * 0.4"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.4","0.0099999998 * 0.4"},1},
				{"Slip_Ball_X",1,{"-0.02 * 0.4","0 * 0.4"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.4","-0.0099999998 * 0.4"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.4","-0.01732 * 0.4"},1},
				{"Slip_Ball_X",1,{"0 * 0.4","-0.02 * 0.4"},1},
				{},
				{"Slip_Ball_X",1,{"0 * 0.30","-0.02 * 0.30"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.30","-0.01732 * 0.30"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.30","-0.0099999998 * 0.30"},1},
				{"Slip_Ball_X",1,{"0.02 * 0.30","0 * 0.30"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.30","0.0099999998 * 0.30"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.30","0.01732 * 0.30"},1},
				{"Slip_Ball_X",1,{"0 * 0.30","0.02 * 0.30"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.30","0.01732 * 0.30"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.30","0.0099999998 * 0.30"},1},
				{"Slip_Ball_X",1,{"-0.02 * 0.30","0 * 0.30"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.30","-0.0099999998 * 0.30"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.30","-0.01732 * 0.30"},1},
				{"Slip_Ball_X",1,{"0 * 0.30","-0.02 * 0.30"},1},
				{},
				{"Slip_Ball_X",1,{"0 * 0.20","-0.02 * 0.20"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.20","-0.01732 * 0.20"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.20","-0.0099999998 * 0.20"},1},
				{"Slip_Ball_X",1,{"0.02 * 0.20","0 * 0.20"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.20","0.0099999998 * 0.20"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.20","0.01732 * 0.20"},1},
				{"Slip_Ball_X",1,{"0 * 0.20","0.02 * 0.20"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.20","0.01732 * 0.20"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.20","0.0099999998 * 0.20"},1},
				{"Slip_Ball_X",1,{"-0.02 * 0.20","0 * 0.20"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.20","-0.0099999998 * 0.20"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.20","-0.01732 * 0.20"},1},
				{"Slip_Ball_X",1,{"0 * 0.20","-0.02 * 0.20"},1},
				{},
				{"Slip_Ball_X",1,{"0 * 0.1","-0.02 * 0.1"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.1","-0.01732 * 0.1"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.1","-0.0099999998 * 0.1"},1},
				{"Slip_Ball_X",1,{"0.02 * 0.1","0 * 0.1"},1},
				{"Slip_Ball_X",1,{"0.01732 * 0.1","0.0099999998 * 0.1"},1},
				{"Slip_Ball_X",1,{"0.0099999998 * 0.1","0.01732 * 0.1"},1},
				{"Slip_Ball_X",1,{"0 * 0.1","0.02 * 0.1"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.1","0.01732 * 0.1"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.1","0.0099999998 * 0.1"},1},
				{"Slip_Ball_X",1,{"-0.02 * 0.1","0 * 0.1"},1},
				{"Slip_Ball_X",1,{"-0.01732 * 0.1","-0.0099999998 * 0.1"},1},
				{"Slip_Ball_X",1,{"-0.0099999998 * 0.1","-0.01732 * 0.1"},1},
				{"Slip_Ball_X",1,{"0 * 0.1","-0.02 * 0.1"},1}
			};
		};
	};

	#include "flight.hpp"
	#include "navigationInfo.hpp"
	#include "headingTape.hpp"
	#include "DVE.hpp"
	#include "radar.hpp"
	#include "pitchLadder.hpp"
	#include "horizonBankRot.hpp"
	#include "weaponInfo.hpp"
	#include "CCIP.hpp"
}; // Draw
