#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax();
int BS(int start, int end);

int n, m;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vec.resize(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		sum += vec[i];
	}

	int max = getMax();
	cout << BS(max, sum);
}

int BS(int start, int end)
{
	int count = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int sum = 0;
		count = 0;

		for (int i = 0; i < n; i++)
		{
			if (mid < sum + vec[i])
			{
				count++;
				sum = 0;
			}
			sum += vec[i];
		}

		if (sum != 0)
		{
			count++;
		}

		if (count > m)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return start;
}

int getMax()
{
	int max=vec[0];
	for (int i = 1; i < n; i++)
	{
		if (max < vec[i])
		{
			max = vec[i];
		}
	}
	return max;
}
