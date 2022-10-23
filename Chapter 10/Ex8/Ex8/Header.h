#ifndef HEADER
#define HEADER

#include <iostream>
using namespace std;

template <typename T>
struct element
{
	T val;
	element* prev;
};

class List
{
private:
	element<int>* cur_v;
public:
	List();
	void add(int el);
	void show();
};
#endif 
