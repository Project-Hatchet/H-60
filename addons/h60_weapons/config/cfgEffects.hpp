class hct_agm114_trail
{
	class FX_Missile_AA_light_01
	{
		simulation = "light";
		type = "RocketLight";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class hct_h60_missileTrail
	{
		simulation = "particles";
		type = "hct_h60_missileTrail";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};

class hct_agm114_explosion
{
	class LightExp
	{
		simulation = "light";
		type = "ExploLight";
		position[] = {0,1.5,0};
		intensity = 0.001;
		interval = 3;
		lifeTime = 0.25;
	};
	class Explosion1
	{
		simulation = "particles";
		type = "hct_h60_explosionCloudCenter";
		position[] = {0,0,0};
		intensity = 34;
		interval = 1;
		lifeTime = 0.25;
	};
	class SmallSmoke1
	{
		simulation = "particles";
		type = "hct_h60_explosionCloud";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.5;
	};
};
