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

int main() {
    return 0;
}
