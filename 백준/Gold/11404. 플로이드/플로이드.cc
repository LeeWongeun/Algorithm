#include <iostream>
#include <vector>

using namespace std;

struct edge
{
	int s;
	int e;
	int cost;
};

int n, m;
vector<edge> edges, start, end;
vector<vector<long long>> dist;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	dist = vector<vector<long long>>(n + 1, vector<long long>(n + 1, 1e9));

	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		if (dist[s][e] > cost)
		{
			dist[s][e] = cost;
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				dist[s][e] = min(dist[s][e], dist[s][k] + dist[k][e]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			long long d = dist[i][j];
			if (d != 1e9)
			{
				cout << d << ' ';
			}
			else
			{
				cout << '0' << ' ';
			}
		}
		cout << '\n';
	}
}