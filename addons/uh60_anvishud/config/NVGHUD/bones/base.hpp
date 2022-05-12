class FOVCenter
{
	type = "fixed";
	pos[] = {0.5, 0.3};
}; // FOVCenter

class Velocity
{
	type = "vector";
	source = "velocity";
	pos0[] = {0.5, 0.3};
	pos10[] = {0.5+0.03, 0.3+0.03};
}; // Velocity

#include "pitchladder.hpp"
#include "headingtape.hpp"
#include "rollbar.hpp"
#include "altscale.hpp"