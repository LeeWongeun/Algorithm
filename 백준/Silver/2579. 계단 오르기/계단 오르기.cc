#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getInput(int& n, vector<int>& vec)
{
	int intTemp;
	cin >> n;

	vec.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		cin >> intTemp;
		vec.push_back(intTemp);
	}
}

int calcMax(int n, vector<int> vec)
{
	vector<int> memorization;
	if (n >= 0)
	{
		memorization.push_back(0);
	}
	if (n >= 1)
	{
		memorization.push_back(vec[1]);
	}
	if (n >= 2)
	{
		memorization.push_back(vec[1] + vec[2]);
	}
	for (int i = 3; i <= n; i++)
	{
		memorization.push_back(max(memorization[i - 3] + vec[i - 1] + vec[i], memorization[i - 2] + vec[i]));
	}

	return memorization[n];
}

int main()
{
	int n;
	vector<int> vec;
	int ans;

	getInput(n, vec);
	ans = calcMax(n, vec);

	cout << ans;
}