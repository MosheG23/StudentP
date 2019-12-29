#include "Person.h"

Person::Person() {
	personID = "";
	firstName = "";
	lastName = "";
	city = "";
}

Person::Person(std::string personId, std::string lastName, std::string firstName, std::string city) {
	this->personID = personId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->city = city;
}

std::string Person::GetPersonID() { return this->personID; }
std::string Person::GetFirstName() { return this->firstName; }
std::string Person::GetLastName() { return this->lastName; }
std::string Person::GetCity() { return this->city; }

std::string Person::GetFullName() {
	std::string fullName = this->firstName + " " + this->lastName;
	return fullName;
}

void Person::SetPersonID(std::string personID) { this->personID = personID; }
void Person::SetFirstName(std::string fName) { this->firstName = fName; }
void Person::SetLastName(std::string lName) { this->lastName = lName; }
void Person::SetCity(std::string city) { this->city = city; }

