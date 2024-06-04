#include "Person.h"

Person::Person(string name, string id) : name(name), id(id) {}

Person::Person(const Person& other) : name(other.name), id(other.id) {}

string Person::getName() const { return name; }
void Person::setName(const string& name) { this->name = name; }
string Person::getId() const { return id; }
void Person::setId(const string& id) { this->id = id; }

ostream& operator<<(ostream& os, const Person& person) {
    os << "Person [Name: " << person.name << ", ID: " << person.id << "]";
    return os;
}

istream& operator>>(istream& is, Person& person) {
    cout << "Enter name: ";
    is >> person.name;
    cout << "Enter ID: ";
    is >> person.id;
    return is;
}
