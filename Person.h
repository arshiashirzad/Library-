#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string id;

public:
    Person(string name, string id);
    Person(const Person& other);

    string getName() const;
    void setName(const string& name);
    string getId() const;
    void setId(const string& id);

    friend ostream& operator<<(ostream& os, const Person& person);
    friend istream& operator>>(istream& is, Person& person);
};

#endif
