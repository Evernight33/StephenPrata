#include <iostream>
#include <new>
using namespace std;

const int BUF = 512;
const int N = 5;
char buf[BUF];

int main()
{
	double* pd1, *pd2;
	int i;

	cout << "Calling new and placement new:\n";
	pd1 = new double[N];
	pd2 = new(buf) double[N];
	for (int i = 0; i < N; i++)
	{
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	}
	cout << "Memory adress:\n" << "heap:" << pd1;
	cout << " static: " << (void*)buf << endl;
	cout << "Memory contents:\n";
	for (int i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}

	cout << "\nCalling new and placement new a second time:\n";
	double* pd3, * pd4;
	pd3 = new double[N];
	pd4 = new(buf) double[N];
	for (int i = 0; i < N; i++)
	{
		pd4[i] = pd3[i] = 1000 + 20.0 * i;
	}
	cout << "Memory contents:\n";
	for (int i = 0; i < N; i++)
	{
		cout << pd3[i] << " at " << &pd3[i] << "; ";
		cout << pd4[i] << " at " << &pd4[i] << endl;
	}

	cout << "\nCalling new and placement new a third time:\n";
	pd1 = new double[N];
	pd2 = new (buf + N * sizeof(double)) double[N];

	for (int i = 0; i < N; i++)
	{
		pd1[i] = pd2[i] = 1000 + 20.0 * i;
	}
	cout << "Memory contents:\n";
	for (int i = 0; i < N; i++)
	{
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	cout << endl;
	delete[] pd1;
	delete[] pd3;
	return 0;
}