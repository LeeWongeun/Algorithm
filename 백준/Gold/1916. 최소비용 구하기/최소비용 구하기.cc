#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Daijkstra();

vector<vector<pair<int,int>>> g;
vector<int> isVisited;
vector<long> minDist;
int n, m;
int S, E;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	g.resize(n + 1);
	minDist = vector<long>(n + 1, 1E9);
	isVisited = vector<int>(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		g[s].push_back({ e,cost });
	}
	cin >> S >> E;

	Daijkstra();

	cout << minDist[E];
}

void Daijkstra()
{
	priority_queue<pair<int,int>> pq;
	pq.push({ 0,S });
	minDist[S] = 0;
	
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (isVisited[cur] == 1)
		{
			continue;
		}
		isVisited[cur] = 1;

		for (int i = 0; i < g[cur].size(); i++)
		{
			int next = g[cur][i].first;
			int cost = g[cur][i].second;
			
			if (minDist[next] > minDist[cur] + cost)
			{
				minDist[next] = minDist[cur] + cost;
				pq.push({-minDist[next], next});
			}
		}
	}
}