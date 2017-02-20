#include "Course1.h"

long Course::nextCRN = 200;

Course::Course()
{
	CRN = nextCRN++;
	name = "SPACE";
	maxAvaliableSeats = departId = assignedSeats = isTaughtBy = 0;
}

Course::Course(string theName, long theDepartId, long taughtBy, int theMaxAvaliableSeats)
{
	CRN = nextCRN++;
	maxAvaliableSeats = theMaxAvaliableSeats;
	name = theName;
	departId = theDepartId;
	isTaughtBy = taughtBy;
}

void Course::Print()
{
        cout << "CRN: " << CRN << endl;
	cout << "Name: " << name << endl;
}

