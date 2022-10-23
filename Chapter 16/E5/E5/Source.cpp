#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
using namespace std;

const int SIZE = 15;
//-------------------------------------------------------------------------------------------------
template<class T>
int reduce(T ar[], int n);

template <>
int reduce<string>(string ar[], int r);

template<class T>
int data_input(T ar[]);

template<>
int data_input<string>(string ar[]);

template<typename T>
void display(T ar[], int begin, int end);

bool string_compare(std::string s1, std::string s2);
//-------------------------------------------------------------------------------------------------

int main()
{
	cout << "Would you like to enter string or integers? (i fir int; s for string):\n";
	char ch;
	cin.get(ch);
	ch = tolower(ch);

	if (ch != 's' & ch != 'i')
	{
		cout << "Input should be \"s\" or \"i\"\n";
		cout << "Programm abort\n";
		exit(EXIT_FAILURE);
	}

	if (ch == 's')
	{
		string sar[SIZE];
		int values = data_input(sar);

		if (values == 0)
		{
			cout << "No values were entered\n";
			return 0;
		}

		cout << "You entered ";
		display(sar, 0, values);

		cout << "Here is your sorted array, without duplicates:\n";
		int val2 = reduce(sar, values);
		display(sar, 0, val2);
	}
	else
	{
		int sar[SIZE];
		int values = data_input(sar);

		if (values == 0)
		{
			cout << "No values were entered\n";
			return 0;
		}

		cout << "You entered ";
		display(sar, 0, values);

		cout << "Here is your sorted array, without duplicates:\n";
		int val2 = reduce(sar, values);
		display(sar, 0, val2);
	}

}

template <class T>
int reduce(T ar[], int r)
{
	vector<int> var;

	for (int i = 0; i < r; i++)
	{
		var.push_back(ar[i]);
	}

	sort(var.begin(), var.begin() + r);

	vector<int>::iterator end = unique(var.begin(), var.end());
	var.erase(end, var.end());
	vector<int>::iterator iv = var.begin();

	for (int i = 0; iv != var.end(); iv++, i++)
	{
		ar[i] = *iv;
	}

	return var.size();
}

template <>
int reduce(string ar[], int r)
{
	vector<string> var;

	for (int i = 0; i < r; i++)
	{
		var.push_back(ar[i]);
	}

	sort(var.begin(), var.end(), string_compare);

	vector<string>::iterator end = unique(var.begin(), var.end());
	var.erase(end, var.end());
	vector<string>::iterator iv = var.begin();

	for (int i = 0; iv != var.end(); iv++, i++)
	{
		ar[i] = *iv;
	}

	return var.size();
}

template<class T>
int data_input(T ar[])
{
	std::cout << "Enter up to " << SIZE << " numbers (quit to quit):";

	int i = 0;
	int num;

	while (std::cin >> num && i < SIZE)
	{
		ar[i++] = num;
	}

	return i;
}

template<> 
int data_input(string ar[])
{
	std::cout << "Enter up to " << SIZE << " strings (quit to quit):";

	int i = 0;
	string str;

	while (std::cin >> str && str != "quit")
	{
		ar[i++] = str;
	}

	return i;
}

template<typename T>
void display(T ar[], int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl;
}

bool string_compare(std::string s1, std::string s2)
{
	transform(s1.begin(), s1.end(), s1.begin(), tolower);
	transform(s2.begin(), s2.end(), s2.begin(), tolower);
	return s1 < s2;
}