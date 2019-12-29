#include "ReportCard.h"


//string name;
//double credit;
//int grade;
//int year;

ReportCard::ReportCard() {
	this->lessonArr = new Lesson[MAXLESSONS];
}

ReportCard::ReportCard(int numOfLessons, Lesson* lessonArr) {
	this->numOfLessons;
	this->lessonArr = lessonArr;
}

ReportCard::ReportCard(ReportCard *reportCard) {
	this->lessonArr = reportCard->GetLessonsArr();
	this->numOfLessons = reportCard->GetNumOfLessons();
}

int ReportCard::GetNumOfLessons() { return this->numOfLessons; }

Lesson* ReportCard::GetLessonsArr() { return this->lessonArr; }

void ReportCard::AddLesson(string name, double credit, int grade, int year) {
	Lesson newLesson(name, credit, grade, year);
	if (numOfLessons < MAXLESSONS) {
		int flag = 1, i;
		for (i = 0; i < this->numOfLessons && flag == 1; i++) {
			if (this->lessonArr[i].GetName() == newLesson.GetName())
				flag = 0;
		}
		if (flag == 1) {
			this->lessonArr[numOfLessons++] = newLesson;
			std::cout << newLesson.GetName() << " was added (no." << numOfLessons
				<< ") with grade: " << newLesson.GetGrade() << endl;
		}
		else {
			std::cout << "The lesson is already been done, it's now updated to " << grade << endl;
			this->lessonArr[i--].AddNumOfTimesDone();
			this->lessonArr[i--].SetGrade(grade);
		}
	}
	else
	{
		cout << "You reached your lessons max, sorry.";
	}
}

void ReportCard::AddLesson(Lesson lesson) {
	if (numOfLessons < MAXLESSONS) {
		int flag = 1;
		for (int i = 0; i < this->numOfLessons && flag == 1; i++) {
			if (this->lessonArr[i].GetName()._Equal(lesson.GetName()))
				flag = 0;
		}
		if (flag = 1) {
			this->lessonArr[numOfLessons++] = lesson;
			std::cout << lesson.GetName() << " was added (no." << numOfLessons
				<< ") with grade: " << lesson.GetGrade() << endl;
		}
		else {
			std::cout << "The lesson is already been done" << endl;
		}
	}
	else
	{
		cout << "You reached your lessons max, sorry.";
	}
}

double ReportCard::GetAvgByYear(int year) {
	double count = 0, sum = 0;
	for (int i = 0; i < numOfLessons; i++) {
		if (lessonArr[i].GetYear() == year) {
			sum += lessonArr[i].GetGrade() * lessonArr[i].GetCredit();
			count += lessonArr[i].GetCredit();
		}
	}
	if (count != 0)
		return sum / count;
	return -1;
}
double ReportCard::GetAvgAll() {
	double count = 0, sum = 0;
	for (int i = 0; i < numOfLessons; i++) {
		sum += lessonArr[i].GetGrade() * lessonArr[i].GetCredit();
		count += lessonArr[i].GetCredit();
	}
	if (count != 0)
		return sum / count;
	return -1;
}

int ReportCard::GetNumOfFails() {
	int numOfFails = 0;
	for (int i = 0; i < this->numOfLessons; i++) {
		if (this->lessonArr[i].GetGrade() < 60)
			numOfFails++;
	}
	return numOfFails;
}

void ReportCard::SetNumOfLessons(int numOfLessons) { this->numOfLessons = numOfLessons; }
void ReportCard::SetLessonsArr(Lesson *lessonsArr) { this->lessonArr = lessonsArr; }

void ReportCard::PrintReportCard() {
	std::cout << "Report Card:" << endl;
	std::cout << "*********************" << endl;
	std::cout << "Number of fails:" << this->GetNumOfFails() << endl;
	std::cout << "Lessons passed:" << endl;
	int count = 0;
	for (int i = 0; i < this->numOfLessons; i++) {
		if (lessonArr[i].GetGrade() > 60)
			std::cout << ++count << ". " << lessonArr[i].GetName() << "(" << lessonArr[i].GetGrade() 
						<< ")" << endl;
	}
}

std::string ReportCard::toString() {
	std::string output = "Report Card:\n";
	output += "**********************\n";
	output += "Number of fails: " + this->GetNumOfFails();
	output += "\nLessons passed:";
	int count = 0;
	double creditPass = 0;
	for (int i = 0; i < this->numOfLessons; i++) {
		if (lessonArr[i].GetGrade() > 60) {
			creditPass += lessonArr[i].GetCredit();
			output += ++count + ". " + lessonArr[i].GetName() + "("; 
			output += lessonArr[i].GetGrade() + ")\n";
		}
	}
	output += "Total credit: "; 
	output += creditPass;
	return output;
}

//std::ostream& operator<<(std::ostream &strm, const ReportCard *rc) {
//	return strm << rc->toString();
//}