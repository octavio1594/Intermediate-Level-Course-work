#include <iostream>
#include <string>

using namespace std;

bool isFibonacci(int num);
long fib(int n);

int main()
{
        int num;

        cout << "Enter a number (enter a negative number to quit): ";
        cin >> num;
	
	while (num >= 0)
	{
		if (isFibonacci(num) == true)
			cout << "Yes, you got it, " << num << " is a Fibonacci number." << endl;

        	if (isFibonacci(num) == false)
			cout << "!!!!! Sorry " << num << " is not a Fibonacci number." << endl;
                
		cout << "Enter a number (enter a negative number to quit): ";
        	cin >> num;
	}
}

//------------------------------------------------------------------------------------------

bool isFibonacci(int num)
{
	int n = 0;	

	while (n < n + 1)
	{
		int fibNo = fib(n);

		if(fibNo == num)
			return true;
		if(fibNo > num)
			return false;
		n++;
	}
}

//-----------------------------------------------------------------------------------------

long fib(int n)
{
	if (n == 0)
		return 0;

	if ((n == 1)||(n == 2))
		return 1;
	
	int a = fib(n - 1);
	int b = fib(n - 2);
		
	return a + b;
}
