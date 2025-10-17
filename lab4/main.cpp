#include <iostream>
#include "Fraction.h"

int main()
{
    Fraction f1(1,2);
    Fraction f2 = 3;
    Fraction f3;
    double d = f1;


    f3 = f1 +f2;
    std::cout << f3.numerator << "/" << f3.denominator << "\n";
    f3 = f1 +2;
    std::cout << f3.numerator << "/" << f3.denominator << "\n";
    f3 = 2 + f1;
    std::cout << f3.numerator << "/" << f3.denominator << "\n";
    f3 = f1 - f2;
    std::cout << f3.numerator << "/" << f3.denominator << "\n";
    f3 = f1 - 2;
    std::cout << f3.numerator << "/" << f3.denominator << "\n";
    f3 = 2 - f1;
    std::cout << f3.numerator << "/" << f3.denominator << "\n";
    std::cout << d << "\n"; 

    return 0;
}