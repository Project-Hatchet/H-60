#define MOVE_LEFT    minMoveX
#define MOVE_RIGHT maxMoveX

#define PILOTVIEW \
initFov=1; \
minFov=0.25; \
maxFov=0.80000001; \
initAngleX=-5; \
minAngleX=-75; \
maxAngleX=89; \
initAngleY=0; \
minAngleY=-150; \
maxAngleY=150; \
MOVE_LEFT = -0.5; \
MOVE_RIGHT = 0.2; \
minMoveY = -0.2; \
maxMoveY = 0.1; \
minMoveZ = -0.2; \
maxMoveZ = 0.25;

#define COPILOTVIEW \
initFov=1; \
minFov=0.25; \
maxFov=0.80000001; \
initAngleX=-5; \
minAngleX=-75; \
maxAngleX=89; \
initAngleY=0; \
minAngleY=-150; \
maxAngleY=150; \
MOVE_LEFT = -0.2; \
MOVE_RIGHT = 0.5; \
minMoveY = -0.2; \
maxMoveY = 0.1; \
minMoveZ = -0.2; \
maxMoveZ = 0.25;
