#include "Staff.h"

Staff::Staff(string name, string id, string staffId)
        : Person(name, id), staffId(staffId) {}

Staff::Staff(const Staff& other) : Person(other), staffId(other.staffId) {}

string Staff::getStaffId() const { return staffId; }
void Staff::setStaffId(const string& staffId) { this->staffId = staffId; }

ostream& operator<<(ostream& os, const Staff& staff) {
    os << "Staff [Name: " << staff.name << ", ID: " << staff.id << ", StaffID: " << staff.staffId << "]";
    return os;
}

istream& operator>>(istream& is, Staff& staff) {
    cout << "Enter name: ";
    is >> staff.name;
    cout << "Enter ID: ";
    is >> staff.id;
    cout << "Enter staff ID: ";
    is >> staff.staffId;
    return is;
}
