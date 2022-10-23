#include <iostream>
#include <sstream>
#include <string>

int main()
{
	using namespace std;

	ostringstream outstr;
	string hdisk;
	cout << "What's the name of your hard disk?\n";
	getline(cin, hdisk);
	int cap;
	cout << "What's it capacity GB?\n";
	cin >> cap;

	outstr << "The hard disk " << hdisk << " has a capacity of " << cap << " gygabytes.\n";
	string result = outstr.str();
	cout << result;
	return 0;

}