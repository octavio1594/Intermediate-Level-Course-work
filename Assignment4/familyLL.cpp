#include "familyLL.h"

familyLL::familyLL()
{
	top = NULL;
}
//---------------------------------------------------------------------------
familyLL::~familyLL()
{

}
//---------------------------------------------------------------------------
/*This function searches the entire linked list for the ssn pased to the function*/
//---------------------------------------------------------------------------
bool familyLL::search(long SSN)
{
		husbPtr p = top;

		while (p != NULL)
		{
			if(p-> ssn == SSN)
				return true;

			p = p-> nextFamily;
		}

		return false;
}
//---------------------------------------------------------------------------
/*This function adds a husband to the family. It first checks if the husband is
already in the list and if it is the function ends, if he is not, the husband is
added to the list*/
//---------------------------------------------------------------------------
void familyLL::AddHusband(long SSN, string Fname, string Lname)
{
		if(search(SSN) == true)//Check if the husband is in the list already
			return;

		husbPtr p = new husband(SSN, Fname, Lname);
		p-> nextFamily = top;
		top = p;
		return;
}
//---------------------------------------------------------------------------
/*This function removes a husband from the family. It first checks if the list is 
empty, if it is the function ends. It then checks if the husband is not in the list
and if he is not the function ends, if he is, the function removes the husband, along 
with the wife and children, with the corresponding ssn passed to the function*/
//---------------------------------------------------------------------------
void familyLL::RemoveHusband(long SSN)
{
		if(top == NULL)//If list is empty
			return;

		if(search(SSN) == false)//Check if the husband exist
			return;

		husbPtr p = top;
		husbPtr q = top;

		while (q != NULL)
		{
			q = p;
			p = p->nextFamily;
			if(p->ssn == SSN)
			{
				husbPtr k = p->nextFamily;
				wifePtr w = p->myWife;
				if (k == NULL)// If husband has no wife
				{
					delete p;
					q->nextFamily = k;
					return;
				}
				childPtr c = w-> myChildren;
				if (c == NULL)// If wife has no children
				{
					delete w;
					delete p;
					q->nextFamily = k;
					return;
				}
				if (c-> mySibiling == NULL)// If there is only one child
				{
					delete c;
					delete w;
					delete p;
					q->nextFamily = k;
					return;
				}
				childPtr s = c;
				childPtr a;
				while (c-> mySibiling != NULL)//Multiple children in the family
				{
					s = c;
					s = s-> mySibiling;
					a = s-> mySibiling;
					delete s;
					c-> mySibiling = a;
				}
				delete c;
				delete w;
				delete p;
				q->nextFamily = k;
				return;
				
			}
		}
}
//--------------------------------------------------------------------------------
/*This function adds a wife to the family. It first checks if the list is empty, if it
is the function ends. It then checks if the husband is in the list and if he is not
the function ends, Finally the wife is added to the corresponding husband with the ssn
passed to the function*/
//--------------------------------------------------------------------------------
void familyLL::AddWife(long SSN, string Fname, string Lname, long husbandSSN)
{
		if(top == NULL)//List empty, no husband in the list to atatch wife to
		{
			cout << "List is empty" << endl;
			return;
		}
		
		if(search(husbandSSN) == false)//Check if the husband is in the list
		{
			cout << "Husband with SSN: " << husbandSSN << ". doesn't exist, wife could not be added" << endl;
			return;
		}

		wifePtr p = new wife(SSN, Fname, Lname);
		husbPtr k = top;
		while (k != NULL)
		{
			if(k-> ssn == husbandSSN)
			{
				k-> myWife = p;
				return;
			}
		
			k = k-> nextFamily;
		}
}
//------------------------------------------------------------------------------------------
/*This function removes a wife from the family. It first checks if the list is empty, if it
is the function ends. It then checks if the husband is in the list and if he is not
the function ends, Finally the wife is removed along with the children from the corresponding
 husband with the ssn passed to the function*/
