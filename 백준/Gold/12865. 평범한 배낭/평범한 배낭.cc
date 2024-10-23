#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> d(n+1, vector<int>(k + 1, 0));
	vector<pair<int,int>> item;

	item.push_back({ 0,0 });
	for (int i = 0; i < n; i++)
	{
		pair<int, int> temp; //first : 무게, second : 가치
		cin >> temp.first >> temp.second;
		item.push_back(temp);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j - item[i].first >= 0)
			{
				d[i][j] = max(d[i-1][j], d[i-1][j - item[i].first] + item[i].second);
			}
			else
			{
				d[i][j] = d[i - 1][j];
			}
		}
	}

	cout << d[n][k];
}