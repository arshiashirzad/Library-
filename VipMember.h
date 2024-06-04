#ifndef VIPMEMBER_H
#define VIPMEMBER_H

#include "Member.h"
#include "VIPBook.h"

class VIPMember : public Member {
private:
    int remainingBooks;
public:
    VIPMember(string name, string id, string memberId, int remainingBooks = 2);
    VIPMember(const VIPMember& other);

    int getRemainingBooks() const;
    void setRemainingBooks(int remainingBooks);

    void borrowBook(Book* book);
    void returnBook(Book* book);

    friend ostream& operator<<(ostream& os, const VIPMember& member);
    friend istream& operator>>(istream& is, VIPMember& member);
};

#endif
