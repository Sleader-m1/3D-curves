#ifndef FIGURE_H
#define FIGURE_H

#define dT 0.05 //Приращение функции при подсчете производной
#define PI 3.1415

#include <vector>
#include <iostream>

using coordinates = std::vector<double>;

class Figure{
public:
	virtual coordinates First_derivative(float t) const = 0;
	virtual coordinates Get_3D_point(float t) const = 0;
};

#endif