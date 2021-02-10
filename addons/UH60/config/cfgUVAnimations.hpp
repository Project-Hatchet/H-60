class UVAnimations
{
	class MFD1_MapX
	{
		type                        = translation;
		source                    = MAP_X;
		section                 = MAP_MFD1;
		minValue		= 0;
		maxValue 		= 1;
		offset0[]		= {-0.5,0};
		offset1[]		= {0.5,0};
	};
	class MFD2_MapX: MFD1_MapX {section = MAP_MFD2;};
	class MFD3_MapX: MFD1_MapX {section = MAP_MFD3;};
	class MFD4_MapX: MFD1_MapX {section = MAP_MFD4;};
	//class MFD1_OverlayX: MFD1_MapX {section = MAP_OVERLAY1;};
	//class MFD2_OverlayX: MFD1_MapX {section = MAP_OVERLAY2;};
	//class MFD3_OverlayX: MFD1_MapX {section = MAP_OVERLAY3;};
	//class MFD4_OverlayX: MFD1_MapX {section = MAP_OVERLAY4;};

	class MFD1_MapY
	{
		type                        = translation;
		source                    = MAP_Y;
		section                 = MAP_MFD1;
		minValue 		= 0;
		maxValue 		= 1;
		offset0[]		= {0,0.5};
		offset1[]		= {0,-0.5};
	};
	class MFD2_MapY: MFD1_MapY {section = MAP_MFD2;};
	class MFD3_MapY: MFD1_MapY {section = MAP_MFD3;};
	class MFD4_MapY: MFD1_MapY {section = MAP_MFD4;};
	//class MFD1_OverlayY: MFD1_MapY {section = MAP_OVERLAY1;};
	//class MFD2_OverlayY: MFD1_MapY {section = MAP_OVERLAY2;};
	//class MFD3_OverlayY: MFD1_MapY {section = MAP_OVERLAY3;};
	//class MFD4_OverlayY: MFD1_MapY {section = MAP_OVERLAY4;};

	class MFD1_MapScale
	{
		type                        = scale;
		source                    = MAP1_Scale;
		section                 = MAP_MFD1;
		minValue                = 0;
		maxValue                = 1;
		center[] 		= { 0.5, 0.5 };
		scale0[] 		= {1,1};
		scale1[] 		= {0.2,0.2};
	};
	class MFD2_MapScale: MFD1_MapScale {section = MAP_MFD2;};
	class MFD3_MapScale: MFD1_MapScale {section = MAP_MFD3;};
	class MFD4_MapScale: MFD1_MapScale {section = MAP_MFD4;};
	//class MFD1_OverlayScale: MFD1_MapScale {section = MAP_OVERLAY1;};
	//class MFD2_OverlayScale: MFD1_MapScale {section = MAP_OVERLAY2;};
	//class MFD3_OverlayScale: MFD1_MapScale {section = MAP_OVERLAY3;};
	//class MFD4_OverlayScale: MFD1_MapScale {section = MAP_OVERLAY4;};

	class MFD1_MapRotation
	{
		type                        = rotate;
		source                    = MAP_Rotation;
		section                 = MAP_MFD1;
		minValue		= "0";
		maxValue 		= "360";
		center[] 		= { 0.5, 0.5 };
		angle0 			= "rad 0";
		angle1 			= "rad +360";
	};
	class MFD2_MapRotation: MFD1_MapRotation {section = MAP_MFD2;};
	class MFD3_MapRotation: MFD1_MapRotation {section = MAP_MFD3;};
	class MFD4_MapRotation: MFD1_MapRotation {section = MAP_MFD4;};
	//class MFD1_OverlayRotation: MFD1_MapRotation {section = MAP_OVERLAY1;};
	//class MFD2_OverlayRotation: MFD1_MapRotation {section = MAP_OVERLAY2;};
	//class MFD3_OverlayRotation: MFD1_MapRotation {section = MAP_OVERLAY3;};
	//class MFD4_OverlayRotation: MFD1_MapRotation {section = MAP_OVERLAY4;};
};
