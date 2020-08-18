#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include<vector>
#include<sstream>
#include "degree.h"
#include "student.h"
using namespace std;

class Roster
{
private:

	int studentDataSize;
	const string** stringRosterArray = new const string * [5];
	int rosterCounter = 0;


public:

	Roster();
	~Roster();

	// Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
	Student** classRosterArray = new Student * [5];
	void set_StringRosterArray(const string studentData[], int studentDataSize) const;

	int get_RosterSize();
	void set_RosterSize(int size);

	void add(string studentID, string firstName,
		string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2,
		int daysInCourse3, string degreeprogram);

	void remove(string studentID);

	void initializeStudents(int studentDataSize);

	void printAll();

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);

};
