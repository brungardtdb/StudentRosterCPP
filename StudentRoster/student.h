#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include "degree.h"
using namespace std;

class Student
{

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;

	DegreeProgram studentDegreeProgram;

	int get_DaysInCourse1();

	void set_DaysInCourse1(int daysInCourse1);

	int get_DaysInCourse2();

	void set_DaysInCourse2(int daysInCourse2);

	int get_DaysInCourse3();

	void set_DaysInCourse3(int daysInCourse3);

public:

	Student(string studentID, string firstName, string lastName,
		string emailAddress, int age, int daysInCourse1,
		int daysInCourse2, int daysInCourse3, string degreeProgram);
	~Student();

	int daysInCourse[3];
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;

	string get_StudentID();

	void set_StudentID(string studentID);

	string get_FirstName();

	void set_FirstName(string firstName);

	string get_LastName();

	void set_LastName(string lastName);

	string get_EmailAddress();

	void set_EmailAddress(string email);

	int get_Age();

	void set_Age(int age);

	int* get_DaysInCourse();

	void set_DaysInCourse(int daysInCourse1, int daysInCourse2,
		int daysInCourse3);

	DegreeProgram get_StudentDegreeProgram();

	void set_StudentDegreeProgram(string studentDegreeProgram);

	void print();

};
