#include "wife.h"

wife::wife():familyInfo()
{
        myChildren = NULL;
}

wife::wife(long theSSN, string theFirstName, string theLastName):familyInfo(theSSN, theFirstName, theLastName)
{
        myChildren = NULL;
}

