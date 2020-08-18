#include "roster.h"
using namespace std;

#pragma region Constructor/Destructor
Roster::Roster()
{
	this->studentDataSize = 0;
	this->rosterCounter = 0;
}

Roster::~Roster()
{

}
#pragma endregion

#pragma region public methods



void Roster::set_StringRosterArray(const string studentData[], int studentDataSize) const
{
	for (size_t i = 0; i < studentDataSize; i++)
	{
		this->stringRosterArray[i] = &studentData[i];
	}


}

void Roster::add(string studentID, string firstName,
	string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, string degreeProgram)
{
	if (this->rosterCounter < this->studentDataSize)
	{
		// Assign new student to pointer upon creation
		Student* ptr = new Student(studentID, firstName, lastName,
			emailAddress, age, daysInCourse1,
			daysInCourse2, daysInCourse3, degreeProgram);

		// Add pointer to class roster and increment student counter
		this->classRosterArray[this->rosterCounter] = ptr;
		this->rosterCounter++;
	}
	else
	{
		int currentRoster = this->rosterCounter;
		this->rosterCounter++;

		Student** temp = new Student * [this->rosterCounter];

		// Assign new student to pointer upon creation
		Student* ptr = new Student(studentID, firstName, lastName,
			emailAddress, age, daysInCourse1,
			daysInCourse2, daysInCourse3, degreeProgram);

		temp[currentRoster] = ptr;

		for (size_t i = 0; i < currentRoster; i++)
		{
			temp[i] = this->classRosterArray[i];
		}

		this->classRosterArray = temp;

		for (size_t i = 0; i < this->rosterCounter; i++)
		{
			this->classRosterArray[i]->print();
		}

	}


}

void Roster::remove(string studentID)
{
	/*
	public void remove(string studentID)
	that removes students from the roster by student ID.
	If the student ID does not exist, the function prints an error
	message indicating that the student was not found.*/


	bool idIsValid = false;
	int studentIndex;
	int newDataSize = this->rosterCounter - 1;
	Student** temp = new Student * [newDataSize];
	string errMessage = "Student was not found!\n";

	for (size_t i = 0; i < this->rosterCounter; i++)
	{

		if (this->classRosterArray[i]->get_StudentID() == studentID)
		{
			idIsValid = true;
			studentIndex = i;
		}

		if (idIsValid)
		{
			if (i != studentIndex)
			{
				temp[i - 1] = this->classRosterArray[i];
			}
		}

		if (!idIsValid && (i != (studentDataSize - 1)))
		{
			temp[i] = this->classRosterArray[i];
		}

	}


	if (idIsValid)
	{
		this->rosterCounter--;
		this->classRosterArray = temp;
	}
	else
	{
		cout << errMessage;
	}
}

void Roster::initializeStudents(int studentDataSize)
{
	/*
	Create a student object for each student in the data table and populate classRosterArray.
		a.  Parse each set of data identified in the “studentData Table.”
		b.  Add each student object to classRosterArray.*/

	this->studentDataSize = studentDataSize;
	string invalidInputMessage = "Student Input was Invalid!";

	for (size_t i = 0; i < studentDataSize; i++)
	{
		string temp = *stringRosterArray[i];

		vector<string> csv_result;
		// create string stream
		stringstream temp_stream(temp);

		while (temp_stream.good())
		{
			string subString;
			// break string into sub strings
			//based on comma-delimited values
			getline(temp_stream, subString, ',');
			csv_result.push_back(subString);
		}

		try
		{
			string currentStudentID = csv_result[0];
			string currentStudentFirst = csv_result[1];
			string currentStudentLast = csv_result[2];
			string currentStudentEmail = csv_result[3];
			int currentStudentAge = stoi(csv_result[4]);
			int currentStudentDaysinCourse1 = stoi(csv_result[5]);
			int currentStudentDaysinCourse2 = stoi(csv_result[6]);
			int currentStudentDaysinCourse3 = stoi(csv_result[7]);
			string currentStudentProgram = csv_result[8];

			// Create new student object using comma-delimited values.
			// sets the instance variables from part D1 and updates the roster.
			add(currentStudentID, currentStudentFirst, currentStudentLast,
				currentStudentEmail, currentStudentAge, currentStudentDaysinCourse1,
				currentStudentDaysinCourse2, currentStudentDaysinCourse3, currentStudentProgram);

		}
		catch (const std::exception&)
		{
			cout << invalidInputMessage;
		}

	}
}

