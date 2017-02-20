#include "University.h"

bool University::failure = false;
bool University::success = true;

University::University()
{

}

//----------------------------------------------------------------------------

University::~University()
{

}

//----------------------------------------------------------------------------

/*
	- This rutine checks if the depChairId is 0, it also checks if the depChairId passed to this
	 method is a valid existing faculty.
	  It also prints appropriate message and return failures if the chair is not valid
	  

	- Finally it creates an object of department that calls appropriate constructor to assign
	  these values
	- the value of id is assigned to the value of nextDepartId
	- it increments the value of nextDepartId by 1 in the constructor
	- it inserts the new object to the Departments vector
*/
bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{
	if ((depChairId != 0) && (!FacultyExist(depChairId)))
	{
		cout << "The chair with id: " << depChairId << " does not exist" << endl << endl;
		return failure;
	}

	Department D(depName, depLoc, depChairId);
	
	Departments.push_back(D);
	
	return success;
}

/* This rutine checks the vector of Faculties for an object matching the passed id*/
bool University::FacultyExist(long FacId)
{
	for (int i = 0; i < Faculties.size(); i++)	
	{
		if (Faculties[i].id == FacId)
			return success;
	}
	
	return failure;
}

//----------------------------------------------------------------------------

/*
	- This rutine checks if the sMajor is 0, i also  checks if the sMajor passed to this method is a
	 valid existing department name.
	  it prints appropriate message and return failure if this is not the case

 	- This rutine checks if the sAdvisorId is 0, it also checks if the sAdvisorId passed to this method 
	  is a valid existing faculty id. It Prints appropriate message and return failure if this is not the case

	- it creates an object of student that calls appropriate constructor to assign
	  these values
	- value of id is  assigned to the value of nextSttId
	- itincrements the value of nextStId by 1 in the constructor
	- it inserts the new object to the Students vector
*/
bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender,int sYearOfStudy, string sMajor, long sAdvisorId)
{
	if ((sMajor != "0") && (!DepartmentExist(sMajor)))
        {
                cout << "The major: " << sMajor << " does not exist" << endl << endl;
                return failure;
        }
	
	else  if ((sAdvisorId != 0) && (!FacultyExist(sAdvisorId)))
        {
                cout << "The student advisor id: " << sAdvisorId << " does not exist" << endl << endl;
                return failure;
        }

	Student S(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId);

	Students.push_back(S);

	return success;
}

/* This rutine checks the vector of Departments for an object matching the passed department name*/
bool University::DepartmentExist(string DepName)
{      for (int i = 0; i < Departments.size(); i++)
        {
                if (Departments[i].name == DepName)
                        return success;
        }

        return failure;
}

//----------------------------------------------------------------------------

/*
	- This rutine checks if the cTaughtBy is 0, it also checks if the cTaughtBy passed to this
	method is a valid existing faculty. It prints appropriate message and return failure if 
	this is not the case

    	-  This rutine checks if the cDepId passed to this method is a valid existing department. 
	  It prints appropriate message and return failure if this is not the case

	- It creates an object of Course that calls appropriate constructor to assign these values
	- the value of assigned seats is  assigned to zero in the constructor
	- the value of CRN is  assigned to the value of nextCRN
	- It increments the value of nextCRN by 1 in the constructor
	- It inserts the new object to the Courses vector
*/
bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
	if ((cTaughtBy != 0) && (! FacultyExist(cTaughtBy)))
        {
                cout << "The faculty id: " << cTaughtBy << " does not exist" << endl << endl;
                return failure;
        }

        else  if (! DepIdExist(cDepId))
        {
                cout << "The department id: " << cDepId << " does not exist" << endl << endl;
                return failure;
        }

        Course C(cName, cDepId, cTaughtBy, cMaxSeat);

        Courses.push_back(C);

        return success;

}

/* This rutine checks the vector of Departments for an object matching the passed id*/
bool University::DepIdExist(long DepId)
{
        for (int i = 0; i < Departments.size(); i++)
        {
                if (Departments[i].id == DepId)
                        return success;
        }

        return failure;
}

//----------------------------------------------------------------------------

