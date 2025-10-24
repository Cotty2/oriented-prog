#include <iostream>
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"

int main()
{
    Shape* shapes[3] = {
        new Square("Square", 5.0),
        new Triangle("Triangle", 3.0, 4.0, 5.0),
        new Circle("Circle", 3.0)
    };
    
    for (int i = 0; i < 3; i++) {
        shapes[i]->info();
        std::cout << "Perimeter: " << shapes[i]->perimetr() << std::endl;
        std::cout << "Ploshad: " << shapes[i]->ploshad() << std::endl;
    }
    return 0;
}