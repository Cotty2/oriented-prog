#include <iostream>
#include "ordered_store.h"

using namespace std;

int main()
{
    OrderedStore<int> s1;
    s1.add(5);
    s1.add(3);
    s1.add(4);
    s1.add(6);
    s1.add(2);
    s1.add(7);

    cout << "Хранимые данные (int):\n";
    s1.info();

    cout << "Фильтрованная итерация (неубывающий порядок):\n";
    for (OrderedStore<int>::iterator it = s1.begin(); it != s1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n\n";

    OrderedStore<Person> s2;
    s2.add(Person("Артур", 25));
    s2.add(Person("Денис", 30));
    s2.add(Person("Дарья", 20));
    s2.add(Person("Владимир", 35));

    cout << "Хранимые данные (Person):\n";
    s2.info();

    cout << "Фильтрованная итерация (неубывающий порядок по возрасту):\n";
    for (OrderedStore<Person>::iterator it = s2.begin(); it != s2.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}