/*
    	- This rutine checks if the fDeptId passed to this method is a valid existing department. 
	  It prints appropriate message and return failure if this is not the case

	- It creates an object of Faculty that calls appropriate constructor to assign these values
	- the value of faculty is assigned to the value of nextFacultyId
	- It increments the value of nextFacultyId by 1 in the constructor
	- It inserts the new object to the Faculties vector
*/
bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,float fSalary, int fYearOfExp, long fDepId)
{
	if (!DepIdExist(fDepId))
        {
                cout << "The department id: " << fDepId << " does not exist" << endl << endl;
                return failure;
        }

        Faculty F(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId);

        Faculties.push_back(F);

        return success;
}

//----------------------------------------------------------------------------

/*
	- This routine lists all the courses (courseId and CourseName)
	  that are currently being taught by a particular faculty 
	- It makes sure that the facultyId passed to this method is a valid existing 
	  faculty id. If this is not the case it prints appropriate message and returns failure; 
	  otherwise, returns success

*/
bool University::ListCoursesTaughtByFaculty(long facultyId)
{
	if (!FacultyExist(facultyId))
	{
		cout << "The faculty id: " << facultyId << " does not exist" << endl << endl;
                return failure;
	}
	
	cout << "COURSES TAUGHT BY FACULTY WITH ID: " << facultyId << endl;

	for(int i = 0; i < Courses.size(); i++)
        {
		if (Courses[i].isTaughtBy == facultyId)
		        Courses[i].Print();
			cout << endl;
	}

	return success;

}



//----------------------------------------------------------------------------

/*
	- This routine lists all the courses (courseId and CourseName) 
	  that currently taken by a particular student
	- it makes sure that the studentId passed to this method is a valid existing 
	  student id. If this is not the case it prints appropriate message and returns failure; 
	otherwise, returns success

*/
bool University::ListCoursesTakenByStudent(long studentId)
{
	if (!stuExist(studentId))
        {
                cout << "The student id: " << studentId << " does not exist" << endl << endl;
                return failure;
        }

        cout << "COURSES TAKEN BY STUDENT WITH ID: " << studentId << endl;

	for(int i = 0; i < Students.size(); i++)
        {
                if (Students[i].id == studentId)
		{
			for (int j = 0; j < Courses.size(); j++)
                        {
				Students[i].coursesTaken[j].Print();
				cout << endl;
			}
		}
        }

	return success;

}

/* This rutine checks the vector of Students for an object matching the passed id*/
bool University::stuExist(long stuId)
{
	for (int i = 0; i < Students.size(); i++)
        {
                if (Students[i].id == stuId)
                        return success;
        }

        return failure;
}

/* This rutine checks the vector of Courses for an object matching the passed id*/
bool University::CourExist(long courID)
{
        for (int i = 0; i < Courses.size(); i++)
        {
                if (Courses[i].CRN == courID)
                        return success;
        }

        return failure;
}

//----------------------------------------------------------------------------

/*
	- This routine lists all the faculties (facultyId, facultyName) in a particular 
	  department
	- it makes sure that the departId passed to this method is a valid existing 
	  department id. If this is not the case it prints appropriate message and returns failure; 
	  otherwise, returns success

*/
bool University::ListFacultiesInDepartment (long departId)
{
	if (!DepIdExist(departId))
        {
                cout << "The department id: " << departId << " does not exist" << endl << endl;
                return failure;
        }
	
	cout << "FACULTIES OF DEPARTMENT WITH ID: " << departId << endl;
	
	for(int i = 0; i < Faculties.size(); i++)
        {
                if (Faculties[i].deparId == departId)
                        Faculties[i].Print();
			cout << endl;
        }

	return success;
}

//----------------------------------------------------------------------------

/*
	- This routine lists all the students (studentId and studentName) of a particular 
	  faculty
	- it makes sure that the facultyId passed to this method is a valid existing 
	  faculty id. If this is not the case it prints appropriate message and returns failure; otherwise, 
	  returns success
	  
*/
bool University::ListStudentsOfAFaculty(long facultyId)
{
	if (!FacultyExist(facultyId))
        {
                cout << "The faculty id: " << facultyId << " does not exist" << endl << endl;
                return failure;
        }

	cout << "STUDENTS OF FACULTY WITH ID: " << facultyId << endl;

	for(int i = 0; i < Students.size(); i++)
        {
                if (Students[i].advisorId == facultyId)
                        Students[i].Print();
			 cout << endl;
        }

        return success;
}

