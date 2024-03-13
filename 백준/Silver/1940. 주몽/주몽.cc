#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int n, m;

	cin >> n >> m;
	vector<int> vec(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	int a = 0, b = n - 1, cnt = 0, sum;
	while (a < b)
	{
		sum = vec[a] + vec[b];
		if (sum == m)
		{
			cnt++;
			a++;
			b--;
		}
		else if (sum < m)
		{
			a++;
		}
		else if (sum > m)
		{
			b--;
		}
	}
	cout << cnt;
}
