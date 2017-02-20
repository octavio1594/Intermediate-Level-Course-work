#ifndef PERSON1_H
#define PERSON1_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Person
{
        protected:
                string          name;
                string          email;
                string          address;
                string          dateOfBirth;
                string          gender;
        public:
		Person();
                Person(string theName, string theEmail, string theAddress, string theDateOfBirth, string theGender);
};

#endif
