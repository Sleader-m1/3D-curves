#include "Circle.h"
#include <cmath>

Circle::Circle(float radius):radius(radius){}

coordinates Circle::First_derivative(float t) const{
	/*Используем центральную разностную производную
		f(x)' = [ f(x + dt) - f(x - dt) ] / 2*dt
	*/ 
	coordinates func_arg_PLUS_dT = Get_3D_point(t + dT);  //f(x + dt)
	coordinates func_arg_MINUS_dT = Get_3D_point(t - dT); //f(x - dt)

	return coordinates{ 
		(float)(func_arg_PLUS_dT[0] - func_arg_MINUS_dT[0]) / (2 * dT), // f'x
		(float)(func_arg_PLUS_dT[1] - func_arg_MINUS_dT[1]) / (2 * dT), // f'y
		0 			/*Должно быть: 
          			(func_arg_PLUS_dT[2] - func_arg_MINUS_dT[2]) / (2 * dT)
		  			но известно, что вдоль Oz движения нет => f'z = 0*/
	};
}

coordinates Circle::Get_3D_point(float t) const {
	return coordinates{radius * cos(t), radius * sin(t), 0}; //	x = r * cos(t) |-------| y = r * sin(t) |-------| z = 0
}

bool Circle::operator<(const Circle& another_circle) const{
	return this->radius < another_circle.radius;
}