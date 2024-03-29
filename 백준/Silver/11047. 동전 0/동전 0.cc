#include<iostream>
#include <vector>

using namespace std;

int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> coin;
	int result = 0;
	
	cin >> n >> k;
	coin.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	for (int i = n - 1; i >= 0; i--)
	{
		int count = k / coin[i];
		k = k - coin[i] * count;
		result += count;
	}

	cout << result;
}