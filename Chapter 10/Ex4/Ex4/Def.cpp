#include "Header.h"
using namespace SALES;

// �������� ������� �������� �� 4 ��� n ��������� �� �������
	// ar � ���� sales ��������� s, ��������� � ���������
	// ������� �������������� , ������������ � �����������
	// �������� ��������� �����;
	// ���������� �������� sales, ���� ������� ����, ��������������� � �

SALES::Sales::Sales(const double ar[], int n)
{
	int i;
	min = ar[0];
	max = ar[0];
	for (i = 0; i < n; i++)
	{
		sales[i] = ar[i];
		average += ar[i];

		if (sales[i] < min)
			min = sales[i];
		else if (sales[i] > max)
			max = sales[i];
	}
	if (n < 4)
	{
		for (i = n; i < 4; i++)
		{
			sales[i] = 0;
			average += sales[i];
		}
	}
	average /= 4;
}

// ������������ ������������ ������� �� 4 �������� ,
	// ��������� �� � ����� sales ��������� s, ��������� �
		// ��������� ������� ��������������, � ����� ��������� ���
		// � ����������� �������� ��������� �����
SALES::Sales::Sales()
{
	for (int i = 0; i < 4; i++)
	{
		cout << "Enter sales in quarter " << i + 1 << ": ";
		cin >> sales[i];
		if (i == 0)
		{
			min = sales[i];
			max = sales[i];
		}
		average += sales[i];
		if (sales[i] < min)
			min = sales[i];
		if (sales[i] > max)
			max = sales[i];
	}
	average /= 4;
}

// ���������� ��� ���������� �� ��������� s
void SALES::Sales::showSales()
{
	cout << "Min = " << min << endl;
	cout << "Max = " << max << endl;
	cout << "Avarage = " << average << endl;
	for (size_t i = 0; i < 4; i++)
	{
		cout << "Sales in quarter " << i + 1 << ": ";
		cout << sales[i] << endl;
	}
	cout << endl;
}