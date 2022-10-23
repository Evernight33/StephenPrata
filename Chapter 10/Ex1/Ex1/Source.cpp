#include <iostream>
using namespace std;

class BankAkk
{
private:
	const char* name;
	string acc_n;
	int bal;
public:
	BankAkk()
	{
		name = "Not defined";
		acc_n[0] = '\0';
		bal = 0;
	}
	BankAkk(const char* n, string acN, int b) : name(n),  acc_n(acN), bal(b)
	{
		
	}
	void show()
	{
		cout << "Account holder's name: " << name;
		cout << "\nAccount number: " << acc_n;
		cout << "\nBalance: " << bal << "$\n\n";
	}
	void add_sum(int s)
	{
			bal += s;
	}
	void ass_m(int s)
	{
			bal -= s;
	}
};

int main()
{
	BankAkk b1("Ilia Radkevich", "45456", 134678);
	b1.show();
	b1.add_sum(456);
	b1.show();
	b1.ass_m(567);
	b1.show();
	b1.add_sum(456);
	b1.show();
	
}
