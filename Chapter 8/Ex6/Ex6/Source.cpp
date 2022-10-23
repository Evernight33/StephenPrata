#include <iostream>
using namespace std;

template<typename T>
T func(T ar[], int n)
{
	T max = ar[0];
	for (int i = 1; i < n; i++)
	{
		if (ar[i] > max)
		{
			max = ar[i];
		}
	}
	return max;
}

const char* func(const char* ar[], int n)
{
	const char* max = &ar[0][0];
	int ms = strlen(ar[0]);
	int next = 0;
	for (int i = 1; i < n; i++)
	{
		next = strlen(ar[i]);
		if (next > ms)
		{
			ms = next;
			max = &ar[i][0];
		}
	}
	return max;
} 

int main()
{
	double ar1[] = { 4.56, 3.78, 1.34, 8.45, 6.43 };
	double ar2[] = { 3, 7, 8, 4};
	const char* ar[5] = { "Bread", "BrokeBoy", "Milk", "Gucci", "Omg" };
	cout << "ar1 MAX element: " << func(ar1, 5) << endl;
	cout << "ar2 MAX element: " << func(ar2, 4) << endl;
	cout << "ar MAX element: " << func(ar, 5) << endl;

}