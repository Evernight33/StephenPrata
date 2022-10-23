#include "Header.h"

//CD methods
CD::CD(const char* s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	label = new char[strlen(s2) + 1];
	strcpy_s(performers, strlen(s1) + 1, s1);
	strcpy_s(label, strlen(s2) + 1, s2);
	selections = n;
	playtime = x;
}

CD::CD()
{
	performers = new char[5];
	label = new char[5];
	strcpy_s(performers, 5, "None");
	strcpy_s(label, 5, "None");
	selections = 0;
	playtime = 0;
}

CD::CD(const CD& d)
{
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, d.label);
	selections = 0;
	playtime = 0;
}

void CD::Report() const
{
	cout << "Performs: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Selection: " << selections << endl;
	cout << "Playtime: " << playtime << endl << endl;
}

CD& CD::operator= (const CD& d)
{
	if (this == &d)
		return *this;
	delete[]  performers;
	delete[]  label;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, d.label);
	selections = 0;
	playtime = 0;
	return *this;
}

CD::~CD()
{
	delete performers;
	delete label;
}

// Classic methods
Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x) : CD(s1, s2, n, x)
{
	main = new char[strlen(s3) + 1];
	strcpy_s(main, strlen(s3) + 1, s3);
}

Classic::Classic(const Classic& d) : CD(d)
{
	main = new char[strlen(d.main) + 1];
	strcpy_s(main, strlen(d.main) + 1, d.main);
}

void Classic::Report() const
{
	CD::Report();
	cout << "Main: " << main << endl << endl;
}

Classic::Classic()
{
	main = new char[5];
	strcpy_s(main, 5, "None");
}

Classic& Classic::operator= (const Classic& d)
{
	if (this == &d)
		return *this;
	CD::operator=(d);
	delete[] main;
	main = new char[strlen(d.main) + 1];
	strcpy_s(main, strlen(d.main) + 1, d.main);
	return *this;
}

Classic::~Classic()
{
	delete main;
}