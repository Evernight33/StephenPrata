#include "Header.h"
using namespace SALES;

// Копирует меньшее значение из 4 или n элементов из массива
	// ar в член sales структуры s, вычисляет и сохраняет
	// среднее арифметическое , максимальное и минимальное
	// значения введенных чисел;
	// оставшиеся элементы sales, если таковые есть, устанавливаются в О

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

// Интерактивно подсчитывает продажи за 4 квартала ,
	// сохраняет их в члене sales структуры s, вычисляет и
		// сохраняет среднее арифметическое, а также максималь ное
		// и минимальное значения введенных чисел
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

// Отображает всю информацию из структуры s
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