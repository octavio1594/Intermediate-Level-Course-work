#include "Person1.h"

Person::Person()
{
	name = email = address = dateOfBirth = gender = "SPACE";
}

Person::Person(string theName, string theEmail, string theAddress, string theDateOfBirth, string theGender)
{
	name = theName;
	email = theEmail;
	address = theAddress;
	dateOfBirth = theDateOfBirth;
	gender = theGender;
}
