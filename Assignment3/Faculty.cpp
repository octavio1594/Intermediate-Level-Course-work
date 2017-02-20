#include "Faculty.h"

long Faculty::nextFacultyId = 600;

Faculty::Faculty():Person()
{
	id = nextFacultyId++;
	salary = yearOfExp = deparId = 0;
}

Faculty::Faculty(string theName, string theEmail, string theAddress, string theDateOfBirth, string theGender, float theSalary, int theYearOfExp, long theDeparId):Person(theName, theEmail, theAddress, theDateOfBirth, theGender)
{
	id = nextFacultyId++;
	salary = theSalary;
	yearOfExp = theYearOfExp;
	deparId = theDeparId;
}

void Faculty::Print()
{
	cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
}
