#include <iostream>
#include <string>

#include "admin_tasks.h"
#include "search.h"
#include "Library.h"

Admin* loginAdmin() {
    std::string id, name, passwd;

    std::cout << "Enter Admin ID.\n";
    std::getline(std::cin, id);

    std::cout << "Enter Admin Name.\n";
    std::getline(std::cin, name);

    std::cout << "Enter Admin password.\n";
    std::getline(std::cin, passwd);

    Library& lib = Library::getInstance();
    if (lib.authAdmin(id, passwd))
        return new Admin(name, id, passwd);
    return nullptr;
}

Book* newBook() {
    std::string id, title, author;
    int copies = -1;

    std::cout << "ID:\n";
    std::getline(std::cin, id);

    std::cout << "Title:\n";
    std::getline(std::cin, title);

    std::cout << "Author:\n";
    std::getline(std::cin, author);

    while (copies < 0) {
        std::cout << "Copies:\n";
        std::cin >> copies;
        std::cin.ignore();  
    }

    return new Book(id, title, author, copies);
}

void manageInventory(Admin* a) {
    std::cout << "Add or remove books or edit book.\n";
    char c = 0;

    while (c != '9') {
        std::cout << "1. Add book.\n"
            << "2. Remove book.\n"
            << "3. Edit book details.\n"
            << "9. Quit.\n";

        std::cin >> c;
        std::cin.ignore(); 

        switch (c) {
        case '1': {
            std::cout << "Enter new book info.\n";
            Book* book = newBook();
            a->addInventoryItem(*book);
        } break;

        case '2': {
            std::string bid;
            std::cout << "Please enter ID of book to remove.\n";
            std::getline(std::cin, bid);
            a->removeInventoryItem(bid);
        } break;

        case '3': {
            std::string bid;
            std::cout << "Enter ID of book to edit.\n";
            std::getline(std::cin, bid);
            std::cout << "Now enter the new info about the book.\n";
            Book* book = newBook();
            a->editInventoryItem(bid, *book);
        } break;

        case '9':
            std::cout << "Done managing inventory.\n";
            break;

        default:
            std::cout << "Unknown option. Please try again.\n";
        }
    }
}

void manageUsers(Admin* a) {
    std::cout << "Delete User or edit info.\n";
    char c = 0;

    while (c != '9') {
        std::cout << "1. Delete user.\n"
            << "2. Edit info.\n"
            << "9. Exit.\n";

        std::cin >> c;
        std::cin.ignore();

        switch (c) {
        case '1': {
            std::string uid;
            std::cout << "Enter ID of user to delete.\n";
            std::getline(std::cin, uid);
            a->deleteUserAccount(uid);
        } break;

        case '2': {
            std::string oldId, newName, newId, newPass;
            std::cout << "Enter ID of user to edit.\n";
            std::getline(std::cin, oldId);

            std::cout << "Enter new user name.\n";
            std::getline(std::cin, newName);

            std::cout << "Enter new user ID.\n";
            std::getline(std::cin, newId);

            std::cout << "Enter new user password.\n";
            std::getline(std::cin, newPass);

            User* updated = new User(newName, newId, newPass);
            a->editUserDetails(oldId, *updated);
        } break;

        case '9':
            std::cout << "Done managing users.\n";
            break;

        default:
            std::cout << "Unknown option. Please try again.\n";
        }
    }
}

void printStats() {
    Library& lib = Library::getInstance();
    std::cout << "Number of users: " << lib.getAllUsers().size() << "\n";
    std::cout << "Number of books: " << lib.getAllBooks().size() << "\n";
}

void borrowAndReturn(Admin*) {
    std::cout << "Borrow or return book for user.\n";
    char c = 0;

    while (c != '9') {
        std::cout << "1. Borrow book.\n"
            << "2. Return book.\n"
            << "9. Quit.\n";

        std::cin >> c;
        std::cin.ignore(); 

        switch (c) {
        case '1': {
            std::string bid, uid;
            std::cout << "Enter ID of book to borrow.\n";
            std::getline(std::cin, bid);
            std::cout << "Enter user ID of borrower.\n";
            std::getline(std::cin, uid);

            Library::getInstance().borrowBook(uid, bid);
        } break;

        case '2': {
            std::string bid, uid;
            std::cout << "Enter ID of book to return.\n";
            std::getline(std::cin, bid);
            std::cout << "Enter user ID of borrower.\n";
            std::getline(std::cin, uid);

            Library::getInstance().returnBook(uid, bid);
        } break;

        case '9':
            std::cout << "Done with borrow/return.\n";
            break;

        default:
            std::cout << "Unknown option. Please try again.\n";
        }
    }
}
void adminTasks(Admin* a) {
    std::cout << "Welcome to Administrator panel. Please select an option.\n";
    char c = 0;

    while (c != '9') {
        std::cout << "1. Manage Inventory.\n"
            << "2. Manage User Accounts.\n"
            << "3. Get Library statistics.\n"
            << "4. Borrow and return books.\n"
            << "5. Search inventory and users.\n"
            << "9. Logout.\n";

        std::cin >> c;
        std::cin.ignore(); 

        switch (c) {
        case '1': manageInventory(a);     break;
        case '2': manageUsers(a);         break;
        case '3': printStats();           break;
        case '4': borrowAndReturn(a);     break;
        case '5': adminSearch(a);         break;
        case '9': std::cout << "Now logging out Admin.\n"; break;
        default:  std::cout << "Unknown option. Try again.\n"; break;
        }
    }
}
