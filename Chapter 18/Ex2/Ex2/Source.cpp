#include "Header.h"

CopyMove::CopyMove()
{
	pi = new Info;
	cout << "Default constructor\n";
	cout << "Address " << (void*)pi << "\n\n";
}

CopyMove::CopyMove(string q, string l)
{
	pi = new Info;
	pi->qcode = q;
	pi->lcode = l;
	cout << "q and l constructor called\n";
	cout << "Address " << (void*)pi << "\n\n";
}

CopyMove::CopyMove(const CopyMove& copy)
{
	pi = new Info;
	pi->qcode = copy.pi->qcode;
	pi->lcode = copy.pi->lcode;
	cout << "Copy constructor called\n";
	cout << "Address " << (void*)pi << "\n\n";
}

CopyMove::CopyMove(CopyMove&& move)
{
	pi = new Info;
	pi->qcode = move.pi->qcode;
	pi->lcode = move.pi->lcode;
	move.pi = nullptr;
	cout << "Move constructor called\n";
	cout << "Address " << (void*)pi << "\n\n";
}

CopyMove CopyMove::operator+(const CopyMove& obj) const
{
	cout << "Entering operator+()\n";
	CopyMove temp;
	temp.pi->lcode = obj.pi->lcode + pi->lcode;
	temp.pi->qcode = obj.pi->qcode + pi->qcode;
	cout << "Leaving operator+()";

	return temp;
}

CopyMove& CopyMove::operator=(const CopyMove& copy)
{
	cout << "Entering copy operator= \n";

	if (this != &copy)
	{
		delete pi;
		pi = new Info;
		pi->lcode = copy.pi->lcode;
		pi->qcode = copy.pi->qcode;
	}

	cout << "Leaving copy operator= \n";

	return *this;
}

CopyMove& CopyMove::operator=(CopyMove&& move)
{
	cout << "Entering move operator= \n";

	if (this != &move)
	{
		delete pi;
		pi = move.pi;
		move.pi = nullptr;
		cout << "Address " << (void*)pi << "\n\n";
	}

	cout << "Leaving move operator= \n";

	return *this;
}

CopyMove::~CopyMove()
{
	cout << "Destructor called\n";
	cout << "Address " << (void*)pi << "\n\n";

	delete pi;
}

void CopyMove::Display() const
{
	if (pi == nullptr)
	{
		cout << "Object is empty";
	}
	else
	{
		cout << " " << pi->qcode << ", ";
		cout << pi->lcode << endl;
	}
}

int main()
{
	CopyMove first("Akame Ga", "Kill");
	CopyMove second = first;

	CopyMove third("Satsuriku", "no Tenshi");
	CopyMove fourth(first + third);

	CopyMove fifth;
	fifth = first;

	CopyMove sixth;
	sixth = fifth + third;

	cout << "\n Object 1";
	first.Display();

	cout << "\n Object 2";
	second.Display();

	cout << "\n Object 3";
	third.Display();

	cout << "\n Object 4";
	fourth.Display();

	cout << "\n Object 5";
	fifth.Display();

	cout << "\n Object 6";
	sixth.Display();
}