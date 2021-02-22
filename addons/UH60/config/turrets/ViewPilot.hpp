// Field of View Limits
initFov = 1;
minFov = 0.3;
maxFov = 1.2;

// Head tilt up and down limits
initAngleX = 0;
minAngleX = -75; // -65
maxAngleX = 85;

// Head rotate left and right limits
initAngleY = 0;
minAngleY = -170;
maxAngleY = 170;

//How far can the head be moved to the sides left and right
minMoveX = -0.30;//-0.1;
maxMoveX = 0.30;//0.1;

//How far can the head be moved up and down
minMoveY = -0.025;//-0.025;  // CHANGING THIS TO -1 HAS NO EFFECT // 0.5 SEEMS OK
maxMoveY = 0.1;//0.05;

//How far can the head be moved forward and backward
minMoveZ = -0.30;//-0.1;
maxMoveZ = 0.30;//0.1;

speedZoomMaxSpeed=0;
speedZoomMaxFOV=1;
