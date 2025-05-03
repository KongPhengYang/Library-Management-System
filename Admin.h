#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include <iostream>

//Inheritance because Admin inherits Person
class Admin : public Person {
public:
    //Allows admin to pass credentials to Person
    Admin(const std::string& name, const std::string& id, const std::string& password);
    //Print admin details
    void printSummary() const override; 
};

#endif