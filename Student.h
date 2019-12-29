#pragma once
#include "Person.h"
#include "ReportCard.h"

class Student :
	public Person, public ReportCard
{
private:
	 int studentID;
	 int year;
	 std::string status;

public:
	 static int numOfStudent;
	 Student();
	 Student(Person);
	 Student(Person, int, ReportCard);
	 Student(std::string, std::string, std::string, std::string, int, ReportCard*);
	 /*Student(const Student &Student);*/

	 static int GetNumOfStudent() { return numOfStudent; }
	 static void NewStudentAdded() { numOfStudent++; }

	 int GetStudentID();
	 int GetYear();
	 std::string GetStatus();

	 ReportCard GetReportCard();
	 Person GetPerson();

	 void SetStudentID(int);
	 void SetYear(int);
	 void SetStatus(std::string);
	 void SetReportCard(ReportCard);

	 void PrintReport();
};

