#include <iostream>
#include "Library.h"
#include "Admin.h"
#include "User.h"
#include "Book.h"

int main() {
    //Testing making admin
    Admin adminTest("John", "11111", "password");
    std::cout << "Admin Summary:\n";
    adminTest.printSummary();
    std::cout << std::endl;

    //Testing making user and the borrow/return
    User userTest("Bob", "22222", "password");
    std::cout << "Initial User Summary:\n";
    userTest.printSummary();

    std::cout << "Borrowing 'Harry Potter'\n";
    userTest.borrowItem("HArry Potter");
    std::cout << "After Borrow Summary:\n";
    userTest.printSummary();

    std::cout << "Returning 'Harry Potter'...\n";
    userTest.returnItem("Hary Potter");
    std::cout << "After Return Summary:\n";
    userTest.printSummary();

    //Testing book
    Book bookTest("B123", "Harry Potter", "JK ROWLING", 5);
    std::cout << "\nBook Summary:\n";
    bookTest.printSummary();

    //Test searchItems
    std::cout << "Testing searchItems:\n";
    SearchFunction::searchItems(inventory, "Harry");

    //Test findUser
    std::cout << "\nTesting findUser:\n";
    SearchFunction::findUser(users, "Bob");

	//Test library
    Library& library = Library::getInstance();

    //Test Add users
	library.addUser("Bob", "22222", "password");
	library.addUser("Alice", "33333", "password");

	//Test Authenticate users
	library.authUser("22222", "password");

    //Test Save Data
	library.saveAll();

    return 0;
}
