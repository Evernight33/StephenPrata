#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Lotto(int nums, int rands);

int main(int nums, int rands)
{
	vector<int> wins = Lotto(51, 7);
	int j = 1;
	for (vector<int>::iterator i = wins.begin(); i < wins.end(); i++)
	{
		cout << j << ": "<< *i << endl;
		j++;
	}
}

vector<int> Lotto(int nums, int rands)
{
	if (nums <= 0 || rands <= 0)
	{
		cout << "Function parameters must be greater then 0\n";
		exit(EXIT_FAILURE);
	}

	vector<int> all_num;

	for (int i = 1; i < nums; i++)
	{
		all_num.push_back(i);
	}
	
	random_shuffle(all_num.begin(), all_num.end());

	vector<int> rand_num;

	rand_num.assign(all_num.begin(), all_num.begin() + rands);

	return rand_num;
}