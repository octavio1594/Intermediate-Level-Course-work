#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Node;
typedef Node* NodePtr;
class LL;

class Node 
{
	friend class LL;

	private:
      		int 	stId;
	  	string 	stName;
	  	string 	stEmail;
	  	int 	stAge;
      		NodePtr nextStudent;

	public:
		Node();
		Node(int theId, string theName, string theEmail, int theAge);
};

class LL
{
	private:
		NodePtr  top;
		void destroy (NodePtr&);

	public:
		LL();
		LL(const LL& source);
		~LL();
		void insertDataFromFile();
		void print ();
		bool search (int);
		void insertAfterFirst (int id, string name, string email, int age);
		void insertBeforeFirst (int id, string name, string email, int age);
		void insertAfterLast (int id, string name, string email, int age);
		void insertBeforeLast (int id, string name, string email, int age);
		void remove (int);
		void copy (NodePtr top1, NodePtr& top2);
		bool removeFirstNode();
};

//--------------------------------------------------------------------------------------

Node::Node()
{
	stId = stAge = 0;
	stName = stEmail = "SPACE";
	nextStudent = NULL;
}

//---------------------------------------------------------------------------------------

Node::Node(int theId, string theName, string theEmail, int theAge)
{
	stId = theId;
	stAge = theAge;
	stName = theName;
	stEmail = theEmail;
	nextStudent = NULL;
}

//----------------------------------------------------------------------------------------

LL::LL()
{
	top = NULL;
}

//----------------------------------------------------------------------------------------
                                               
LL::LL(const LL& source)
{
	top = NULL;
	copy(source.top, top);
}

//----------------------------------------------------------------------------------------

LL::~LL()
{

}

//-----------------------------------------------------------------------------------------

void LL::insertDataFromFile()
{
	ifstream fin;
	
	string name;
        string email;
	int id;
	int age;

	fin.open("data.txt");

        if (!fin)
                cout << "Could not open file, file might not exist." << endl;
	else
	{	
		fin >> id >> name >> email >> age;

		while (fin)
		{
			insertAfterLast(id, name, email, age);
			fin >> id >> name >> email >> age;
		}	 
	}
}

//-------------------------------------------------------------------------------------------

void LL::print ()
{
	NodePtr p = top;

	while (p != NULL)	
	{
		cout << "- " << p-> stName << endl;
	        p = p-> nextStudent;
	}
}

//-------------------------------------------------------------------------------------------

bool LL::search (int id)
{
	NodePtr p = top;
	
	while (p != NULL)
	{
		if(p-> stId == id)
			return true;
	
		p = p-> nextStudent;
	}
	
	return false;
}

//---------------------------------------------------------------------------------------------

void LL::insertAfterFirst (int id, string name, string email, int age)
{
	if (top == NULL)
	{
		insertBeforeFirst(id, name, email, age);
		return;
	}

	NodePtr p = new Node(id, name, email, age);
	p-> nextStudent = top->nextStudent;
	top->nextStudent = p;
		
}

//----------------------------------------------------------------------------------------------

void LL::insertBeforeFirst (int id, string name, string email, int age)
{
	if(search(id) == true)
		return;
	
	NodePtr p = new Node(id, name, email, age);
	p-> nextStudent = top;
	top = p;
}

//-----------------------------------------------------------------------------------------------

void LL::insertAfterLast (int id, string name, string email, int age)
{
	if(search(id) == true)
                return;

	if (top == NULL)
	{
		insertBeforeFirst(id, name, email, age);
		return;
	}
	
	NodePtr p = new Node(id, name, email, age);
	NodePtr q = top;
	
	while (q->nextStudent != NULL)
        	q = q-> nextStudent;
	
	q->nextStudent = p;
        
}

//-----------------------------------------------------------------------------------

void LL::insertBeforeLast (int id, string name, string email, int age)
{
	if(search(id) == true)
                return;

        if (top == NULL)
        {
                insertBeforeFirst(id, name, email, age);
                return;
        }

	if (top-> nextStudent == NULL)
        {
                insertBeforeFirst(id, name, email, age);
                return;
        }
	
	NodePtr p = new Node(id, name, email, age);
	NodePtr q = top;
	
	 while (q->nextStudent->nextStudent != NULL)
                q = q-> nextStudent;
	
	NodePtr k = q-> nextStudent;
	q->nextStudent = p;
	p->nextStudent = k;
}

//-----------------------------------------------------------------------------------
 
void LL::remove (int id)
{
	if (top == NULL)
		return;
	
	if(search(id) == false)
                return;

	if (top->stId == id)
	{
		removeFirstNode();
		return;
	}
	
	NodePtr p = top;
	NodePtr q = top;
	
	while (q != NULL)
	{
		q = p;
		p = p->nextStudent;
		if(p->stId == id)
		{
			NodePtr k = p->nextStudent;
			delete p;
			q->nextStudent = k;
			return;
		}
	}
}

//-----------------------------------------------------------------------------------

bool LL::removeFirstNode()
{
	if (top == NULL)
                return false;
	
	NodePtr p = top;
	top = top->nextStudent;
	delete p;
	return true;
}

//------------------------------------------------------------------------------------

void LL::copy (NodePtr atop, NodePtr& btop)
{
	NodePtr acurr, bcurr;
   	
	destroy (btop);
   	if (atop != NULL) 
	{
      		btop = new Node;
      		
		btop -> stId = atop -> stId;
                btop -> stName = atop -> stName;
                btop -> stEmail = atop -> stEmail;
                btop -> stAge = atop -> stAge; 
      		
		acurr = atop;
      		bcurr = btop;
		
		while (acurr -> nextStudent != NULL) 
		{
          		bcurr -> nextStudent = new Node;
          		acurr = acurr -> nextStudent;
          		bcurr = bcurr -> nextStudent;
          		
			bcurr -> stId = acurr -> stId;
                	bcurr -> stName = acurr -> stName;
                	bcurr -> stEmail = acurr -> stEmail;
                	bcurr -> stAge = acurr -> stAge;
          	}
      
		bcurr -> nextStudent = NULL;
      	}
}       

//------------------------------------------------------------------------------------

void LL::destroy(NodePtr& top) 
{
	NodePtr p = top;
        NodePtr q = top;
	
	while (p != NULL)
	{
		p = p->nextStudent;
		delete q;
		q = p;
	}
	
	top = NULL;
}

int main()
{
	LL list1;
   	list1.insertDataFromFile();
   	cout << "List 1" << endl;
	list1.print();
   	list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
   	list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
   	list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
	list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
	cout << "List 2" << endl;
	list1.print();
   	
	bool  found = list1.search (12321);
   	if (found)
	   cout << "The record was found" << endl;
  	else
	   cout << "The record was not found" << endl;
   
	list1.remove (54321);
   	cout << "List 3" << endl;
	list1.print();
   
   	LL list2(list1);
   	cout << "List 4" << endl;
	list2.print();
	
	return 0;
}
