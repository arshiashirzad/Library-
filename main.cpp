#include "Library.h"

int main() {
    Library lib("Ketabkhune Markazi");

    Staff* staff1 = new Staff("Aroosha", "S1", "ST1");
    Staff* staff2 = new Staff("Azadeh", "S2", "ST2");
    lib.addStaff(staff1);
    lib.addStaff(staff2);

    Member* member1 = new Member("Arshia", "M1", "MB1");
    Member* member2 = new Member("Hoseein", "M2", "MB2");
    lib.addMember(member1);
    lib.addMember(member2);

    VIPMember* vipMember1 = new VIPMember("ShanbeZadeh", "V1", "VIP1");
    lib.addVIPMember(vipMember1);

    Book* book1 = new Book("Riazi1", "B1");
    Book* book2 = new Book("Riazi2", "B2");
    lib.addBook(book1);
    lib.addBook(book2);

    VIPBook* vipBook1 = new VIPBook("C++ Coders", "VB1");
    lib.addVIPBook(vipBook1);

    lib.borrowBook("MB1", "B1");
    lib.returnBook("MB1", "B1");

    lib.deleteStaff(staff1);
    lib.deleteStaff(staff2);
    lib.deleteMember(member1);
    lib.deleteMember(member2);
    lib.deleteVIPMember(vipMember1);
    lib.deleteBook(book1);
    lib.deleteBook(book2);
    lib.deleteVIPBook(vipBook1);
    //Free Memory
    delete staff1;
    delete staff2;
    delete member1;
    delete member2;
    delete vipMember1;
    delete book1;
    delete book2;
    delete vipBook1;

    return 0;
}
