#include "employee.h"    

void setSalary(Employee& emp1);

int main ()
{

	Employee emp1;
	emp1.Print();
	Employee emp2("Unknown", 10, '?', 0);
	emp2.GetInfo();
	setSalary(emp2);
	emp2.Print();
}

//----------------------------------------------------------

void setSalary(Employee& emp1)
{
	if ((emp1.empPosition == 'E') && (emp1.yearOfExp < 2))
	{
		emp1.salary = 50000.00;
	}

	if ((emp1.empPosition == 'E') && (emp1.yearOfExp >= 2))
        {
                emp1.salary = 55000.00;
        }

	if ((emp1.empPosition == 'P') && (emp1.yearOfExp < 4))
        {
                emp1.salary = 60000.00;
        }

	if ((emp1.empPosition == 'P') && (emp1.yearOfExp >= 4))
        {
                emp1.salary = 65000.00;
        }

	if (emp1.empPosition == 'M')
        {
                emp1.salary = 70000.00;
        }

	if (emp1.empPosition == 'D')
        {
                emp1.salary = 80000.00;
        }

}
