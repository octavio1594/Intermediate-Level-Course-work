#ifndef HUSBAND_H
#define HUSBAND_H

#include "familyInfo.h"
using namespace std;

class husband:public familyInfo
{
	friend class familyInfo;
	friend class familyLL;

        protected:
                husbPtr		nextFamily;
		wifePtr		myWife;
        public:
                husband();
                husband(long theSSN, string theFirstName, string theLastName);
};

#endif

