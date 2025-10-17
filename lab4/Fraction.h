#ifndef FRACTION_H
#define FRACTION_H
#include <ostream> 

class Fraction
{
    public:
    int numerator;
    int denominator;
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(int n);
    
    operator double() const;
};

Fraction operator+(Fraction f1, Fraction f2);
Fraction operator+(Fraction f1, int n);
Fraction operator+(int n, Fraction f2);
Fraction operator-(Fraction f1, Fraction f2);
Fraction operator-(Fraction f1, int n);
Fraction operator-(int n, Fraction f2);
std::ostream& operator<<(std::ostream& os, const Fraction& f);
#endif