#include <iostream>
#include "fraction.h"
#include "mytemplates.h"

using namespace std;
template <class T>
int countLess(T* arr, int n, const T& value)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] < value)
            cnt++;
    return cnt;
}

template <class T>
int countGreater(T* arr, int n, const T& value)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (value < arr[i]) 
            cnt++;
    return cnt;
}

int main()
{

    int arrInt[] = {10, 5, -3, 8, 15};
    int size = 5;
    int x = 8;

    cout << "Массив целых чисел:\n";
    cout << "Меньше чем " << x << ": " << countLess(arrInt, size, x) << "\n";
    cout << "Больше чем " << x << ": " << countGreater(arrInt, size, x) << "\n\n";


    Fraction arrFrac[] = {
        Fraction(1, 2),  
        Fraction(3, 4),  
        Fraction(2, 3),  
        Fraction(5, 1),  
        Fraction(-1, 2)  
    };
    Fraction ref(2, 3); 
    cout << "Массив дробей:\n";
    for (int i = 0; i < size; i++) arrFrac[i].info();
    cout << " Заданное: ";
    ref.info();
    cout << "колво дробей меньше заданного: " << countLess(arrFrac, size, ref) << "\n";
    cout << "колво дробей больше заданного: " << countGreater(arrFrac, size, ref) << "\n";

    return 0;
}