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

// Remove a user by ID
bool Library::removeUser(const std::string& userID) {
    auto it = std::remove_if(users.begin(), users.end(), [&](const User& user) {
        return user.getID() == userID;
    });
    if (it != users.end()) {
        users.erase(it, users.end());
        std::cout << "User with ID " << userID << " removed successfully.\n";
        return true;
    }
    std::cout << "User with ID " << userID << " not found.\n";
    return false;
}

// Edit user details
bool Library::editUser(const std::string& userID, const User& updatedUser) {
    for (auto& user : users) {
        if (user.getID() == userID) {
            user = updatedUser;
            std::cout << "User with ID " << userID << " updated successfully.\n";
            return true;
        }
    }
    std::cout << "User with ID " << userID << " not found.\n";
    return false;
}

// Get all users
std::vector<User> Library::getAllUsers() const {
    return users;
}

// Get active user count
size_t Library::getActiveUserCount() const {
    return users.size();
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

// Add a new book
bool Library::addBook(const Book& book) {
    for (const auto& existingBook : books) {
        if (existingBook.getID() == book.getID()) {
            std::cout << "Book with ID " << book.getID() << " already exists.\n";
            return false;
        }
    }
    books.push_back(book);
    std::cout << "Book " << book.getTitle() << " added successfully.\n";
    return true;
}

// Remove a book by ID
bool Library::removeBook(const std::string& bookID) {
    auto it = std::remove_if(books.begin(), books.end(), [&](const Book& book) {
        return book.getID() == bookID;
    });
    if (it != books.end()) {
        books.erase(it, books.end());
        std::cout << "Book with ID " << bookID << " removed successfully.\n";
        return true;
    }
    std::cout << "Book with ID " << bookID << " not found.\n";
    return false;
}

// Edit book details
bool Library::editBook(const std::string& bookID, const Book& updatedBook) {
    for (auto& book : books) {
        if (book.getID() == bookID) {
            book = updatedBook;
            std::cout << "Book with ID " << bookID << " updated successfully.\n";
            return true;
        }
    }
    std::cout << "Book with ID " << bookID << " not found.\n";
    return false;
}

// Get all books
std::vector<Book> Library::getAllBooks() const {
    return books;
}

// Borrow a book
bool Library::borrowBook(const std::string& userID, const std::string& itemID) {
    auto bookIt = std::find_if(books.begin(), books.end(), [&](const Book& book) {
        return book.getID() == itemID;
    });

    if (bookIt == books.end()) {
        std::cout << "Book with ID " << itemID << " not found.\n";
        return false;
    }

    if (bookIt->getCopies() <= 0) {
        std::cout << "No copies available for book: " << bookIt->getTitle() << "\n";
        return false;
    }

    bookIt->setCopies(bookIt->getCopies() - 1); // Decrease available copies
    std::cout << "Book " << bookIt->getTitle() << " borrowed successfully by user " << userID << ".\n";
    return true;
}

// Return a book
bool Library::returnBook(const std::string& userID, const std::string& itemID) {
    auto bookIt = std::find_if(books.begin(), books.end(), [&](const Book& book) {
        return book.getID() == itemID;
    });

    if (bookIt == books.end()) {
        std::cout << "Book with ID " << itemID << " not found.\n";
        return false;
    }

    bookIt->setCopies(bookIt->getCopies() + 1); // Increase available copies
    std::cout << "Book " << bookIt->getTitle() << " returned successfully by user " << userID << ".\n";
    return true;
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

    // Save books
    outFile << "Books:\n";
    for (const auto& book : books) {
        outFile << book.getID() << "," << book.getTitle() << "," << book.getAuthor() << "\n";
    }

    outFile.close();
    std::cout << "Data saved successfully.\n";
}
