#pragma once

#include <string>
#include <iostream>

struct Person {
    unsigned int ID;
    std::string FirstName;
    std::string LastName;

    bool operator== (const Person& other) const {
        return this->ID == other.ID;
    }

    bool operator< (const Person& other) const {
        return this->ID < other.ID;
    }

    bool operator> (const Person& other) const {
        return this->ID > other.ID;
    }

    operator unsigned int() const { return ID; }

    friend std::ostream& operator<< (std::ostream& stream, const Person& person);

    friend bool operator< (const unsigned int& key, const Person& person);
    friend bool operator< (const Person& person, const unsigned int& key);

    friend bool operator> (const unsigned int& key, const Person& person);
    friend bool operator> (const Person& person, const unsigned int& key);

    friend bool operator<= (const unsigned int& key, const Person& person);
    friend bool operator<= (const Person& person, const unsigned int& key);

    friend bool operator>= (const unsigned int& key, const Person& person);
    friend bool operator>= (const Person& person, const unsigned int& key);

    friend bool operator== (const unsigned int& key, const Person& person);
    friend bool operator== (const Person& person, const unsigned int& key);
};

std::ostream& operator<< (std::ostream& stream, const Person& person) {
    return stream << "[ " << person.ID << ", " << person.FirstName << ", "
    << person.LastName << " ]";
}

bool operator< (const unsigned int& key, const Person& person)
{
    return key < person.ID;
}
bool operator< (const Person& person, const unsigned int& key)
{
    return person.ID < key;
}

bool operator> (const unsigned int& key, const Person& person)
{
    return key > person.ID;
}
bool operator> (const Person& person, const unsigned int& key)
{
    return person.ID > key;
}

bool operator<= (const unsigned int& key, const Person& person)
{
    return key <= person.ID;
}
bool operator<= (const Person& person, const unsigned int& key)
{
    return person.ID <= key;
}

bool operator>= (const unsigned int& key, const Person& person)
{
    return key >= person.ID;
}
bool operator>= (const Person& person, const unsigned int& key)
{
    return person.ID >= key;
}

bool operator== (const unsigned int& key, const Person& person)
{
    return key == person.ID;
}
bool operator== (const Person& person, const unsigned int& key)
{
    return person.ID == key;
}

