#include "Helix.h"
#include <cmath>

Helix::Helix(float radius, float step):radius(radius), step(step){}

coordinates Helix::First_derivative(float t) const {
	/*Используем центральную разностную производную
		f(x)' = [ f(x + dt) - f(x - dt) ] / 2*dt
	*/ 
	coordinates func_arg_PLUS_dT = Get_3D_point(t + dT);  //f(x + dt)
	coordinates func_arg_MINUS_dT = Get_3D_point(t - dT); //f(x - dt)

	return coordinates{ 
		(float)(func_arg_PLUS_dT[0] - func_arg_MINUS_dT[0]) / (2 * dT), // f'x
		(float)(func_arg_PLUS_dT[1] - func_arg_MINUS_dT[1]) / (2 * dT), // f'y
        (float)(func_arg_PLUS_dT[2] - func_arg_MINUS_dT[2]) / (2 * dT)  // f'z
	};
}

coordinates Helix::Get_3D_point(float t) const {
	return coordinates{radius * cos(t), radius * sin(t), step * t}; //	x = r * cos(t) |-------| y = r * sin(t) |-------| z = step * t
}