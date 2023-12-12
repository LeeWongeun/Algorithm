#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	vector<int> dp;
	cin >> n;
	dp.push_back(0);
	dp.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		dp.push_back(dp[i - 1] + 1);
		for (int j = 2; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n];
}