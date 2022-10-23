#include <iostream>
using namespace std;

int main()
{
	int temperature = 63;
	cout << "Today's water temperature: ";
	cout.setf(ios_base::showpos);
	cout << temperature << endl;

	cout << "For our programming friends, that's\n";
	cout << std::hex << temperature << endl;
	cout.setf(ios_base::uppercase);
	cout.setf(ios_base::showbase);
	cout << "or\n";
	cout << temperature << endl;
	cout << "How " << true << "!   oooops How ";
	cout.setf(ios_base::boolalpha);
	cout << true << "!\n";

	cin.get();
	cin.get();
	return 0;
}