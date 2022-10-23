#include <iostream>
using namespace std;

int main()
{
	float price1 = 20.40;
	float price2 = 1.9 + 8.0 / 9.0;
	cout << "\"Furry friends \"is $" << price1 << "!\n";
	cout << "\"Furry friends \"is $" << price2 << "!\n";

	cout.precision(2);
	cout << "\"Furry friends \"is $" << price1 << "!\n";
	cout << "\"Furry friends \"is $" << price2 << "!\n";
}