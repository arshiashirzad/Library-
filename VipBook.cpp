#include "VIPBook.h"

VIPBook::VIPBook(string name, string bookId, bool isBorrowed)
        : Book(name, bookId, isBorrowed) {}

VIPBook::VIPBook(const VIPBook& other)
        : Book(other) {}

VIPBook& VIPBook::operator=(const VIPBook& other) {
    if (this != &other) {
        this->name = other.name;
        this->bookId = other.bookId;
        this->isBorrowed = other.isBorrowed;
    }
    return *this;
}

ostream& operator<<(ostream& os, const VIPBook& book) {
    os << "VIPBook [Name: " << book.name << ", BookID: " << book.bookId << ", IsBorrowed: " << (book.isBorrowed ? "Yes" : "No") << "]";
    return os;
}

istream& operator>>(istream& is, VIPBook& book) {
    cout << "Enter name: ";
    is >> book.name;
    cout << "Enter book ID: ";
    is >> book.bookId;
    cout << "Enter is borrowed (1 for true, 0 for false): ";
    is >> book.isBorrowed;
    return is;
}
