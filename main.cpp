#include <iostream>
using namespace std;

class Book {
protected:
    string name;
    string bookId;
    bool isBorrowed;

public:
    Book(string name, string bookId, bool isBorrowed = false)
            : name(name), bookId(bookId), isBorrowed(isBorrowed) {}

    Book(const Book& other)
            : name(other.name), bookId(other.bookId), isBorrowed(other.isBorrowed) {}

    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }
    string getBookId() const { return bookId; }
    void setBookId(const string& bookId) { this->bookId = bookId; }
    bool getIsBorrowed() const { return isBorrowed; }
    void setIsBorrowed(bool isBorrowed) { this->isBorrowed = isBorrowed; }

    string getId() const { return bookId; }

    // Overloaded <<
    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "Book [Name: " << book.name << ", BookID: " << book.bookId << ", IsBorrowed: " << (book.isBorrowed ? "Yes" : "No") << "]";
        return os;
    }

    // Overloaded >>
    friend istream& operator>>(istream& is, Book& book) {
        cout << "Enter name: ";
        is >> book.name;
        cout << "Enter book ID: ";
        is >> book.bookId;
        cout << "Enter is borrowed (1 for true, 0 for false): ";
        is >> book.isBorrowed;
        return is;
    }
};
class Person {
protected:
    string name;
    string id;

public:
    Person(string name, string id) : name(name), id(id) {}

    Person(const Person& other) : name(other.name), id(other.id) {}

    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    string getId() const { return id; }
    void setId(const string& id) { this->id = id; }

    // Overloaded <<
    friend ostream& operator<<(ostream& os, const Person& person) {
        os << "Person [Name: " << person.name << ", ID: " << person.id << "]";
        return os;
    }

    // Overloaded >>
    friend istream& operator>>(istream& is, Person& person) {
        cout << "Enter name: ";
        is >> person.name;
        cout << "Enter ID: ";
        is >> person.id;
        return is;
    }
};
class Staff : public Person {
private:
    string staffId;

public:
    Staff(string name, string id, string staffId)
            : Person(name, id), staffId(staffId) {}

    Staff(const Staff& other) : Person(other), staffId(other.staffId) {}

    string getStaffId() const { return staffId; }
    void setStaffId(const string& staffId) { this->staffId = staffId; }

    // Overloaded <<
    friend ostream& operator<<(ostream& os, const Staff& staff) {
        os << "Staff [Name: " << staff.name << ", ID: " << staff.id << ", StaffID: " << staff.staffId << "]";
        return os;
    }

    // Overloaded >>
    friend istream& operator>>(istream& is, Staff& staff) {
        cout << "Enter name: ";
        is >> staff.name;
        cout << "Enter ID: ";
        is >> staff.id;
        cout << "Enter staff ID: ";
        is >> staff.staffId;
        return is;
    }
};

class Member : public Person {
protected:
    string memberId;
    Book* books[10];
    int bookCount;

public:
    Member(string name, string id, string memberId)
            : Person(name, id), memberId(memberId), bookCount(0) {}

    Member(const Member& other)
            : Person(other), memberId(other.memberId), bookCount(other.bookCount) {
        for (int i = 0; i < bookCount; ++i) {
            books[i] = other.books[i];
        }
    }

    string getMemberId() const { return memberId; }
    void setMemberId(const string& memberId) { this->memberId = memberId; }

    void borrowBook(Book* book) {
        if (bookCount < 10) {
            books[bookCount++] = book;
        }
    }

    void returnBook(Book* book) {
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

    bool isBookBorrowed(Book* book) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i] == book) {
                return true;
            }
        }
        return false;
    }

    // Overloaded <<
    friend ostream& operator<<(ostream& os, const Member& member) {
        os << "Member [Name: " << member.name << ", ID: " << member.id << ", MemberID: " << member.memberId << "]";
        return os;
    }

    // Overloaded >>
    friend istream& operator>>(istream& is, Member& member) {
        cout << "Enter name: ";
        is >> member.name;
        cout << "Enter ID: ";
        is >> member.id;
        cout << "Enter member ID: ";
        is >> member.memberId;
        return is;
    }
};

class VIPMember : public Member {
private:
    int remainingBooks;

public:
    // Constructor
    VIPMember(string name, string id, string memberId)
            : Member(name, id, memberId), remainingBooks(2) {}

    // Copy Constructor
    VIPMember(const VIPMember& other)
            : Member(other), remainingBooks(other.remainingBooks) {}

    // Getter and Setter for remainingBooks
    int getRemainingBooks() const { return remainingBooks; }
    void setRemainingBooks(int remainingBooks) { this->remainingBooks = remainingBooks; }

    // Borrow book
    void borrowBook(Book* book) {
        if (remainingBooks > 0 && bookCount < 10) {
            books[bookCount++] = book;
            remainingBooks--;
        }
    }

    // Return book
    void returnBook(Book* book) {
        for (int i = 0; i < bookCount; ++i) {
            if (books[i] == book) {
                for (int j = i; j < bookCount - 1; ++j) {
                    books[j] = books[j + 1];
                }
                bookCount--;
                remainingBooks++;
                break;
            }
        }
    }