//----------------------------------------------------------------------------

/*
	- This routine lists all the courses offered by a particular department
	- it makes sure that the departId passed to this method is a valid existing 
	  department id. If this is not the case it prints appropriate message and returns failure; otherwise, 
	  returns success
*/
bool University::ListCoursesOfADepartment(long deparId)
{
	if (!DepIdExist(deparId))
        {
                cout << "The department id: " << deparId << " does not exist" << endl << endl;
                return failure;
        }
	
	cout << "COURSES OF DEPARTMENT WITH ID: " << deparId << endl;

	for(int i = 0; i < Courses.size(); i++)
        {
                if (Courses[i].departId == deparId)
                        Courses[i].Print();
			cout << endl;
        }

        return success;
}

//----------------------------------------------------------------------------

/*
	- This routine adds a course for a student
	- When it adds a course for a student, it ensures that there is enough seats in that class
	  it also Increments the number of assigned seats if the student was able to enrrolfor this course
	- it makes sure that the courseId and stId passed to this method are both valid 
	  If this is not the case it prints appropriate message and returns failure; otherwise, 
	  returns success
*/
bool University::AddACourseForAStudent(long courseId, long stId)
{
	if (!stuExist(stId))
        {
                cout << "The student id: " << stId << " does not exist" << endl << endl;
                return failure;
        }

	if(!CourExist(courseId))
        {
                cout << "The course id: " << courseId << " does not exist" << endl << endl;
                return failure;
        }

	for(int i = 0; i < Students.size(); i++)
	{
		if (Students[i].id == stId)
		{
			if (Courses[i].maxAvaliableSeats == Courses[i].assignedSeats)
			{
				return failure;
				cout << "Course with number: " << courseId << " is full" << endl << endl;
			}

			for(int j = 1; j < Courses.size(); j++)
        		{
                		if (Courses[j].CRN == courseId)
                		{
                        		Students[i].coursesTaken.push_back(Courses[j]);
					Courses[j].assignedSeats++;
                		}
        		}
		}
	}

	return success;
}
		
//----------------------------------------------------------------------------

/*
	- This routine assigns a chair to a department
	- it makes sure that the facultyId and departId passed to this method are both valid 
	  If this is not the case it prints appropriate message and returns failure; otherwise, 
	  returns success
*/
bool University::AssignDepartmentChair(long facultyId, long departId)
{
	if(!FacultyExist(facultyId))
        {
                cout << "The faculty id: " << facultyId << " does not exist" << endl << endl;
                return failure;
        }

	if(!DepIdExist(departId))
        {
                cout << "The department id: " << departId << " does not exist" << endl << endl;
                return failure;
        }

	for(int i = 0; i < Departments.size(); i++)
        {
                if (Departments[i].id == departId)
                {
			Departments[i].chairId = facultyId;
			return success;
		}
	}
}

//----------------------------------------------------------------------------

/*
	- This routine assigns a course to an instructor to teach
	- it makes sure that the courseId and facultyId passed to this method are both valid.
	  If this is not the case it prints appropriate message and returns failure; otherwise, 
	  returns success
*/
bool University::AssignInstructorToCourse (long facultyId, long courseId)
{
	

	if(!FacultyExist(facultyId))
        {
                cout << "The faculty id: " << facultyId << " does not exist" << endl << endl;
                return failure;
        }

	if(!CourExist(courseId))
        {
                cout << "The course id: " << courseId << " does not exist" << endl << endl;
                return failure;
        }

	for(int i = 0; i < Courses.size(); i++)
        {
                if (Courses[i].CRN == courseId)
                {
                        Courses[i].isTaughtBy = facultyId;
                        return success;
                }
        }
}

//----------------------------------------------------------------------------

/*
	- This method should list the department id's and department names only
*/
bool University::ListDepartments()
{
	cout << "DEPARTMENTS" << endl;

	 for(int i = 0; i < Departments.size(); i++)
	 {
		 Departments[i].Print();
		 cout << endl;
	 }
}

//----------------------------------------------------------------------------

