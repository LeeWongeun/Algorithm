#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		vector<vector<int>> s(2, vector<int>(n + 1));
		s[0][0] = 0;
		s[1][0] = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> s[i][j];
			}
		}

		vector<vector<int>> d(2, vector<int>(n + 1, 0));

		for (int i = 1; i <= n; i++)
		{
			if (i == 1)
			{
				d[0][i] = s[0][i];
				d[1][i] = s[1][i];
				continue;
			}

			d[0][i] = max(d[1][i - 1] + s[0][i], max(d[0][i - 2] + s[0][i], d[1][i - 2] + s[0][i]));
			d[1][i] = max(d[0][i - 1] + s[1][i], max(d[0][i - 2] + s[1][i], d[1][i - 2] + s[1][i]));
		}
		cout << max(d[0][n], d[1][n]) << '\n';
	}
}