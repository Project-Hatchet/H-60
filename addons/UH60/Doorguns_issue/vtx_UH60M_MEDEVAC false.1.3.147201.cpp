class vtx_UH60M_MEDEVAC: vtx_UH60M
{
	scope = 2;
	displayName = "UH-60M MEDEVAC";
	transportSoldier = 0;
	cargoProxyIndexes[] = {};
	cargoAction[] = {};
	class AnimationSources: AnimationSources
	{
		class CabinSeats_Hide
		{
			source = "user";
			animPeriod = 1;
			initPhase = 1;
		};
		class GunnerSeats_Hide
		{
			source = "user";
			animPeriod = 1;
			initPhase = 1;
		};
		class Minigun_Mount_L_hide
		{
			source = "user";
			animPeriod = 1;
			initPhase = 1;
		};
		class Minigun_Mount_R_hide
		{
			source = "user";
			animPeriod = 1;
			initPhase = 1;
		};
		class Minigun_L_hide
		{
			source = "user";
			animPeriod = 1;
			initPhase = 1;
		};
		class Minigun_R_hide
		{
			source = "user";
			animPeriod = 1;
			initPhase = 1;
		};
	};
	class Turrets: Turrets
	{
		class MainTurret: MainTurret
		{
			hasGunner = 0;
		};
		class RightDoorGun: MainTurret
		{
			hasGunner = 0;
		};
	};
	class VehicleTransport
	{
		class Carrier
		{
			cargoBayDimensions[] = {"VTV_slick_1", "VTV_slick_2"};
			disableHeightLimit = 1;
			maxLoadMass = 4100;
			cargoAlignment[] = {"back", "right"};
			cargoSpacing[] = {0.1, 0.1, 0.1};
			exits[] = {"VTV_exit_1", "VTV_exit_2"};
			unloadingInterval = 2;
			loadingDistance = 5;
			loadingAngle = 60;
			parachuteClassDefault = "B_Parachute_02_F";
			parachuteHeightLimitDefault = 50;
		};
	};
};
