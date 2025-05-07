#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "User.h"
#include "Admin.h"
#include "Book.h"

//This header file should implement the user and admin authenitication, addUSer, saveAll 
class Library {
private:
	std::vector<User> users; //Vector to hold all the users
	std::vector<Admin> admins; //Vector to hold all the admins
    std::vector<Book> books; //Vector to hold all the books
	Library() = default; //Private constructor
public:
    static Library& getInstance(); //Static member

    //User Management
    bool addUser(const std::string& name, const std::string& id, const std::string& password);     //For adding a new user
    bool removeUser(const std::string& userID);     //For removing a user
    bool editUser(const std::string& userID, const User& updatedUser);      //For modifying a user
    std::vector<User> getAllUsers() const;      //Return list of all users
    size_t getActiveUserCount() const;      //return number of currently active users

    //Authentication
    bool authAdmin(const std::string& id, const std::string& password);   //For the admin lgoin
    bool authUser(const std::string& id, const std::string& password);    //For the user login

    //Book Management
    bool addBook(const Book& book);     //For adding a book
    bool removeBook(const std::string& bookID);     //For removing a book
    bool editBook(const std::string& bookID, const Book& updatedBook);      //For modifying a book
    std::vector<Book> getAllBooks() const;      //Return list of all books
    // Book borrowing and returning
    bool borrowBook(const std::string& userID, const std::string& itemID);
    bool returnBook(const std::string& userID, const std::string& itemID);

    void saveAll();     //This is to save the data //This will use file I/O
};

#endif 