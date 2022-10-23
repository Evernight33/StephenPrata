#include "header.h"
#include <iostream>
using namespace std;

Golf::Golf() : fullname(""), hand(0)
{}

Golf::Golf(const char* name, int hc)
{
	strcpy_s(fullname, strlen(fullname), name);
	hand = hc;
}

bool Golf::setgolf()
{
	char fn[len];
	int hn;
	cout << "Enter name:\n";
	cin >> fn;
	while (cin.get() != '\n')
	{
		continue;
	}
	if (!isalpha(fullname[0]))
	{
		cout << "Wrong input\n";
		return false;
	}
	cout << "Enter handicap:\n";
	cin >> hn;
	*this = Golf(fn, hn);
	return true;
}

void Golf::handicap(int hc)
{
	hand = hc;
}

void Golf::showgolf()
{
	cout << "Name:\t";
	cout << fullname;
	cout << "\nHandicap:\t" << hand << endl;
}