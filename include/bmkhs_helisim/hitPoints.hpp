//BMKHS_HITPOINT - declares one damageable component.
//
//The AIRCRAFT declares its own hitpoints with this macro; Core declares none. That is what
//lets an airframe have one engine or three generators, no pylons and no FCR, without Core
//knowing anything about the airframe.
//
//  cls          class name. Conventionally the same as nm.
//  nm           the selection in the p3d. Arma matches this EXACTLY, case included, and
//               returns -1 from getHitPointDamage for a name the vehicle does not have.
//  arm          armor - hit points before destruction
//  rad          hit sphere radius, m
//  minr         minimalHit - smallest hit that registers
//  expShl       explosionShielding - blast resistance
//  rl           the HeliSim system this damages, or "" for none. Core looks components up
//               BY ROLE, so it never needs to know what the aircraft called them. A
//               hitpoint with no role still takes damage; it just does not feed the model.
//  rlIdx        position within a role that has several members - engine 0 and engine 1,
//               generator 0, 1 and 2. Use 0 for single-member roles.
//
//role and roleIndex are ordinary properties, inert to Arma, so Core can read the mapping
//back out of the vehicle's own config rather than keeping a second list of names.
#define BMKHS_HITPOINT(cls,nm,arm,rad,minr,expShl,rl,rlIdx) \
    class cls { \
        name               = nm; \
        armor              = arm; \
        radius             = rad; \
        minimalHit         = minr; \
        explosionShielding = expShl; \
        material           = 51; \
        passThrough        = 0; \
        bmkhsRole          = rl; \
        bmkhsRoleIndex     = rlIdx; \
    };

//Neutralises Arma's own engine hitpoint so the per-engine hitpoints drive engine damage
//instead. dependsExpr averages them - "0.5 * (HitEngine1 + HitEngine2)" for two engines.
//An aircraft that declares engine hitpoints wants this; one that does not, does not.
#define BMKHS_HITPOINT_ENGINE_PASSTHROUGH(dependsExpr) \
    class hitengine { \
        armor              = 999; \
        depends            = dependsExpr; \
        explosionShielding = 1; \
        material           = 51; \
        minimalHit         = 1; \
        name               = "engine_hit"; \
        passThrough        = 0; \
        radius             = 0.05; \
    };
