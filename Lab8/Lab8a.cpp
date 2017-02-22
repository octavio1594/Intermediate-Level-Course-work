#include <iostream>
using namespace std;

int gcd(int x, int y);

int main()
{
	int a,b;

	cout << "Enter first number : ";
	cin >> a;

	cout << "Enter second number : ";
	cin >> b;

	cout << "The greates common divisor of " << a << " and " << b << " is: " << gcd(a,b) << endl;

}

//------------------------------------------------------------------------------------------------------

int gcd(int x, int y)
{
	if (x == 0)
		return y;
	if(y == 0)
		return x;
	if (x == y)
		return x;
	else
		return gcd(y, x % y);
}

