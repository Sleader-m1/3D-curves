#include <iostream>
#include "Curves.h"
#include <utility>
#include <memory>
#include <algorithm>

using Figures_Vector = std::vector<Figure*>;
using Circle_Vector = std::vector<Circle*>;

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

Figures_Vector* GenerateFigures(int size = 5){ //по умолчанию будем создавать 5 элементов
    Figures_Vector* result_vec = new Figures_Vector();
    for(int i = 0; i < size; ++i){
        switch(rand() % 3){
            case 0:
                result_vec->push_back( new Circle( fRand(1., 10.) ) ); //random radius [1; 10]
                break;
            case 1:
                result_vec->push_back( new Ellipse( fRand(1., 10.), fRand(1., 10.) ) ); //random radiuses [1; 10]
                break;
            default: //case 2
                result_vec->push_back( new Helix( fRand(1., 10.), fRand(1., 10.) ) ); // random radius and step [1; 10]
                break;
        }
    }
    return result_vec; 
}

using Points_Derivatives_Vector = std::vector<std::pair<coordinates, coordinates>>; 

Points_Derivatives_Vector GetPointsAndDerivatives(Figures_Vector& figures_vec){
    Points_Derivatives_Vector result;
    double t = PI / 4;
    for(const auto& figure : figures_vec)
        result.push_back(std::make_pair((*figure).Get_3D_point(t), (*figure).First_derivative(t)));
    return result;
}

Circle_Vector GetSortedCircles(const Figures_Vector* figures_vec){
    Circle_Vector result;
    for(Figure* figure : *figures_vec){
        Circle* circle = dynamic_cast<Circle*>(figure);
        if(circle){
            result.push_back(circle);
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}

float SumOfRadii(Circle_Vector circles_vec){
    float sum = 0;
    for(Circle* circle : circles_vec){
        sum += circle->GetRadius();
    }
    return sum;
}

int main(){
    auto figures = GenerateFigures(20);
    auto circles = GetSortedCircles(figures);
    std::cout << SumOfRadii(circles);
}