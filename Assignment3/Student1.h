#ifndef STUDENT1_H
#define STUDENT1_H

#include <string>
#include <vector>
#include <iostream>
#include "Person1.h"
#include "Course1.h"
using namespace std;

class Student:public Person
{
	friend class University;

	protected:
		long		id;
		int		yearOfStudy;
		string		major;
		long		advisorId;
		vector<Course>	coursesTaken; 
		static long	nextStId;
	public:
		Student();
		Student(string theName, string theEmail, string theAddress, string theDateOfBirth, string theGender, int theYearOfStudy, string theMajor, long theAdvisorId);
		void Print();
};

#endif

