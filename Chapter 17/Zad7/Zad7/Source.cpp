#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Store
{
private:
	ofstream* pfout;
public:
	Store(ofstream& p_pfout)
	{
		pfout = &p_pfout;
	}
	~Store(){}
	Store& operator()(const string& str)
	{
		size_t len = str.length();
		char * temp = (char*)&len;
		pfout->write(temp, sizeof(size_t));
		pfout->write(str.data(), len);

		return *this;
	}
};

void ShowStr(const string str);
void GetStr(ifstream& fin, vector<string>& vistr);

int main()
{
	vector<string> vostr;
	string temp;

	cout << "Enter strings (empty lines to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
	{
		vostr.push_back(temp);
	}

	cout << "\nHere is your input: \n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	ofstream fout("strings.dat", ios_base::out | ios_base::binary);

	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	std::vector<string> visr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);

	if (!fin.is_open())
	{
		cerr << "Can't open a file :(\n";
		exit(EXIT_FAILURE);
	}

	GetStr(fin, visr);
	cout << "Here are string from the file:\n";
	for_each(visr.begin(), visr.end(), ShowStr);

	cin.get();
	cin.get();
	return 0;

}

void ShowStr(const string str)
{
	cout << str << endl;
}

void GetStr(ifstream& fin, vector<string>& vistr)
{
	size_t len = 0;
	char ch = 0;
	string str;

	while (fin.peek() && !fin.eof())
	{
		fin.read((char*)len, sizeof(size_t));
		for (int i = 0; i < len; i++)
		{
			fin.read((char*)ch, sizeof(char));
			str.push_back(ch);
		}
		vistr.push_back(str);
		str.clear();
	}
} 
