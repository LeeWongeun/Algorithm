#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long n, m, cnt = 0;
	long ans = 0;
	cin >> n >> m;

	vector<long> sumvec(n+1);
	vector<long> cntvec(m, 0);

	for (long i = 1; i <= n; i++)
	{
		long temp;
		cin >> temp;
		sumvec[i] = sumvec[i - 1] + temp;
	}
	for (long i = 1; i <= n; i++)
	{
		sumvec[i] = sumvec[i] % m;
		if (sumvec[i] == 0)
		{
			ans++;
		}
		cntvec[sumvec[i]]++;
	}
	for (long i = 0; i < m; i++)
	{
		ans += cntvec[i] * (cntvec[i] - 1) / 2;
	}
	cout << ans;
}