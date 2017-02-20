#include "Department.h"

long Department::nextDepartId = 100;

Department::Department()
{
	id = nextDepartId++;
	name = location = "SPACE";
	chairId = 0;
}

Department::Department(string theName, string theLocation, long theChairId)
{
	id = nextDepartId++;
        name = theName;
	location = theLocation;
        chairId = theChairId;
} 

void Department::Print()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
}
