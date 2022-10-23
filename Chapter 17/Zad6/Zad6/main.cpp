#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "emh.h"

using namespace std;

const int MAX = 10;

void displayMenu()
{
	cout << "Select one of the following:" << endl;
	cout << left;
	cout << setw(20) << "a. Employee";
	cout << setw(20) << "b. Manager";
	cout << endl;
	cout << setw(20) << "c. Fink";
	cout << setw(20) << "d. Highfink";
	cout << endl;
	cout << "(q to quit)" << endl;
}

void eatline()
{
	char ch;
	while (cin.get(ch) && ch != '\n')
	{
		continue;
	}
}

int main()
{
	abstr_emp* pc[MAX];
	cout << "You may enter of to " << MAX << " employees" << endl;

	int count = 0;
	char ch;
	bool quit = false;
	ifstream fin;
	fin.open("employeeList.dat");

	if (fin.is_open())
	{
		int classtype = 0;
		while ((fin >> classtype).get(ch))
		{
			switch (classtype)
			{
				case abstr_emp::Employee:
					cout << "Creating an employee object: ";
					pc[count] = new employee;
					pc[count++]->get_all(fin);
					break;
				case abstr_emp::Manager:
					cout << "Creating a manager object: ";
					pc[count] = new manager;
					pc[count++]->get_all(fin);
					break;
				case abstr_emp::Fink:
					cout << "Creating a fink object: ";
					pc[count] = new fink;
					pc[count++]->get_all(fin);
					break;
				case abstr_emp::Highfink:
					cout << "Creating a high fink object: ";
					pc[count] = new highfink;
					pc[count++]->get_all(fin);
					break;
				default:
					cerr << "It looks like an error has been occured\n";
			}		
		}

		cout << "Here is your current list: ";
		for (int i = 0; i < count; i++)
		{
			pc[i]->ShowAll();
			cout << endl;
		}
		fin.close();
	}

	while (count < MAX)
	{
		displayMenu();
		cin >> ch;
		eatline();

		switch (ch)
		{
			case 'a':
				pc[count] = new employee();
				pc[count++]->SetAll();
				break;
			case 'b':
				pc[count] = new manager();
				pc[count++]->SetAll();
				break;
			case 'c':
				pc[count] = new fink();
				pc[count++]->SetAll();
				break;
			case 'd':
				pc[count] = new highfink();
				pc[count++]->SetAll();
				break;
			case 'q':
				quit = true;
				break;
			default:
				cout << "Wrong input\n";
				break;
		}
		if (quit == true)
		{
			quit = false;
			break;
		}
	}

	ofstream fout;
	fout.open("employeeList.dat");

	if (!fout.is_open())
	{
		cerr << "File wasn't open " << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Here is your updated list:\n";

	for (int i = 0; i < count; i++)
	{
		pc[i]->ShowAll();
		cout << endl;
		pc[i]->write_all(fout);
	}
	fout.close();
	return 0;
}