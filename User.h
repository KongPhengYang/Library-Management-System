#ifndef USER_H
#define USER_H

#include "Person.h"
#include <list>
#include <string>

// User class for library users
class User : public Person {
public:
    // Allows passing credentials to Person
    User(const std::string& name, const std::string& id, const std::string& password);

    // Borrow an item 
    void borrowItem(const std::string& itemID);
    // Return an item previously borrowed
    void returnItem(const std::string& itemID);

    // Print user summary: current loans and history
    void printSummary() const override;

    // Getters
    const std::list<std::string>& getBorrowed() const;
    const std::list<std::string>& getHistory() const;

private:
    std::list<std::string> borrowed; // List of currently borrowed item IDs
    std::list<std::string> history; // Full borrow/return history records
};

#endif
