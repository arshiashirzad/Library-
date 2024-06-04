#include "VIPMember.h"

VIPMember::VIPMember(string name, string id, string memberId, int remainingBooks)
        : Member(name, id, memberId), remainingBooks(remainingBooks) {}

VIPMember::VIPMember(const VIPMember& other)
        : Member(other), remainingBooks(other.remainingBooks) {}

int VIPMember::getRemainingBooks() const { return remainingBooks; }
void VIPMember::setRemainingBooks(int remainingBooks) { this->remainingBooks = remainingBooks; }

void VIPMember::borrowBook(Book* book) {
    if (remainingBooks > 0 && dynamic_cast<VIPBook*>(book)) {
        Member::borrowBook(book);
        remainingBooks--;
    }
}

void VIPMember::returnBook(Book* book) {
    Member::returnBook(book);
    remainingBooks++;
}

ostream& operator<<(ostream& os, const VIPMember& member) {
    os << "VIPMember [Name: " << member.getName() << ", ID: " << member.getId() << ", MemberID: " << member.getMemberId() << ", RemainingBooks: " << member.remainingBooks << "]";
    return os;
}

istream& operator>>(istream& is, VIPMember& member) {
    cout << "Enter name: ";
    is >> member.name;
    cout << "Enter ID: ";
    is >> member.id;
    cout << "Enter member ID: ";
    is >> member.memberId;
    return is;
}
