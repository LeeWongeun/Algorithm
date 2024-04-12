#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void unionFunc(int a, int b);
int find(int a);

vector<int> vec;
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		vec[i] = i;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 1)
			{
				unionFunc(i, j);
			}
		}
	}

	int temp;
	cin >> temp;
	int root = find(temp-1);
	for (int i = 0; i < m-1; i++)
	{
		cin >> temp;
		if (root != find(temp-1))
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
	return 0;
}

void unionFunc(int a, int b)
{

	vec[find(b)] = vec[find(a)];
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