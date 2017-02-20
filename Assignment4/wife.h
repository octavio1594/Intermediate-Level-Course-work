#ifndef WIFE_H
#define WIFE_H

#include "familyInfo.h"
using namespace std;

class wife:public familyInfo
{
        friend class familyInfo;
	friend class familyLL;

	protected:
                childPtr	myChildren;
        public:
                wife();
                wife(long theSSN, string theFirstName, string theLastName);
};

#endif

