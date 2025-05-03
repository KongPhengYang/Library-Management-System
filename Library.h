#ifndef LIBRARY_H
#define LIBRARY_H


//This header file should implement the user and admin authenitication, addUSer, saveAll 
class Library {
public:
    static Library& getInstance(); //Static member
    bool addUser();     //For adding new users for adding a new user
    bool authAdmin();   //For the admin lgoin
    bool authUser();    //For the user login
    void saveAll();     //This is to save the data //This will use file I/O
};

#endif 