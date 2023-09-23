#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Figure.h"

class Ellipse : public Figure{
	float first_radius,
		  second_radius;
public:
	Ellipse(float first_radius, float second_radius);
	coordinates First_derivative(float t) const override;
	coordinates Get_3D_point(float t) const override;
};

#endif