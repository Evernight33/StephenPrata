#ifndef EMP_H
#define EMP_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class abstr_emp
{
private:
	string fname;
	string lname;
	string job;
public:
	enum classkind{Employee, Manager, Fink, Highfink};
	abstr_emp();
	abstr_emp(const string& fn, const string& ln, const string& j);
	virtual void ShowAll() const;
	virtual void SetAll();
	friend ostream& operator<<(ostream& os, const abstr_emp& e);

	virtual ~abstr_emp() = 0;
	virtual void write_all(ofstream& ofs) const;
	virtual void get_all(ifstream& ifs);
};

class employee : public abstr_emp
{
public:
	employee();
	employee(const string& fn, const string& ln, const string& j);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void write_all(ofstream& ofs) const;
	virtual void get_all(ifstream& ifs);
};

class manager : public virtual abstr_emp
{
private:
	int inchargeof;
protected:
	int InChargeOf() const
	{
		return inchargeof;
	}

	int& InChargeOf()
	{
		return inchargeof;
	}
public:
	manager();
	manager(const string& fn, const string& ln, const string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void write_all(ofstream& ofs) const;
	virtual void get_all(ifstream& ifs);
};

class fink : public virtual abstr_emp
{
private:
	string reportsto;
protected:
	string ReportsTo() const
	{
		return reportsto;
	}

	string& ReportsTo()
	{
		return reportsto;
	}
public:
	fink();
	fink(const string& fn, const string& ln, const string& j, string reps);
	fink(const abstr_emp& e, string& reps);
	fink(const fink& f);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void write_all(ofstream& ofs) const;
	virtual void get_all(ifstream& ifs);
};

class highfink : public manager, public fink
{
public:
	highfink();
	highfink(const string& fn, const string& ln, const string& j, string reps, int ico = 0);
	highfink(const abstr_emp& e, string& reps, int ico = 0);
	highfink(const fink& f, int ico);
	highfink(const highfink& h);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void write_all(ofstream& ofs) const;
	virtual void get_all(ifstream& ifs);
};

#endif