/*
	- This method should list the student id's and student names only
*/
bool University::ListStudents()
{
	cout << "STUDENTS" << endl;

	for(int i = 0; i < Students.size(); i++)
        {       
		Students[i].Print();
		cout << endl;
	}
}

//----------------------------------------------------------------------------

/*
	- This method should list the course id's and course names only
*/
bool University::ListCourses()
{
	cout << "COURSES" << endl;

	for(int i = 0; i < Courses.size(); i++)
        {
	       Courses[i].Print();
	       cout << endl;
	}

}

//----------------------------------------------------------------------------

/*
	- This method should list the faculty id's and faculty names only
*/
bool University::ListFaculties()
{
	cout << "FACULTIES" << endl;

	for(int i = 0; i < Faculties.size(); i++)
        {
        	Faculties[i].Print();
		cout << endl;
	}
}

//----------------------------------------------------------------------------

/*
	- This rutine opens the transaction file and process it one by one
	- If the file could not be opened, it prints appropriate message and returns failure; 
	  otherwise, returns success
*/
bool University::ProcessTransactionFile(string fileName)
{
        fstream fin;
        string comand;
	
	string word1;
        string word2;
	string word3;
        string word4;
	string word5;
	string word6;
        int num;
	long id;
	long id2;
	float salary;
        
	fin.open(fileName.data());

        if (!fin)
                cout << "Could not open file, file might not exist." << endl;


                        while (fin >> comand)
                        {
                                if (comand == "CreateNewDepartment")
                                {
                                        fin >> word1;
					fin >> word2;
					fin >> id;
                                        CreateNewDepartment(word1, word2, id);
                                }

                                if (comand == "ListDepartments")
                                {
                                        ListDepartments();
                                }

                                if (comand == "CreateNewFaculty")
                                {
                                	fin >> word1;
                                        fin >> word2;
					fin >> word3;
                                        fin >> word4;
					fin >> word5;
                                        fin >> salary;
					fin >> num;
					fin >> id;
			
					CreateNewFaculty(word1, word2, word3, word4, word5, salary, num, id);        
                                }

                                if (comand == "ListFaculties")
                                {
                                	ListFaculties();
                                }

                                if (comand == "ListFacultiesInDepartment")
                                {
                                        fin >> id;
				
					ListFacultiesInDepartment(id);
                                }

                                if (comand == "CreateNewStudent")
                                {
                                        fin >> word1;
                                        fin >> word2;
                                        fin >> word3;
                                        fin >> word4;
                                        fin >> word5;
					fin >> num;
					fin >> word6;
					fin >> id;

					CreateNewStudent(word1, word2, word3, word4, word5, num, word6, id);
                                }
	
				if (comand == "ListStudents")
                                {
                                        ListStudents();
                                }
			
				if (comand == "ListStudentsOfAFaculty")
                                {
					fin >> id;
					
					ListStudentsOfAFaculty(id);
                                }

				if (comand == "CreateNewCourse")
                                {
                                        fin >> word1;
                                        fin >> id;
                                        fin >> id2;
                                        fin >> num;
				
					CreateNewCourse(word1, id, id2, num);

                                }

				if (comand == "ListCourses")
                                {
                                        ListCourses();
                                }

				if (comand == "ListCoursesTaughtByFaculty")
                                {
                                        fin >> id;

                                        ListCoursesTaughtByFaculty(id);
                                }

				if (comand == "ListCoursesOfADepartment")
                                {
                                        fin >> id;

                                        ListCoursesOfADepartment(id);
                                }

				if (comand == "AddACourseForAStudent")
                                {
                                        fin >> id;
					fin >> id2;

                                        AddACourseForAStudent(id, id2);
                                }

				if (comand == "ListCoursesTakenByStudent")
                                {
                                        fin >> id;

                                        ListCoursesTakenByStudent(id);
                                }

				if (comand == "AssignDepartmentChair")
                                {
                                        fin >> id;
					fin >> id2;

                                        AssignDepartmentChair(id, id2);
                                }
	
				if (comand == "AssignInstructorToCourse")
                                {
                                        fin >> id;
                                        fin >> id2;

                                        AssignInstructorToCourse(id, id2);
                          	}
	

	
	
			 }

        fin.close();
}

