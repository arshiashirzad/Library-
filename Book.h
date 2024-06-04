#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string name;
    string bookId;
    bool isBorrowed;

public:
    Book(string name, string bookId, bool isBorrowed = false);
    Book(const Book& other);

    string getName() const;
    void setName(const string& name);
    string getBookId() const;
    void setBookId(const string& bookId);
    bool getIsBorrowed() const;
    void setIsBorrowed(bool isBorrowed);
    string getId() const;

    friend ostream& operator<<(ostream& os, const Book& book);
    friend istream& operator>>(istream& is, Book& book);
};

#endif
