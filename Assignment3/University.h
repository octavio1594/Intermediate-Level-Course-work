#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Department.h"
#include "Course1.h"
#include "Student1.h"
#include "Faculty.h"
using namespace std;

class University
{
	protected:
		vector<Department> Departments;
		vector<Student> Students;
		vector<Course> Courses;
		vector<Faculty> Faculties;
		static bool failure;
		static bool success;

	public:
		University();
		~University();
		bool CreateNewDepartment(string depName, string depLoc, long depChairId);
		bool FacultyExist(long FacId);
		bool CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, 
					string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
		bool DepartmentExist(string DepName);
		bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
		bool TaughtByExist(long cTaughtBy);
		bool DepIdExist(long DepId);
		bool CourExist(long courID);
		bool CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, 
					string fGender, float fSalary, int fYearOfExp, long fDepId);
		bool ListCoursesTaughtByFaculty(long facultyId);
		bool ListCoursesTakenByStudent(long studentId);
		bool stuExist(long stuId);
		bool ListFacultiesInDepartment(long departId);
		bool ListStudentsOfAFaculty(long facultyId);
		bool ListCoursesOfADepartment(long departId);
		bool AddACourseForAStudent(long courseId, long stId);
		bool AssignDepartmentChair(long facultyId, long departId);
		bool AssignInstructorToCourse(long facultyId, long courseId);
		bool ListDepartments();
		bool ListStudents();
		bool ListCourses();
		bool ListFaculties();
		bool ProcessTransactionFile(string fileName);
};

#endif
