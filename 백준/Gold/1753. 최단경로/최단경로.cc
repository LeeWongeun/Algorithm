#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input(vector<vector<pair<int, int>>>& g, int& v, int& e, int& start)
{
	cin >> v >> e >> start;
	g.resize(e+1);
	for (int i = 0; i < e; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		g[from-1].push_back({ to-1, cost });
	}
}

vector<int> diijkstra(vector<vector<pair<int, int>>>& g, int v, int start)
{
	vector<int> d(v, 100000000);
	priority_queue<pair<int, int>> pq;

	d[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int curDist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < g[cur].size(); i++)
		{
			int next = g[cur][i].first;
			int newDist = g[cur][i].second + d[cur];
			if (d[next] > newDist)
			{
				d[next] = newDist;
				pq.push({ -newDist,next });
			}
		}
	}

	return d;
}

void print(vector<int> &d)
{
	for (int i = 0; i < d.size(); i++)
	{
		if(d[i] == 100000000) cout << "INF";
		else cout << d[i];
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> d;
	vector<vector<pair<int,int>>> g;
	int v, e;
	int start;

	input(g, v, e, start);
	d = diijkstra(g, v, start-1);
	print(d);
}