#include <iostream>

#include "admin_tasks.h"
#include "search.h"
#include "Admin.h"
#include "Library.h"
#include "User.h"

Admin *loginAdmin() {
	std::string id, name passwd;
	
	std::cout << "Enter Admin ID.\n";
	std::getline(std::cin, id);
	
	std::cout << "Enter Admin Name.\n";
	std::getline(std::cin, name);
	
	std::cout << "Enter Admin password.\n";
	std::getline(std::cin, passwd);
	
	if (library.authAdmin(id, password))
		return new Admin(id, name, passwd);
	else
		return NULL;
}


Book *newBook() {
	std::string id, title, author;
	int copies = -1;
	
	std::cout << "ID:\n"
	std::getline(std::cin, id);
	
	std::cout << "Title:\n"
	std::getline(std::cin, name);
	
	std::cout << "Author :\n"
	std::getline(std::cin, author);
	
	while (copies < 0) {
		std::cout << "Copies:\n"
		std::cin >> copies
	}

	Book newBook = new Book(id, title, author, copies);
	return newBook;
}

void manageInventory(Admin *a) {
	std::cout << "Add or remove books or edit book.\n";
	char c = 0;

	while (c != '9') {
		std::cout << "1. Add book.\n";
		std::cout << "2. Remove book.\n";
		std::cout << "3. Edit book details.\n";
		std::cout << "9, Quit.\n";
		
		std::cin >> c;
		
		switch (c) {
			case '1': {
				std::cout << "Enter new book info.\n";
				Book *book = newBook();
				
				//1
				a->addInventoryItem(book);
			}
			break;
			case '2': {
				std::string id;
				
				std::cout << "Plese enter ID of book to remove.\n";
				std::getline(std::cin, id);
				
				// T2
				a->removeInventoryItem(id);
				
			}
			break;
			case '3': {
				std::cout << "Enter id of book to edit.\n";
				std::string id;
				
				
				std::getline(std::cin, id);
				
				std::cout << "Now enter the new info about the book.\n";
				Book *book = newBook();
				
				a->editInventoryItem(id, book);
				
			}
			break;
			
			case '9':
				std::cout << "Done managing inventory.\n"
				break;
				
			default:
				std::cout << "Unknown option. Please try again.\n";
		}
		
	}
}

void manageUsers(Admin *a) {
	std::cout << "Delete User or edit info.\n";
	char c = 0;
	
	while (c != '9') {
		std::cout << "1. Delete user.\n";
		std::cout << "2. Edit info.\n";
		std::cout << "9. Exit.\n";
	
		std::cin >> c;
		
		switch (c) {
			case '1': {
				std::string id;
				std::cout << "Enter ID of user to delete.\n";
				std::cin >> id;
				
				a->deleteUserAccount(id);
			}
			break;
			case '2':  {
				std::string id;
				std::string nid, nname, npasswd;
				
				std::cout << "Enter id of user to edit.\n";
				std::getline(std::cin, id);
				
				std::cout << "Enter new user name.\n";
				std::getline(std::cin, nname);
				
				std::cout << "Enter new user id.\n";
				std::getline(std::cin, nid);
				
				std::cout << "Enter new user password.\n";
				std::getline(std::cin, npasswd);
				
				User newUser = new User(name, id, password);
				
				a->editUserDetails(id, newUser);
			}
			break;
			
			case '9':
				std::cout << "Done managing users.\n";
				break;
				
			default:
				std::cout << "Unknown option. Please try again.\n";
		}
}

void printStats() {
	Library& lib = Library::getInstance();
	
	std::cout << "Number of users: " << library.getAllUsers().size() << "\n";
	std::cout << "Number of books: " << library.getAllBooks().size() << "\n";
}	

void borrowAndReturn(Admin *a) {
	std::cout << "Borrow or return book for user";
	char c = 0;
	
	while (c != '9') {
		std::cout << "1. Borrow book.\n";
		std::cout << "2. Return book.\n";
		std::cout << "9. Quit.\n";
		
		std::cin >> c;
		
		switch (c) {
			case '1': {
				std::string book_id, user_id;
				User *user;
				
				std::cout << "Enter id of book to borrow.\n";
				std::getline(std::cin, book_id);
				std::cout << "Enter user id of borrower.\n";
				std:getline(std::cin, user_id);
				
				// !
				Library& lib = Library::getInstance();
				lib.borrowBook(user_id, book_id);
				
			}
			break
			
			case '2': {
				std::string book_id, user_id;
				User *user;
				
				std::cout << "Enter id of book to return.\n";
				std::getline(std::cin, book_id);
				std::cout << "Enter user id of borrower.\n";
				std:getline(std::cin, user_id);
				
				Library& lib = Library::getInstance();
				lib.returnBook(user_id, book_id);
			}
			break;
			
			default:
				std::cout << "Unknown option. Please try again.\n";
		}
	}
}


void adminTasks(Admin *a) {
	std::cout << "Welcome to Administrator panel. Please select an option.\n"
	char c = 0;
	
	while (c != '9') {
		std::cout << "1. Manage Inventory.\n";
		std::cout << "2. Manage User Accounts.\n";
		std::cout << "3. Get Library statistics.\n";
		std::cout << "4. Borrow and return books.\n";
		std::cout << "5. Search inventory and users.\n";
		std::cout << "9. Logout.\n";
		
		std::cin >> c;
		
		switch (c) {
			case '1':
				manageInventory(a);
				break;
			case '2':
				manageUsers(a)
				break;
			case '3':
				printStats();
				break;
			case '4':
				borrowAndReturn(Admin *a);
				break;
			case '5':
				adminSearch(a);
				break;
			case '9':
				std::cout << "Now logging out Admin.\n";
				break;
			default:
				std::cout << "Unknown option. Please review the set of options and try again.\n";
				break;
		}
	}
}