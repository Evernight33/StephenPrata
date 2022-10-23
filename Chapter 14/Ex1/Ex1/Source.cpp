#include "Header.h"

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) : string(l), PairArray(Arrayint(y), Arrayint(y))
{
	year = y;

	for (int i = 0; i < year; i++)
	{
		PairArray::first[i] = yr[i];
		PairArray::second[i] = bot[i];
	}
}

Wine::Wine(const char* l, int y) : PairArray(Arrayint(y), Arrayint(y)), year(y)
{
	PairArray::first.resize(y);
	PairArray::second.resize(y);
}

Wine::~Wine()
{

}

void Wine::Show() const 
{
	cout << "Wine: " << (const string&)(*this) << endl;
	cout << "\tYear\tBottles" << endl;

	for (int i = 0; i < year; i++)
	{
		cout << "\t" << PairArray::first[i] << "\t";
		cout << PairArray::second[i] << endl;
	}
}

const string& Wine::Label() const
{
	return (const string&)*this;
}

void Wine::GetBottles()
{
	cout << "Enter " << (const string&)*this << " data for " << year << "year(s):\n";
	int inp = 0;

	for (int i = 0; i < year; i++)
	{
		cout << "Enter year: ";
		cin >> inp;
		PairArray::first[i] = inp;
		cout << "Enter bottles for that year\n";
		cin >> inp;
		PairArray::second[i] = inp;
		cout << endl;
	}
}

int Wine::Sum() const
{
	int sum = 0;
	for (int i = 0; i < year; i++)
	{
		sum += PairArray::second[i];
	}
	return sum;
}