#include <iostream>
#include <cctype>
#include "stack.h"
using namespace std;

int main()
{
	Stack st;
	char ch;
	Item po;
	cout << "Please press A to add customer,\n";
	cout << "P to precess a customer, or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << "\a";
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "Enter a customer fullname: ";
			cin >> po.fullname;
			while (cin.get() != '\n')
				continue;
			cout << "Enter a customer precess: ";
			cin >> po.payment;
			if (st.isfull())
			{
				cout << "stack is already full\n";
			}
			else
			{
				st.push(po);
			}
			break;
		case 'P':
		case 'p':
			if (st.isempty())
			{
				cout << "stack is already empty\n";
			}
			else
			{
				st.pop(po);
				cout << "Customer #" << po.fullname << " popped\n";
			}
			break;
		}
		cout << "Please press A to add customer,\n";
		cout << "P to precess a customer, or Q to quit.\n";
	}
	cout << "Bye!\n";
}