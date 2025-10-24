#include "Square.h"
#include <iostream>

Square::Square() : Shape(), side(1.0) {}

Square::Square(std::string name, double side) : Shape(name), side(side) {}

void Square::info()
{
    std::cout << "Square '" << name << "' with side = " << side << "\n";
}

double Square::perimetr()
{
    return 4 * side;
}

double Square::ploshad()
{
    return side * side;
}