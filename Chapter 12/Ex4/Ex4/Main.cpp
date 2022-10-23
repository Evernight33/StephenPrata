#include "Stack.h"

int main()
{
	cout << "setting s1..." << endl;
	Stack s1;
	std::cout << "setting s2..." << endl;
	Stack s2(5);
	cout << "setting s3..." << endl;
	Stack s3(-1);
	cout << "setting s4..." << endl;
	Stack s4 = Stack(10);
	cout << "setting s5..." << endl;
	Stack s5(s4);
	cout << "setting s6..." << endl;
	Stack s6 = Stack(s3);
	cout << endl;

	cout << "s1.isempty() == " << s1.isempty() << endl;
	s1.push(10);
	s1.push(20);
	s1.push(30);

	s2 = s1;

	unsigned long int x = 0;
	s2.pop(x);

	cout << "We pushed 10, 20, and 30 into s1" << endl;
	cout << "We assigned s2 to s1" << endl;
	cout << "s2.pop(x), x = " << x << endl;
	cout << std::endl;

	cout << "s1: " << endl;
	cout << endl;
	cout << s1;
	cout << "s2: " << endl << s2;
	cout << endl;

	std::cin.get();
	std::cin.get();
	return 0;
}