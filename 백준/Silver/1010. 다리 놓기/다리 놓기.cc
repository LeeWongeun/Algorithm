#include <iostream>
#include <vector>

using namespace std;

//D[n][m] = D[n-1][m-1] + D[n][m-1];

void Calc(int n, int m);

long D[30][30] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, testcase;

	for (int i = 0; i < 30; i++)
	{
		D[i][i] = 1;
		D[i][0] = 1;
		D[i][1] = i;
	}

	cin >> testcase;

	for (int t = 0; t < testcase; t++)
	{
		cin >> n >> m;
		if (D[m][n] == 0)
		{
			Calc(m, n);
		}
		cout << D[m][n] << '\n';
	}
}

void Calc(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (D[i][j] == 0)
			{
				D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
			}
		}
	}
}