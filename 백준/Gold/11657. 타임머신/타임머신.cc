#include <iostream>
#include <vector>

using namespace std;

void bellman_ford();
int checkAndUpdateDist();

struct edge
{
	int s;
	int e;
	int cost;
};

int n, m;
vector<edge> edges, start, end;
vector<long long> dist;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	edges.resize(m + 1);
	dist.resize(n + 1, 1e9);
	for (int i = 1; i <= m; i++)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		edges[i] = { s,e,cost };
	}

	bellman_ford();
	
	if (checkAndUpdateDist())
	{
		cout << "-1";
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] != 1e9)
			{
				cout << dist[i] << '\n';
			}
			else
			{
				cout <<  "-1\n" ;
			}
		}
	}
}

void bellman_ford()
{
	dist[1] = 0;
	for (int i = 1; i < n; i++)
	{
		checkAndUpdateDist();
	}
}

int checkAndUpdateDist()
{
	int flag = 0;
	for (int j = 1; j <= m; j++)
	{
		int s = edges[j].s;
		int e = edges[j].e;
		int cost = edges[j].cost;
		if (dist[s] != 1e9 && dist[s] + cost < dist[e])
		{
			dist[e] = dist[s] + cost;
			flag = 1;
		}
	}
	return flag;
}