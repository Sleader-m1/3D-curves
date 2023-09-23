#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"

class Circle : public Figure{
	float radius;
public:
	Circle(float radius);
	coordinates First_derivative(float t) const override;
	coordinates Get_3D_point(float t) const override;
	bool operator<(const Circle& another_circle) const; //Перегрузка оператора для сортировки массива по размеру радиуса
	float GetRadius() const{
		return radius;
	}
};

#endif