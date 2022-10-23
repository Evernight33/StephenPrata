#include "emh.h"

abstr_emp::abstr_emp()
{
	fname = "";
	lname = "";
	job = "";
}

abstr_emp::abstr_emp(const string& fn, const string& ln, const string& j)
	:fname(fn),
	lname(ln),
	job(j)
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
	cout << "Enter first name: ";
	cin >> fname;

	while (cin.get() != '\n')
	{
		continue;
	}

	cout << "Enter last name: ";
	cin >> lname;

	while (cin.get() != '\n')
	{
		continue;
	}

	cout << "Enter the job: ";
	getline(cin, job);
}

ostream& operator<<(ostream& os, const abstr_emp& e)
{
	os << e.lname << ", " << e.fname << endl;
	return os;
}


void abstr_emp::write_all(ofstream& ofs) const
{
	ofs << "Firts name: " << fname << endl;
	ofs << "Last name: " << lname << endl;
	ofs << "Job: " << job << endl;
}

void abstr_emp::get_all(ifstream& ifs)
{
	ifs.ignore(256, ':');
	while (ifs.peek() == ' ')
	{
		ifs.get();
	}
	getline(ifs, fname);
	cout << "First name is: " << fname << endl;

	ifs.ignore(256, ':');
	while (ifs.peek() == ' ')
	{
		ifs.get();
	}
	getline(ifs, lname);
	cout << "Last name is: " << lname << endl;

	ifs.ignore(256, ':');
	while (ifs.peek() == ' ')
	{
		ifs.get();
	}
	getline(ifs, job);
	cout << "Job: " << job << endl;
}

abstr_emp::~abstr_emp()
{

}

/**************************************************************************/

employee::employee()
{

}

employee::employee(const string& fn, const string& ln, const string& j)
	: abstr_emp(fn, ln, j)
{

}

void employee::ShowAll() const
{
	cout << "Status: Employee" << endl;
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

void employee::write_all(ofstream& ofs) const
{
	ofs << abstr_emp::classkind::Employee << endl;
	abstr_emp::write_all(ofs);
}

void employee::get_all(ifstream& ifs)
{
	abstr_emp::get_all(ifs);
}

/**************************************************************************/

manager::manager() 
	: abstr_emp(), 
	inchargeof(0)
{

}

manager::manager(const string& fn, const string& ln, const string& j, int ico)
	: abstr_emp(fn, ln, j)
{
	if (ico < 0)
	{
		cout << "Error, cannot be in charge of negative people" << endl;
		cout << "Setting inchargeof to 0\n";
		inchargeof = 0;
	}
	else
	{
		inchargeof = ico;
	}
}

manager::manager(const abstr_emp& e, int ico)
	: abstr_emp(e)
{
	if (ico < 0)
	{
		cout << "Error, cannot be in charge of negative people" << endl;
		cout << "Setting inchargeof to 0\n";
		inchargeof = 0;
	}
	else
	{
		inchargeof = ico;
	}
}

manager::manager(const manager& m)
	:abstr_emp(m)
{

}

void manager::ShowAll() const
{
	cout << "Status: manager\n";
	abstr_emp::ShowAll();
	cout << "In charge of " << inchargeof << " people" << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter the number of people the manager is in charge of: ";
	cin >> inchargeof;
	if (inchargeof < 0)
	{
		cout << "Error, cannot be in charge of negative people" << endl;
		cout << "Setting inchargeof to 0\n";
		inchargeof = 0;
	}
}

void manager::write_all(ofstream& ofs) const
{
	ofs << abstr_emp::Manager << endl;
	abstr_emp::write_all(ofs);
	ofs << "Number of people managed: " << inchargeof << endl;
}

void manager::get_all(ifstream& ifs)
{
	abstr_emp::get_all(ifs);
	ifs.ignore(256, ':');
	ifs >> inchargeof;
	ifs.get();
}

/**************************************************************************/

fink::fink()
	: abstr_emp(),
	reportsto("")
{

}

fink::fink(const string& fn, const string& ln, const string& j, string reps)
	: abstr_emp(fn, ln, j), reportsto(reps)
{

}

fink::fink(const abstr_emp& e, string& reps)
	: abstr_emp(e), reportsto(reps)
{
	
}

fink::fink(const fink& f)
	: abstr_emp(f)
{
	reportsto = f.reportsto;
}

void fink::ShowAll() const
{
	cout << "Status: fink\n";
	abstr_emp::ShowAll();
	cout << "Reports to " << reportsto << " people" << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter whomever is reported to: ";
	getline(cin, reportsto);
}

void fink::write_all(ofstream& ofs) const
{
	ofs << abstr_emp::Fink << endl;
	abstr_emp::write_all(ofs);
	ofs << "Reports to: " << reportsto << endl;
}

void fink::get_all(ifstream& ifs)
{
	abstr_emp::get_all(ifs);
	ifs.ignore(256, ':');
	getline(ifs, reportsto);
}

/**************************************************************************/

highfink::highfink()
	: abstr_emp(),
	manager(),
	fink()
{

}

highfink::highfink(const string& fn, const string& ln, const string& j, string reps, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, reps)
{

}

highfink::highfink(const abstr_emp& e, string& reps, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, reps)
{

}

highfink::highfink(const fink& f, int ico)
	: abstr_emp(f), manager(f, ico), fink()
{
	
}


highfink::highfink(const highfink& h)
	: abstr_emp(h), manager(h), fink(h)
{

}

void highfink::ShowAll() const
{
	cout << "Status: Highfink\n";
	abstr_emp::ShowAll();
	cout << "Reports to " << ReportsTo() << "people" << endl;
	cout << "In charge of " << InChargeOf() << " people" << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	;

	cout << "Enter the number of people the manager is in charge of: ";
	cin >> InChargeOf();
	if (InChargeOf() < 0)
	{
		cout << "Error, cannot be in charge of negative people" << endl;
		cout << "Setting inchargeof to 0\n";
		InChargeOf() = 0;
	}

	cin.get();
	cout << "Enter whomever is reported to: ";
	getline(cin, ReportsTo());
}

void highfink::write_all(ofstream& ofs) const
{
	ofs << abstr_emp::Highfink << endl;
	abstr_emp::write_all(ofs);
	ofs << "Reports to: " << ReportsTo() << endl;
	ofs << "Number of people managed: " << InChargeOf() << endl;
}

void highfink::get_all(ifstream& ifs)
{
	abstr_emp::get_all(ifs);
	ifs.ignore(256, ':');
	ifs >> InChargeOf();
	ifs.get();
	ifs.ignore(256, ':');
	getline(ifs, ReportsTo());
}
