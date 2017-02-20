#ifndef CHILD_H
#define CHILD_H

#include "familyInfo.h"
using namespace std;

class child:public familyInfo
{
        friend class familyLL;
	friend class familyInfo;

        protected:
                childPtr	mySibiling;
        public:
                child();
                child(long theSSN, string theFirstName, string theLastName);
};

#endif


