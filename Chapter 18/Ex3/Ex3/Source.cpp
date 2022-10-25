#include <iostream>
#include <iomanip>
using namespace std;

template <typename T, typename... Args>
long double SumValues(const T& value, const Args&... args);

int main()
{
	cout << "SumValues 1:\t" << SumValues(5, 4.5, 2, 8, 1.22);
	cout << "\nSumValues 2:\t" << setprecision(6) << SumValues(false, 3, 2.8945, 2.34, 6, 8.34) << "\n\n";
}

long double SumValues()
{
	return 0.0;
}

template <typename T, typename... Args>
long double SumValues(const T& value, const Args&... args)
{
	long double sum = 0;
	sum = value + SumValues(args...);

	return sum;
}