void Roster::printAll()
{
	/*
	prints a complete tab-separated list of student data in the provided format:
	A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
	The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.*/

	string errMessage = "No students were found in roster.";

	if (classRosterArray != nullptr)
	{
		for (size_t i = 0; i < this->rosterCounter; i++)
		{
			this->classRosterArray[i]->print();
		}
	}
	else
	{
		cout << errMessage;
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	/*
	Correctly prints a student’s average number of days in the three courses.
	The student is identified by the studentID parameter.*/

	int totalCourses = 3;
	double averageDays;
	bool idIsValid = false;
	string errMessage = "Student was not found!\n";
	string outputMessage = "Average days in courses: ";

	for (size_t i = 0; i < this->rosterCounter; i++)
	{
		if (this->classRosterArray[i]->get_StudentID() == studentID)
		{
			idIsValid = true;

			int* days = this->classRosterArray[i]->get_DaysInCourse();

			int daysInCourseOne = days[0];
			int daysInCourseTwo = days[1];
			int daysInCourseThree = days[2];

			averageDays = ((daysInCourseOne + daysInCourseTwo + daysInCourseThree) / 3);
		}
	}

	if (idIsValid)
	{
		cout << outputMessage << averageDays;
	}
	else
	{
		cout << errMessage;
	}
}

void Roster::printInvalidEmails()
{
	// verifies student email addresses and displays all invalid email addresses to the user.
	//Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').

	vector<string> invalidEmails;
	bool invalidMissingAt = false;
	bool invalidMissingPeriod = false;
	bool invalidHasSpace = false;
	bool hasBeenAdded = false;
	string invalidMessage = "\nThe following emails were invalid: ";
	string validMessage = "\nAll student emails were valid!";

	for (size_t i = 0; i < this->rosterCounter; i++)
	{
		vector<string> atResults;
		vector<string> periodResults;
		vector<string> spaceResults;

		string studentEmail = this->classRosterArray[i]->get_EmailAddress();

		stringstream temp_stream(studentEmail);

		while (temp_stream.good())
		{
			string subString;
			getline(temp_stream, subString, '@');
			atResults.push_back(subString);
		}

		if (atResults.size() == 1)
		{
			invalidMissingAt = true;
			invalidEmails.push_back(studentEmail);
			hasBeenAdded = true;
		}

		stringstream temp_stream2(studentEmail);

		while (temp_stream2.good())
		{
			string subString;
			getline(temp_stream2, subString, '.');
			periodResults.push_back(subString);
		}

		if (periodResults.size() == 1 && hasBeenAdded == false)
		{
			invalidMissingPeriod = true;
			invalidEmails.push_back(studentEmail);
			hasBeenAdded = true;
		}

		stringstream temp_stream3(studentEmail);

		while (temp_stream3.good())
		{
			string subString;
			getline(temp_stream3, subString, ' ');
			spaceResults.push_back(studentEmail);
		}

		if (spaceResults.size() > 1 && hasBeenAdded == false)
		{
			invalidHasSpace = true;
			invalidEmails.push_back(studentEmail);
			hasBeenAdded = true;
		}

		hasBeenAdded = false;
	}

	if (invalidMissingAt || invalidMissingPeriod || invalidHasSpace)
	{
		cout << invalidMessage;

		for (size_t i = 0; i < invalidEmails.size(); i++)
		{
			cout << "\n" << invalidEmails[i];
		}

		cout << "\n";
	}
	else
	{
		cout << validMessage << "\n";
	}
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (size_t i = 0; i < this->rosterCounter; i++)
	{
		if (this->classRosterArray[i]->get_StudentDegreeProgram() == degreeProgram)
		{
			cout << "\n";
			this->classRosterArray[i]->print();
			cout << "\n";
		}
	}


}

#pragma endregion
