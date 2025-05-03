#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

// Represents a book or similar inventory item
class Book {
private:
    std::string id;         //Book ID
    std::string title;      //Book title
    std::string author;     //Author name
    int copies;             //Number of copies available
public:
    Book() = default;
    Book(const std::string& id,
        const std::string& title,
        const std::string& author,
        int copies);

    //Getters
    std::string getID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getCopies() const;

    //Print the book info/summary
    void printSummary() const;
};

#endif // BOOK_H