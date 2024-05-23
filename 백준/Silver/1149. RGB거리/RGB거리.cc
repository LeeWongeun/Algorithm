#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> vec(n + 1, vector<int>(n + 1));
	vector<vector<int>> d(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> vec[i][j];
		}
	}
	for (int i=0; i < 3; i++)
	{
		d[1][i] = vec[1][i];
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int m = 1e9;
			for (int k = 0; k < 3; k++)
			{
				if (m > d[i - 1][k] && k != j)
				{
					m = d[i - 1][k];
				}
			}
			d[i][j] = m + vec[i][j];
		}
	}

	int result = min(d[n][0], min(d[n][1], d[n][2]));
	cout << result;
}