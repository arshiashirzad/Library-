#ifndef STAFF_H
#define STAFF_H

#include "Person.h"

class Staff : public Person {
private:
    string staffId;

public:
    Staff(string name, string id, string staffId);
    Staff(const Staff& other);

    string getStaffId() const;
    void setStaffId(const string& staffId);

    friend ostream& operator<<(ostream& os, const Staff& staff);
    friend istream& operator>>(istream& is, Staff& staff);
};

#endif
