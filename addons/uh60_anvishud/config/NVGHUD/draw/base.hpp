#include "dev.hpp"

class FOVCenter {
	type="line";
	width = 4;
	points[] ={
		{"FOVCenter", {-0.15, 0}, 1},
		{"FOVCenter", {-0.05, 0}, 1},
		{"FOVCenter", {-0.05, 0.02}, 1},
		{},
		{"FOVCenter", {00.15, 0}, 1},
		{"FOVCenter", {00.05, 0}, 1},
		{"FOVCenter", {00.05, 0.02}, 1},
	}; // points
}; // FOVCenter

#define VEL_DIA_SIZE 0.01
class Velocity {
	type="line";
	width = 4;
	points[] ={
		{"FOVCenter",{0, 0}, 1},
		{"Velocity", {0, 0}, 1},{},

		{"Velocity", {-VEL_DIA_SIZE, 0}, 1},
		{"Velocity", {0, -VEL_DIA_SIZE}, 1},
		{"Velocity", {VEL_DIA_SIZE, 0}, 1},
		{"Velocity", {0, VEL_DIA_SIZE}, 1},
		{"Velocity", {-VEL_DIA_SIZE, 0}, 1}
	}; // points
}; // Velocity

#include "headingtape.hpp"
#include "textLeft.hpp"
#include "textRight.hpp"
#include "textBottom.hpp"
#include "trimball.hpp"
#include "altScale.hpp"
#include "pitchladder.hpp"
#include "rollbar.hpp"
