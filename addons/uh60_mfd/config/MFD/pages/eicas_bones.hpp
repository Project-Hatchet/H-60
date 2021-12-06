#ifdef BARTOP
    #undef BARTOP
#endif
#define BARTOP 0.209
#ifdef BARBOTTOM
    #undef BARBOTTOM
#endif
#define BARBOTTOM 0.417

/*
#define RANDOMPERC(BASE,RAND) __EXEC(BASE + random RAND)
__EXEC(vtx_t1 = 1.45 + random 0.05;)
__EXEC(vtx_t2 = 1.45 + random 0.05;)

__EXEC(vtx_ng1 = 0.95 + random 0.05;)
__EXEC(vtx_ng2 = 0.95 + random 0.05;)

__EXEC(vtx_tgt1 = 7.85 + random 0.15;)
__EXEC(vtx_tgt2 = 7.85 + random 0.15;)

__EXEC(vtx_Q1 = 0.95 + random 0.05;)
__EXEC(vtx_Q2 = 0.95 + random 0.05;)
class EICAS_RPM1
{
    type="linear";
    source="user";
    sourceIndex=21;
    sourceScale=1;
    min=0;
    max=130;
    minPos[]={0,BARTOP};
    maxPos[]={0,BARBOTTOM};
};
class RPM2: EICAS_RPM1 {
    source="user";
    sourceIndex=22;
};
class T1: EICAS_RPM1 {
    source="user";
    sourceScale=1;
    sourceIndex=21;
    max=160;
};
class T2: EICAS_RPM1 {
    sourceIndex=22;
    sourceScale=1;
    max=160;
};
class NG1: T1 {max=120;sourceScale=1;};
class NG2: T2 {max=120;sourceScale=1;};
class TGT1: T1 {max=900;sourceScale=1;};
class TGT2: T2 {max=900;sourceScale=1;};
class Q1: T1 {max=120;sourceScale=1;};
class Q2: T2 {max=120;sourceScale=1;};
class TRQ: EICAS_RPM1 {
    source="rtdRotorTorque";
    max=0.1;
};
class COLL: EICAS_RPM1 {
    min=0;
    max=1;
    sourceScale=1;
    source="rtdCollective";
};

class RPM: EICAS_RPM1 {
    min=0;
    max=10;
    source="rpm"
};
*/
class EICAS_RPM1
{
    type="linear";
            source="user";
            sourceIndex=21;
            sourceScale=1;
            min=0;
            max=130;
    minPos[]={0,BARTOP};
    maxPos[]={0,BARBOTTOM};
};
class EICAS_RPM2: EICAS_RPM1 {
            source="user";
            sourceIndex=22;
};
class T1: EICAS_RPM1 {
    source="user";
            sourceScale=1;
            sourceIndex=21;
            max=160;
};
class T2: EICAS_RPM1 {
    sourceIndex=22;
            sourceScale=1;
            max=160;
};
class NG1: T1 {max=120;sourceScale=1;};
    class NG2: T2 {max=120;sourceScale=1;};
    class TGT1: T1 {max=520;sourceScale=5;};
    class TGT2: T2 {max=520;sourceScale=5;};
    class Q1: T1 {max=120;sourceScale=1;};
    class Q2: T2 {max=120;sourceScale=1;};
    class TRQ: EICAS_RPM1 {
            source="rtdRotorTorque";
            max=0.1;
    };
    class COLL: EICAS_RPM1 {
            min=0;
            max=1;
            sourceScale=1;
            source="rtdCollective";
    };

class EICAS_RPM: EICAS_RPM1 {
            min=0;
            max=10;
            source="rpm";
};

#ifdef FUEL_BARS_Y1
    #undef FUEL_BARS_Y1
#endif
#ifdef FUEL_BARS_Y2
    #undef FUEL_BARS_Y2
#endif
#define FUEL_BARS_Y1 0.635
#define FUEL_BARS_Y2 0.775
class EICAS_Fuel
{
    type="linear";
    source="fuel";
    sourceScale=1;
    min=0;
    max=1;
    minPos[]={0,FUEL_BARS_Y1};
    maxPos[]={0,FUEL_BARS_Y2};
}; // Fuel