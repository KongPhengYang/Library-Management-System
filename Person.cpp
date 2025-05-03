#include "Person.h"

// Constructor: store name, id, and password
Person::Person(const std::string& name, const std::string& id, const std::string& password)
    : name(name), id(id), password(password) {
}

std::string Person::getID() const { return id; }
std::string Person::getName() const { return name; }
bool Person::checkPassword(const std::string& pw) const { return password == pw; }


