#ifndef LOCATION_H
#define LOCATION_H

#include <string>
using namespace std;


/*
    CLASS SUMMARY(The Idea behind each function) :
    
    The Location class stores information about a specific place in a system
    such as a transport map, hospital network, or delivery routing system

    WHAT THE CLASS STORES:
    id: To identify the location
    name: A string to describe location
    isHospital: A boolean which will indicate whether the location is a hospital

    EXPLANATION
   
    Constructors:
    Location(): Creates a default empty location
    Location(id, name, isHospital): Creates a fully initialized location

    Getters:
    getId(): Returns the location's ID
    getName(): Returns the location's name
    getIsHospital(): Returns true if it's a hospital

    Setters:
    setId(): Changes the location ID
    setName(): Changes the location name
    setIsHospital(): Marks the location as hospital or non-hospital

    Other Function:
    display(): Prints all details of the location
*/

class Location {
private:
    int id;
    string name;
    bool isHospital;

public:
    Location();
    Location(int id, string name, bool isHospital = false);
    
    int getId() const;
    string getName() const;
    bool getIsHospital() const;
    
    void setId(int id);
    void setName(string name);
    void setIsHospital(bool isHospital);
    
    void display() const;
};

#endif