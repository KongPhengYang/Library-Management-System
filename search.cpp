#include <iostream>

#include "search.h"
#include "SearchFuncion.h"

void search() {
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
				
				// TODO fixme
				s.searchItems(library->inventory, keyword);
			}
			break;
			
			case '2': {
				std::string keyword;
				std::cout << "Enter keyword to search user by.\n";
				std::getline(std::cin, keyword);
				
				// TODO fixme
				s.searchItems(library->users, keyword);
			}
			
			case '9':
				std::cout << "Finished searching.\n";
				break;
				
			default:
				std::cout << "Unknown option. Please try again.\n";
		}
		
	}
	
}