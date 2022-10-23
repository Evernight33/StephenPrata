#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

bool stringCompare(string s1, string s2);

int main()
{
	vector<string> names1;
	vector<string> names2;
	string name;

	cout << "Enter Matt's friends:\n (\"q\" to quit):\n";
	while (name != "q")
	{
		getline(cin, name);

		if (name != "" && name != "q")
		{
			names1.push_back(name);
		}
	}
	cout << endl;

	name = "\0";
	cout << "Enter Susie's friends:\n (\"q\" to quit):\n";
	while (name != "q")
	{
		getline(cin, name);

		if (name != "" && name != "q")
		{
			names2.push_back(name);
		}
	}
	cout << endl;

	sort(names1.begin(), names1.end(), stringCompare);
	sort(names2.begin(), names2.end(), stringCompare);

	vector<string> merged;
	insert_iterator<vector<string>> iter(merged, merged.begin());
	set_union(names1.begin(), names1.begin(), names2.begin(), names2.end(), iter, stringCompare);

	for (int i = 0; i < merged.size(); i++)
	{
		cout << merged[i] << endl;
	}

	cout << endl;
	return 0;
}

bool stringCompare(string s1, string s2)
{
	transform(s1.begin(), s1.end(), s1.begin(), tolower);
	transform(s2.begin(), s2.end(), s2.begin(), tolower);

	return s1 < s2;
}
