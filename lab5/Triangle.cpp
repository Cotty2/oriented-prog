#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle() : Shape(), a(3.0), b(4.0), c(5.0) {}

Triangle::Triangle(std::string name, double a, double b, double c) 
    : Shape(name), a(a), b(b), c(c) {}

void Triangle::info()
{
    std::cout << "Triangle '" << name << "' with sides: " << a << ", " << b << ", " << c << "\n";
}

double Triangle::perimetr()
{
    return a + b + c;
}

double Triangle::ploshad()
{
    double p = perimetr() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}