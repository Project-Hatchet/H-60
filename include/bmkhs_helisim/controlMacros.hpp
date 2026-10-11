#ifndef BMKHS_HELISIM_CONTROLMACROS_HPP
#define BMKHS_HELISIM_CONTROLMACROS_HPP

//Cockpit control bindings - the macros. Core ships these; the AIRCRAFT ships the rows,
//because a row naming a switch is airframe knowledge and Arma's preprocessor has no loop.
//
//Its own header so a pack can take the macros WITHOUT Core's own CfgUserActions class,
//which would collide with the pack reopening it. Include this, not CfgUserActions.hpp.
//
//Field reference for the controls themselves: \bmkhs_helisim\controls.hpp

//Two tokens for the position: ## cannot paste a bare number into a class name, so ptok is
//an identifier for the name and pnum a number for the dispatch. They must agree.
#define BMKHS_CONTROL(cname,ptok,pnum,vdisplayName) \
class bmkhs_ctrl_##cname##_##ptok {\
    displayName = vdisplayName;\
    tooltip     = vdisplayName;\
    onActivate  = __EVAL(format["['%1', %2] call bmkhs_fnc_controlSet", #cname, pnum]);\
}
//The separator carries the terminator, because the two views need DIFFERENT ones: a class
//ends with ; and an array element with , - so the row itself can carry neither.
#define BMKHS_CONTROL_SEP() ;


//For the SECOND view of the same table, a pack redefines these to yield just the class
//names into a group[] array - see the example in controls.hpp. That is what lets one data
//table emit both the classes and the group list, so the two cannot drift apart.

#endif
