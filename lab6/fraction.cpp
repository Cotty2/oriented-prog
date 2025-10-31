#include "fraction.h"

Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int n, int d) : num(n), den(d) {}

bool Fraction::operator<(const Fraction& other) const
{
    return num * other.den < other.num * den;
}

void Fraction::info() const
{
    std::cout << num << "/" << den << "\n";
}