#include <iostream>
using namespace std;

template<typename T>
auto func(T ar[]) -> decltype(ar[0])
{
	T max = ar[0];
	for (int i = 1; i < 5; i++)
	{
		if (ar[i] > max)
		{
			max = ar[i];
		}
	}
	return max;
}

int main()
{
	double ar1[] = { 4.56, 3.78, 1.34, 8.45, 6.43 };
	double ar2[] = { 3, 7, 8, 4, 5 };
	cout << "ar1 MAX element: " << func(ar1) << endl;
	cout << "ar2 MAX element: " << func(ar2) << endl;
}