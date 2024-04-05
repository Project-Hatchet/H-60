class vtx_Internal_Base
{
	volumefactor=vtx_Vol_Multi_Int(0.3);
	spatial=0;
	loop=1;
};
class vtx_External_Base
{
	sound3dprocessingtype="vtx_Close_3DProcessor";
	distancefilter="vtx_Close_Engine_Filter";
	volumecurve="vtx_Ext_Base_Curve";
	occlusionObstruction=1;
	occlusionFactor=0.3;
	obstructionFactor=0.2;
	volumefactor=1;
	spatial=1;
	loop=1;
};
class vtx_Standard_External_Base: vtx_External_Base
{
	sound3dprocessingtype="default3DProcessingType";
};

//External

// -Empty
class vtx_Empty_SoundSet: vtx_External_Base
{
	soundshaders[]=
	{
		"vtx_Empty_SoundShader"
	};
};

// -Alarm
class vtx_Alarm_Damage_Ext_SoundSet_Base: vtx_Standard_External_Base
{
	soundshaders[]=
	{
		"vtx_Alarm_Damage_Ext_SoundShader_Base"
	};
	volumefactor=0.2;
};
class vtx_Alarm_RotorLow_Ext_SoundSet_Base: vtx_Alarm_Damage_Ext_SoundSet_Base
{
	soundshaders[]=
	{
		"vtx_Alarm_RotorLow_Ext_SoundShader_Base"
	};
};

// -Scrub Sound
class vtx_ScrubTree_Ext_SoundSet_Base: vtx_Standard_External_Base
{
	soundshaders[]=
	{
		"vtx_ScrubTree_Ext_SoundShader_Base"
	};
	volumefactor=0.5;
};

// -Damage
class vtx_TransmissionDamage_Ext_phase1_SoundSet_Base: vtx_Standard_External_Base
{
	soundshaders[]=
	{
		"vtx_TransmissionDamage_Ext_phase1_SoundShader_Base"
	};
	volumefactor=0.4;
};
class vtx_TransmissionDamage_Ext_phase2_SoundSet_Base: vtx_TransmissionDamage_Ext_phase1_SoundSet_Base
{
	soundshaders[]=
	{
		"vtx_TransmissionDamage_Ext_phase2_SoundShader_Base"
	};
};

//-SlingLoad
class vtx_SlingLoadDown_Ext_SoundSet_Base: vtx_Standard_External_Base
{
	soundshaders[]=
	{
		"vtx_SlingLoadDown_Ext_SoundShader_Base"
	};
	volumefactor=0.2;
};
class vtx_SlingLoadUp_Ext_SoundSet_Base: vtx_SlingLoadDown_Ext_SoundSet_Base
{
	soundshaders[]=
	{
		"vtx_SlingLoadUp_Ext_SoundShader_Base"
	};
};
//-Noise
class vtx_Rain_Ext_SoundSet_Base: vtx_Standard_External_Base
{
	soundshaders[]=
	{
		"vtx_Rain_Ext_SoundShader_Base"
	};
	volumefactor=0.25;
};
class vtx_Rotor_Stress_Ext_SoundSet_Base: vtx_External_Base
{
	soundshaders[]=
	{
		"vtx_Rotor_Stress_Ext_SoundShader_Base"
	};
};
class vtx_Wind_Close_Ext_SoundSet_Base: vtx_External_Base
{
	soundshaders[]=
	{
		"vtx_Wind_Close_Ext_SoundShader_Base"
	};
	volumefactor=0.15;
	sound3dprocessingtype="vtx_WindWash_3DProcessor";
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Internal
// -Alarm
class vtx_Alarm_Damage_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_Alarm_Damage_Int_SoundShader_Base"
	};
	volumefactor=vtx_Vol_Multi_Int(2);
};
class vtx_Alarm_RotorLow_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_Alarm_RotorLow_Int_SoundShader_Base"
	};
	volumefactor=vtx_Vol_Multi_Int(2);
};

// -Scrub Sound
class vtx_ScrubLand_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_ScrubLand_Int_SoundShader_Base"
	};
};
class vtx_ScrubBuilding_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_ScrubBuilding_Int_SoundShader_Base"
	};
};
class vtx_ScrubTree_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_ScrubTree_Int_SoundShader_Base"
	};
};

// -Damage
class vtx_TransmissionDamage_Int_phase1_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_TransmissionDamage_Int_phase1_SoundShader_Base"
	};
};
class vtx_TransmissionDamage_Int_phase2_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_TransmissionDamage_Int_phase2_SoundShader_Base"
	};
};
class vtx_TransmissionDamage_Int_phase3_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_TransmissionDamage_Int_phase3_SoundShader_Base"
	};
};

//-SlingLoad
class vtx_SlingLoadDown_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_SlingLoadDown_Int_SoundShader_Base"
	};
};
class vtx_SlingLoadUp_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_SlingLoadUp_Int_SoundShader_Base"
	};
};

//-Noise
class vtx_Rain_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_Rain_Int_SoundShader_Base"
	};
	volumefactor=vtx_Vol_Multi_Int(0.5);
};
class vtx_Wind_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_Wind_Int_SoundShader_Base"
	};
};
class vtx_WindWash_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_WindWash_Int_SoundShader_Base"
	};
	volumeFactor=vtx_Vol_Multi_Int(1.2);
};
class vtx_WindWash_Int_Transport_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_WindWash_Int_Transport_SoundShader_Base"
	};
	volumeFactor=vtx_Vol_Multi_Int(5);
};
class vtx_FrameStress_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_FrameStress_Int_SoundShader_Base"
	};
	volumeFactor=vtx_Vol_Multi_Int(0.8);
};
class vtx_GStress_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_GStress_Int_SoundShader_Base"
	};
	volumeFactor=vtx_Vol_Multi_Int(0.45);
};
class vtx_SpeedStress_Int_SoundSet_Base: vtx_Internal_Base
{
	soundshaders[]=
	{
		"vtx_SpeedStress_Int_SoundShader_Base"
	};
};

#include "Engine_SoundSets.hpp"