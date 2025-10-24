#include "Shape.h"

Shape::Shape()
{
    name = "NO NAME";
}

Shape::Shape(std::string name)
{
    this->name = name;
}

void Shape::info()
{
    std::cout << "This is shape " << name << "\n";
}