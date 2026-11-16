class hct_Internal_Base
{
	volumefactor=hct_Vol_Multi_Int(0.3);
	spatial=0;
	loop=1;
};
class hct_External_Base
{
	sound3dprocessingtype="hct_Close_3DProcessor";
	distancefilter="hct_Close_Engine_Filter";
	volumecurve="hct_Ext_Base_Curve";
	occlusionObstruction=1;
	occlusionFactor=0.3;
	obstructionFactor=0.2;
	volumefactor=1;
	spatial=1;
	loop=1;
};
class hct_Standard_External_Base: hct_External_Base
{
	sound3dprocessingtype="default3DProcessingType";
};

//External

// -Empty
class hct_Empty_SoundSet: hct_External_Base
{
	soundshaders[]=
	{
		"hct_Empty_SoundShader"
	};
};

// -Alarm
class hct_Alarm_Damage_Ext_SoundSet_Base: hct_Standard_External_Base
{
	soundshaders[]=
	{
		"hct_Alarm_Damage_Ext_SoundShader_Base"
	};
	volumefactor=0.2;
};
class hct_Alarm_RotorLow_Ext_SoundSet_Base: hct_Alarm_Damage_Ext_SoundSet_Base
{
	soundshaders[]=
	{
		"hct_Alarm_RotorLow_Ext_SoundShader_Base"
	};
};

// -Scrub Sound
class hct_ScrubTree_Ext_SoundSet_Base: hct_Standard_External_Base
{
	soundshaders[]=
	{
		"hct_ScrubTree_Ext_SoundShader_Base"
	};
	volumefactor=0.5;
};

// -Damage
class hct_TransmissionDamage_Ext_phase1_SoundSet_Base: hct_Standard_External_Base
{
	soundshaders[]=
	{
		"hct_TransmissionDamage_Ext_phase1_SoundShader_Base"
	};
	volumefactor=0.4;
};
class hct_TransmissionDamage_Ext_phase2_SoundSet_Base: hct_TransmissionDamage_Ext_phase1_SoundSet_Base
{
	soundshaders[]=
	{
		"hct_TransmissionDamage_Ext_phase2_SoundShader_Base"
	};
};

//-SlingLoad
class hct_SlingLoadDown_Ext_SoundSet_Base: hct_Standard_External_Base
{
	soundshaders[]=
	{
		"hct_SlingLoadDown_Ext_SoundShader_Base"
	};
	volumefactor=0.2;
};
class hct_SlingLoadUp_Ext_SoundSet_Base: hct_SlingLoadDown_Ext_SoundSet_Base
{
	soundshaders[]=
	{
		"hct_SlingLoadUp_Ext_SoundShader_Base"
	};
};
//-Noise
class hct_Rain_Ext_SoundSet_Base: hct_Standard_External_Base
{
	soundshaders[]=
	{
		"hct_Rain_Ext_SoundShader_Base"
	};
	volumefactor=0.25;
};
class hct_Rotor_Stress_Ext_SoundSet_Base: hct_External_Base
{
	soundshaders[]=
	{
		"hct_Rotor_Stress_Ext_SoundShader_Base"
	};
	shape="hct_BottomLess_Shape";
	sound3dprocessingtype="hct_Rotor_3DProcessor";
};
class hct_Wind_Close_Ext_SoundSet_Base: hct_External_Base
{
	soundshaders[]=
	{
		"hct_Wind_Close_Ext_SoundShader_Base"
	};
	volumefactor=0.15;
	sound3dprocessingtype="hct_WindWash_3DProcessor";
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Internal
// -Alarm
class hct_Alarm_Damage_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_Alarm_Damage_Int_SoundShader_Base"
	};
	volumefactor=hct_Vol_Multi_Int(2);
};
class hct_Alarm_RotorLow_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_Alarm_RotorLow_Int_SoundShader_Base"
	};
	volumefactor=hct_Vol_Multi_Int(2);
};

// -Scrub Sound
class hct_ScrubLand_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_ScrubLand_Int_SoundShader_Base"
	};
};
class hct_ScrubBuilding_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_ScrubBuilding_Int_SoundShader_Base"
	};
};
class hct_ScrubTree_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_ScrubTree_Int_SoundShader_Base"
	};
};

// -Damage
class hct_TransmissionDamage_Int_phase1_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_TransmissionDamage_Int_phase1_SoundShader_Base"
	};
};
class hct_TransmissionDamage_Int_phase2_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_TransmissionDamage_Int_phase2_SoundShader_Base"
	};
};
class hct_TransmissionDamage_Int_phase3_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_TransmissionDamage_Int_phase3_SoundShader_Base"
	};
};

//-SlingLoad
class hct_SlingLoadDown_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_SlingLoadDown_Int_SoundShader_Base"
	};
};
class hct_SlingLoadUp_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_SlingLoadUp_Int_SoundShader_Base"
	};
};

//-Noise
class hct_Rain_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_Rain_Int_SoundShader_Base"
	};
	volumefactor=hct_Vol_Multi_Int(0.5);
};
class hct_Wind_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_Wind_Int_SoundShader_Base"
	};
};
class hct_WindWash_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_WindWash_Int_SoundShader_Base"
	};
	volumeFactor=hct_Vol_Multi_Int(1.2);
};
class hct_WindWash_Int_Transport_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_WindWash_Int_Transport_SoundShader_Base"
	};
	volumeFactor=hct_Vol_Multi_Int(5);
};
class hct_FrameStress_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_FrameStress_Int_SoundShader_Base"
	};
	volumeFactor=hct_Vol_Multi_Int(0.8);
};
class hct_GStress_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_GStress_Int_SoundShader_Base"
	};
	volumeFactor=hct_Vol_Multi_Int(0.45);
};
class hct_SpeedStress_Int_SoundSet_Base: hct_Internal_Base
{
	soundshaders[]=
	{
		"hct_SpeedStress_Int_SoundShader_Base"
	};
};

#include "Engine_SoundSets.hpp"
