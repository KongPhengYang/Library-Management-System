#ifndef USER_H
#define USER_H

#include "Person.h"
#include <list>
#include <string>

//Person who is also a user that can borrow and return items
class User : public Person { //Another inheritance
private:
    //Encapsulation containers
    std::list<std::string> borrowed; //IDs of the borrowed items
    std::list<std::string> history;  //History logs of the borrow/return actions
public:
    User() = default;
    User(const std::string& name, const std::string& id, const std::string& password);
    //Borrow an item up to 4 at once
    void borrowItem(const std::string& itemID);
    //Return an item that was previously borrowed
    void returnItem(const std::string& itemID);

    //Getters
    const std::list<std::string>& getBorrowed() const;
    const std::list<std::string>& getHistory() const;
    //Print user details/history
    void printSummary() const override;
};

#endif // USER_H