#ifndef PHONE_H
#define PHONE_H

#include <iostream>
#include <map>
#include <string>

class PhoneBook {
public:

    std::map<std::string, std::string> phoneToName;

    std::multimap<std::string, std::string> nameToPhones;

    void loadEntry(const std::string& phone, const std::string& name);

    void printPhonesByName(const std::string& name) const;

    void printNameByPhone(const std::string& phone) const;
};

#endif // PHONE_H