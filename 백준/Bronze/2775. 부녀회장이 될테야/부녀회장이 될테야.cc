#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, testcase;
	cin >> testcase;
	for (int t = 0; t < testcase; t++)
	{
		cin >> k >> n;
		//arr[a][b] = arr[a-1][0] + ... + arr[a-1][b];
		vector<vector<int>> vec(k + 1, vector<int>(n + 1, 0));

		for (int i = 0; i <= n; i++)
		{
			vec[0][i] = i;
		}

		for (int i = 1; i <= k; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				for (int k = 0; k <= j; k++)
				{
					vec[i][j] += vec[i - 1][k];
				}
			}
		}
		cout << vec[k][n] << '\n';
	}
}
