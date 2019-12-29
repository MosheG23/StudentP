// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include "Student.h"

// Initialize static num of student of class Student
int Student::numOfStudent = 1;

void FillReportCard(Student &student, int num) {
	for (int i = 1; i <= num; i++) {
		std::string lessonsName[] = { "Data Mining", "Databases", "Oprating Systems",
									"Introduction to Computer Science", "Machine Learning" };
		int grade = rand() % 50 + 50, year = rand() % 3 + 1, credit = rand() % 6 + 1;
		std::string lessonRand = lessonsName[rand() % 5];
		student.AddLesson(lessonRand, credit, grade, year);
	}
}

Student* FillStudent(int num) {
	Student *students = new Student[num];
	std::string fNames[] = { "Moshe", "Yuval", "Ariel", "Itay", "Tomer", "Sky" };
	std::string lNames[] = { "Gotam", "Ron", "Atas", "Glaser", "Burr", "Hart", "Rock" };
	std::string cities[] = { "Ashdod", "Modiin", "Holon", "Ramat Gan", "Akko" };
	for (int i = 0; i < num; i++) {
		std::string fNameRan = fNames[rand() % 6], lNameRan = lNames[rand() % 7],
			citiesRan = cities[rand() % 5], id = "123";
		//students[i](new Student());
		students[i].SetPersonID(std::string(id));
		students[i].SetStudentID(Student::GetNumOfStudent());
		students[i].SetFirstName(std::string(fNameRan));
		students[i].SetLastName(std::string(lNameRan));
		students[i].SetCity(citiesRan);
		students[i].SetYear(rand() % 3 + 1);
		students[i].SetStatus("Active");
		//students[i].SetReportCard(new ReportCard());
		Student::NewStudentAdded();
		FillReportCard(students[i], rand() % 5 + 3);
	}
	return students;
}

int main()
{
	std::cout << "Please enter the amount of students: " << endl;
	int numOfStudents, maxGrade = 0, maxIndex;
	cin >> numOfStudents;
	Student *clSt = FillStudent(numOfStudents);
	/*Person m("303029250", "Moshe", "Gotam", "Ashdod");
	Student moshe(m, "Active");
	Lesson dataMining("Data Mining", 4, 96, 1);
	moshe.AddLesson(dataMining);*/
	//Student m("123", "Moshe", "Gotam", "Ashdod", 1, new ReportCard());
	//m.SetFirstName("Moshe");
	//Lesson dataMining("Data Mining", 4, 96, 1);
	//m.AddLesson(dataMining);
	for (int i = 0; i < numOfStudents; i++) {
		clSt[i].PrintReport();
		if (clSt[i].GetAvgAll() > maxGrade) {
			maxGrade = clSt[i].GetAvgAll();
			maxIndex = i;
		}
	}
	std::cout << "The student with highest score is: " << clSt[maxIndex].GetFullName() << endl;
	std::cout << "With the score of " << maxGrade << endl;
	return 0;
}
