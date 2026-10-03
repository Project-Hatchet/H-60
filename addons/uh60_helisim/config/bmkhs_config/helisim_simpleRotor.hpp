/////////////////////////////////////////////////////////////////////////////////////////////
// Rotors - Simple //////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//A rotor is a hub at a position turning blades of a given size, so its geometry, its blade
//and what it does with the controls are defined together here. Core reads numSimpleRotors
//and loops; nothing downstream indexes by rotor NUMBER.
//
//The simple model works four fixed blade positions and scales by blade count, so the lift
//and drag tables carry what the rotor does rather than deriving it per blade element.
//
//  type         - "main" or "tail". What the rotor IS, so Core never assumes rotor 0 is
//                 the main one.
//  direction    - "ccw" or "cw", seen from above.
//  numBlades    - the four modelled positions are scaled to this.
//  pivot[]      - hub position, {lateral, longitudinal, vertical} in m,
//                 right-positive / nose-positive / up-positive
//  rotation[]   - disc orientation, {pitch, roll, yaw} in deg
//  mastLength   - m along the disc's own up axis, from pivot to hub
//  gearRatio    - rotor to engine shaft; shared with the transmission model
//  torqueTau    - s, torque filter time constant
//
//  BLADE
//  bladeRadius  - m
//  bladeChord   - m
//  bladeMass    - kg, one blade
//
//  DISC TILT - min / mid / max in deg, interpolated from the centred stick. A rotor whose
//  disc does not tilt declares zeroes.
//
//  coneAngle    - deg at full collective. Coning lifts the tips, so the thrust position
//                 moves inboard and the disc carries a vertical arm.
//  flapBackRollMax / flapBackPitchMax - deg at an advance ratio of 1.0. The advancing blade
//                 lifts more than the retreating one, so the disc tilts as speed builds.
//                 Applied as blade flap, which moves both the thrust position and its
//                 direction - it is NOT also applied to the lift coefficient.
//  rollLiftCoef / pitchLiftCoef - the cyclic lift coefficient, independent of the
//                 collective's. This is what makes the fore/aft and left/right blades carry
//                 different lift, so the pitch and roll moments come out of real forces at
//                 real positions rather than being applied as a torque.
//  gndEffValue  - thrust multiplier on the deck, fading to 1.0 by one rotor diameter up.
//                 A rotor that does not sit in ground effect declares 1.0.
//  reacTqScalar - scales the tangential blade drag that produces the yaw reaction. The same
//                 drag drives the transmission, which this does not touch.
//
//  liftCoefTable / dragCoefTable - rows are the control axis that loads this rotor
//  (collective for a main, pedal for a tail), columns are the airspeeds in the header row,
//  m/s. The drag table carries induced and profile together, and its airspeed columns carry
//  how they vary with speed - that is what the transmission feels.

