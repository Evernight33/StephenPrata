#ifndef Header_h
#define Header_h

#include <iostream>
#include <valarray>
#include <string>
using namespace std;

typedef valarray<int> Arrayint;
typedef pair<Arrayint, Arrayint> PairArray;

class Wine : private string, private PairArray
{
private:
	int year;
public:
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	~Wine();
	void Show() const;
	void GetBottles();
	const string& Label() const;
	int Sum() const;
};

#endif