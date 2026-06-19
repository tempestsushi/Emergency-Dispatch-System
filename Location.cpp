#include "Location.h"
#include <iostream>
using namespace std;


// FOR EXPLANATION OF THIS CLASS  PLEASE REFER TO HEADER FILE

Location::Location() : id(0), name(""), isHospital(false) {}

Location::Location(int id, string name, bool isHospital) 
    : id(id), name(name), isHospital(isHospital) {}

int Location::getId() const {
    return id;
}

string Location::getName() const {
    return name;
}

bool Location::getIsHospital() const {
    return isHospital;
}

void Location::setId(int id) {
    this->id = id;
}

void Location::setName(string name) {
    this->name = name;
}

void Location::setIsHospital(bool isHospital) {
    this->isHospital = isHospital;
}

void Location::display() const {
    cout << "Location " << id << ": " << name;
    if (isHospital) {
        cout << " [HOSPITAL]";
    }
    cout << endl;
}