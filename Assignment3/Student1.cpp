#include "Student1.h"

long Student::nextStId = 500;

Student::Student():Person()
{
	id = nextStId++;
	yearOfStudy = advisorId = 00000;
	major = "SPACE";
}

Student::Student(string theName, string theEmail, string theAddress, string theDateOfBirth, string theGender, int theYearOfStudy, string theMajor, long theAdvisorId):Person(theName, theEmail, theAddress, theDateOfBirth, theGender)
{	
	id = nextStId++;
	yearOfStudy = theYearOfStudy;
	advisorId = theAdvisorId;
	major = theMajor;
}

void Student::Print()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
}


