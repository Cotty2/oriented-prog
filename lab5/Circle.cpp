#include "Circle.h"
#include <iostream>

Circle::Circle() : Shape(), radius(1.0) {}

Circle::Circle(std::string name, double radius) : Shape(name), radius(radius) {}

void Circle::info()
{
    std::cout << "Circle '" << name << "' with radius = " << radius << "\n";
}

double Circle::perimetr()
{
    return 2 * 3.14159 * radius;
}

double Circle::ploshad()
{
    return 3.14159 * radius * radius;
}