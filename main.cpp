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

	//Testing library
    Library& library = Library::getInstance();

    //Add users
	library.addUser("Bob", "22222", "password");
	library.addUser("Alice", "33333", "password");

	//Authenticate users
	library.authUser("22222", "password");

    //Save Data
	library.saveAll();

    return 0;
}