    // Overloaded << Operator
    friend ostream& operator<<(ostream& os, const VIPMember& member) {
        os << "VIPMember [Name: " << member.getName() << ", ID: " << member.getId() << ", MemberID: " << member.getMemberId() << ", RemainingBooks: " << member.remainingBooks << "]";
        return os;
    }

    // Overloaded >> Operator
    friend istream& operator>>(istream& is, VIPMember& member) {
        cout << "Enter name: ";
        is >> member.name;
        cout << "Enter ID: ";
        is >> member.id;
        cout << "Enter member ID: ";
        is >> member.memberId;
        return is;
    }
};
class VIPBook : public Book {
public:
    VIPBook(string name, string bookId, bool isBorrowed = false)
            : Book(name, bookId, isBorrowed) {}

    VIPBook(const VIPBook& other)
            : Book(other) {}

    // Overloaded =
    VIPBook& operator=(const VIPBook& other) {
        if (this != &other) {
            this->name = other.name;
            this->bookId = other.bookId;
            this->isBorrowed = other.isBorrowed;
        }
        return *this;
    }

    // Overloaded <<
    friend ostream& operator<<(ostream& os, const VIPBook& book) {
        os << "VIPBook [Name: " << book.name << ", BookID: " << book.bookId << ", IsBorrowed: " << (book.isBorrowed ? "Yes" : "No") << "]";
        return os;
    }

    // Overloaded >>
    friend istream& operator>>(istream& is, VIPBook& book) {
        cout << "Enter name: ";
        is >> book.name;
        cout << "Enter book ID: ";
        is >> book.bookId;
        cout << "Enter is borrowed (1 for true, 0 for false): ";
        is >> book.isBorrowed;
        return is;
    }
};
// Using template for multiple types here
template <typename T>
struct Node {
    T* data;
    Node* next;
    Node(T* data) : data(data), next(nullptr) {}
};

class Library {
private:
    string name;
    Node<Staff>* staffHead;
    Node<Member>* memberHead;
    Node<VIPMember>* VIPmemberHead;
    Node<Book>* bookHead;
    Node<VIPBook>* VIPbookHead;

public:

    Library(string name) : name(name), staffHead(nullptr), memberHead(nullptr), VIPmemberHead(nullptr), bookHead(nullptr), VIPbookHead(nullptr) {}


    ~Library() {
        // Clean up dynamically allocated nodes and objects
        clearList(staffHead);
        clearList(memberHead);
        clearList(VIPmemberHead);
        clearList(bookHead);
        clearList(VIPbookHead);
    }

    template <typename T>
    void clearList(Node<T>*& head) {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
        }
    }

    string getName() const { return name; }
    void setName(const string& name) { this->name = name; }


    void addStaff(Staff* staff) {
        addNode(staffHead, staff);
    }


    void deleteStaff(Staff* staff) {
        deleteNode(staffHead, staff);
    }


    void addMember(Member* member) {
        addNode(memberHead, member);
    }


    void deleteMember(Member* member) {
        deleteNode(memberHead, member);
    }


    void addVIPMember(VIPMember* vipMember) {
        addNode(VIPmemberHead, vipMember);
    }


    void deleteVIPMember(VIPMember* vipMember) {
        deleteNode(VIPmemberHead, vipMember);
    }


    void addBook(Book* book) {
        addNode(bookHead, book);
    }


    void deleteBook(Book* book) {
        deleteNode(bookHead, book);
    }


    void addVIPBook(VIPBook* vipBook) {
        addNode(VIPbookHead, vipBook);
    }


    void deleteVIPBook(VIPBook* vipBook) {
        deleteNode(VIPbookHead, vipBook);
    }


    void borrowBook(const string& memberId, const string& bookId) {
        Member* member = findNode(memberHead, memberId);
        if (member) {
            Book* book = findNode(bookHead, bookId);
            if (book && !book->getIsBorrowed()) {
                member->borrowBook(book);
                book->setIsBorrowed(true);
                cout << "Book borrowed successfully!" << endl;
            } else {
                cout << "Book not found or already borrowed!" << endl;
            }
        } else {
            cout << "Member not found!" << endl;
        }
    }


    void returnBook(const string& memberId, const string& bookId) {
        Member* member = findNode(memberHead, memberId);
        if (member) {
            Book* book = findNode(bookHead, bookId);
            if (book) {
                member->returnBook(book);
                book->setIsBorrowed(false);
                cout << "Book returned successfully!" << endl;
            } else {
                cout << "Book not found!" << endl;
            }
        } else {
            cout << "Member not found!" << endl;
        }
    }

private:
    template <typename T>
    void addNode(Node<T>*& head, T* data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }


    template <typename T>
    void deleteNode(Node<T>*& head, T* data) {
        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        while (temp && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            delete temp->data;
            delete temp;
        }
    }

//
//    template <typename T>
//    T* findNode(Node<T>* head, const string& id) {
//        Node<T>* temp = head;
//        while (temp) {
//            if (temp->data->getId()== id) {
//                return temp->data;
//            }
//            temp = temp->next;
//        }
//        return nullptr;
//    }
};
int main() {
    return 0;
}
