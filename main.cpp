#include <iostream.h>

#include "admin_tasks.h"
#include "search.h"
#include "Library.h"
#include "User.h"
#include "Admin.h"

void registerNewUsers() {
	std::string name, id, passwd
	std::string done("DONE");
	
	while (1) {
		std::cout << "Please enter the new name, id, and password of the user.\n\
		Or type 'DONE' to finish.\n";
		
		std::cout << "User name or 'DONE':\n";
		std::getline(std::cin, name);
		if (buf.compare("DONE") == 0) {
			return;
		}
		
		std::cout << "User ID:\n";
		std::getline(std::cin, id);
		
		std::cout << "User Password:\n";
		std::getline(std::cin, passwd);
		
		Library& lib = Library::getInstance();
		
		if (!(library->addUser(name, id, passwd))) {
			std::cout << "Please try again with another user.\n";
		}
	}
}

User *loginUser() {
	std::string id, passwd, name;
	User *user;
	
	std::cout << "Enter User ID.\n";
	std::getline(std::cin, id);
	
	std::cout << "Enter User Name.\n";
	std::getline(std::cin, name);
	
	std::cout << "Enter User password.\n";
	std::getline(std::cin, passwd);
	
	return new User(name, id, password);
}

void userTasks(User *user) {
	char c = 0;
	std::cout << "Select user operation.\n";
	
	while (c != '9') {
		std::cout << "1. Print user info.\n";
		std::cout << "2. Search.\n";
		std::cout << "9. Quit.\n"
		
		std::cin >> c;
		
		switch (c) {
			case '1':
				user->printSummary();
				break;
			case '2':
				search();
				break;
			case '9':
				std::cout << "Logging out user.\n";
				break;
			default:
				std::cout << "Unknown option. Please try again.\n";
		}
	}
}

int main() {
	char c = 0;
	std::cout << "Welcome to the library system. Please select an option\n";
	
	while (c != '4') {
		std::cout << "1. Register New Users\n";
		std::cout << "2. Admin (Librarian) Login\n";
		std::cout << "3. User Login\n";
		std::cout << "4. Exit"
		
		std::cin >> c;
		
		switch (c) {
			case '1':
				registerNewUsers();
				break;
			case '2':
				Admin *admin = loginAdmin();
				if (admin)
					adminTasks(admin);
				break;
			case '3':
				Use *user = loginUser();
				if (user) {
					userTasks(user);
				}
				break;
			case '4':
				std::cout << "Session finished.\n";
				std::cout << "All data is now being saved then the program will terminate.\n";
				library.saveAll();
				break;
			default: 
				std::cout << "Invalid option. Please review the current options.\n";
		}
		
	}
	
	return 0;
}