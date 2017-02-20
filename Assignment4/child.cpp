#include "child.h"

child::child():familyInfo()
{
        mySibiling = NULL;
}

child::child(long theSSN, string theFirstName, string theLastName):familyInfo(theSSN, theFirstName, theLastName)
{
        mySibiling = NULL;
}

