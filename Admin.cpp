#include "Admin.h"
#include "Library.h"
#include "SearchFunction.h"
#include <iostream>

// Allows admin to pass credentials to Person
Admin::Admin(const std::string& name, const std::string& id, const std::string& password)
    : Person(name, id, password) {
}

// Print admin summary/info
void Admin::printSummary() const {
    std::cout << "Admin: " << name << " (" << id << ")\n";
}

// Add an inventory item (e.g., books, magazines)
bool Admin::addInventoryItem(const Book& book) {
    Library& lib = Library::getInstance();
    // Delegate to Library to add book and persist
    if (lib.addBook(book)) {
        lib.saveAll();    // Save updated book list to book.txt
        return true;
    }
    return false;
}

// Delete an inventory item by ID
bool Admin::removeInventoryItem(const std::string& bookID) {
    Library& lib = Library::getInstance();
    if (lib.removeBook(bookID)) {
        lib.saveAll();
        return true;
    }
    return false;
}

// Add a new user account
bool Admin::createUserAccount(const std::string& name, const std::string& id, const std::string& password) {
    Library& lib = Library::getInstance();
    if (lib.addUser(name, id, password)) {
        lib.saveAll();    // Save updated users to users file
        return true;
    }
    return false;
}

// Delete a user account by ID
bool Admin::deleteUserAccount(const std::string& userID) {
    Library& lib = Library::getInstance();
    if (lib.removeUser(userID)) {
        lib.saveAll();
        return true;
    }
    return false;
}

// Edit an existing inventory item
bool Admin::editInventoryItem(const std::string& bookID, const Book& updatedBook) {
    Library& lib = Library::getInstance();
    if (lib.editBook(bookID, updatedBook)) {
        lib.saveAll();
        return true;
    }
    return false;
}

// Edit an existing user details
bool Admin::editUserDetails(const std::string& userID, const User& updatedUser) {
    Library& lib = Library::getInstance();
    if (lib.editUser(userID, updatedUser)) {
        lib.saveAll();
        return true;
    }
    return false;
}

// View total number of currently active users in the system
size_t Admin::viewActiveUserCount() const {
    return Library::getInstance().getActiveUserCount();
}

// Search for inventory items by keyword/title/author/publisher
std::vector<Book> Admin::searchInventory(const std::string& keyword) const {
    auto books = Library::getInstance().getAllBooks();
    SearchFunction::searchItems(books, keyword);
    return books;
}

// Search for users by keyword/name/ID
std::vector<User> Admin::searchUsers(const std::string& keyword) const {
    auto users = Library::getInstance().getAllUsers();
    SearchFunction::searchUsers(users, keyword);
    return users;
}