#include "namesp.h";

void other(void);
void another(void);

int main()
{
	using debts::Debt;
	using debts::showDebt;
	Debt golf = { {"Benny", "Goatsniff"}, 120.0 };
	showDebt(golf);
	other();
	another();

	return 0;
}

void other()
{
	using namespace debts;
	Person dg = { "Doodles", "Glister" };
	showPerson(dg);
	cout << endl;
	Debt zippy[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		getDebt(zippy[i]);
	}

	for (i = 0; i < 3; i++)
	{
		showDebt(zippy[i]);
		cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
	}
}

void another()
{
	using person::Person;
	Person collector = { "Milo", "Rightshift" };
	person::showPerson(collector);
	cout << endl;
}