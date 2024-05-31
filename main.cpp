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
lass Person {
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
int main() {
    return 0;
}
