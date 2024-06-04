#include "Member.h"

Member::Member(string name, string id, string memberId)
        : Person(name, id), memberId(memberId), bookCount(0) {}

Member::Member(const Member& other)
        : Person(other), memberId(other.memberId), bookCount(other.bookCount) {
    for (int i = 0; i < bookCount; ++i) {
        books[i] = other.books[i];
    }
}

string Member::getId() const { return memberId; }
void Member::setMemberId(const string& memberId) { this->memberId = memberId; }

void Member::borrowBook(Book* book) {
    if (bookCount < 10) {
        books[bookCount++] = book;
    }
}

void Member::returnBook(Book* book) {
    for (int i = 0; i < bookCount; ++i) {
        if (books[i] == book) {
            for (int j = i; j < bookCount - 1; ++j) {
                books[j] = books[j + 1];
            }
            bookCount--;
            break;
        }
    }
}

bool Member::isBookBorrowed(Book* book) {
    for (int i = 0; i < bookCount; ++i) {
        if (books[i] == book) {
            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& os, const Member& member) {
    os << "Member [Name: " << member.name << ", ID: " << member.id << ", MemberID: " << member.memberId << "]";
    return os;
}

istream& operator>>(istream& is, Member& member) {
    cout << "Enter name: ";
    is >> member.name;
    cout << "Enter ID: ";
    is >> member.id;
    cout << "Enter member ID: ";
    is >> member.memberId;
    return is;
}
