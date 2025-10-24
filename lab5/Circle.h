#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
private:
    double radius;
public:
    Circle();
    Circle(std::string name, double radius);
    void info();
    double perimetr();
    double ploshad();
};

#endif