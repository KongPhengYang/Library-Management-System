#include <iostream>
#include "User.h"

//User info
User::User(const std::string& name, const std::string& id, const std::string& password)
    : Person(name, id, password) {
}

//Record a borrow action if under the limit of 4 items
void User::borrowItem(const std::string& itemID) {
    if (borrowed.size() < 4) {
        borrowed.push_back(itemID);
        history.push_back("B:" + itemID);  //B for borrow
    }
}

//Record a return action and remove from the borrowed list
void User::returnItem(const std::string& itemID) {
    for (auto it = borrowed.begin(); it != borrowed.end(); ++it) {
        if (*it == itemID) {
            borrowed.erase(it);
            history.push_back("R:" + itemID);  //R for return
            break;
        }
    }
}

const std::list<std::string>& User::getBorrowed() const { return borrowed; }
const std::list<std::string>& User::getHistory() const { return history; }

//Print user name, ID, and lists of the borrows and returns
void User::printSummary() const {
    std::cout << "User: " << name << " (" << id << ")\n";
    std::cout << " Currently borrowed:\n";
    for (const auto& b : borrowed) std::cout << "  - " << b << "\n";
    std::cout << " History:\n";
    for (const auto& h : history) std::cout << "  - " << h << "\n";
}