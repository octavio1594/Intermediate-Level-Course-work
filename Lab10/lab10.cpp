#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Node;
typedef Node* NodePtr;
class CircularDLL;

class Node 
{
	friend class CircularDLL;
	protected:
      		int stId;
	  	string stName;
	  	string stEmail;
	  	int stAge;
      		NodePtr next;
		NodePtr prev;
	
	public:
		Node();
		Node(long id, string name, string email, int age);
};

class CircularDLL
{
	protected:
		NodePtr  top;
		void destroy (NodePtr&);

	public:
		CircularDLL();
		CircularDLL(const CircularDLL& source);
		~CircularDLL();
		void insertDataFromFile();
		void print ();
		bool search (int);
		void insertAfterFirst (int id, string name, string email, int age);
		void insertBeforeFirst (int id, string name, string email, int age);
		void insertAfterLast (int id, string name, string email, int age);
		void insertBeforeLast (int id, string name, string email, int age);
		void remove (int);
		void copy (NodePtr top1, NodePtr& top2);
		void removeFirstNode();		
};

//----------------------------------------------------------------------------------------

Node::Node()
{
	stAge = stId = 0;
	stName = stEmail = " ";
	next = prev = NULL;
}

//----------------------------------------------------------------------------------------

Node::Node(long id, string name, string email, int age)
{
        stAge = age;
	stId = id;
        stName = name;
	stEmail = email;
        next = prev = NULL;
} 

//----------------------------------------------------------------------------------------

CircularDLL::CircularDLL()
{
	top = NULL;
}

//----------------------------------------------------------------------------------------

CircularDLL::CircularDLL(const CircularDLL& source)
{
	top = NULL;
	copy(source.top, top);
}

//----------------------------------------------------------------------------

CircularDLL::~CircularDLL()
{
	destroy(top);
}

//--------------------------------------------

// Read a transaction file and insert the data into it
// after reading a set of data you can call any of the 
// insert functions to insert the node into the linked list 
/* use the following data to test your program
	76543	Mary	mary@csusm.edu		19
	98765	Kathy	kathy@csusm.edu		30
	16438	Flora	flora@csusm.edu		25
	43260	Peter	peter@csusm.edu		29
	87590	kim		kim@csusm.edu		31
*/
void CircularDLL::insertDataFromFile()
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

//--------------------------------------------

void CircularDLL::print ()
{
	NodePtr p = top-> next;

        cout << "- " << top-> stName << endl;

	while (p != top)
        {
		cout << "- " << p-> stName << endl; 
		p = p->next;
        }
        
        return;
}

//--------------------------------------------

bool CircularDLL::search (int id)
{	
	NodePtr p = top;
	
	if (top == NULL)
		return false;

	while (p != top)
	{
		if (p-> stId == id)
		return true;

		p = p->next;
	}
	
	return false;
}

//--------------------------------------------

void CircularDLL::insertAfterFirst (int id, string name, string email, int age)
{
	if (top == NULL)
        {
                insertBeforeFirst(id, name, email, age);
                return;
        }

	if (top-> next == top)
	{
		insertAfterLast(id, name, email, age);
		return;
	}

        NodePtr p = new Node(id, name, email, age);
        p-> next = top-> next;
        top-> next = p;
	p-> prev = top;
	NodePtr k;
	k = p-> next;
	k-> prev = p;
	
}

//--------------------------------------------

void CircularDLL::insertBeforeFirst (int id, string name, string email, int age)
{
	if (search(id))
	{
		cout << "The id: " << id << " already exists" << endl;
		return;
	}

	NodePtr p = new Node(id, name, email, age);
	
	if (top == NULL)
	{
		top = p;
		top-> prev = top;
                top-> next = top;
		return;
	}
	
	p-> next = top;
	top-> prev = p;

	NodePtr q = top;
	while (q-> next != top)
        {
                q = q->next;
        }

	q -> next = p;
	p -> prev = q;
	top = p;
}

//--------------------------------------------

void CircularDLL::insertAfterLast (int id, string name, string email, int age)
{
	if (search(id))
        {
                cout << "The id: " << id << " already exists" << endl;
                return;
        }

	NodePtr p = new Node(id, name, email, age);
	
	if (top == NULL)
        {
                top = p;
		top-> prev = top;
		top-> next = top;
                return;
        }

	NodePtr q = top;

	while (q-> next != top)
		q = q->next;

	q-> next = p;
	p-> prev = q;
	p-> next = top;
	top -> prev = p;
}

//--------------------------------------------

void CircularDLL::insertBeforeLast (int id, string name, string email, int age)
{
	if(search(id) == true)
                return;

        if (top == NULL)
        {
                insertBeforeFirst(id, name, email, age);
                return;
        }

        if (top-> next == top)
        {
                insertBeforeFirst(id, name, email, age);
                return;
        }
		
	NodePtr p = new Node(id, name, email, age);
        NodePtr q = top;

         while (q-> next-> next != top)
                q = q-> next;

        NodePtr k = q-> next;
        q->next = p;
        p->next = k;

	k-> prev = p;
	p-> prev = q;

	return;
}

//--------------------------------------------

void CircularDLL::remove (int id)
{
	if (top == NULL)
                return;

        if(search(id))
                return;

        if (top->stId == id)
        {
                removeFirstNode();
                return;
        }
	
	NodePtr p = top-> next;

	while (p != top)
        {
                if(p->stId == id)
                {
                        NodePtr k = p->next;
			NodePtr q = p->prev;
                        k-> prev = q;
			q-> next = k;

			delete p;
                }
	
		p = p-> next;
        }

	return;

}

//-----------------------------------------------------

void CircularDLL::removeFirstNode()
{
	if (top == NULL)
                return;

        NodePtr p = top;
        top = top->next;
        
	NodePtr k = p;
	while (k-> next != p)
		k = k-> next;
	
	k-> next = top;
	top-> prev = k;
	
	delete p;
        return;	
}

//--------------------------------------------

void CircularDLL::copy (NodePtr atop, NodePtr& btop)
{
	NodePtr acurr, bcurr, ccurr;
	
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
		ccurr = btop;

                while (acurr-> next != atop)
                {
			bcurr -> next = new Node;
                        acurr = acurr -> next;
                        bcurr = bcurr -> next;
	
			bcurr -> stId = acurr -> stId;
                        bcurr -> stName = acurr -> stName;
                        bcurr -> stEmail = acurr -> stEmail;
                        bcurr -> stAge = acurr -> stAge;
			bcurr-> prev = ccurr;
			ccurr = bcurr;
                }

                bcurr -> next = top;
        }	
}       

//--------------------------------------------

void CircularDLL::destroy(NodePtr& top) 
{
	NodePtr p = top;
	NodePtr q = top;
	
	while(p!= top)
	{
		p = p-> next;
		delete q;
		q = p;
	}
	
	top = NULL;
}

//--------------------------------------------

int main () 
{
   CircularDLL list1;
   list1.insertDataFromFile();
   cout << "---------- List 1 --------- " << endl;
   list1.print();
   list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
   list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
   list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
   list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
   cout << "---------- List 2 --------- " << endl;
   list1.print();
   bool  found = list1.search (12321);
   if (found)
	   {
		cout << "--------- Success ----------" << endl;
	   	cout << "- The record was found" << endl;
	   }
   else
	   {
		cout << "--------- Error ----------" << endl;
	   	cout << "- The record was not found" << endl;
	   }
   list1.remove (54321);
   cout << "---------- List 3 --------- " << endl;
   list1.print();
   
   CircularDLL list2(list1);
   cout << "---------- List 4 --------- " << endl;
   list2.print();
   return 0;
}
