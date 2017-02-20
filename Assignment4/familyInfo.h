#ifndef FAMILYINFO_H
#define FAMILYINFO_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class husband;
class wife;
class child;

typedef husband* husbPtr;
typedef wife* wifePtr;
typedef child* childPtr;

class familyInfo
{
	friend class familyLL;

	protected:
                long            ssn;
                string          firstName;
                string          lastName;
        public:
                familyInfo();
                familyInfo(long theSSN, string theFirstName, string theLastName);
};

#endif

