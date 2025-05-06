#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "User.h"
#include "Admin.h"

//This header file should implement the user and admin authenitication, addUSer, saveAll 
class Library {
private:
	std::vector<User> users; //Vector to hold all the users
	std::vector<Admin> admins; //Vector to hold all the admins
	Library() = default; //Private constructor
public:
    static Library& getInstance(); //Static member
    bool addUser(const std::string& name, const std::string& id, const std::string& password);     //For adding a new user
    bool authAdmin(const std::string& id, const std::string& password);   //For the admin lgoin
    bool authUser(const std::string& id, const std::string& password);    //For the user login
    void saveAll();     //This is to save the data //This will use file I/O
};

#endif 