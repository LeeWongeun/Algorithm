#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BS(int start, int end);

int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	cout << BS(1, k);
}

int BS(int start, int end)
{
	int lastMid = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int count = 0;
		
		for (int i = 1; i <= n; i++)
		{
			int a = mid / i;
			if (a < n)
			{
				count += a;
			}
			else
			{
				count += n;
			}
		}


		if (count < k)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
			lastMid = mid;
		}
	}

	return lastMid;
}