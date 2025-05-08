#include <iostream>

#include "search.h"
#include "SearchFuncion.h"
#include "Admin.h"

void search() {
	std::string keyword;
	std::string done("DONE");
				
	
	while (1) {
		std::cout << "Enter keyword to search book for. Or type DONE to quit\n";
		std::getline(std::cin, keyword);
		
		if (keyword == done)
			break;
		
		SearchFunction.searchItems(keyword);
	}
}

void adminSearch(Admin *a) {
	char c = 0;
	SearchFuncion s;
	
	std::cout << "Search for book or user by keywowrd.\n";
	
	while (c != '9') {
		std::cout << "1. Search for book.\n";
		std::cout << "2. Search for user.\n";
		std::cout << "9. Quit.\n";

		std::cin >> c;
		
		switch (c) {
			case '1': {
				std::string keyword;
				
				std::cout << "Enter keyword to search book for.\n";
				std::getline(std::cin, keyword);
				
				a->searchInventory(keyword);
			}
			break;
			
			case '2': {
				std::string keyword;
				std::cout << "Enter keyword to search user by.\n";
				std::getline(std::cin, keyword);
				
				a->searchUsers(keyword);
			}
			
			case '9':
				std::cout << "Finished searching.\n";
				break;
				
			default:
				std::cout << "Unknown option. Please try again.\n";
		}
		
	}
	
}