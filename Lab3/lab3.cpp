#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class Course
{
        public:
                long    CourseNum;
                string  CourseName;
};

class Person 
{
	public:
		long		SSN;
		string 		Fname;
		string 		Lname;
		int 		Age;
		char 		Gender;

class Student
{
        public:
                long    StNo;
                Course  C1;
                Course  C2;
                Course  C3;

};

class StudentProfile
{
        public:
                Person          PersonalInfo;
                Student         StudentInfo;

};

//----------------------------------------------------------
void PrintCollections(const vector<StudentProfile>& StCollection);
void GetInfo(vector<StudentProfile>& StCollection);

//----------------------------------------------------------
void PrintCollections(vector<StudentProfile>& StCollection)
{
	for (int i=0; i < StCollection.size(); i++)
	{
		 cout << "First Name: " << StCollection[i].PersonalInfo.Fname << endl
			 << "Last Name: " << StCollection[i].PersonalInfo.Lname << endl
			 << "Age: " << StCollection[i].PersonalInfo.Age << endl
			 << "Social Security Number: " << StCollection[i].PersonalInfo.SSN << endl
			 << "Gender: " << StCollection[i].PersonalInfo.Gender << endl
			 << "Student Number: " << StCollection[i].StudentInfo.StNo << endl
			 << "Course 1 Name: " << StCollection[i].StudentInfo.C1.CourseName << endl
			 << "Course 1 Number: " << StCollection[i].StudentInfo.C1.CourseNum << endl
			 << "Course 2 Name: " << StCollection[i].StudentInfo.C2.CourseName << endl
			 << "Course 2 Number: " << StCollection[i].StudentInfo.C2.CourseNum << endl
			 << "Course 3 Name: " << StCollection[i].StudentInfo.C3.CourseName << endl
                         << "Course 3 Number: " << StCollection[i].StudentInfo.C3.CourseNum << endl
			 << "---------------------------------------------" << endl;

	}

}

//----------------------------------------------------------
void GetInfo(vector <StudentProfile>& StCollection)
{
	StudentProfile new_entry;
	ifstream studentData;
	studentData.open("data.txt");


	studentData >> new_entry.PersonalInfo.Fname >> new_entry.PersonalInfo.Lname
		>> new_entry.PersonalInfo.Age >> new_entry.PersonalInfo.SSN
		>> new_entry.PersonalInfo.Gender >> new_entry.StudentInfo.StNo 
		>> new_entry.StudentInfo.C1.CourseName >> new_entry.StudentInfo.C1.CourseNum 
		>> new_entry.StudentInfo.C2.CourseName >> new_entry.StudentInfo.C2.CourseNum
		>> new_entry.StudentInfo.C3.CourseName >> new_entry.StudentInfo.C3.CourseNum;	

	cout <<  new_entry.PersonalInfo.Fname <<  " " << new_entry.StudentInfo.C3.CourseNum << endl;
	while (studentData)
	{
	
		StCollection.push_back(new_entry);
		studentData >> new_entry.PersonalInfo.Fname >> new_entry.PersonalInfo.Lname
                	>> new_entry.PersonalInfo.Age >> new_entry.PersonalInfo.SSN
               	 	>> new_entry.PersonalInfo.Gender >> new_entry.StudentInfo.StNo 
                	>> new_entry.StudentInfo.C1.CourseName >> new_entry.StudentInfo.C1.CourseNum   
                	>> new_entry.StudentInfo.C2.CourseName >> new_entry.StudentInfo.C2.CourseNum
                	>> new_entry.StudentInfo.C3.CourseName >> new_entry.StudentInfo.C3.CourseNum;
		
	

	}
	studentData.close();
	return;
}

//----------------------------------------------------------
int main()
{

	vector <StudentProfile> StCollection;
	GetInfo(StCollection);
        PrintCollections(StCollection);
}
//----------------------------------------------------------

