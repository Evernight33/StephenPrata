#include <iostream>
#include <cmath>
#include "coordin.h"
using namespace std;

int main()
{
	rect rplace;
	polar pplace;

	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "Next two �um�ers (q to qui t) : ";
	}
	cout << " D��� . \n ";
	return 0;
}
