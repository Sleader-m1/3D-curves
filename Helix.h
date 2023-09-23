#ifndef HELIX_H
#define HELIX_H

#include "Figure.h"

class Helix : public Figure{
	float radius,
		  step;
public:
	Helix(float radius, float step);
	coordinates First_derivative(float t) const override;
	coordinates Get_3D_point(float t) const override;
};

#endif