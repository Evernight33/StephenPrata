#include <iostream>
using namespace std;

void to_up(string& s)
{
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		s[i] = toupper(s[i]);
	}
}

void show(const string& s)
{
	cout << s << endl;
}

int main()
{
	string s1 = "Goodby my dear!";
	to_up(s1);
	show(s1);
}