#define OO(heli) heli##_O
#define CSAT(heli) \
class heli; \
class OO(heli): heli { \
	_generalMacro = QUOTE(OO(heli)); \
	side = 0; \
	faction = "OPF_F"; \
	crew = "O_helipilot_F"; \
	typicalCargo[] = {"O_Soldier_lite_F"}; \
};

class CfgVehicles {
    CSAT(vtx_UH60M)
    CSAT(vtx_HH60)
    CSAT(vtx_MH60M)
    CSAT(vtx_MH60M_DAP)
    CSAT(vtx_MH60S_Pylons_GAU21L)
    CSAT(vtx_MH60S_GAU21L)
    CSAT(vtx_MH60S_Pylons)
    CSAT(vtx_MH60S)
}; // CfgVehicles

#undef OO
#undef CSAT
