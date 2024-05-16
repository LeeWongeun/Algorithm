/*
* 5개 중에 2개를 뽑아야한다.
* = 4개중에 1개 뽑는 경우의 수 4개중에 2개 뽑는 경우의 수
* D[i][j] = D[i-1][j-1] + D[i-1][j]
* 
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<long>> D(n + 1, vector<long>(n + 1, -1));

	for (int i = 0; i <= n; i++)
	{
		D[i][1] = i;
		D[i][i] = 1;
		D[i][0] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (D[i][j] = -1)
			{
				D[i][j] = D[i - 1][j - 1] + D[i - 1][j];
				D[i][j] = D[i][j] % 10007;
			}
		}
	}

	cout << D[n][k];
}
