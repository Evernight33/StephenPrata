#include <iostream>
using namespace std;

int main()
{
	float price1 = 20.40;
	float price2 = 1.9 + 8.0 / 9.0;

	cout.setf(ios_base::showpoint);
	cout << "\"Furry firends\" is $" << price1 << "!\n";
	cout << "\"Fierry firends\" is $" << price2 << "!\n";

	cout.precision(2);
	cout << "\"Furry firends\" is $" << price1 << "!\n";
	cout << "\"Fierry firends\" is $" << price2 << "!\n";

	return 0;
}