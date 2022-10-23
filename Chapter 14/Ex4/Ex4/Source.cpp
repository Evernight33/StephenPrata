#include "Header.h"

//Person
Person::Person(const std::string& n, const std::string& s) : name(n), surname(s)
{

}

void Person::Data() const
{
	cout << "First name: " << name << endl;
	cout << "Last name: " << surname << endl;
}

void Person::Show() const
{
	cout << "Type person:\n";
	Data();
}

void Person::Set()
{
	cout << "First name:\n";
	getline(cin, name);
	cout << "Last name:\n";
	getline(cin, surname);
}

//Sniper
void Sniper::Data() const
{
	cout << "Draw time: " << drawtime;
	cout << "\nCount: " << count << endl;
}

void Sniper::SetData()
{
	cout << "Enter the draw time:\n";
	cin >> drawtime;
	while (!cin || drawtime < 0)
	{
		cin.clear();
		cout << "Draw time must be a positive number, try again\n";
		cin >> drawtime;
	}

	cout << "Enter the number of notches:\n";
	cin >> count;
	while (!cin || drawtime < 0)
	{
		cin.clear();
		cout << "Notches number must be a positive number, try again\n";
		cin >> count;
	}
}

Sniper::Sniper(const std::string& n, const std::string& s, double dr, int cnt) : Person(n, s)
{
	count = cnt;
	drawtime = dr;
}

void Sniper::SetDrawTime(double d)
{
	if (d < 0)
	{
		cerr << "Error, draw time cannot be negative\n";
		cerr << "Setting draw time to null\n";
		drawtime = 0;
	}
	else 
	{
		drawtime = d;
	}
}


void Sniper::SetCount(int c)
{
	if (c < 0)
	{
		cerr << "Error, count cannot be negative\n";
		cerr << "Setting draw time to null\n";
		count = 0;
	}
	else
	{
		count = c;
	}
}

void Sniper::Show() const
{
	cout << "Type Sniper" << endl;
	Person::Data();
	Data();
}

//PockerPlayer
PokerPlayer::PokerPlayer(std::string n, std::string s) : Person(n, s)
{}

void PokerPlayer::Show() const
{
	cout << "Type PokerPlayer\n";
	Data();
}

//badDude
BadDude::BadDude(std::string n, std::string s, double dr, int cnt) : Person(n, s), Sniper(n, s, dr, cnt), PokerPlayer(n, s)
{

}

void BadDude::Show() const
{
	std::cout << "Type BadDude" << std::endl;
	Person::Data();
	Sniper::Data();
	PokerPlayer::Data();
}
//-------------------------------------------------------------------------------------------------
void BadDude::Set()
{
	Person::Set();
	Sniper::SetData();
}