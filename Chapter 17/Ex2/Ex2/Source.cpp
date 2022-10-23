#include <iostream>
#include <fstream>
#include <cstdlib>


int main(int argc, char* argv[])
{
	using namespace std;

	if (argc == 1)
	{
		cerr << "Error, a filename must be an argument of the command line.";
		cerr << endl;
		exit(EXIT_FAILURE);
	}

	else if (argc > 2)
	{
		cout << "Arguments on the command line beyond the firts are ignored";
		cout << endl;
	}

	ofstream outfile;
	outfile.open(argv[1]);

	if (!outfile.is_open())
	{
		cerr << "Error, file wasn't open" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Enter input (cntrl-D when done):";

	char ch;

	while (cin.get(ch))
	{
		outfile.put(ch);
	}

	if (!outfile.eof())
	{
		cerr << "Warning, input quit due to something other than ";
		cerr << "Simulated eof" << endl;
	}

	outfile.close();

	cin.get();
	cin.get();

	return 0;
}