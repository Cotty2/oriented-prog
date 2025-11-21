
#include <iostream>
#include "phone.h"

using namespace std;

int main() {
    PhoneBook pb;

    pb.loadEntry("89123456789", "Иванов");
    pb.loadEntry("89012345678", "Петров");
    pb.loadEntry("89998887766", "Иванов");
    pb.loadEntry("89234567890", "Сидоров");
    pb.loadEntry("89112223344", "Петров");

    cout << "\nТЕЛЕФОННАЯ КНИГА \n" << endl;

    pb.printPhonesByName("Иванов");
    cout << "------------------------" << endl;
    pb.printPhonesByName("Петров");
    cout << "------------------------" << endl;
    pb.printPhonesByName("Кузнецов");
    cout << "------------------------" << endl;

    pb.printNameByPhone("89123456789");
    cout << "------------------------" << endl;
    pb.printNameByPhone("89998887766");
    cout << "------------------------" << endl;
    pb.printNameByPhone("89999999999");

    return 0;
}