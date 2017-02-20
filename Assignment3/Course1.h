#ifndef COURSE1_H
#define COURSE1_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Course
{
	friend class University;

	protected:
		long 		CRN;
		int		maxAvaliableSeats;
		string		name;
		long		departId;
		long		assignedSeats;
		long		isTaughtBy;
		static long	nextCRN;
	public:
		Course();
		Course(string theName, long theDepartId, long taughtBy, int theMaxAvaliableSeats);
		void Print();
};

#endif


