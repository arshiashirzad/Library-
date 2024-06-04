#include "VIPMember.h"

VIPMember::VIPMember(string name, string id, string memberId, int remainingBooks)
        : Member(name, id, memberId), remainingBooks(remainingBooks) {}

VIPMember::VIPMember(const VIPMember& other)
        : Member(other), remainingBooks(other.remainingBooks) {}

int VIPMember::getRemainingBooks() const { return remainingBooks; }
void VIPMember::setRemainingBooks(int remainingBooks) { this->remainingBooks = remainingBooks; }

void VIPMember::borrowBook(Book* book) {
    VIPBook* vipBook = static_cast<VIPBook*>(book);
    if (remainingBooks > 0 && vipBook) {
        Member::borrowBook(book);
        remainingBooks--;
    } else {
        cout << "Cannot borrow book: either it is not a VIP book or you have no remaining borrows." << endl;
    }
}

void VIPMember::returnBook(Book* book) {
    VIPBook* vipBook = static_cast<VIPBook*>(book);
    if (vipBook) {
        Member::returnBook(book);
        remainingBooks++;
    } else {
        cout << "Cannot return book: it is not a VIP book." << endl;
    }
}

ostream& operator<<(ostream& os, const VIPMember& member) {
    os << "VIPMember [Name: " << member.getName() << ", ID: " << member.getId() << ", MemberID: " << member.getId() << ", RemainingBooks: " << member.remainingBooks << "]";
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
