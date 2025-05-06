#ifndef SEARCHFUNCTION_H
#define SEARCHFUNCTION_H
#include <string>
#include <vector>
#include "User.h"
#include "Book.h"

class SearchFunction {
public:
    //This function should be able to search for inventryor items by keyword in the title/author
    static void searchItems(const std::vector<Book>& inventory, const std::string& keyword); //Will probably use list with pointers and referances
    //This function should fina a user by their name or by their id
    static void findUser(const std::vector<User>& users, const std::string& keyword);//Will probably return a pointer to User
};

#endif