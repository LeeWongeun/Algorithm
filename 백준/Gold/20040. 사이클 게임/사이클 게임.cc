#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> unionVec;

int unionFunc(int a, int b);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	unionVec = vector<int>(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		unionVec[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		if (unionFunc(s, e))
		{
			cout << i + 1;
			return 0;
		}
	}

	cout << '0';
}

int find(int n)
{
	if (n == unionVec[n])
	{
		return n;
	}

	return unionVec[n] = find(unionVec[n]);
}

int unionFunc(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		unionVec[a] = b;
		return 0;
	}
	else
	{
		return 1;
	}
}