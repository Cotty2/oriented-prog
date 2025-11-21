#include "phone.h"
#include <iostream>

void PhoneBook::loadEntry(const std::string& phone, const std::string& name) {

    phoneToName[phone] = name;

    nameToPhones.insert(std::make_pair(name, phone));
}

void PhoneBook::printPhonesByName(const std::string& name) const {
    std::cout << "Телефоны для \"" << name << "\":" << std::endl;

    auto range = nameToPhones.equal_range(name);
    if (range.first == range.second) {
        std::cout << "Нет записей." << std::endl;
        return;
    }

    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "  " << it->second << std::endl;
    }
}

void PhoneBook::printNameByPhone(const std::string& phone) const {
    auto it = phoneToName.find(phone);
    if (it != phoneToName.end()) {
        std::cout << "Фамилия для телефона \"" << phone << "\": " << it->second << std::endl;
    } else {
        std::cout << "Телефон \"" << phone << "\" не найден." << std::endl;
    }
}