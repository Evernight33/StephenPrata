#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

void check(ifstream& infile, string filename);
void check(ofstream& infile, string filename);
bool stringEqual(string s1, string s2);
bool stringCompare(string s1, string s2);

int main()
{
	ifstream patfile("pat.dat");
	ifstream matfile("mat.dat");
	ofstream patnmat("patnmat.dat");

	check(patfile, "pat.dat");
	check(matfile, "mat.dat");
	check(patnmat, "patnmat.dat");

	string name;
	vector<string> patlist;
	vector<string> matlist;

	while (getline(patfile, name) && name != "")
	{
		patlist.push_back(name);
	}

	while (getline(matfile, name) && name != "")
	{
		matlist.push_back(name);
	}

	vector<string> matnpat_list;
	back_insert_iterator<vector<string>> i_iter(matnpat_list);

	copy(patlist.begin(), patlist.end(), i_iter);
	copy(matlist.begin(), matlist.end(), i_iter);

	sort(matnpat_list.begin(), matnpat_list.end(), stringCompare);
	vector<string>::iterator iter = unique(matnpat_list.begin(), matnpat_list.end(), stringEqual);
	matnpat_list.erase(iter, matnpat_list.end());

	ostream_iterator<string> os_iter(cout, "\n");
	ostream_iterator<string> os_file_iter(patnmat, "\n");

	cout << "Here is your list of guests:\n";
	copy(matnpat_list.begin(), matnpat_list.end(), os_iter);
	cout << endl;

	cout << "Here is your list of guests:\n";
	copy(matnpat_list.begin(), matnpat_list.end(), os_file_iter);

	cout << endl;

	return 0;
}

void check(ifstream& infile, string filename)
{
	if (!infile.is_open())
	{
		cerr << "Error, cannot open " << filename << endl;
		exit(EXIT_FAILURE);
	}
}

void check(ofstream& infile, string filename)
{
	if (!infile.is_open())
	{
		cerr << "Error, cannot open " << filename << endl;
		exit(EXIT_FAILURE);
	}
}

bool stringCompare(string s1, string s2)
{
	transform(s1.begin(), s1.end(), s1.begin(), tolower);
	transform(s2.begin(), s2.end(), s2.begin(), tolower);

	return s1 < s2;
}

bool stringEqual(string s1, string s2)
{
	transform(s1.begin(), s1.end(), s1.begin(), tolower);
	transform(s2.begin(), s2.end(), s2.begin(), tolower);
	return s1 == s2;
}
