#include "Header.h"

int main()
{
	Person one;
	Person two(" Smythe craft ");
	Person three(" Dimwiddy ", "Sam");
	one = three;
	one.Show();
	one.FormalShow();
	cout << endl;
	two.FormalShow();
	two.Show();
}