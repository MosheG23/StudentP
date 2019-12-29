#pragma once
#include <string>
#include <stdio.h>


class Person
{
private:
	std::string personID;
	std::string firstName;
	std::string lastName;
	std::string city;
public:
	Person();
	Person(std::string, std::string, std::string, std::string);
	
	std::string GetPersonID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetCity();
	std::string GetFullName();

	void SetPersonID(std::string);
	void SetFirstName(std::string);
	void SetLastName(std::string);
	void SetCity(std::string);
};

