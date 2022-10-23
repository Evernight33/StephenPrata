#ifndef HEADER_H
#define HEADER_H

#include <iostream>
using namespace std;

class CD
{
private:
	char* performers;
	char* label;
	int selections;
	double playtime;
public:
	CD(const char* s1, const char* s2, int n, double x);
	CD(const CD& d);
	CD();
	virtual ~CD();
	virtual void Report() const;
	CD& operator= (const CD& d);
};

class Classic : public CD
{
private:
	char* main;
public:
	Classic(const char* s1, const char* s2, const char* s3, int n, double x);
	Classic(const Classic& d);
	Classic();
	virtual void Report() const;
	virtual ~Classic();
	Classic& operator= (const Classic& d);
};

#endif