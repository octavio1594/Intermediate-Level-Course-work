#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<string>
#include<iostream>
using namespace std;

class Employee
{
	friend void setSalary(Employee&);	

	private:
		string  	name;
		const long	officeNo;
		const long  	empId;
		int     	deptNo;
		char		empPosition; // .E.: entry level, .M.: manager, .D.: Director, .P.:Project_leader 
		int 		yearOfExp;
		float		salary;
		static  int 	totalNumofEmployees;
		static  int 	nextEmpId;
		static  int 	nextOfficeNo;

	public:
		Employee();
		~Employee();
		Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp);
		void Print() const ;
		void GetInfo();
};

#endif

