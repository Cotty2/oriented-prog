#include "ComplexNumber.h"
#include <iostream>

void info(ComplexNumber c)
{
    std::cout << "(" << c.re << " + i*" << c.im << ") \n";
}

ComplexNumber plus(ComplexNumber c1, ComplexNumber c2)
{
    ComplexNumber result;
    result.re = c1.re + c2.re;
    result.im = c1.im + c2.im;
    return result;
}