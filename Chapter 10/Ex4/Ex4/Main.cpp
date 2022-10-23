#include "Header.h"
int main()
{
	using namespace SALES;
	const int N = 3;
	double ar[N] = { 2.54, 3.45, 5.01 };
	Sales s1(ar, N);
	s1.showSales();
	Sales s2;
	s2.showSales();
	return 0;
}