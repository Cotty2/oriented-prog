#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape
{
public:
    std::string name;
    Shape();
    Shape(std::string name);
    virtual void info();
    virtual double perimetr() = 0;
    virtual double ploshad() = 0;
    virtual ~Shape() = default;
};

#endif