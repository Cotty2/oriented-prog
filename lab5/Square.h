#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape
{
private:
    double side;
public:
    Square();
    Square(std::string name, double side);
    void info();
    double perimetr();
    double ploshad();
};

#endif