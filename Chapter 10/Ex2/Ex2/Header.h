#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;

class Person {
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person()
	{
		lname = "";
		fname[0] = '\0';
	}
	Person(const string& ln, const char* fn = " Heyyou ");
	void Show() const;
	void FormalShow() const;
};


Person::Person(const string& ln, const char* fn) : lname(ln)
{
	for (int i = 0; i < LIMIT; i++)
	{
		if (!fn)
		{
			fname[i] = '\0';
			break;
		}
		fname[i] = fn[i];
	}
}

void Person::Show() const
{
	cout << "Name: " << lname << endl;
	cout << "Surname: " << fname << endl;
}

void Person::FormalShow() const
{
	cout << "Surname: " << fname << endl;
	cout << "Name: " << lname << endl;
}
#endif
