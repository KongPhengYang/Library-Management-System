#include "Library.h"
#include <iostream>
#include <fstream>

// Singleton instance
Library& Library::getInstance() {
    static Library instance;
    return instance;
}

// Add a new user
bool Library::addUser(const std::string& name, const std::string& id, const std::string& password) {
    // Check if user ID already exists
    for (const auto& user : users) {
        if (user.getID() == id) {
            std::cout << "User with ID " << id << " already exists.\n";
            return false;
        }
    }

    // Add new user
    users.emplace_back(name, id, password);
    std::cout << "User " << name << " added successfully.\n";
    return true;
}

// Authenticate admin
bool Library::authAdmin(const std::string& id, const std::string& password) {
    for (const auto& admin : admins) {
        if (admin.getID() == id && admin.checkPassword(password)) {
            std::cout << "Admin authenticated successfully.\n";
            return true;
        }
    }
    std::cout << "Invalid admin credentials.\n";
    return false;
}

// Authenticate user
bool Library::authUser(const std::string& id, const std::string& password) {
    for (const auto& user : users) {
        if (user.getID() == id && user.checkPassword(password)) {
            std::cout << "User authenticated successfully.\n";
            return true;
        }
    }
    std::cout << "Invalid user credentials.\n";
    return false;
}

// Save all data to a file
void Library::saveAll() {
    std::ofstream outFile("library_data.txt");
    if (!outFile) {
        std::cerr << "Error opening file for saving data.\n";
        return;
    }

    // Save users
    outFile << "Users:\n";
    for (const auto& user : users) {
        outFile << user.getName() << "," << user.getID() << "\n";
    }

    // Save admins
    outFile << "Admins:\n";
    for (const auto& admin : admins) {
        outFile << admin.getName() << "," << admin.getID() << "\n";
    }

    outFile.close();
    std::cout << "Data saved successfully.\n";
}
