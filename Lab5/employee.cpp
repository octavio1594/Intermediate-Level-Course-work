#include "employee.h"

int Employee::totalNumofEmployees = 0; 
int Employee::nextEmpId = 1000;
int Employee::nextOfficeNo = 10;

Employee::Employee():officeNo(nextOfficeNo), empId(nextEmpId)
{
	name = "Unknown";
	empPosition = 'E';
	deptNo = yearOfExp = 0;
	salary = 0.00;
	
	totalNumofEmployees++;
	nextEmpId++;
	nextOfficeNo++;
}

//--------------------------------------------------------------------------------

Employee::Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp):officeNo(nextOfficeNo), empId(nextEmpId)

{
	name = theName;
	deptNo = theDeptNo;
	empPosition = theEmpPosition;
	yearOfExp = theYearOfExp;
	
	totalNumofEmployees++;
        nextEmpId++;
        nextOfficeNo++;
}

//-----------------------------------------------------------------------------------

void Employee::Print() const
{
	cout << "Name of the employee: " << name << endl; 
	cout << "Office number of the employee: " << officeNo << endl;
 	cout << "ID of the employee: " << empId << endl;
 	cout << "Department number of the employee: " << deptNo << endl;
 	cout << "Position of the employee: " << empPosition << endl;
 	cout << "Years of experience of the employee: " << yearOfExp << endl;
 	cout << "The salary of the employee is: $" << salary << endl;
	cout << "The total number of employees is " << totalNumofEmployees << endl;
        cout << "The next office number is " << nextOfficeNo << endl;
        cout << "The next employee ID is " << nextEmpId << endl;
	cout << "----------------------------------------------------" << endl;
}

//------i-----------------------------------------------------------------------------------------------------------------

void Employee::GetInfo()
{
	cout << "Enter the name of the employee: ";
	getline(cin, name);
	cout << "Enter the position of the employee: ";
	cin >> empPosition;
	cout << "Enter years of experience of the employee: ";
	cin >> yearOfExp;
	cout << "----------------------------------------------------" << endl;

}

//---------------------------------------------------------------------------------------------------------------------
	
Employee::~Employee()
{
	totalNumofEmployees--;
        nextEmpId--;
        nextOfficeNo--;
}

//----------------------------------------------------------------------------------------------------------------------
