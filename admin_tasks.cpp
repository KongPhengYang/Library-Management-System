#include <iostream>

#include "admin_tasks.h"
#include "search.h"

bool loginAdmin() {
	std::string id, passwd;
	
	std::cout << "Enter Admin ID.\n";
	std::getline(std::cin, id);
	std::cout << "Enter Admin password.\n";
	std::getlie(std::cin, passwd);
	return library.authAdmin();
}

void manageInventory() {
	std::cout << "Add or remove books or set number of copies.\n";
	char c = 0;

	while (c != '9') {
		std::cout << "1. Add book.\n";
		std::cout << "2. Remove book.\n";
		std::cout << "3. Set number of copies.\n";
		std::cout << "9, Quit.\n";
		
		std::cin >> c;
		
		switch (c) {
			case '1': {
				std::string id, title, author;
				int copiesl
				
				std::cout << "Enter book info.\n";
				std::cout << "ID:\n"
				std::getline(std::cin, id);
				
				std::cout << "Title:\n"
				std::getline(std::cin, name);
				
				std::cout << "Author :\n"
				std::getline(std::cin, author);
				
				std::cout << "Copies:\n"
				std::cin >> copies
				
				Book newBook = new Book(id, title, author, copies);
				
				//TODO: Add to inventory
				std::cout << "Added book.\n";
			}
			break;
			case '2': {
				std::string id;
				
				std::cout << "Plese enter ID of book to remove.\n";
				std::getline(std::cin, id);
				
				// TODO Find Book. Remove if found
				std::cout << "Removed book.\n";
			}
			break;
			case '3': {
				std::string id;
				int copies = -1;
				
				std::cout << "Enter id of book to set number of copies.\n";
				std::getline(std::cin, id);
				
				while (copies < 0) {
					std::cout << "Enter number of copies"
					std::cin >> copies;
				}
				
				// TODO Find book and set number of copies
				std::cout << "Updated number of copies.\n";
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

void manageUsers() {
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
				
				// TODO DELETE USER
			}
			break;
			case '2':  {
				std::string id;
				std::string buf;
				char t;
				
				std::cout << "Enter ID of user to modify.\n";
				std::getline(std::cin, id);
				std::cout << "1. Modify name.\n 2. Modify Password."
				
				std::cin >> t;
				switch (t) {
					case '1':
						std::cout << "Enter new name of user.\n";
						std::getline(std::cin, buf);
						// TODO update user
						
						break;
					case '2':
						std::cout << "Enter new password for user.\n";
						std::getline(std::cin, buf)l
						
						// TODO update user
					default:
						std::cout << "Invalid operation.\n";
				}
			}
			break;
			
			case '9':
				std::cout << "Done managing users.\n";
				break;
				
			default:
				std::cout << "Unknown option. Please try again.\n";
		}
}

// TODO implement methhods

void printStats() {
	/*
	std::cout << "Number of users: " << library.getUsers().size() << "\n";
	std::cout << "Number of admins: " << library.getAdmins().size() << "\n";
	std::cout << "Number of unique books: " << library.getBooks().size() << "\n";
	*/
}	

void borrowAndReturn() {
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
				
				// TODO find user
				//
				user->borrowitem(book_id);
				std::cout << "Borrowed book.\n";
			}
			break
			
			case '2': {
				std::string book_id, user_id;
				User *user;
				
				std::cout << "Enter id of book to return.\n";
				std::getline(std::cin, book_id);
				std::cout << "Enter user id of borrower.\n";
				std:getline(std::cin, user_id);
				
				// TODO find user
				//
				user->returnItem(book_id);
				std::cout << "Returned book.\n";
			}
			break;
			
			default:
				std::cout << "Unknown option. Please try again.\n";
		}
	}
}


void adminTasks() {
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
				manageInventory();
				break;
			case '2':
				manageUsers()
				break;
			case '3':
				printStats();
				break;
			case '4':
				borrowAndReturn();
				break;
			case '5':
				search();
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