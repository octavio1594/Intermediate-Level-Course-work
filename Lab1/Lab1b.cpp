#include <iostream>
#include <fstream>
using namespace std;

void getInfo (int arrayA[]);
void reverse(int arrayA[], int arrayB[]);
void print(const int arrayA[]);
int between(const int arrayA[]);
int divide(const int arrayA[]);
void divideIndex(const int arrayA[]);
double average(const int arrayA[]);
int min (const int arrayA[]);
bool findKey(const int arrayA[], int key);

int main()
{
	int arrayA[10];
	int arrayB[10];
	int key;  	   
	
	getInfo (arrayA);
	reverse(arrayA, arrayB);
	print(arrayA);
	print(arrayB);
	cout << "The elements between 80 and 100 are: " << between(arrayA) << " " << endl;
	cout << "The elements that are divisible by 5 are: " << divide(arrayA) << " " << endl;
	cout << "The idexes that are divisible by 5 are: "; divideIndex(arrayA);
	cout << "The average is: " << average(arrayA) << endl;
	cout << "The minimum number in the file is: " << min(arrayA) << endl;
	cout << "Enter a key." << endl;
	cin >> key;
	if (findKey(arrayA, key) == 1)
	cout << "The key was found." << endl;
	else
	cout << "The key was not found." << endl;

	return 0;
}


void getInfo(int array [])
	{
		ifstream file;
		int num;

		file.open("data.txt");

		if (!file)
		cout << "The file does not exist." << endl;

		else
		{
			for(int i = 0; i < 10; i++)
			{
				file >> array[i];
			}
		}
	}

void reverse(int arrayA[], int arrayB[])
	{
  		int count = 10 - 1;
  		for(int i = 0; i < 10; i++)
    		{
      		arrayB[count]=arrayA[i];
      		count--;
   		 }
	}


void print(const int array[])
	{
		for(int i = 0; i < 10; i++)
		{
			cout << array[i] << " ";
		}
		
		cout << endl;
	}

int between(const int array[])
	{
		int x = 0;
		for(int i = 0; i < 10; i++)
		{
		
			if (array[i] >= 80 && array[i] <= 100)
				
			x++;
			
		}
		return x;
	}

int divide(const int array[])
	{
		int x = 0;
		for(int i = 0; i < 10; i++)
		{
			if ((array[i]%5)==0)
			
				x++;
			
		}
		return x;
	}
void divideIndex(const int array[])
        {
                for(int i = 0; i < 10; i++)
                {
                        if ((array[i]%5) == 0)
                        cout << i << " ";
                        
                }
        	cout << endl;
	}
	
double average(const int array[])
	{
		double total = 0;
		
		for(int i = 0; i < 10; i++)
		
			total = array[i] + total;
		
			return (total/10);
	
	
	}
	
int min(const int array[])
	{
		int min = 999;
		
		for(int i = 0; i < 10; i++)
		{
			if (array[i] < min)
			min = array[i];
		}
			
		return min;
	}

bool findKey(const int array[], int key)
	{
		for(int i = 0; i < 10; i++)
		{
			if(key == array[i])
			return true;
			
			else
			return false;
		}
	}

