#include <iostream>

#include "Person.h"

Person::Person(std::istream& is) {
    read(is, *this);
}

std::istream& read(std::istream& is, Person& person) {
    is >> person.full_name >> person.age >> person.address;
    return is;
}

std::ostream& print(std::ostream& os, const Person& person) {
    os << "Name: " << person.name() << ", Age: " << person.age 
       << ", Address: " << person.address;
    return os;
}
