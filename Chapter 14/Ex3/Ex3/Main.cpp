#include "Workermi.h"
#include <iostream>
using namespace std;

const int sz = 5;

int main()
{
	QueueTp<Worker*> wk;
	Worker* pw = nullptr;
	int ct;
	for (ct = 0; ct < sz; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n";
		cout << "w: waiter\ns: singer\nt: singing waiter\nq: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter w, s, t or q:\n";
			cin >> choice;
		}
		if (choice == 'q')
		{
			break;
		}
		switch (choice)
		{
		case 'w':
			pw = new Waiter;
			break;
		case 's':
			pw = new Singer;
			break;
		case 't':
			pw = new SingingWaiter;
			break;
		}
		cin.get();
		pw->Set();
		wk.enqueue(pw);
	}

	cout << "Here is your staff:\n";
	int i;
	for (int i = 0; i < ct; i++)
	{
		cout << endl;
		wk.dequeue(pw);
		pw->Show();
	}
	for (int i = 0; i < ct; i++)
	{
		cin.get();
		cin.get();
	}
	cout << "\nBye!\n";
	return 0;
}

