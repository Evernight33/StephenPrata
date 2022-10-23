#include "header.h"
#include <iostream>
using namespace std;

int main()
{
	const int s = 5;
	Golf g1("Vasya", 45);
	g1.showgolf();
	g1.handicap(56);
	Golf ar[s];
	for (int i = 0; i < s; i++)
	{
		if (ar[i].setgolf() == 0)
		{
			break;
		}
		ar[i].showgolf();
	}
}