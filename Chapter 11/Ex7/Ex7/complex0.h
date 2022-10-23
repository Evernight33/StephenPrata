#include <iostream>
using namespace std;

class Complex0
{
private:
	double n1;
	double n2;
public:
	Complex0();
	Complex0(double x, double y);
	Complex0& operator+(Complex0 a);
	Complex0& operator-(Complex0 a);
	Complex0& operator*(Complex0 a);
	Complex0& operator~();
	friend Complex0 operator*(double num, Complex0 a);
	friend ostream& operator<<(ostream& os, Complex0 a);
	friend istream& operator>>(istream& os, Complex0& a);
};