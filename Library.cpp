#include "Library.h"

Library::Library(string name)
        : name(name), staffCount(0), memberCount(0), VIPmemberCount(0), bookCount(0), VIPbookCount(0) {}

Library::~Library() {}

string Library::getName() const { return name; }
void Library::setName(const string& name) { this->name = name; }

void Library::addStaff(Staff* staff) { addToArray(staffs, staffCount, staff); }
void Library::deleteStaff(Staff* staff) { deleteFromArray(staffs, staffCount, staff); }

void Library::addMember(Member* member) { addToArray(members, memberCount, member); }
void Library::deleteMember(Member* member) { deleteFromArray(members, memberCount, member); }

void Library::addVIPMember(VIPMember* vipMember) { addToArray(VIPmembers, VIPmemberCount, vipMember); }
void Library::deleteVIPMember(VIPMember* vipMember) { deleteFromArray(VIPmembers, VIPmemberCount, vipMember); }

void Library::addBook(Book* book) { addToArray(books, bookCount, book); }
void Library::deleteBook(Book* book) { deleteFromArray(books, bookCount, book); }

void Library::addVIPBook(VIPBook* vipBook) { addToArray(VIPbooks, VIPbookCount, vipBook); }
void Library::deleteVIPBook(VIPBook* vipBook) { deleteFromArray(VIPbooks, VIPbookCount, vipBook); }

void Library::borrowBook(const string& memberId, const string& bookId) {
    Member* member = findById(members, memberCount, memberId);
    if (!member) {
        cout << "Member not found!" << endl;
        return;
    }

    Book* book = findById(books, bookCount, bookId);
    if (!book || book->getIsBorrowed()) {
        cout << "Book not found or already borrowed!" << endl;
        return;
    }

    member->borrowBook(book);
    book->setIsBorrowed(true);
    cout << "Book borrowed successfully!" << endl;
}

void Library::returnBook(const string& memberId, const string& bookId) {
    Member* member = findById(members, memberCount, memberId);
    if (!member) {
        cout << "Member not found!" << endl;
        return;
    }

    Book* book = findById(books, bookCount, bookId);
    if (!book) {
        cout << "Book not found!" << endl;
        return;
    }

    member->returnBook(book);
    book->setIsBorrowed(false);
    cout << "Book returned successfully!" << endl;
}

template <typename T>
T* Library::findById(T* array[], int count, const string& id) {
    for (int i = 0; i < count; ++i) {
        if (array[i]->getId() == id) {
            return array[i];
        }
    }
    return nullptr;
}

template <typename T>
void Library::addToArray(T* array[], int& count, T* item) {
    if (count < 100) {
        array[count++] = item;
    }
}

template <typename T>
void Library::deleteFromArray(T* array[], int& count, T* item) {
    for (int i = 0; i < count; ++i) {
        if (array[i] == item) {
            for (int j = i; j < count - 1; ++j) {
                array[j] = array[j + 1];
            }
            count--;
            break;
        }
    }
}
