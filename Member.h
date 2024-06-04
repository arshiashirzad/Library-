#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include "Book.h"

class Member : public Person {
protected:
    string memberId;
    Book* books[10];
    int bookCount;

public:
    Member(string name, string id, string memberId);
    Member(const Member& other);

    string getId() const;
    void setMemberId(const string& memberId);

    void borrowBook(Book* book);
    void returnBook(Book* book);
    bool isBookBorrowed(Book* book);

    friend ostream& operator<<(ostream& os, const Member& member);
    friend istream& operator>>(istream& is, Member& member);
};

#endif
