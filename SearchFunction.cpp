#include "SearchFunction.h"
#include <iostream>
#include <algorithm>

// Search inventory items by title, author, or publisher
void SearchFunction::searchItems(const std::vector<Book>& inventory, const std::string& keyword) {
    std::cout << "Search Results for \"" << keyword << "\":\n";
    std::cout << "-----------------------------------\n";

    bool found = false;
    for (const auto& item : inventory) {
        if (item.getTitle().find(keyword) != std::string::npos ||
            item.getAuthor().find(keyword) != std::string::npos) {
            std::cout << "Title: " << item.getTitle() << "\n";
            std::cout << "Author: " << item.getAuthor() << "\n";
            std::cout << "Copies Available: " << item.getCopies() << "\n";
            std::cout << "-----------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No items found matching the keyword \"" << keyword << "\".\n";
    }
}

// Find a user by name or ID
void SearchFunction::findUser(const std::vector<User>& users, const std::string& keyword) {
    std::cout << "User Search Results for \"" << keyword << "\":\n";
    std::cout << "-----------------------------------\n";

    bool found = false;
    for (const auto& user : users) {
        if (user.getName().find(keyword) != std::string::npos ||
            user.getID().find(keyword) != std::string::npos) {
            std::cout << "Name: " << user.getName() << "\n";
            std::cout << "ID: " << user.getID() << "\n";
            std::cout << "-----------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No users found matching the keyword \"" << keyword << "\".\n";
    }
}