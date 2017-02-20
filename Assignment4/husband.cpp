#include "husband.h"

husband::husband():familyInfo()
{
	nextFamily = NULL;
	myWife = NULL;
}

husband::husband(long theSSN, string theFirstName, string theLastName):familyInfo(theSSN, theFirstName, theLastName)
{
	nextFamily = NULL;
        myWife = NULL;
}
