#define ANIMATED(ANIM,POINT) (_vehicle animationPhase ANIM == POINT)
#define ANIM(ANIM) (_vehicle animationPhase ANIM)
#define SET_ANIM(ANIM,PHASE) (_vehicle animate [ANIM,PHASE,true])
#define GET(VAR,DEFAULT) (_vehicle getVariable [VAR, DEFAULT])
#define SET(VAR,VAL) (_vehicle setVariable [VAR, VAL])
#define SET_GLOBAL(VAR,VAL) (_vehicle setVariable [VAR, VAL, true])
#define POWER_CONSUME(NUM) (SET("POWER_DRAIN_RATE",(GET("POWER_DRAIN_RATE",0)+NUM)))
#define BATT_POWER ((_vehicle getVariable ["BATT1_POWER", 0]) + (_vehicle getVariable ["BATT1_POWER", 0]))
#define BATT_POWER_CHANGE(BATT,RATE) _vehicle setVariable [BATT, (_vehicle getVariable BATT) + (RATE) min 100 max 0];
#define BATT_ON ((_vehicle animationPhase "Switch_batt1" < 0.1) && (_vehicle animationPhase "Switch_batt2" < 0.1))
#define BATT_ON_AND_POWERED (BATT_ON && BATT_POWER > 0)

#define TO_FT(M) (M*3.28084)
#define TO_M(FT) (FT*0.3048)
#define TO_KTS(KMH) (KMH*0.539957)
#define TO_KMH(KTS) (KTS*1.852)
#define SPEED_KTS (TO_KTS((speed _vehicle)))
#define TO_MS(FPM) (FPM/196.85)

#define RALT_ANIM_STR "FD_1_ROT"
#define ALTP_ANIM_STR "FD_2_ROT"
#define ALT_ANIM_STR "FD_3_ROT"
#define IAS_ANIM_STR "FD_4_ROT"
#define HDG_ANIM_STR "FD_5_ROT"

#define GET_RALT ((round (ANIM(RALT_ANIM_STR)*10))*10)
#define GET_ALT    ((round (ANIM(ALT_ANIM_STR)*10))*100)
#define GET_ALTP ((round (ANIM(ALTP_ANIM_STR)*10))*100)
#define GET_IAS    ((round (ANIM(IAS_ANIM_STR)*10))*10)
#define GET_HDG    ((round (ANIM(HDG_ANIM_STR)))*36)
#define GET_VS     (GET("vs_val",0))

#define SET_RALT(FT) (SET_ANIM(RALT_ANIM_STR,(round(FT/10)/10)))
#define SET_ALT(FT)    (SET_ANIM(ALT_ANIM_STR,(round(FT/10)/100)))
#define SET_ALTP(FT) (SET_ANIM(ALTP_ANIM_STR,(round(FT/10)/100)))
#define SET_IAS(KTS) (SET_ANIM(IAS_ANIM_STR,(round(KTS/10)/10)))
#define SET_HDG(DEG) (SET_ANIM(HDG_ANIM_STR,(round(DEG/10)/36)))
#define SET_VS(FPM)    (SET_GLOBAL("vs_val",FPM))

#define GET_RALT_STATE GET("ralt",false)
#define GET_ALT_STATE    GET("alt",false)
#define GET_ALTP_STATE GET("altp",false)
#define GET_IAS_STATE    GET("ias",false)
#define GET_HDG_STATE    GET("hdg",false)
#define GET_VS_STATE     GET("vs",false)

#define CYCLE_RALT_STATE SET_GLOBAL("ralt",!GET_RALT_STATE)
#define CYCLE_ALT_STATE    SET_GLOBAL("alt",!GET_ALT_STATE)
#define CYCLE_ALTP_STATE SET_GLOBAL("altp",!GET_ALTP_STATE)
#define CYCLE_IAS_STATE    SET_GLOBAL("ias",!GET_IAS_STATE)
#define CYCLE_HDG_STATE    SET_GLOBAL("hdg",!GET_HDG_STATE)
#define CYCLE_VS_STATE     SET_GLOBAL("vs",!GET_VS_STATE)

#define SET_RALT_STATE(VAL) SET_GLOBAL("ralt",VAL)
#define SET_ALT_STATE(VAL)    SET_GLOBAL("alt",VAL)
#define SET_ALTP_STATE(VAL) SET_GLOBAL("altp",VAL)
#define SET_IAS_STATE(VAL)    SET_GLOBAL("ias",VAL)
#define SET_HDG_STATE(VAL)    SET_GLOBAL("hdg",VAL)
#define SET_VS_STATE(VAL)     SET_GLOBAL("vs",VAL)

#define LIGHT_TEXTURE(VAL) (if (VAL) then [{"#(rgb,8,8,3)color(0,1,0,1)"},{""}])
