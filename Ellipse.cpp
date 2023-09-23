#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(float first_radius, float second_radius):first_radius(first_radius),second_radius(second_radius){}

coordinates Ellipse::First_derivative(float t) const {
	/*Используем центральную разностную производную
		f(x)' = [ f(x + dt) - f(x - dt) ] / 2*dt
	*/ 
	coordinates func_arg_PLUS_dT = Get_3D_point(t + dT);  //f(x + dt)
	coordinates func_arg_MINUS_dT = Get_3D_point(t - dT); //f(x - dt)

	return coordinates{ 
		(func_arg_PLUS_dT[0] - func_arg_MINUS_dT[0]) / (2 * dT), // f'x
		(func_arg_PLUS_dT[1] - func_arg_MINUS_dT[1]) / (2 * dT), // f'y
		0 			/*Должно быть: 
          			(func_arg_PLUS_dT[2] - func_arg_MINUS_dT[2]) / (2 * dT)
		  			но известно, что вдоль Oz движения нет => f'z = 0*/
	};
}

coordinates Ellipse::Get_3D_point(float t) const {
	return coordinates{first_radius * cos(t), second_radius * sin(t), 0}; //	x = a * cos(t) |-------| y = b * sin(t) |-------| z = 0
}