
#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;

int main()
{
    const string studentData[] = { "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,David,Brungardt,dbStudent@wgu.edu,28, 10,14,21,SOFTWARE" };

    try
    {
        const int studentDataSize = sizeof(studentData) / sizeof(studentData[0]);
        Roster classRoster = Roster();
        classRoster.set_StringRosterArray(studentData, studentDataSize);
        classRoster.initializeStudents(studentDataSize);

        cout << "\nPrinting all students.\n";
        classRoster.printAll();

        cout << "\nPrinting average days in course.\n";
        for (size_t i = 0; i < studentDataSize; i++)
        {
            string var = studentData[i];
            string studentID = var.substr(0, 2);

            cout << "\n" << studentID << " Average: ";
            classRoster.printAverageDaysInCourse(studentID);
        }

        cout << "\n";
        cout << "\nPrinting by degree program (SOFTWARE).\n";
        classRoster.printByDegreeProgram(SOFTWARE);

        cout << "\nPrinting invalid emails.\n";
        classRoster.printInvalidEmails();

        cout << "\nAttempting to remove student A3.\n";
        classRoster.remove("A3");

        cout << "\nPrinting all students.\n";
        classRoster.printAll();

        cout << "\nAttempting to remove student A3 again.\n";
        classRoster.remove("A3");

    }
    catch (const std::exception&)
    {
        string errString = "\nSomething went wrong!\n";

        cout << errString;
    }

    return 0;
}
