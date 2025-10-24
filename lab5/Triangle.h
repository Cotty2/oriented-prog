#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
private:
    double a, b, c;
public:
    Triangle();
    Triangle(std::string name, double a, double b, double c);
    void info() ;
    double perimetr() ;
    double ploshad() ;
};

#endif