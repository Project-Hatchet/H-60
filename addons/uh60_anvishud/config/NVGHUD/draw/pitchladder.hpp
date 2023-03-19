#define PITCH_LINE(BONE,X) {BONE, {X-0.04, 0}, 1},{BONE, {X+0.04, 0}, 1},{}
class PitchLadder {
  type="line";
  width = 4;
  points[] ={
    PITCH_LINE("Level0",0),
    PITCH_LINE("Level0",-0.1),PITCH_LINE("Level0",-0.2),PITCH_LINE("Level0",-0.3),
    PITCH_LINE("Level0",00.1),PITCH_LINE("Level0",00.2),PITCH_LINE("Level0",00.3),
    PITCH_LINE("P10_pos",0),PITCH_LINE("P10_neg",0),
    PITCH_LINE("P20_pos",0),PITCH_LINE("P20_neg",0),
    PITCH_LINE("P30_pos",0),PITCH_LINE("P30_neg",0)
  }; // points
}; // FOVCenter