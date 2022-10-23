#include <iostream>
#include <initializer_list>

using namespace std;

template <typename T>
T AverageList(initializer_list<T> Il)
{
	T Sum = 0;

	for (auto pi = Il.begin(); pi != Il.end(); pi++)
	{
		cout << *pi << "  ";
		Sum += *pi;
	}

	cout << endl;

	T Avg = Sum / Il.size();
	return Avg;
}

int main()
{
	auto Result1 = AverageList({ 17.4, 10.7, 5.0, 3.1 });
	cout << "Result1: " << Result1 << "\n\n";

	auto Result2 = AverageList({ 20, 40, 74, 23, 148, 5 });
	cout << "Result2: " << Result2 << "\n\n";

	auto Result3 = AverageList<double>({ 'A', 39, 70.40, 'F', 40 });
	cout << "Result3: " << Result3 << "\n\n";

}