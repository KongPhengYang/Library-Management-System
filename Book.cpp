#include "Book.h"

Book::Book(const std::string& id,
    const std::string& title,
    const std::string& author,
    int copies)
    : id(id), title(title), author(author), copies(copies) {
}

std::string Book::getID() const { return id; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getCopies() const { return copies; }

// Setter for copies
void Book::setCopies(int newCopies) {
    if (newCopies >= 0) {
        copies = newCopies;
    } else {
        std::cerr << "Error: Number of copies cannot be negative.\n";
    }
}

void Book::printSummary() const {
    std::cout << "Book: " << title << " (ID: " << id << ")\n" << " Author: " << author << "\n"<< " Copies Available: " << copies << "\n";
}