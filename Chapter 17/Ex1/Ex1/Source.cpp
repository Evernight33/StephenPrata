#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter your string:\n";
	cout << "Input will be read up until first '$' character:\n";

	char string;
	cin.get(string);

	int count = 0;

	while (string != '$')
	{
		count++;
		cin.get(string);
	}

	cin.putback(string);

	cout << "Symbols count: " << count << endl;
	cout << "The next symbol to be extracted: ";
	cout << (char) cin.get() << endl;

	cin.get();
	cin.get();
	return 0;
}