//UH-60: geometry (pivots, disc rotation, gear ratios, blades) from the pre-1.1 UH-60 config;
//the rotor is hub-at-pivot there, so mastLength is 0. The flap, lift/drag coefficient and
//torque values are the AH-64D's as a starting tune - same tip speed (221 m/s) and ~10% more
//blade area. Tail disc is canted 20 deg (roll 70); the pedal tables keep the AH-64D's sign for
//a positive-roll tail disc - if yaw comes out reversed, flip the tail liftCoefTable signs.

    numSimpleRotors = 2;
    //Rotor limits, Nr - {normal low, normal high, high rotor, maximum}; below and above normal is transient.
    nrLimits[] = {0.95, 1.05, 1.06, 1.10};
    class SimpleRotors {
        class SimpleRotor01 {
            type             = "main";
            direction        = "ccw";
            numBlades        = 4;
            pivot[]          = {0.00, 1.81, 1.50};
            rotation[]       = {-3.00, 0.00, 0.00};
            mastLength       = 0.00;      //m
            gearRatio        = 80.99;
            torqueTau        = 0.10;      //s

            bladeRadius      = 8.178;     //m
            bladeChord       = 0.527;     //m
            bladeMass        = 107.226;    //kg

            pitchFlapMin     = -10.0;     //deg
            pitchFlapMid     =   0.0;
            pitchFlapMax     =  20.0;
            rollFlapMin      = -10.5;
            rollFlapMid      =   0.0;
            rollFlapMax      =   7.0;

            coneAngle        = 12.0;  //deg at full collective
            flapBackRollMax  = 15.0;  //deg per unit advance ratio
            flapBackPitchMax =  9.0;  //deg per unit advance ratio
            rollLiftCoef     = 0.19;
            pitchLiftCoef    = 0.72;
            gndEffValue      = 1.225;
            reacTqScalar     = 0.50;
            autoTorque       = 80.0;

            //------------Coll----0.00---10.29---20.58---36.01---46.30---51.44---61.73---66.88---72.02
            liftCoefTable[] = {
                        {"A/S", 0.00,   10.29,  20.58,  36.01,  46.30,  51.44,  61.73,  66.88,  72.02}
                        ,{0.00, 0.1000, 0.1000, 0.1000, 0.1000, 0.1000, 0.1000, 0.1000, 0.1000, 0.1000}
                        ,{0.20, 0.1666, 0.1695, 0.1826, 0.1904, 0.1841, 0.1786, 0.1666, 0.1541, 0.1252}
                        ,{0.40, 0.2331, 0.2389, 0.2653, 0.2809, 0.2681, 0.2571, 0.2331, 0.2081, 0.1503}
                        ,{0.64, 0.2997, 0.3084, 0.3479, 0.3713, 0.3522, 0.3357, 0.2997, 0.2622, 0.1755}
                        ,{0.80, 0.3330, 0.4100, 0.5340, 0.6100, 0.5790, 0.5713, 0.4860, 0.3928, 0.2915}
                        ,{1.00, 0.4120, 0.4120, 0.4120, 0.4120, 0.4120, 0.4120, 0.4120, 0.4120, 0.4120}
                        };
            //------------Coll----0.00---10.29---20.58---36.01---46.30---51.44---61.73---66.88---72.02
            dragCoefTable[] = {
                        {"A/S", 0.00,   10.29,  20.58,  36.01,  46.30,  51.44,  61.73,  66.88,  72.02}
                        ,{0.00, 0.0078, 0.0078, 0.0060, 0.0005, 0.0005, 0.0005, 0.0005, 0.0005, 0.0005}
                        ,{0.20, 0.0193, 0.0178, 0.0150, 0.0099, 0.0100, 0.0101, 0.0110, 0.0110, 0.0110}
                        ,{0.40, 0.0309, 0.0281, 0.0242, 0.0195, 0.0197, 0.0200, 0.0217, 0.0217, 0.0217}
                        ,{0.64, 0.0447, 0.0401, 0.0350, 0.0307, 0.0310, 0.0314, 0.0341, 0.0341, 0.0341}
                        ,{0.80, 0.0474, 0.0474, 0.0474, 0.0474, 0.0474, 0.0474, 0.0474, 0.0474, 0.0474}
                        ,{1.00, 0.1000, 0.1000, 0.1000, 0.1000, 0.1000, 0.1000, 0.1000, 0.1000, 0.1000}
                        };
        };

        class SimpleRotor02 {
            type             = "tail";
            direction        = "ccw";
            numBlades        = 4;
            pivot[]          = {0.35, -7.99, 1.77};
            rotation[]       = {0.00, 70.00, 0.000};
            mastLength       = 0.00;     //m
            gearRatio        = 17.57;
            torqueTau        = 0.10;      //s

            bladeRadius      = 1.676;     //m
            bladeChord       = 0.247;     //m
            bladeMass        = 7.018;     //kg

            //The tail disc does not tilt - pedal changes its pitch, not its plane.
            pitchFlapMin     = 0.0;
            pitchFlapMid     = 0.0;
            pitchFlapMax     = 0.0;
            rollFlapMin      = 0.0;
            rollFlapMid      = 0.0;
            rollFlapMax      = 0.0;

            coneAngle        = 0.0;
            flapBackRollMax  = 0.0;
            flapBackPitchMax = 0.0;
            rollLiftCoef     = 0.0;
            pitchLiftCoef    = 0.0;
            gndEffValue      = 1.0;
            reacTqScalar     = 0.25;
            autoTorque       = 0.0;

            //-----------Pedal----0.00---10.29---20.58---36.01---46.30---51.44---61.73---66.88---72.02
            liftCoefTable[] = {
                         {"A/S", 0.00,  10.29,  20.58,  36.01,  46.30,  51.44,  61.73,  66.88,  72.02}
                        ,{-1.00, 2.1344, 2.3460, 2.5324, 2.7784, 2.9256, 2.9952, 3.1280, 3.1912, 3.2524}
                        ,{-0.60, 0.1921, 0.2111, 0.2279, 0.2501, 0.2633, 0.2696, 0.2815, 0.2872, 0.2927}
                        ,{ 0.00, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000, 0.0000}
                        ,{ 0.60,-0.1921,-0.2111,-0.2279,-0.2501,-0.2633,-0.2696,-0.2815,-0.2872,-0.2927}
                        ,{ 1.00,-2.1344,-2.3460,-2.5324,-2.7784,-2.9256,-2.9952,-3.1280,-3.1912,-3.2524}
                        };
            //-----------Pedal----0.00---10.29---20.58---36.01---46.30---51.44---61.73---66.88---72.02
            dragCoefTable[] = {
                         {"A/S", 0.00,  10.29,  20.58,  36.01,  46.30,  51.44,  61.73,  66.88,  72.02}
                        ,{-1.00, 0.1200, 0.1200, 0.1200, 0.1200, 0.1200, 0.1200, 0.1200, 0.1200, 0.1200}
                        ,{-0.60, 0.0226, 0.0226, 0.0226, 0.0226, 0.0226, 0.0226, 0.0226, 0.0226, 0.0226}
                        ,{ 0.00, 0.0130, 0.0130, 0.0130, 0.0130, 0.0130, 0.0130, 0.0130, 0.0130, 0.0130}
                        ,{ 0.60, 0.0122, 0.0122, 0.0122, 0.0122, 0.0122, 0.0122, 0.0122, 0.0122, 0.0122}
                        ,{ 1.00, 0.0040, 0.0040, 0.0040, 0.0040, 0.0040, 0.0040, 0.0040, 0.0040, 0.0040}
                        };
        };
    };
