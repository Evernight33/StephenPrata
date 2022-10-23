#include "Header.h"

abstr_emp::abstr_emp()
{
	fname = "";
	lname = "";
	job = "";
}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j) : fname(fn), lname(ln), job(j)
{

}

void abstr_emp::ShowAll() const
{
	cout << "First name: " << fname << endl;
	cout << "Last name: " << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter first name:\n";
	cin >> fname;
	while (cin.get() != '\n')
	{
		continue;
	}

	cout << "Enter last name:\n";
	cin >> lname;
	while (cin.get() != '\n')
	{
		continue;
	}

	cout << "Enter job:\n";
	cin >> job;
	while (cin.get() != '\n')
	{
		continue;
	}
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << e.fname << ", " << e.lname << endl;
	return os;
}

abstr_emp::~abstr_emp()
{

}

//employee methods
employee::employee() : abstr_emp()
{

}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j) : abstr_emp(fn, ln, j)
{

}
void employee::ShowAll() const
{
	cout << "Status employee\n";
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

// manager methods
manager::manager() : abstr_emp()
{
	inchargeof = 0;
}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) : abstr_emp(fn, ln, j)
{
	inchargeof = ico;
	if (inchargeof < 0)
	{
		std::cout << "Error, cannot be in charge of negative people." << std::endl;
		std::cout << "Setting inchargeof to 0" << std::endl;
		inchargeof = 0;
	}
}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e)
{
	inchargeof = ico;
	if (inchargeof < 0)
	{
		std::cout << "Error, cannot be in charge of negative people." << std::endl;
		std::cout << "Setting inchargeof to 0" << std::endl;
		inchargeof = 0;
	}
}

manager::manager(const manager& m) : abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void manager::ShowAll() const
{
	cout << "Status: manager" << endl;
	abstr_emp::ShowAll();
	cout << "In charge of " << inchargeof << "people" << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter the number of people the manager is in charge of: ";
	cin >> inchargeof;


	if (inchargeof < 0)
	{
		std::cout << "Error, cannot be in charge of negative people." << std::endl;
		std::cout << "Setting inchargeof to 0" << std::endl;
		inchargeof = 0;
	}
}

fink::fink() : abstr_emp()
{
	reportsto = "";
}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) : abstr_emp(fn, ln, j)
{
	reportsto = rpo;
}

fink::fink(const abstr_emp& e, const std::string& rpo) : abstr_emp(e)
{
	reportsto = rpo;
}

fink::fink(const fink& e) : abstr_emp(e)
{
	reportsto = "";
}

void fink::ShowAll() const
{
	cout << "Status: fink" << endl;
	abstr_emp::ShowAll();
	cout << "Reportsto: " << reportsto << endl;
}

void fink::SetAll() 
{
	abstr_emp::SetAll();
	cout << "Enter whomever is reported to\n";
	getline(cin, reportsto);
}

//hightfink
highfink::highfink() : abstr_emp(), manager(), fink()
{

}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico) 
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{

}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo)
{

}

highfink::highfink(const fink& f, int ico) : abstr_emp(f), manager(f, ico), fink(f)
{

}

highfink::highfink(const manager& m, const std::string& rpo) : abstr_emp(m), manager(m), fink(m, rpo)
{

}

highfink::highfink(const highfink& h) : abstr_emp(h), manager(h), fink(h)
{

}

void highfink::ShowAll() const
{
	cout << "Status hightfink" << endl;
	abstr_emp::ShowAll();
	cout << "In charge of" << InChargeOf() << " people" << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter the number of people managed: ";
	cin >> InChargeOf();

	if (InChargeOf() < 0)
	{
		std::cout << "Error, cannot be in charge of negative people." << std::endl;
		std::cout << "Setting inchargeof to 0" << std::endl;
		InChargeOf() = 0;
	}

	cin.get();
	cout << "Enter whomever is reported to:\n";
	getline(cin, ReportsTo());
}