//------------------------------------------------------------------------------------------
void familyLL::RemoveWife(long husbandSSN)
{
		if(top == NULL)//List empty, no husband in the list to remove wife from
			return;

		if(search(husbandSSN) == false)//Check if the husband exist
			return;

		husbPtr p = top;
		husbPtr q = top;

		while (q != NULL)
		{
			q = p;
			p = p->nextFamily;
			if(p->ssn == husbandSSN)
			{
				wifePtr w = p->myWife;
				if (w == NULL)// If husband has no wife
				{
					return;
				}
				childPtr c = w-> myChildren;
				if (c == NULL)// If wife has no children
				{
					delete w;
					p->myWife = NULL;
					return;
				}
				if (c-> mySibiling == NULL)// If there is only one child
				{
					delete c;
					delete w;
					p->myWife = NULL;
					return;
				}
				childPtr s = c;
				childPtr a;
				while (c-> mySibiling != NULL)//Multiple children in the family
				{
					s = c;
					s = s-> mySibiling;
					a = s-> mySibiling;
					delete s;
					c-> mySibiling = a;
				}
				delete c;
				delete w;
				p->myWife = NULL;
				return;
				
			}
		}

}
//------------------------------------------------------------------------------------------
/*This function adds a child to the family. It first checks if the list is empty, if it
is the function ends. It then checks if the father is in the list and if he is not
the function ends, Finally the child is added to the corresponding father with the ssn
passed to the function*/
//------------------------------------------------------------------------------------------
void familyLL::AddAChild(long SSN, string Fname, string Lname, long fatherSSN)
{
		if(top == NULL)//List is empty, no father to atatch child to
		{
			cout << "List is empty" << endl;
			return;
		}
		
		if(search(fatherSSN) == false)//Check if the father exists
		{
			cout << "Father with SSN; " << fatherSSN << ". doesn't exist" << endl;
			return;
		}

		childPtr p = new child(SSN, Fname, Lname);
		husbPtr k = top;
		
		while (k != NULL)
		{
			if(k-> ssn == fatherSSN)
			{	
				childPtr q = k-> myWife-> myChildren;
				k-> myWife-> myChildren = p;
				p-> mySibiling = q;
				return;
			}

			k = k-> nextFamily;
		}
}
//--------------------------------------------------------------------------------------------
/*This function removes a child from the family. It first checks if the list is empty, if it
is the function ends. It then checks if the father is in the list and if he is not
the function ends, Finally the child is removed from the corresponding removed with the ssn
passed to the function*/
//--------------------------------------------------------------------------------------------
void familyLL::RemoveAChild(long FatherSSN, long childSSN)
{
		if(top == NULL)//List is empty, no father to remove child from
			return;
		
		if(search(FatherSSN) == false)//Check if the father exist
			return;

		husbPtr p = top;

		while (p != NULL)
		{
			if(p->ssn == FatherSSN)
			{
				wifePtr w = p->myWife;
				if (w == NULL)// If husband has no wife
				{
					return;
				}
				childPtr c = w-> myChildren;
				if (c == NULL)// If wife has no children
				{
					return;
				}
				if (c-> mySibiling == NULL)// If there is only one child
				{
					if (c-> ssn == childSSN)
					{
						delete c;
						w->myChildren = NULL;
						return;
					}
					return;
				}
				childPtr s = c;
				childPtr a= s-> mySibiling;
				while (a-> mySibiling != NULL)//Multiple children in the family
				{
					a = s-> mySibiling;
					if(a-> ssn == childSSN)
					{
						s-> mySibiling = a-> mySibiling;
						delete a;
						return;
						
					}
					s = s-> mySibiling;

				}
				
				cout << "Child to be removed with SSN: " << childSSN << " doesn't exist" << endl;
				return;
			}

			p = p->nextFamily;
		}

	}
