#include "Header.h"


//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << "Enter name of wine: "; // ���� �������� ���� 
	char lab[50];
	std::cin.getline(lab, 50);
	std::cout << std::endl;

	std::cout << "Enter number of years: "; // ���� ���������� ����� ����� ��������� 
	int yrs = 0;
	std::cin >> yrs;

	Wine holding(lab, yrs);	// ���������� ��������, ���, 
							// �������� �������� �� yrs ��������� 
	holding.GetBottles();	// ����������� ������ ��� � ���������� ������� 
	holding.Show();			// ����� ����������� ������� 

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	// �������� ������ �������, ������������� 
	// � �������������� ������ �� �������� � � b 
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	std::cout << std::endl;

	std::cout << "Total bottles for " << more.Label();  // ������������ ����� Label() 
	std::cout << ": " << more.Sum() << std::endl; 		// ������������ ����� sum() 
	std::cout << "Bye\n";

	std::cin.get();
	std::cin.get();
	return 0;
}