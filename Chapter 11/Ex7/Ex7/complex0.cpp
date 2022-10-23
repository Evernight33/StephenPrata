#include "complex0.h"

Complex0::Complex0() : n1(0.0), n2(0.0)
{}

Complex0::Complex0(double x, double y) : n1(x), n2(y)
{}

Complex0& Complex0::operator+(Complex0 a)
{
	n1 += a.n1;
	n2 += a.n1;
	return *this;
}

Complex0& Complex0::operator-(Complex0 a)
{
	n1 -= a.n1;
	n2 -= a.n1;
	return *this;
}

Complex0& Complex0::operator*(Complex0 a)
{
	n1 = n1 * a.n1 - n1 * a.n2;
	n2 = n1 * a.n1 + n1 * a.n2;
	return *this;
}

Complex0 operator*(double num, Complex0 a)
{
	a.n1 *= num;
	a.n2 *= num;
	return a;
}

Complex0& Complex0::operator~()
{
	n2 = -n2;
	return *this;
}

ostream& operator<<(ostream& os, Complex0 a)
{
	os << "( " << a.n1 << ", " << a.n2 << ")" << endl;
	return os;
}

istream& operator>>(istream& os, Complex0& a)
{
	os >> a.n1;
	os >> a.n2;
	return os;
}