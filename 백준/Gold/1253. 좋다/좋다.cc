#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	int a, b, cnt = 0, sum;
	for (int i = 0; i < n; i++)
	{
		long m = vec[i];
		a = 0;
		b = n - 1;
		while (a < b)
		{
			sum = vec[a] + vec[b];
			if (sum == m)
			{
				if (a != i && b != i)
				{
					cnt++;
					break;
				}
				if (a == i)
				{
					a++;
				}
				if (b == i)
				{
					b--;
				}
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
	}
	cout << cnt;
}