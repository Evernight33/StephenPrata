#include <iostream>
#include <string>
using namespace std;

namespace person
{
	struct Person
	{
		string fname;
		string lname;
	};
	void getPerson(Person&);
	void showPerson(const Person&);
}

namespace debts
{
	using namespace person;
	struct Debt
	{
		Person name;
		double amount;
	};
	void getDebt(Debt&);
	void showDebt(const Debt&);
	double sumDebts(const Debt ar[], int n);
}