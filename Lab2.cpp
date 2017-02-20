#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void Insert(vector<string>&, string, int);
void Delete(vector<string>&, int);
void Print(const vector<string>&);

int main()
{
	vector<string> V;
	string cmd, word;
	int pos;

	ifstream comands;
	comands.open("comands.txt");
	
	if (!comands)
		cout << "The file does not exist." << endl;

	else
		{
			comands >> cmd;
	
			while (comands)
			{
				if (cmd == "Insert")
				{
				comands >> word;
				comands >> pos;
				Insert(V, word, pos);
				}

				if (cmd == "Delete")
				{			
				comands >> pos;
				Delete(V, pos);
				}
				
				if (cmd == "Print")
				{
				Print(V);
				cout << endl;
				}
				
				comands >> cmd;
			}
		}	

	comands.close();
	
	return 0;
}

void Insert(vector<string>& v, string w, int p)
{
	
	if (p > v.size())
		cout << "Error inserting at " << p << endl;

	else
	
		v.insert(v.begin() + p, w);
	
	return;
}

void Delete(vector<string>& v, int p)
{
        if (v.size() <= p)
		{
		cout << "Error deleting at " << p << endl;
		}
        else
		{
                v.erase(v.begin() + p);
		}
	return;
}

void Print(const vector<string>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
		

	return;
}	
