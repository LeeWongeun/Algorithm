#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
	int parentL = -1;
	int parentR = -1;
	int num = -1;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;
	vector<vector<int>> vec(n);
	vector<vector<int>> D(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			int temp;
			cin >> temp;
			vec[i].push_back(temp);
			D[i].push_back(0);
		}
	}

	D[0][0] = vec[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			if (j == 0)
			{
				D[i][j] = D[i - 1][j] + vec[i][j];
			}
			else if (j == i)
			{
				D[i][j] = D[i - 1][j - 1] + vec[i][j];
			}
			else
			{
				D[i][j] = max(D[i - 1][j] + vec[i][j], D[i - 1][j - 1] + vec[i][j]);
			}
		}
	}

	cout << *max_element(D[n - 1].begin(), D[n - 1].end());
}