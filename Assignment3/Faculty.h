#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <vector>
#include <iostream>
#include "Person1.h"
using namespace std;

class Faculty:public Person
{
	friend class University;

	protected:
		long		id;
		float		salary;
		int		yearOfExp;
		long		deparId;
		static long	nextFacultyId;
	public:
		Faculty();
		Faculty(string theName, string theEmail, string theAddress, string theDateOfBirth, string theGender, float 			theSalary, int theYearOfExp, long theDeparId);
		void Print();
};

#endif
