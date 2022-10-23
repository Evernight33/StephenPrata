#include "Header.h"

List::List()
{
	cur_v = NULL;
}

void List::add(int el)
{
	element<int>* new_el = new element<int>;
	new_el->val = el;
	new_el->prev = cur_v;
	cur_v = new_el;
}

void List::show()
{
	element<int>* new_el = cur_v;

	while (new_el)
	{
		cout << "Value: " << new_el->val << endl;
		new_el = new_el->prev;
	}
}

int main()
{
	List l1;
	l1.add(56);
	l1.add(78);
	l1.add(45);
	l1.show();
}