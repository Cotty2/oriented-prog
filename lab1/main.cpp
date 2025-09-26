#include <iostream>
#include "ComplexNumber.h"

int main()
{
    ComplexNumber c1, c2, c3;
    c1.re = 4; c1.im = -2;
    c2.re = 5; c2.im = 3;
    
    info(c1);  // ← исправлено: добавлена ;
    info(c2);  // ← исправлено: добавлена ;
    
    c3 = plus(c1, c2);
    info(c3);  // можно добавить для проверки результата

    return 0;
}