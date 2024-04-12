#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void u(int a, int b);
int find(int a);

vector<int> vec;
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vec.resize(n + 1);

	for (int i = 0; i < n + 1; i++)
	{
		vec[i] = i;
	}

	for (int t = 0; t < m; t++)
	{
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0)
		{
			u(a, b);
		}

		else if (op == 1)
		{
			if (find(vec[a]) == find(vec[b]))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}

void u(int a, int b)
{
	int x = find(a);
	int y = find(b);
	vec[y] = x;
}

int find(int a)
{
	if (vec[a] == a)
	{
		return a;
	}
	else
	{
		return vec[a] = find(vec[a]);
	}
}