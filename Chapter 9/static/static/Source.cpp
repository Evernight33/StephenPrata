#include <iostream>
using namespace std;

const int ArS = 10;

void strcount(const char* str);

int main()
{
	char input[ArS];
	char next;
	cout << "Enter a line:\n";
	cin.get(input, ArS);
	while (cin)
	{
		cin.get(next);
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
		cin.get(input, ArS);
	}
	cout << "Bye!\n";
	return 0;
}

void strcount(const char* str)
{
	static int total = 0;
	int count = 0;
	cout << "\"" << str << "\" contains ";
	while (*str++)
		count++;
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}