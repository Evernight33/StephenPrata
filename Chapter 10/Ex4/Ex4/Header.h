#ifndef HEAD
#define HEAD

#include <iostream>
using namespace std;

namespace SALES
{
	const int QUARTERS = 4;

	class Sales
	{
	private:
		double sales[QUARTERS];
		double average = 0;
		double max;
		double min;
	public:
		Sales();
		Sales(const double ar[], int n);
		void showSales();
	};
}

#endif // !HEAD

