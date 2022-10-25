#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

#if 0

template <class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T& t) : cutoff(t) {}
	bool operator()(const T& val) { return val > cutoff; }
};

void outint(int n) { cout << n << " "; }

#endif

int main()
{
	int values[10] = { 50, 190, 370, 34, 280, 12, 34, 10, 123, 83};
	list<int> FirstList(values, values + 10);
	list<int> SecondList(values, values + 10);

	auto OutInt = [](int n) { cout << n << " "; };

	cout << "Original lists:\n";
	for_each(FirstList.begin(), FirstList.end(), OutInt);
	cout << endl;
	for_each(SecondList.begin(), SecondList.end(), OutInt);
	cout << endl;

	FirstList.remove_if( [](int x) { return x > 100; } );
	SecondList.remove_if( [](int x) { return x > 200; } );

	cout << "Updated list:\n";
	for_each(FirstList.begin(), FirstList.end(), OutInt);
	cout << endl;
	for_each(SecondList.begin(), SecondList.end(), OutInt);
	cout << endl;

	return 0;
}