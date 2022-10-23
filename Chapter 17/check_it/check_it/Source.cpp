#include <iostream>
using namespace std;

int main()
{
	cout << "Enter numbers:\n";
	int input;
	int sum = 0;

	while (cin >> input)
	{
		sum += input;
	}

	cout << "Last value entered: " << input << endl;
	cout << "Sum: " << sum << endl;
	return 0;
}