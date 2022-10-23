#include "Header.h"
#include <cstring>

//absDMA methods
absDMA::absDMA(const char* l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy_s(label, strlen(l) + 1, l);
	rating = r;
}

absDMA::absDMA(const absDMA& rs)
{
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
}

absDMA::~absDMA()
{
	delete[] label;
}

absDMA& absDMA::operator=(const absDMA& rs)
{
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
	return *this;
}

ostream& operator<<(ostream& os, const absDMA& rs)
{
	os << "Label: " << rs.label << endl;
	os << "Rating: " << rs.rating << endl;
	return os;
}

void absDMA::Show() const
{
	std::cout << "Label: " << label << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}

//baseDMA methods
baseDMA::baseDMA(const char* l, int r) : absDMA(l, r)
{
	
}

baseDMA::baseDMA(const baseDMA& rs) : absDMA(rs)
{
	
}

baseDMA::~baseDMA()
{
	
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	absDMA::operator=(rs);
	return *this;
}

ostream& operator<<(ostream& os, const baseDMA& rs)
{
	os << (const baseDMA &) rs<< endl;
	return os;
}

void baseDMA::Show() const
{
	std::cout << "baseDMA object" << std::endl;
	absDMA::Show();
}

// lacksDMA methods
lacksDMA::lacksDMA(const char* c, const char* l, int r) : absDMA(l, r)
{
	strncpy_s(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

ostream& operator<<(ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;
	os << "Colos: " << ls.color << endl;
	return os;
}

void lacksDMA::Show() const
{
	std::cout << "lacksDMA object" << std::endl;
	absDMA::Show();
	std::cout << "Color: " << color << std::endl;
}

// hasDMA methods
hasDMA::hasDMA(const char* s, const char* l, int r) : absDMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const char* s, const baseDMA& rs) : absDMA(rs)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const hasDMA& rs) : absDMA(rs)
{
	style = new char[strlen(rs.style) + 1];
	strcpy_s(style, strlen(rs.style) + 1, rs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;
	delete[] style;
	absDMA::operator=(hs);
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
	style = hs.style;
	return *this;
}

void hasDMA::Show() const
{
	std::cout << "hasDMA object" << std::endl;
	absDMA::Show();
	std::cout << "Style: " << style << std::endl;
}

ostream& operator<< (ostream& os, const hasDMA& rs)
{
	os << (const baseDMA&)rs;
	os << "Style: " << rs.style << endl;
	return os;
}
