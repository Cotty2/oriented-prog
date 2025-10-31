#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction
{
public:
    int num; 
    int den; 

    Fraction();
    Fraction(int n, int d);
    bool operator<(const Fraction& other) const;
    void info() const;
};

#endif  