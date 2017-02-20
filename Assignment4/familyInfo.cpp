#include "familyInfo.h"

familyInfo::familyInfo()
{
	ssn = 0;
	firstName = lastName = "SPACE";
}

familyInfo::familyInfo(long theSSN, string theFirstName, string theLastName)
{
	ssn = theSSN;
	firstName = theFirstName;
	lastName = theLastName;
}
	
