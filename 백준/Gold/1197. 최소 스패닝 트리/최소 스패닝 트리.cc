#include <iostream>
#include <queue>

using namespace std;

void input(int& v, int& e, vector<vector<pair<int, int>>>& g)
{
	cin >> v >> e;
	g.resize(v);
	for (int i = 0; i < e; i++)
	{
		int to, from, cost;
		cin >> from >> to >> cost;
		g[from - 1].push_back({ to-1,cost });
		g[to - 1].push_back({ from - 1,cost });
	}
}

int MST(int v, int e, vector<vector<pair<int, int>>>& g)
{
	priority_queue<pair<int, int>> pq; //앞:cost 뒤:노드
	vector<int> visit(v, 0);
	pq.push({ 0,0 });
	int totalCost = 0;


	while (!pq.empty())
	{
		pair<int, int> cur = pq.top(); //앞:cost 뒤:노드
		pq.pop();
		if (visit[cur.second] == 0)
		{
			visit[cur.second] = 1;
			totalCost += -cur.first;
		}
		for (int i = 0; i < g[cur.second].size(); i++)
		{
			pair<int,int> next = g[cur.second][i];
			if (visit[next.first] == 0)
			{
				pq.push({ -next.second,next.first });
			}
		}
	}

	return totalCost;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int v, e;
	vector<vector<pair<int, int>>> g;

	input(v, e, g);
	cout << MST(v, e, g);
}

