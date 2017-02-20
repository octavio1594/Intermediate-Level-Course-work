#ifndef FAMILYLL_H
#define FAMILYLL_H

#include "familyInfo.h"
#include "husband.h"
#include "wife.h"
#include "child.h"
class familyLL
{
	protected: 
            	husbPtr	top;
	public:
            	bool search(long SSN);
		void AddHusband(long SSN, string Fname, string Lname);
            	void RemoveHusband(long SSN);
            	void AddWife(long SSN, string Fname, string Lname, long husbandSSN);
            	void RemoveWife(long husbandSSN);
            	void AddAChild(long SSN, string Fname, string Lname, long fatherSSN);
            	void RemoveAChild(long FatherSSN, long childSSN);
            	void PrintAFamily(long fatherSSN);
            	void PrintAllFamilies();
		void ReadTransactionFile();
		familyLL();
		~familyLL();
};

#endif

