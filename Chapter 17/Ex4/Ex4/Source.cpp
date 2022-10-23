#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		cerr << "Error, Two arguments representing filenames are missing" << endl;
		exit(EXIT_FAILURE);
	}
	else if (argc > 4)
	{
		cerr << "Too many arguments, only first two arguments will be used" << endl;
	}

	cout << "Warning: this will erase the content of " << argv[3];
	cout << "\nProceed? (y/n) ";

	char ch;
	cin >> ch;

	if (ch != 'y' && ch != 'Y')
	{
		return 0;
	}
	else
	{
		ifstream infile1;
		infile1.open(argv[1]);

		if (!infile1.is_open())
		{
			cerr << "Error, could not open " << argv[1] << endl;
			exit(EXIT_FAILURE);
		}

		ifstream infile2;
		infile2.open(argv[2]);

		if (!infile2.is_open())
		{
			cerr << "Error, could not open " << argv[2] << endl;
			exit(EXIT_FAILURE);
		}

		ofstream outfile1;
		outfile1.open(argv[3]);

		if (!outfile1.is_open())
		{
			cerr << "Error, could not open " << argv[3] << endl;
			exit(EXIT_FAILURE);
		}

		while (!infile1.eof() && !infile2.eof())
		{
			while (infile1.get(ch) && ch != '\n')
			{
				outfile1.put(ch);
			}

			outfile1.put(' ');

			while (infile2.get(ch) && ch != '\n')
			{
				outfile1.put(ch);
			}

			outfile1.put('\n');
			infile1.peek();
			infile1.peek();
		}
		
		if (infile1.eof() && !infile2.eof())
		{
			while (infile2.get(ch) && ch != '\n')
			{
				outfile1.put(ch);
			}
			outfile1.put('\n');
		}

		else if (!infile1.eof() && infile2.eof())
		{
			while (infile1.get(ch) && ch != '\n')
			{
				outfile1.put(ch);
			}
			outfile1.put('\n');
		}
		infile1.close();
		infile2.close();
		outfile1.close();
	}
	cin.get();
	cin.get();
	return 0;
}