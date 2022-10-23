#include <iostream>
using namespace std;

class Plorg
{
private:
	const char* name = new char[19];
	int ci;
public:
	Plorg(const char* n = "Plorga") : name(n), ci(50)
	{}
	void change_ci(int c)
	{
		ci = c;
	}
	void show()
	{
		cout << "Name: " << name;
		cout << "\nCI: " << ci << "\n";
	}
};

int main()
{
	Plorg p1;
	Plorg p2("Plorgius1488");
	p1.show();
	p2.show();
	p2.change_ci(1488);
	p2.show();
}