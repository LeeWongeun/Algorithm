#include <iostream>
#include <queue>

using namespace std;

void input(int& v, int& e, int& v1, int& v2, vector<vector<pair<int, int>>>& g)
{
	cin >> v >> e;
	g.resize(e + 1);
	for (int i = 0; i < e; i++)
	{
		int to, from, cost;
		cin >> from >> to >> cost;
		g[from-1].push_back({ to-1,cost });
		g[to-1].push_back({ from-1,cost });
	}
	cin >> v1 >> v2;
	v1--;
	v2--;
}

int diijkstra(vector<vector<pair<int, int>>>& g, int start, int end, int v)
{
	priority_queue<pair<int, int>> pq;
	vector<int> d(v, -1);
	d[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int curDist = -pq.top().first;
		pq.pop();

		for (int i = 0; i < g[cur].size(); i++)
		{
			int next = g[cur][i].first;
			int newDist = g[cur][i].second + d[cur];
			if (d[next] > newDist || d[next] == -1)
			{
				d[next] = newDist;
				pq.push({ -newDist,next });
			}
		}
	}

	return d[end];
}

int solve(vector<vector<pair<int, int>>>& g, int v1, int v2, int v)
{
	if (diijkstra(g, 0, v - 1, v) == -1) return -1;

	int d_1tov1 = diijkstra(g, 0, v1, v) + diijkstra(g, v1, v2, v) + diijkstra(g, v2, v - 1, v);
	int d_1tov2 = diijkstra(g, 0, v2, v) + diijkstra(g, v2, v1, v) + diijkstra(g, v1, v - 1, v);
	return min(d_1tov1,d_1tov2);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int v, e, v1, v2;
	vector<vector<pair<int, int>>> g;

	input(v, e, v1, v2, g);
	cout << solve(g, v1, v2, v);
}