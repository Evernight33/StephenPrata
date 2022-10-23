#include "Cow.h"

int main()
{
	Cow c1;
	Cow c2("Peter", "Football", 78);
	c1 = c2;
	c1.ShowCow();
	c2.ShowCow();
	Cow *c3 = new Cow("Den", "Basketball", 80);
	c3->ShowCow();
	*c3 = c2;
	c3->ShowCow();
}