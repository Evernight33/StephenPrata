#include <iostream>
#include <string>
using namespace std;

bool isPalidrom(string& str);

int main()
{
	string str;

	while (true)
	{
		cout << "Enter your string (q to quit):\n";
		getline(std::cin, str);

		if (str == "q")
		{
			break;
		}
		else if (isPalidrom(str))
		{
			cout << str << " is a palidrom\n\n";
		}
		else
		{
			cout << str << " isn't a palidrom\n\n";
		}
	}

	cin.get();
	cin.get();
	
}

bool isPalidrom(string& str)
{
	bool isPal = true;
	int len = str.length();
	string str1;
	int j = 0;

	for (int i = 0; i < len; i++)
	{
		if (isalpha(str[i]))
		{
			
			str1.push_back(tolower(str[i]));
			j++;
		}
	}

	int len1 = str1.length();
	for (int i = 0; i < len1 / 2; i++)
	{
		if (str1[i] != str1[len1 - i - 1])
		{
			isPal = false;
			break;

		}
	}

	return isPal;
}