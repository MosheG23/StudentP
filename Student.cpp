#include "Student.h"

//Defualt Constructors
Student::Student():Person(), ReportCard() {
	
}

//Constructors for a student without report card
Student::Student(Person person) 
	:Person(person), ReportCard() {
	this->studentID = (this->numOfStudent++);
	this->year = 1;
	this->status = status;
}

//Constructors for a student with report card
Student::Student(Person person, int year, ReportCard reportCard)
	: Person(person), ReportCard(reportCard) {
	this->studentID = (this->numOfStudent++);
	this->year = year;
	this->status = status;
	cout << this->GetFullName() << " was added." << endl;
}

//Constructors for a student with new person and report card
Student::Student(std::string personID, std::string firstName, std::string lastName, std::string city,
	int year, ReportCard *reportCard)
	: Person(personID, firstName, lastName, city), ReportCard(reportCard) {
	this->studentID = (this->numOfStudent++);
	this->year = year;
	this->status = "Active";
	cout << this->GetFullName() << " was added." << endl;
}

//Student::Student(const Student &student) : Person(student->GetPerson()), ReportCard(student->GetReportCard()) {
//	this->year = student.GetYear();
//	this->status = student
//}

//Getters
int Student::GetStudentID() { return this->studentID; }
int Student::GetYear() { return this->year; }

ReportCard Student::GetReportCard() {
	ReportCard rc(this->GetNumOfLessons(), this->GetLessonsArr());
	return rc;
}

//Person Student::GetPerson() {
//	Person person(this->GetPersonID(), this->GetFirstName, this->GetLastName, this->GetCity);
//	return person;
//}

std::string Student::GetStatus() { 
	if (this->GetNumOfFails() > 2)
		return ("Active (Too much fails, " + this->GetNumOfFails());
	return "Active";
}

//Setters
void Student::SetStudentID(int studentID) { this->studentID = studentID; }
void Student::SetYear(int year) { this->year = year; }
void Student::SetStatus(std::string status) { this->status = status; }
void Student::SetReportCard(ReportCard rc) {
	this->SetNumOfLessons(rc.GetNumOfLessons());
	this->SetLessonsArr(rc.GetLessonsArr());
}

//Get student report
void Student::PrintReport() {
	std::cout << this->GetFullName() << "(" << this->GetStudentID() << ")" << endl;
	std::cout << "***********************" << endl;
	std::cout << "Year: " << this->GetYear() << endl;
	std::cout << "Status: " << this->GetStatus() << endl;
	std::cout << "Grade avarage: " << this->GetAvgAll() << endl;
	std::cout << "***********************" << endl;
	this->PrintReportCard();
	std::cout << "\n" << endl;
}