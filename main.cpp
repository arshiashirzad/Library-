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
        private:
        string name;
        string id;

        public:
        Person(string name, string id) : name(name), id(id) {}

        Person(const Person &other) : name(other.name), id(other.id) {}

        ~Person() {}

        string getName() const { return name; }

        void setName(const string &name) { this->name = name; }

        string getId() const { return id; }

        void setId(const string &id) { this->id = id; }

        // Overloaded <<
        friend ostream &operator<<(ostream &out, const Person &person) {
            out << "Name: " << person.name << ", ID: " << person.id;
            return out;
        }

        // Overloaded >>
        friend istream &operator>>(istream &in, Person &person) {
            cout << "Enter person name: ";
            in >> person.name;
            cout << "Enter person ID: ";
            in >> person.id;
            return in;
        }

        // Overloaded =
        Person &operator=(const Person &other) {
            if (this != &other) {
                name = other.name;
                id = other.id;
            }
            return *this;
        }
};
class Staff : public Person {
private:
string staffId;

public:
Staff(string name, string id, string staffId) : Person(name, id), staffId(staffId) {}

Staff(const Staff& other) : Person(other), staffId(other.staffId) {}

~Staff() {}

string getStaffId() const { return staffId; }
void setStaffId(const string& staffId) { this->staffId = staffId; }

// Overloaded <<
friend ostream& operator<<(ostream& out, const Staff& staff) {
    out << "Staff: " << static_cast<const Person&>(staff) << ", Staff ID: " << staff.staffId;
    return out;
}

// Overloaded >>
friend istream& operator>>(istream& in, Staff& staff) {
    in >> static_cast<Person&>(staff);
    cout << "Enter staff ID: ";
    in >> staff.staffId;
    return in;
}

// Overloaded =
Staff& operator=(const Staff& other) {
    if (this != &other) {
        Person::operator=(other);
        staffId = other.staffId;
    }
    return *this;
}
};

class Member : public Person {
private:
    string memberId;
    Book* books[5];

public:
    Member(string name, string id, string memberId) : Person(name, id), memberId(memberId) {
        for (int i = 0; i < 5; ++i) {
            books[i] = nullptr;
        }
    }

    Member(const Member& other) : Person(other), memberId(other.memberId) {
        for (int i = 0; i < 5; ++i) {
            if (other.books[i] != nullptr) {
                books[i] = new Book(*(other.books[i]));
            } else {
                books[i] = nullptr;
            }
        }
    }


    ~Member() {
        for (int i = 0; i < 5; ++i) {
            delete books[i];
        }
    }

    string getMemberId() const { return memberId; }
    void setMemberId(const string& memberId) { this->memberId = memberId; }

    // Overloaded <<
    friend ostream& operator<<(ostream& out, const Member& member) {
        out << "Member: " << static_cast<const Person&>(member) << ", Member ID: " << member.memberId << ", Borrowed Books: ";
        bool first = true;
        for (int i = 0; i < 5; ++i) {
            if (member.books[i] != nullptr) {
                if (!first) {
                    out << ", ";
                }
                out << *(member.books[i]);
                first = false;
            }
        }
        return out;
    }

    // Overloaded >>
    friend istream& operator>>(istream& in, Member& member) {
        in >> static_cast<Person&>(member);
        cout << "Enter member ID: ";
        in >> member.memberId;
        return in;
    }

    // Overloaded =
    Member& operator=(const Member& other) {
        if (this != &other) {
            static_cast<Person&>(*this) = static_cast<const Person&>(other);
            memberId = other.memberId;
            for (int i = 0; i < 5; ++i) {
                delete books[i];
                if (other.books[i] != nullptr) {
                    books[i] = new Book(*(other.books[i]));
                } else {
                    books[i] = nullptr;
                }
            }
        }
        return *this;
    }
    bool borrowBook(Book* book) {
        for (int i = 0; i < 5; ++i) {
            if (books[i] == nullptr) {
                books[i] = new Book(*book);
                return true;
            }
        }
        return false;
    }
};
class VIPMember : public Member {
private:
    int remainingBooks;

public:
    VIPMember(string name, string id, string memberId, int remainingBooks = 2)
            : Member(name, id, memberId), remainingBooks(remainingBooks) {}

    VIPMember(const VIPMember& other) : Member(other), remainingBooks(other.remainingBooks) {}


    ~VIPMember() {}

    int getRemainingBooks() const { return remainingBooks; }

    void setRemainingBooks(int remainingBooks) { this->remainingBooks = remainingBooks; }

    // Overloaded <<
    friend ostream& operator<<(ostream& out, const VIPMember& vipMember) {
        out << "VIP Member: " << static_cast<const Member&>(vipMember) << ", Remaining Books: " << vipMember.remainingBooks;
        return out;
    }

    // Overloaded >>
    friend istream& operator>>(istream& in, VIPMember& vipMember) {
        in >> static_cast<Member&>(vipMember);
        cout << "Enter remaining books: ";
        in >> vipMember.remainingBooks;
        return in;
    }
    // Overloaded =
    VIPMember& operator=(const VIPMember& other) {
        if (this != &other) {
            Member::operator=(other);
            remainingBooks = other.remainingBooks;
        }
        return *this;
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
