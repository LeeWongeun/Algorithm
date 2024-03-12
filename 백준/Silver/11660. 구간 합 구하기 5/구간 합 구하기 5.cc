#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> sumarr(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			sumarr[i][j] = sumarr[i - 1][j] + sumarr[i][j - 1] + arr[i][j] - sumarr[i - 1][j - 1];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int beginRow, beginCol, endRow, endCol;
		cin >> beginRow >> beginCol >> endRow >> endCol;
		cout << sumarr[endRow][endCol]
			- sumarr[endRow][beginCol - 1]
			- sumarr[beginRow - 1][endCol]
			+ sumarr[beginRow - 1][beginCol - 1] << '\n';
	}
}