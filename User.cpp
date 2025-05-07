#include "User.h"
#include "Library.h"
#include <iostream>
#include <algorithm>

// Allows passing info to Person
User::User(const std::string& name, const std::string& id, const std::string& password)
    : Person(name, id, password) {
}

// Borrow an item
void User::borrowItem(const std::string& itemID) {
    if (borrowed.size() >= 4) {
        std::cout << "Cannot borrow more than 4 books." << std::endl;
        return;
    }
    Library& lib = Library::getInstance();
    //borrow operation to Library checks for availibility 
    if (lib.borrowBook(id, itemID)) {
        borrowed.push_back(itemID);
        history.push_back("Borrowed: " + itemID);
        lib.saveAll();  // Persist updates
    }
    else {
        std::cout << "Unable to borrow item: " << itemID << std::endl;
    }
}

// Return an item previously borrowed
void User::returnItem(const std::string& itemID) {
    Library& lib = Library::getInstance();
    //return to Library
    if (lib.returnBook(id, itemID)) {
        auto it = std::find(borrowed.begin(), borrowed.end(), itemID);
        if (it != borrowed.end()) borrowed.erase(it);
        history.push_back("Returned: " + itemID);
        lib.saveAll();
    }
    else {
        std::cout << "Return failed for item: " << itemID << std::endl;
    }
}

// Print user history
void User::printSummary() const {
    std::cout << "User: " << name << " (" << id << ")" << std::endl;
    std::cout << "Currently Borrowed Items:" << std::endl;
    for (const auto& item : borrowed) {
        std::cout << " - " << item << std::endl;
    }
    std::cout << "Borrow/Return History:" << std::endl;
    for (const auto& record : history) {
        std::cout << " * " << record << std::endl;
    }
}

// Getters
const std::list<std::string>& User::getBorrowed() const {
    return borrowed;
}
const std::list<std::string>& User::getHistory() const {
    return history;
}
