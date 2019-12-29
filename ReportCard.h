#pragma once
#include <string>
using namespace std;
#include "Lesson.h"

class ReportCard
{
	static const int MAXLESSONS = 20;
private:
	int numOfLessons = 0;
	Lesson* lessonArr;

public:
	ReportCard();
	ReportCard(int, Lesson*);
	ReportCard(ReportCard*);

	int GetNumOfLessons();
	Lesson* GetLessonsArr();

	void AddLesson(std::string, double, int, int);
	void AddLesson(Lesson);
	double GetAvgByYear(int);
	double GetAvgAll();

	int GetNumOfFails();

	void SetNumOfLessons(int);
	void SetLessonsArr(Lesson*);

	void PrintReportCard();
	std::string toString();
	friend std::ostream& operator<<(std::ostream&, const ReportCard&);
};

