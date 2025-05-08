#include <iostream>
#include <string>
#include "search.h"
#include "SearchFunction.h"
#include "Library.h"   
#include "Admin.h" 

void search() {
    std::string keyword;
    const std::string done("DONE");

    while (true) {
        std::cout << "Enter keyword to search book for. Or type DONE to quit\n";
        std::getline(std::cin, keyword);

        if (keyword == done)
            break;

        SearchFunction::searchItems(
            Library::getInstance().getAllBooks(),
            keyword
        );
    }
}

void adminSearch(Admin* a) {
    char c = 0;
    std::string keyword;

    std::cout << "Search for book or user by keyword.\n";

    while (c != '9') {
        std::cout << "1. Search for book.\n";
        std::cout << "2. Search for user.\n";
        std::cout << "9. Quit.\n";

        std::cin >> c;
        std::cin.ignore(); 

        switch (c) {
        case '1':
            std::cout << "Enter keyword to search book for.\n";
            std::getline(std::cin, keyword);
            SearchFunction::searchItems(
                Library::getInstance().getAllBooks(),
                keyword
            );
            break;

        case '2':
            std::cout << "Enter keyword to search user by.\n";
            std::getline(std::cin, keyword);
            SearchFunction::searchUsers(
                Library::getInstance().getAllUsers(),
                keyword
            );
            break;

        case '9':
            std::cout << "Finished searching.\n";
            break;

        default:
            std::cout << "Unknown option. Please try again.\n";
        }
    }
}
