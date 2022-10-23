#include <iostream>
using namespace std;

int n = 0;

void func(const char* str)
{
	cout << str << "\n\n";
	n++;
}

void func(const char* str, int j)
{ 
	for (size_t i = 0; i < n; i++)
	{
		cout << str << endl;
	}
	n++;
	cout << endl;
}

int main()
{
	const char* str1 =  "Ajdfkdfkd";
	const char* str2 = "Sdlsldkfjd";

	func(str1);
	func(str2,4);
	func(str2, 5);
	func(str1);
	func(str2, 5);
}