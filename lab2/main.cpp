#include <iostream>
#include "MyTime.h"
using namespace std;

int main() {
    MyTime t1, t2(3,15,30), t3(1,45,20);
    
    t1.info();
    t2.info();
    
    t1 = t2.add(50);
    t1.info();
    
    t1 = t2.subtract(100);
    t1.info();
    
    t1 = t2.add(t3);
    t1.info();
    
    t1 = t2.subtract(t3);
    t1.info();

    return 0;
}