#ifdef BARTOP
    #undef BARTOP
#endif
#define BARTOP 0.209
#ifdef BARBOTTOM
    #undef BARBOTTOM
#endif
#define BARBOTTOM 0.417

//Main Rotor
class EICAS_RPM { //Good
    type        ="linear";
    source      = "user";
    //source="rpm";
    sourceIndex = 17;
    min         = 0;
    max         = 130;
    sourceScale = 1;
    minPos[]    = {0,BARTOP};
    maxPos[]    = {0,BARBOTTOM};
};

//Engine 1
class NG1 { //Good
    type        ="linear";
    source      = "user";
    sourceIndex = 19;
    min         = 0;
    max         = 120;
    sourceScale = 1;
    minPos[]    = {0,BARTOP};
    maxPos[]    = {0,BARBOTTOM};
};
class EICAS_RPM1 { //Good
    type        ="linear";
    source      = "user";
    sourceIndex = 20;
    min         = 0;
    max         = 130;
    sourceScale = 1;
    minPos[]    = {0,BARTOP};
    maxPos[]    = {0,BARBOTTOM};
};
class TGT1 { //Good
    type        ="linear";
    source      = "user";
    sourceIndex = 21;
    min         = 0;
    max         = 1023;
    sourceScale = 1;
    minPos[]    = {0,BARTOP};
    maxPos[]    = {0,BARBOTTOM};
};
class Q1 {
    type        = "linear";
    source      = "user";
    sourceIndex = 22;
    min         = 0;
    max         = 120;
    sourceScale = 1;
    minPos[]    = {0,BARTOP};
    maxPos[]    = {0,BARBOTTOM};
};

//Engine 2
class NG2: NG1{ //Good
    sourceIndex = 45;
};
class EICAS_RPM2: EICAS_RPM1 { //Good      
    sourceIndex = 46;
};
class TGT2: TGT1 { //Good
    sourceIndex = 47;
};
class Q2: Q1 {
    sourceIndex = 48;    
};

//Miscellaneous

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
//Each main tank, lb, full at 547 kg (1206 lb)
class EICAS_Fuel1: EICAS_Fuel
{
    source="user";
    sourceIndex=USERMFDV_FUEL1;
    max=1206;
};
class EICAS_Fuel2: EICAS_Fuel1
{
    sourceIndex=USERMFDV_FUEL2;
};
