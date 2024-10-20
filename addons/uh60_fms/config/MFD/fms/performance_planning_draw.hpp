TEXT_FMS_C(HEADER_TEXT,0.5,FMS_YHEAD)
	source = "static";
	text = "PERFORMANCE CALC";
}; // HEADER_TEXT


TEXT_FMS_C_STATIC_SCALE(CALC_INFO_1,0.5,0.9,"Cruise calculated at 120kts",0.05)
TEXT_FMS_C_STATIC_SCALE(CALC_INFO_2,0.5,0.27,"",0.06)

TRIANGLE(PAXUP,0.05,0.28,0.8,-1)
TRIANGLE(PAXDN,0.05,0.39,0.8,1)
TEXT_FMS_C_STATIC_SCALE(PAX,0.1,0.31,"Fuel",0.05)
TEXT_FMS_C_STATIC_SCALE(FUEL,0.9,0.31,"Pax",0.05)
TRIANGLE(FUELUP,0.90,0.28,0.8,-1)
TRIANGLE(FUELDN,0.90,0.39,0.8,1)


#define PERF_TABLE_POINTS(X,Y,W,H) \
  {{X - (W/2), Y - (H/2)},1},{{X + (W/2), Y - (H/2)},1},{}, \
  {{X - (W/2), Y + (H/2)},1},{{X + (W/2), Y + (H/2)},1},{}, \
  {{X - (W/2), Y + (H*1.5)},1},{{X + (W/2), Y + (H*1.5)},1},{}, \
  {{X - (W/2) + (W/4*0), Y - (H/2)},1},{{X - (W/2) + (W/4*0), Y + (H*1.5)},1},{}, \
  {{X - (W/2) + (W/4*1), Y - (H/2)},1},{{X - (W/2) + (W/4*1), Y + (H*1.5)},1},{}, \
  {{X - (W/2) + (W/4*2), Y - (H/2)},1},{{X - (W/2) + (W/4*2), Y + (H*1.5)},1},{}, \
  {{X - (W/2) + (W/4*3), Y - (H/2)},1},{{X - (W/2) + (W/4*3), Y + (H*1.5)},1},{}, \
  {{X - (W/2) + (W/4*4), Y - (H/2)},1},{{X - (W/2) + (W/4*4), Y + (H*1.5)},1}


#define PERF_TABLE_POINTS_HALF(X,Y,W,H) \
  {{X - (W/2), Y - (H/2)},1},{{X + (W/2), Y - (H/2)},1},{}, \
  {{X - (W/2), Y + (H/2)},1},{{X + (W/2), Y + (H/2)},1},{}, \
  {{X - (W/2) + (W/4*0), Y - (H/2)},1},{{X - (W/2) + (W/4*0), Y + (H/2)},1},{}, \
  {{X - (W/2) + (W/4*1), Y - (H/2)},1},{{X - (W/2) + (W/4*1), Y + (H/2)},1},{}, \
  {{X - (W/2) + (W/4*2), Y - (H/2)},1},{{X - (W/2) + (W/4*2), Y + (H/2)},1},{}, \
  {{X - (W/2) + (W/4*3), Y - (H/2)},1},{{X - (W/2) + (W/4*3), Y + (H/2)},1},{}, \
  {{X - (W/2) + (W/4*4), Y - (H/2)},1},{{X - (W/2) + (W/4*4), Y + (H/2)},1}


#define TABLE_POINTS_TWO(X,Y,W,H) \
  {{X - (W/2), Y - (H/2)},1},{{X + (W/2), Y - (H/2)},1},{}, \
  {{X - (W/2), Y + (H/2)},1},{{X + (W/2), Y + (H/2)},1},{}, \
  {{X - (W/2) + (W/2*0), Y - (H/2)},1},{{X - (W/2) + (W/2*0), Y + (H/2)},1},{}, \
  {{X - (W/2) + (W/2*1), Y - (H/2)},1},{{X - (W/2) + (W/2*1), Y + (H/2)},1},{}, \
  {{X - (W/2) + (W/2*2), Y - (H/2)},1},{{X - (W/2) + (W/2*2), Y + (H/2)},1},{}


#define PERF_OUTPUT_OFFSET 0.05

TEXT_FMS_C_STATIC_SCALE(EMPTY_AMMO,0.5,0.25-0.025,"EMPTY   AMMO  ",0.05)
TEXT_FMS_C_STATIC_SCALE(EMPTY_AMMO_VAL,0.5,0.30-0.025,"12345 lb  1234 lb   ",0.05)
TEXT_FMS_C_STATIC_SCALE(FUEL_PAX,0.5,0.25-0.025+0.1,"FUEL   PAX   ",0.05)
TEXT_FMS_C_STATIC_SCALE(FUEL_PAX_VAL,0.5,0.30-0.025+0.1,"12345 lb  1 PAX    ",0.05)

class table {
  type="line";
  width = 5;
  points[] ={
    TABLE_POINTS_TWO(0.5,0.25,0.6,0.05),{},
    TABLE_POINTS_TWO(0.5,0.30,0.6,0.05),{},
    TABLE_POINTS_TWO(0.5,(0.25+0.1),0.6,0.05),{},
    TABLE_POINTS_TWO(0.5,(0.30+0.1),0.6,0.05),{},
    PERF_TABLE_POINTS(0.5,0.5+PERF_OUTPUT_OFFSET,0.9,0.05),{},
    PERF_TABLE_POINTS(0.5,0.675+PERF_OUTPUT_OFFSET,0.9,0.05),{}
  };
}; // HEADER_BARS


TEXT_FMS_C_STATIC_SCALE(Q_LBL,0.5,0.405+PERF_OUTPUT_OFFSET,"Q",0.05)
TEXT_FMS_C_STATIC_SCALE(CRUISE_HOVER,0.5,0.425+PERF_OUTPUT_OFFSET,"CRUISE      HOVER   ",0.05)
TEXT_FMS_L_STATIC_SCALE(HEADERS_TABLE_1,0.125,0.475+PERF_OUTPUT_OFFSET,"IGE    OGE    IGE    OGE",0.05)
TEXT_FMS_L_STATIC_SCALE(Q_VALUES,0.1,0.525+PERF_OUTPUT_OFFSET,"123456-123456-123456-123456",0.05)


TEXT_FMS_C_STATIC_SCALE(FUEL_HEADER,0.5,0.575+PERF_OUTPUT_OFFSET,"FUEL FLOW",0.05)
TEXT_FMS_L_STATIC_SCALE(FUEL_ROW_1,0.1,0.675+PERF_OUTPUT_OFFSET-0.025,"1lb/hr 1lb/hr 1lb/hr 1lb/hr",0.05)
TEXT_FMS_L_STATIC_SCALE(FUEL_ROW_2,0.1,0.675+PERF_OUTPUT_OFFSET+0.025,"090min 090min 090min 090min",0.05)