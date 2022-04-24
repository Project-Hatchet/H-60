class HitPoints
{		
	class hithrotor 	
	{	
		armor = 1.35;
		radius = 0.47 ;
		minimalHit = 0.1;
		explosionShielding =3;
		name = "hithrotor";
		material = 51;
		passThrough = 0;
	};	
	class hitvrotor	
	{	
		armor = 0.81;
		radius = 0.24;
		minimalHit = 0.1;
		explosionShielding =0.270;
		name = "hitvrotor";
		material = 51;
		visual = "munice";
		passThrough = 0;
	};	
	class TailGearBox	
	{	
		armor = 1.08;
		radius = 0.69;
		name = "TailGearBox";
		explosionShielding =0.360;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class RearAutoStab	
	{	
		armor = 0.18;
		radius = 0.14;
		name = "RearAutoStab";
		explosionShielding =0.100;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class TailIntermediateGearBox	
	{	
		armor = 0.54;
		radius = 0.22;
		name = "TailIntermediateGearBox";	
		explosionShielding =0.300;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class FlightComp1	
	{	
		armor = 0.36;
		radius = 0.35;
		name = "FlightComp1";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};				
	class ApuHit	
	{	
		armor = 0.72;
		radius = 0.46;
		name = "ApuHit";
		explosionShielding =0.400;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class HitEngine {
		armor = 999;
		depends = "0.5 * (HitEngine1 + HitEngine2)";
		explosionShielding = 1;
		minimalHit = 1;
		name = "hitEngine";
		passThrough = 0;
		radius = 0.05;
	};	
	class hitengine1	
	{	
		armor = 1.08;
		radius = 0.59;
		name = "hitengine1";
		explosionShielding =0.360;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};		
	class hitengine2	
	{	
		armor = 1.08;
		radius = 0.59;
		name = "hitengine2";
		explosionShielding =0.360;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
		
	class SlingHit	
	{	
		armor = 0.3;
		material = 51;
		name = "SlingHit";
		visual = "";
		passThrough = 0;
		radius = 0.2;
		class DestructionEffects
		{
			ammoExplosionEffect = "";				
			class Explo				
			{				
				simulation = "particles";			
				type = "WinchDestructionExplo";			
				position = "slingLoad0";			
				intensity = 1;			
				interval = 1;			
				lifeTime = 0.06;			
			};				
			class Sparks				
			{				
				simulation = "particles";			
				type = "WinchDestructionSparks";			
				position = "slingLoad0";			
				intensity = 1;			
				interval = 1;			
				lifeTime = 0.1;			
			};				
		};
	};	
	class HoistHit	
	{	
		armor = 0.38;
		radius = 0.26;
		name = "HoistHit";
		explosionShielding =0.211;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class HoistHookHit	
	{	
		armor = 0.38;
		radius = 0.13;
		name = "HoistHookHit";
		explosionShielding =0.211;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class MainRotorGearBox	
	{	
		armor = 1.08;
		radius = 0.44;
		name = "MainRotorGearBox";
		explosionShielding =0.599;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class MainRotorHub	
	{	
		armor = 0.96;
		radius = 1.01;
		name = "MainRotorHub";
		explosionShielding =0.533;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class WingStores	
	{	
		armor = 0.54;
		radius = 0.4;
		name = "WingStores";
		explosionShielding =0.300;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class AirDataComp	
	{	
		armor = 0.36;
		radius = 0.12;
		name = "AirDataComp";
		explosionShielding =0.150;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class FlirHit	
	{	
		armor = 0.36;
		radius = 0.35;
		name = "FlirHit";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class ProbTip	
	{	
		armor = 0.36;
		radius = 0.21;
		name = "FuelProbTip";
		explosionShielding =0.599;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class EgiComp	
	{	
		armor = 0.47;
		radius = 0.28;
		name = "EgiComp";
		explosionShielding =0.261;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class Battery1	
	{	
		armor = 0.47;
		radius = 0.21;
		name = "Battery1";
		explosionShielding =0.261;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class Battery2	
	{	
		armor = 0.47;
		radius = 0.21;
		name = "Battery2";
		explosionShielding =0.261;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class FlightControlComp2
	{	
		armor = 0.48;
		radius = 0.35;
		name = "FlightControlComp2";
		explosionShielding =0.266;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class MFD1	
	{	
		armor = 0.36;
		radius = 0.21;
		name = "MFD1";
		explosionShielding =0.200;		
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class MFD2
	{	
		armor = 0.36;
		radius = 0.21;
		name = "MFD2";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class MFD3
	{	
		armor = 0.36;
		radius = 0.21;
		name = "MFD3";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
	class MFD4
	{
		armor = 0.36;
		radius = 0.21;
		name = "MFD4";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};
	class Flare1	
	{	
		armor = 0.36;
		radius = 0.3;
		name = "Flare1";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
		class Flare2
	{	
		armor = 0.36;
		radius = 0.3;
		name = "Flare2";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
		class Flare3
	{	
		armor = 0.36;
		radius = 0.3;
		name = "Flare3";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
		class HHFlare1
	{	
		armor = 0.36;
		radius = 0.3;
		name = "HHFlare1";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
		class HHFlare2
	{	
		armor = 0.36;
		radius = 0.3;
		name = "HHFlare2";
		explosionShielding =0.200;
		minimalHit = 0.1;
		passThrough = 0;
		material = 51;
	};	
};		