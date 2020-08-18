#include "student.h"
using namespace std;

#pragma region Constructor/Destructor


Student::Student(string studentID, string firstName, string lastName,
	string emailAddress, int age, int daysInCourse1,
	int daysInCourse2, int daysInCourse3, string degreeProgram)
{ // Use accessors and mutators (getters and setters) to work with class attributes
	set_StudentID(studentID);
	set_FirstName(firstName);
	set_LastName(lastName);
	set_EmailAddress(emailAddress);
	set_Age(age);
	set_DaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);
	set_StudentDegreeProgram(degreeProgram);
}

Student::~Student()
{
}
#pragma endregion

#pragma region public accessors and mutators (getters and setters)

string Student::get_StudentID()
{
	return studentID;
}

void Student::set_StudentID(string studentID)
{
	this->studentID = studentID;
}

string Student::get_FirstName()
{
	return firstName;
}

void Student::set_FirstName(string firstName)
{
	this->firstName = firstName;
}

string Student::get_LastName()
{
	return lastName;
}

void Student::set_LastName(string lastName)
{
	this->lastName = lastName;
}

string Student::get_EmailAddress()
{
	return emailAddress;
}

void Student::set_EmailAddress(string email)
{
	this->emailAddress = email;
}

int Student::get_Age()
{
	return age;
}

void Student::set_Age(int age)
{
	this->age = age;
}

int* Student::get_DaysInCourse()
{
	return daysInCourse;
}

void Student::set_DaysInCourse(int daysInCourse1, int daysInCourse2,
	int daysInCourse3)
{
	const string errorMessage = "Days in course was invalid.";
	// Error message if a problem occurs with days in course

	try
	{
		set_DaysInCourse1(daysInCourse1);
		set_DaysInCourse2(daysInCourse2);
		set_DaysInCourse3(daysInCourse3);

		this->daysInCourse[0] = this->daysInCourse1;
		this->daysInCourse[1] = this->daysInCourse2;
		this->daysInCourse[2] = this->daysInCourse3;
	}
	catch (const std::exception&)
	{
		cout << errorMessage;
	}
}

DegreeProgram Student::get_StudentDegreeProgram()
{
	return studentDegreeProgram;
}

void Student::set_StudentDegreeProgram(string studentDegreeProgram)
{
	// Convert string characters to lowercase to make our comparison easier
	transform(studentDegreeProgram.begin(), studentDegreeProgram.end(),
		studentDegreeProgram.begin(), ::tolower);

	// Comparison strings we will use to determine the student's degree program
	string security = "security";
	string network = "network";
	string software = "software";

	// Error message we will throw if degree type is invalid
	const string errorMessage = "Student degree program was invalid.";


	if (studentDegreeProgram == security)
	{
		this->studentDegreeProgram = DegreeProgram::SECURITY;
	}
	else if (studentDegreeProgram == network)
	{
		this->studentDegreeProgram = DegreeProgram::NETWORK;
	}
	else if (studentDegreeProgram == software)
	{
		this->studentDegreeProgram = DegreeProgram::SOFTWARE;
	}
	else
	{
		cout << errorMessage;
	}
}

#pragma endregion

void Student::print()
{
	string degreeProgramString;
	switch (this->studentDegreeProgram)
	{
	case SECURITY:
		degreeProgramString = "Security";
		break;
	case NETWORK:
		degreeProgramString = "Network";
		break;
	case SOFTWARE:
		degreeProgramString = "Software";
		break;
	}

	string studentMessage = this->studentID + "\t" +
		"First Name: " + this->firstName + "\t" +
		"Last Name: " + this->lastName + "\t" +
		"Age: " + to_string(this->age) + "\t" +
		"daysInCourse: {" +
		to_string(this->daysInCourse[0]) + ", " +
		to_string(this->daysInCourse[1]) + ", " +
		to_string(this->daysInCourse[2]) + "} " +
		"Degree Program: " + degreeProgramString + ".\n";

	cout << studentMessage;
}

#pragma region private accessors and mutators (getters and setters)

int Student::get_DaysInCourse1()
{
	return daysInCourse1;
}

void Student::set_DaysInCourse1(int daysInCourse1)
{
	this->daysInCourse1 = daysInCourse1;
}

int Student::get_DaysInCourse2()
{
	return daysInCourse2;
}

void Student::set_DaysInCourse2(int daysInCourse2)
{
	this->daysInCourse2 = daysInCourse2;
}

int Student::get_DaysInCourse3()
{
	return daysInCourse3;
}

void Student::set_DaysInCourse3(int daysInCourse3)
{
	this->daysInCourse3 = daysInCourse3;
}

#pragma endregion
