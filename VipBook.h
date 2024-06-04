#ifndef VIPBOOK_H
#define VIPBOOK_H

#include "Book.h"

class VIPBook : public Book {
public:
    VIPBook(string name, string bookId, bool isBorrowed = false);
    VIPBook(const VIPBook& other);

    VIPBook& operator=(const VIPBook& other);

    friend ostream& operator<<(ostream& os, const VIPBook& book);
    friend istream& operator>>(istream& is, VIPBook& book);
};

#endif
