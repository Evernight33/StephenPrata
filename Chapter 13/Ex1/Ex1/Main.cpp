
#include "Header.h" // ����� ��������� #include cd.h 

using namespace std;

void Bravo(const CD& disk);

int main()
{
	CD cl("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in � flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	CD* pcd = &cl;
	// ���������������� ������������� �������� 
	cout << "Using object directly:\n";
	cl.Report(); // ������������� ������ Cd 
	c2.Report(); // ������������� ������ Classic 
	// ������������� ��������� �� ������� ���� cd * 
	cout << "Using type cd * pointer to objects: \n";
	pcd->Report(); // ������������� ������ Cd ��� ������� cd 
	pcd = &c2;
	pcd->Report(); // ������������� ������ Classic ��� ������� classic 
	// ����� ������� � ����������-������� �� Cd 
	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(cl);
	Bravo(c2);
	// ������������ ������������ 
	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	return 0;
}

void Bravo(const CD& disk)
{
	disk.Report();
}