#ifndef PERSON_H
#define PERSON_H

#include <string>

//Abrstact class with polymorphism for Admin and User
class Person {
protected: 
    std::string name;      //Name
    std::string id;        //Login ID
    std::string password;  //Password
public:
    Person() = default; //The default constructor
    Person(const std::string& name, const std::string& id, const std::string& password); //Contructor with parameters 
    virtual ~Person() = default;

    //Getters Encapsulation
    std::string getID() const;
    std::string getName() const;
    bool checkPassword(const std::string& pw) const;

    //Print the users info/summary
    virtual void printSummary() const = 0; //Pure virtual which supports subclass override
};

#endif
