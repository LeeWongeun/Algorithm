#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,int>> vec;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i].first;
		cin >> vec[i].second;
	}
	sort(vec.begin(), vec.end(), cmp);

	int cnt = 0;
	int endTime = 0;
	for (int i = 0; i < n; i++)
	{
		if (vec[i].first >= endTime)
		{
			cnt++;
			endTime = vec[i].second;
		}
	}

	cout << cnt;
}