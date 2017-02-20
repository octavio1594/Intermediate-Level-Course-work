#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Department
{
	friend class University;
	
	protected:
		long		id;
		string		name;
		string		location;
		long		chairId;
		static long	nextDepartId;
	public:
		Department();
		Department(string theName, string theLocation, long theChairId);
		void Print();
};

#endif



