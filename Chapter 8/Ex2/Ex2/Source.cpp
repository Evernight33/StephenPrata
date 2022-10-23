#include <iostream>
using namespace std;

struct CandyBar
{
	const char* name = new char[20];
	double wgt;
	int kal;
};

void Cbr(CandyBar& cb, const char* n = "Millenium Munch", double w = 2.85, int k = 350)
{
	cb.name = n;
	cb.wgt = w;
	cb.kal = k;
}

void Show(const CandyBar& cb)
{
	cout << "Candybar:\n";
	cout << "Name: " << cb.name << endl;
	cout << "Weight: " << cb.wgt << endl;
	cout << "Kkal: " << cb.wgt << "\n\n";
}

int main()
{
	CandyBar cb1, cb2, cb3;
	Cbr(cb1, "AFK", 2.78, 230);
	Show(cb1);
	Cbr(cb2, "Roshen", 3.29);
	Show(cb2);
	Cbr(cb3);
	Show(cb3);
}