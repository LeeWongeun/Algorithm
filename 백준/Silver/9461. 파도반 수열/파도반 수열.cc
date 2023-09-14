#include <iostream>
#include <vector>

using namespace std;

long long padovan(int n, vector<long long> &vec, int &cur)
{
	if (vec.size() > n + 1) return vec[n];

	for (int i = cur; i <= n; i++)
	{
		vec.push_back(vec[i - 2] + vec[i - 3]);
	}

	if (n >= cur) cur = n + 1;

	return vec[n];
}

void initVec(vector<long long>& vec)
{
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
}

int main()
{
	int n, cur, temp;
	vector<long long> vec;
	vector<int> input;

	initVec(vec);
	cur = vec.size();

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		cout << padovan(input[i], vec, cur) << "\n";
	}
}