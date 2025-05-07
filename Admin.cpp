#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include "Book.h"
#include "User.h"
#include <vector>
#include <string>

// Inheritance because Admin inherits Person
class Admin : public Person {
public:
    // Allows admin to pass credentials to Person
    Admin(const std::string& name, const std::string& id, const std::string& password);
    // Print admin summary/info
    void printSummary() const override;

    // Add an inventory item
    bool addInventoryItem(const Book& book);
    // Delete an inventory item by ID
    bool removeInventoryItem(const std::string& bookID);

    // Add a new user account
    bool createUserAccount(const std::string& name, const std::string& id, const std::string& password);
    // Delete a user account by ID
    bool deleteUserAccount(const std::string& userID);

    // Edit an existing inventory item
    bool editInventoryItem(const std::string& bookID, const Book& updatedBook);
    // Edit an existing user details
    bool editUserDetails(const std::string& userID, const User& updatedUser);

    // View total number of currently active users in the system
    size_t viewActiveUserCount() const;

    // Search for inventory items by keyword/title/author/publisher
    std::vector<Book> searchInventory(const std::string& keyword) const;
    // Search for users by keyword/name/ID
    std::vector<User> searchUsers(const std::string& keyword) const;
};

#endif
