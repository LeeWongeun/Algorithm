#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BS(int n, int start, int end);

vector<int> vec;
vector<int> dist;
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		cout << BS(num, 0, vec.size() - 1) << '\n';
	}
}

int BS(int n, int start, int end)
{
	int m = (start + end) / 2;

	if (start > end)
	{
		return 0;
	}
	if (vec[m] == n)
	{
		return 1;
	}
	else if (vec[m] > n)
	{
		return BS(n, start, m - 1);
	}
	else if (vec[m] < n)
	{
		return BS(n, m + 1, end);
	}
}