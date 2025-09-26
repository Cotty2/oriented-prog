#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

struct ComplexNumber
{
    double re;
    double im;
};

void info(ComplexNumber c);
ComplexNumber plus(ComplexNumber c1, ComplexNumber c2);

#endif
