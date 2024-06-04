#include "Book.h"

Book::Book(string name, string bookId, bool isBorrowed)
    : name(name), bookId(bookId), isBorrowed(isBorrowed) {}

Book::Book(const Book& other)
    : name(other.name), bookId(other.bookId), isBorrowed(other.isBorrowed) {}

string Book::getName() const { return name; }
void Book::setName(const string& name) { this->name = name; }
string Book::getBookId() const { return bookId; }
void Book::setBookId(const string& bookId) { this->bookId = bookId; }
bool Book::getIsBorrowed() const { return isBorrowed; }
void Book::setIsBorrowed(bool isBorrowed) { this->isBorrowed = isBorrowed; }
string Book::getId() const { return bookId; }

ostream& operator<<(ostream& os, const Book& book) {
    os << "Book [Name: " << book.name << ", BookID: " << book.bookId << ", IsBorrowed: " << (book.isBorrowed ? "Yes" : "No") << "]";
    return os;
}

istream& operator>>(istream& is, Book& book) {
    cout << "Enter name: ";
    is >> book.name;
    cout << "Enter book ID: ";
    is >> book.bookId;
    cout << "Enter is borrowed (1 for true, 0 for false): ";
    is >> book.isBorrowed;
    return is;
}
