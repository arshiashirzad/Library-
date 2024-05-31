#include <iostream>
using namespace std;

class Book {
private:
    string name;
    string bookId;
    bool isBorrowed;

public:
    Book(string name, string bookId) : name(name), bookId(bookId), isBorrowed(false) {}

    Book(const Book &other) : name(other.name), bookId(other.bookId), isBorrowed(other.isBorrowed) {}

    ~Book() {}

    string getName() const { return name; }

    void setName(const string &name) { this->name = name; }

    string getBookId() const { return bookId; }

    void setBookId(const string &bookId) { this->bookId = bookId; }

    bool getIsBorrowed() const { return isBorrowed; }

    void setIsBorrowed(bool isBorrowed) { this->isBorrowed = isBorrowed; }

    // Overloaded <<
    friend ostream &operator<<(ostream &out, const Book &book) {
        out << "Book: " << book.name << " (ID: " << book.bookId << ")";
        if (book.isBorrowed) {
            out << " - Borrowed";
        } else {
            out << " - Available";
        }
        return out;
    }

    // Overloaded >>
    friend istream &operator>>(istream &in, Book &book) {
        cout << "Enter book name: ";
        in >> book.name;
        cout << "Enter book ID: ";
        in >> book.bookId;
        book.isBorrowed = false; //
        return in;
    }

    // Overloaded =
    Book &operator=(const Book &other) {
        if (this != &other) {
            name = other.name;
            bookId = other.bookId;
            isBorrowed = other.isBorrowed;
        }
        return *this;
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


};
int main() {
    return 0;
}
