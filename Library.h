#ifndef LIBRARY_H
#define LIBRARY_H

#include "Staff.h"
#include "Member.h"
#include "VIPMember.h"
#include "Book.h"
#include "VIPBook.h"

class Library {
private:
    string name;
    Staff* staffs[100];
    int staffCount;
    Member* members[100];
    int memberCount;
    VIPMember* VIPmembers[100];
    int VIPmemberCount;
    Book* books[100];
    int bookCount;
    VIPBook* VIPbooks[100];
    int VIPbookCount;

public:
    Library(string name);
    ~Library();

    string getName() const;
    void setName(const string& name);

    void addStaff(Staff* staff);
    void deleteStaff(Staff* staff);

    void addMember(Member* member);
    void deleteMember(Member* member);

    void addVIPMember(VIPMember* vipMember);
    void deleteVIPMember(VIPMember* vipMember);

    void addBook(Book* book);
    void deleteBook(Book* book);

    void addVIPBook(VIPBook* vipBook);
    void deleteVIPBook(VIPBook* vipBook);

    void borrowBook(const string& memberId, const string& bookId);
    void returnBook(const string& memberId, const string& bookId);

private:
    template <typename T>
    T* findById(T* array[], int count, const string& id);

    template <typename T>
    void addToArray(T* array[], int& count, T* item);

    template <typename T>
    void deleteFromArray(T* array[], int& count, T* item);
};

#endif