//-----------------------------------------------------------------------------------------
/*This function prints a certain family. It first checks if the list is empty, if it is the 
fuction ends. It then checks if the husband is in the list, if he is not, the function ends.
If he is the husband with the ssn passed to the function is printed along with his family*/
//-----------------------------------------------------------------------------------------
void familyLL::PrintAFamily(long fatherSSN)
{
		if(top == NULL)//List is empty, nothing to print.
			return;
		
		if(search(fatherSSN) == false)//Check if the father exist
		{
			cout << "Family with husband's SSN: " << fatherSSN << ". Doesn't exist, family could no be printed." << endl;
			return;
		}
		
		husbPtr p = top;
		
		while (p != NULL)
		{
			if(p->ssn == fatherSSN)
			{
				wifePtr w = p->myWife;
				if (w == NULL)// If husband has no wife
				{
					cout << "Father: " << p-> firstName << endl;
					cout << "     End of family     " << endl;
					return;
				}
				childPtr c = w-> myChildren;
				if (c == NULL)// If wife has no children
				{
					cout << "Father: " << p-> firstName << endl;
					cout << "Wife: " << w-> firstName << endl;
					cout << "     End of family     " << endl;
					return;
				}
				if (c-> mySibiling == NULL)// If there is only one child
				{
					cout << "Father: " << p-> firstName << endl;
					cout << "Wife: " << w-> firstName << endl;
					cout << "Child: " << c-> firstName << endl;
					cout << "     End of family    " << endl;
					return;
				}
				childPtr s = c;
				cout << "Father: " << p-> firstName << endl;
				cout << "Wife: " << w-> firstName << endl;
				while (s != NULL)//Multiple children in the family
				{
					cout << "Child: " << s-> firstName << endl;
					s = s-> mySibiling;
				}
				cout << "     End of family	" << endl;
				return;
			}

			p = p->nextFamily;
		}

}
//-------------------------------------------------------------------------------------------
/*This function prints all the families in the linked list. It first checks if the list is empty,
 if it is the fuction ends. If the list is not empty then the function prints every family in the 
linked list using the printAFamily function.*/
//-------------------------------------------------------------------------------------------
void familyLL::PrintAllFamilies()
{
		if(top == NULL)//List is empty, nothing to print.
			return;
		
		husbPtr p = top;
		
		while (p != NULL)
		{
			PrintAFamily(p-> ssn);
			p = p->nextFamily;
		}
		return;
}
//---------------------------------------------------------------------------
/*This function simply reads a transaction file and calls the functions according 
to the commands in the file.*/
//---------------------------------------------------------------------------
void familyLL::ReadTransactionFile()
{
	ifstream fin;

        string fName;
        string lName;
	string command;
        long ssn;
        long ssn2;

        fin.open("data.txt");

        if (!fin)
                cout << "Could not open file, file might not exist." << endl;
        else
        {
                 fin >> command;

                        while(fin)
                        {
                                if (command == "AddHusband")
                                {
                                fin >> ssn;
                                fin >> fName;
				fin >> lName;
                                AddHusband(ssn, fName, lName);
                                }

                                if (command == "AddWife")
                                {
                                fin >> ssn;
                                fin >> fName;
                                fin >> lName;
                                fin >> ssn2;;
                                AddWife(ssn, fName, lName, ssn2);
                                }

                                if (command == "PrintAllFamilies")
                                {
                                cout << "------ Print all families -------" << endl;
				PrintAllFamilies();
                                }

				if (command == "AddAchild")
                                {
                                fin >> ssn;
                                fin >> fName;
                                fin >> lName;
				fin >> ssn2;
                                AddAChild(ssn, fName, lName, ssn2);
                                }

                                if (command == "RemoveAchild")
                                {
                                fin >> ssn;
                                fin >> ssn2;
                                RemoveAChild(ssn, ssn2);
                                }
				
				if (command == "PrintAFamily")
                                {
                                cout << "------ Print a certain family ------" << endl;
				fin >> ssn;
				PrintAFamily(ssn);
                          	}
		
				fin >> command;
        		}
	}
}
