#pragma once

#include <string>
#include <iostream>

struct Person {
    unsigned int ID;
    std::string FirstName;
    std::string LastName;

    friend std::ostream& operator<< (std::ostream& stream, const Person& person);
};

std::ostream& operator<< (std::ostream& stream, const Person& person) {
    return stream << "[ " << person.ID << ", " << person.FirstName << ", "
    << person.LastName << " ]";
}