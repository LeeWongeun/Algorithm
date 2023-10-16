#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int n, m;

long check(int h)
{
	long sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i] - h > 0)
			sum += v[i] - h;
	}
	return sum;
}

int solve(int start, int end)
{
	int mid = (start + end) / 2;
	long a = check(mid);
	if (start >= end || a == m)
	{
		return mid;
	}
	if (a > m)
	{
		return solve(mid + 1, end);
	}
	else
	{
		return solve(start, mid - 1);
	}
}

int main()
{
	int h = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
		if (temp > h) h = temp - 1;
	}

	h = solve(1, h);

	if (check(h) >= m)
	{
		while (check(h) >= m)
		{
			h++;
		}
		h--;
	}
	else
	{
		while (check(h) < m)
		{
			h--;
		}
	}

	cout << h;
}