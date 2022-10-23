#include "Header.h"


//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter name of wine: "; // ввод названия вина 
	char lab[50];
	std::cin.getline(lab, 50);
	std::cout << std::endl;

	std::cout << "Enter number of years: "; // ввод количества годов сбора винограда 
	int yrs = 0;
	std::cin >> yrs;

	Wine holding(lab, yrs);	// сохранение названия, лет, 
							// создание массивов из yrs элементов 
	holding.GetBottles();	// предложение ввести год и количество бутылок 
	holding.Show();			// вывод содержимого объекта 

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	// Создание нового объекта, инициализация 
	// с использованием данных из массивов у и b 
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	std::cout << std::endl;

	std::cout << "Total bottles for " << more.Label();  // используется метод Label() 
	std::cout << ": " << more.Sum() << std::endl; 		// используется метод sum() 
	std::cout << "Bye\n";

	std::cin.get();
	std::cin.get();
	return 0;
}