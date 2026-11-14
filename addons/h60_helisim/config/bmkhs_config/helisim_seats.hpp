// HeliSim seat-mass macros. Pure #defines, no config content, so both the
// HeliSim pack (helisim_mass.hpp, base Seats) and every variant PBO (its own
// numSeats + Seats delta) can include it:
//   #include "\z\vtx\addons\uh60_helisim\config\bmkhs_config\helisim_seats.hpp"
// Arms are {right, forward, up} in m, measured in game (occupant's chest).

#define SEAT_MASS_CREW  100.0   //220 lb - pilots, door gunners
#define SEAT_MASS_TROOP 149.7   //330 lb - infantry with combat load, every cabin seat
#define SEAT_DRIVER(cls,x,y,z)   class cls { arm[] = {x,y,z}; mass = SEAT_MASS_CREW;  role = "driver"; turret[] = {};  cargoIndex = -1; };
#define SEAT_TURRET(cls,t,x,y,z) class cls { arm[] = {x,y,z}; mass = SEAT_MASS_CREW;  role = "turret"; turret[] = {t}; cargoIndex = -1; };
#define SEAT_TROOP(cls,t,x,y,z)  class cls { arm[] = {x,y,z}; mass = SEAT_MASS_TROOP; role = "turret"; turret[] = {t}; cargoIndex = -1; };
#define SEAT_CARGO(cls,c,x,y,z)  class cls { arm[] = {x,y,z}; mass = SEAT_MASS_TROOP; role = "cargo";  turret[] = {};  cargoIndex = c; };

#define SEATS_UH60M \
    numSeats = 15; \
    class Seats: Seats { \
        SEAT_CARGO(Seat03, 0,-0.80, 0.66,-0.34) \
        SEAT_CARGO(Seat04, 1,-0.32, 0.75,-0.33) \
        SEAT_CARGO(Seat05, 2, 0.22, 0.73,-0.32) \
        SEAT_CARGO(Seat06, 3, 0.72, 0.74,-0.34) \
        SEAT_CARGO(Seat07, 4, 0.81, 1.82,-0.35) \
        SEAT_CARGO(Seat08, 5, 0.27, 1.91,-0.35) \
        SEAT_CARGO(Seat09, 6,-0.25, 1.90,-0.35) \
        SEAT_CARGO(Seat10, 7,-0.63, 1.78,-0.35) \
        SEAT_CARGO(Seat11, 8,-0.55, 2.53,-0.35) \
        SEAT_CARGO(Seat12, 9,-0.07, 2.53,-0.35) \
        SEAT_TURRET(Seat13, 1,-1.05, 3.22,-0.16) \
        SEAT_TURRET(Seat14, 2, 1.05, 3.32,-0.16) \
        SEAT_TROOP(Seat15, 3, 0.46, 2.52,-0.37) \
    };

#define SEATS_MEDEVAC \
    numSeats = 19; \
    class Seats: Seats { \
        SEAT_CARGO(Seat03,11,-0.80, 0.66,-0.34) \
        SEAT_CARGO(Seat04,12,-0.32, 0.75,-0.33) \
        SEAT_CARGO(Seat05,13, 0.22, 0.73,-0.32) \
        SEAT_CARGO(Seat06,14, 0.72, 0.74,-0.34) \
        SEAT_TURRET(Seat07, 1,-1.05, 3.22,-0.16) \
        SEAT_TURRET(Seat08, 2, 1.05, 3.32,-0.16) \
        SEAT_TROOP(Seat09, 3,-1.05, 3.22,-0.16) \
        SEAT_TROOP(Seat10, 4, 1.05, 3.32,-0.16) \
        SEAT_TROOP(Seat11, 5, 0.86, 1.98,-0.69) \
        SEAT_TROOP(Seat12, 6, 0.86, 1.30,-0.68) \
        SEAT_TROOP(Seat13, 7,-0.90, 1.31,-0.70) \
        SEAT_TROOP(Seat14, 8,-0.90, 1.99,-0.69) \
        SEAT_TROOP(Seat15, 9,-0.17, 1.48,-0.49) \
        SEAT_TROOP(Seat16,10,-0.23, 2.11,-0.49) \
        SEAT_TROOP(Seat17,11, 0.48, 2.74,-0.49) \
        SEAT_TROOP(Seat18,12, 0.35, 1.59,-0.49) \
        SEAT_TROOP(Seat19,13, 0.16, 2.20,-0.49) \
    };

#define SEATS_S70I \
    numSeats = 4; \
    class Seats: Seats { \
        SEAT_TURRET(Seat03, 1,-1.05, 3.22,-0.16) \
        SEAT_TURRET(Seat04, 2, 1.05, 3.32,-0.16) \
    };

#define SEATS_SLICK \
    numSeats = 8; \
    class Seats: Seats { \
        SEAT_TURRET(Seat03, 1,-1.05, 3.22,-0.16) \
        SEAT_TURRET(Seat04, 2, 1.05, 3.32,-0.16) \
        SEAT_TROOP(Seat05, 3, 0.86, 1.98,-0.69) \
        SEAT_TROOP(Seat06, 4, 0.86, 1.30,-0.68) \
        SEAT_TROOP(Seat07, 5,-0.90, 1.31,-0.70) \
        SEAT_TROOP(Seat08, 6,-0.90, 1.99,-0.69) \
    };

#define SEATS_MH60M \
    numSeats = 14; \
    class Seats: Seats { \
        SEAT_TURRET(Seat03, 1,-1.05, 3.22,-0.16) \
        SEAT_TURRET(Seat04, 2, 1.05, 3.32,-0.16) \
        SEAT_TROOP(Seat05, 3, 0.86, 1.98,-0.69) \
        SEAT_TROOP(Seat06, 4, 0.86, 1.30,-0.68) \
        SEAT_TROOP(Seat07, 5,-0.90, 1.31,-0.70) \
        SEAT_TROOP(Seat08, 6,-0.90, 1.99,-0.69) \
        SEAT_TROOP(Seat09, 7,-0.17, 1.48,-0.49) \
        SEAT_TROOP(Seat10, 8,-0.23, 2.11,-0.49) \
        SEAT_TROOP(Seat11, 9, 0.48, 2.74,-0.49) \
        SEAT_TROOP(Seat12,10, 0.35, 1.59,-0.49) \
        SEAT_TROOP(Seat13,11, 0.16, 2.20,-0.49) \
        SEAT_TROOP(Seat14,12, 0.01, 3.11,-0.50) \
    };

#define SEATS_DAP \
    numSeats = 11; \
    class Seats: Seats { \
        SEAT_TROOP(Seat03, 1, 0.86, 1.98,-0.69) \
        SEAT_TROOP(Seat04, 2, 0.86, 1.30,-0.68) \
        SEAT_TROOP(Seat05, 3,-0.90, 1.31,-0.70) \
        SEAT_TROOP(Seat06, 4,-0.90, 1.99,-0.69) \
        SEAT_TROOP(Seat07, 5,-0.17, 1.48,-0.49) \
        SEAT_TROOP(Seat08, 6,-0.23, 2.11,-0.49) \
        SEAT_TROOP(Seat09, 7, 0.48, 2.74,-0.49) \
        SEAT_TROOP(Seat10, 8, 0.35, 1.59,-0.49) \
        SEAT_TROOP(Seat11, 9, 0.16, 2.20,-0.49) \
    };
