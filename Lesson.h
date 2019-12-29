#pragma once
#include <stdio.h>
#include <iostream>
#include <string>

class Lesson
{
private:
	std::string name;
	double credit;
	int grade;
	int year;
	int numOfTimesDone;
public:
	Lesson();
	Lesson(std::string, double, int, int);
	Lesson(Lesson&);

	std::string GetName();
	double GetCredit();
	int GetGrade();
	int GetYear();
	int GetNumOfTimesDone();

	void SetName(std::string);
	void SetCredit(double);
	void SetGrade(int);
	void SetYear(int);
	void AddNumOfTimesDone();
};

