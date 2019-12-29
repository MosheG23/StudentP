#include "Lesson.h"


Lesson::Lesson() {	
}

Lesson::Lesson(std::string name, double credit, int grade, int year) {
	SetName(name);
	SetCredit(credit);
	SetGrade(grade);
	SetYear(year);
	numOfTimesDone = 1;
	std::cout << this->name << " was created!" << std::endl;
}

Lesson::Lesson(Lesson &lesson) {
	SetName(lesson.GetName());
	SetCredit(lesson.GetCredit());
	SetGrade(lesson.GetGrade());
	SetYear(lesson.GetYear());
}

std::string Lesson::GetName() {	return this->name; }

double Lesson::GetCredit() { return this->credit; }

int Lesson::GetGrade() { return this->grade; }

int Lesson::GetYear() {	return this->year; }

int Lesson::GetNumOfTimesDone() { return this->numOfTimesDone++; }

void Lesson::SetName(std::string name) {
	this->name = name;
}

void Lesson::SetCredit(double credit) {
	this->credit = credit;
}

void Lesson::SetGrade(int grade) {
	while (grade < 0 || grade > 100)
	{
		std::cout << "Please enter a valid grade: ";
		std::cin >> grade;
	}
	this->grade = grade;
}

void Lesson::SetYear(int year) {
	while (year < 1 || year > 3) {
		std::cout << "Please enter a valid year: ";
		std::cin >> year;
	}
	this->year = year;
}

void Lesson::AddNumOfTimesDone() {
	this->numOfTimesDone++;
}
