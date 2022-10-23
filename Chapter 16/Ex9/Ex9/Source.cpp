#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <random>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	vector<int> vi0(10000);

	for (int i = 0; i < 10000; i++)
	{
		vi0[i] = rand();
	}
	
	vector<int> vi = vi0;
	list<int> li(10000);
	copy(vi0.begin(), vi0.end(), li.begin());

	clock_t start = clock();
	sort(vi.begin(), vi.end());
	clock_t end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

	start = clock();
	li.sort();
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

	copy(vi0.begin(), vi0.end(), li.begin());

	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

	cin.get();
	cin.get();
	return 0;
}