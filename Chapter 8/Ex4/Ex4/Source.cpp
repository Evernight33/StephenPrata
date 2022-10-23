#include <iostream>
using namespace std;
#include <cstring> 
struct stringy
{
	char* str;
	int ct;
};
	
void set(stringy& s, const char* sch)
{
	s.ct = strlen(sch) + 1;
	s.str = new char[s.ct];
	strcpy_s(s.str, s.ct, sch);
}

void show(const char* str, int n = 1)
{
	for (int i = 0; i < n; i++)
	{
		cout << str << endl;
	}
	cout << endl;
}

void show(stringy& s, int n = 1)
{
	for (int i = 0; i < n; i++)
	{
		cout << s.str << endl;
	}
	cout << endl;
}

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be. ";
	set(beany, testing);
	show(beany);
	show(beany, 2); 
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done !");
	return 0;
}

