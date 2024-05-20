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

	int n, m, k;
	int rockNum = 0;
	double result = 0;

	cin >> m;
	vector<int> rocks(m, 0);
	vector<double> probability(m, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		rocks[i] = n;
		rockNum += n;
	}

	cin >> k;

	for (int i = 0; i < m; i++)
	{
		double temp = 1;
		for (int j = 0; j < k; j++)
		{
			temp *= (double(rocks[i] - j) / double(rockNum - j));
		}
		probability[i] = temp;
	}
	for (int i = 0; i < m; i++)
	{
		result += probability[i];
	}

	if (result >= 1)
	{
		cout << "1.0";
	}
	else
	{
		cout.precision(9);
		cout << result;
	}
}